// 2SAT  
// Os literais positivos devem ser numerados de 1 a n/2
// e os negativos, de n/2+1 a n.
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;


const int NVM=200;

// Declarações para o grafo
int n, m, cpre, topo, pre[NVM], low[NVM], vis[NVM], co[NVM], atr[NVM], E[NVM][NVM], S[NVM];

//Outras declarações
int i, j, u, w, nco, k;

void Inicializa(int n){
    memset(E, 0, sizeof(E));
    memset(pre, 0, sizeof(pre));
    memset(low, 0, sizeof(low));
    memset(vis, 0, sizeof(vis));    
    memset(co, 0, sizeof(co)); 
    memset(atr, -1, sizeof(atr));     
    memset(S, 0, sizeof(S));  
	cpre = 0;  nco = 0;   topo = 0;
}
void CriaGrafo(int nc, int na){
	//Este é o grafo do slide
	//a = 1,  x = 2,  y = 3, z = 4, b = 5, -a = 6, -x = 7, -y = 8, -z = 9, -b = 10
	//Expressão: (-x||y)&&(-y||z)&&(-z||x)&&(a||b)&&(-a||-b)&&(-x||a)&&(-y||b)
	// (x||y)&&(-x||-y)
	// nc = 3  H0 W0 H1 W1 H2 W2 -H0 -W0  -H1 -W1 -H2 -W2  
	//         1  2  3  4  5  6  7    8    9   10  11  12
	 
	for(i=1; i<=nc*2; i+=2){
		
		E[i+(nc*2)][i+1] = E[i+1+(nc*2)][i] = 1; // E[-Hi][Wi] = E[-Wi][Hi] = 1
		E[i][i+1+(nc*2)] = E[i+1][i+(nc*2)] = 1; // E[Hi][-Wi] = E[Wi][-Hi] = 1
	}
	
	for(i=1; i<=na;i++){
		char c1, c2;
		int a1, a2;
		cin >> a1 >> c1 >> a2 >> c2; // 1  2  3  4  5  6  7  8
		//      					  0h 0w 1h 1w 2h 2w 3h 3w
		a1 = a1*2+1; // posição do homem (impar)
		a2 = a2*2+1; // 
		if(c1 == 'w') a1++;
		if(c2 == 'w') a2++;
		
		E[a1][a2+(nc*2)] = E[a2][a1+(nc*2)] = 1;
		
	
	} E[1+nc*2][1] = 1;	
	    
}

int Neg(int i){
    if (i <=n/2) return i+n/2;
    else return i-n/2;
}
void CFCOT(int v){
    int w;
    pre[v]=++cpre;   low[v] = pre[v];  co[v] = 0;  vis[v]=1;  S[++topo]=v;
    for(w=1; w<=n; w++)  if (E[v][w]==1){
        if (pre[w]==0) 
		    CFCOT(w);
        if (vis[w]==1) 
		    low[v]=min(low[v],low[w]);
    }
    if (low[v] == pre[v]){
        nco++;
        while(true){
            w = S[topo--];  vis[w]=0;  co[w] = nco;
            if (atr[Neg(w)] == -1) 
			    atr[w] = 1;
            else                   
			    atr[w] = 0;
            if (w==v) break;   
        }   
    }     
}


int main(){


	int na, nc;
	cin >> nc >> na;
    while(nc != 0){ // nc - numero de casais
		n = (nc)*2*2;		// na -> numero de inimigos
		Inicializa(n); 
        CriaGrafo(nc, na);     
        for (i=1; i<=n; i++)
			if(pre[i] == 0)  
				CFCOT(i);
		//for (i=1; i<=n; i++) cout<<co[i]<<" ";  cout<<endl;
		k = 1;
		for (i=1; i<=n/2; i++)
		    if (co[i] == co[Neg(i)]) 
				k=0;
		if (k){
			int sol = 0;
			//for (i=1; i<=n/2; i++) cout<<atr[i]<<" ";  cout<<endl;
		    for (i=3; i<=n/2; i++){ // 1 2 3 4 5 6 7 8 9 10	
		    	if (atr[i] == 0){
		    		if (sol != 0) cout << ' ';
		    		cout << ceil(i/2.0)-1;
		    		if (i%2 != 0) cout << 'h';
		    		else cout << 'w';
		    		sol ++;
				}
				
			} cout << endl;
	
		}
		else 
		    cout<<"bad luck"<<endl;
		cin >> nc >> na;              
    }
    return 0;
}

