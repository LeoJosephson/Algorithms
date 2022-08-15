#include<iostream>
#include <string.h>
#include<vector>
using namespace std;
const int NVM=1005;


vector<int> G[NVM];
int n, expt[NVM], pre[NVM]; 
int bol, nut, nempmax, nempmaxa, nemp;

void Inicializa(int n){
    int i, j;
	for (int i=0; i<=n; i++) {
	    expt[i]=1;  G[i].clear();
	}
	for (i=1; i<=bol; i++){
		G[0].push_back(i);
		for (j=bol+1; j<=bol+nut; j++){ 
			int k;
			cin >> k;
			if (k == 1) G[i].push_back(j);
		}
	}
}

int CamAument(int v){
    if (v > bol && expt[v]) return 1;
    pre[v]=1;
	for (int j = 0; j < G[v].size(); j++) {
        int w = G[v][j];
        if (!pre[w]){
			if ( CamAument(w) )  {
			    expt[w]=0;
				G[v].erase(G[v].begin()+j);
				G[w].push_back(v);
			    return 1;	 				
			}
		}
    }
    return 0;
}

int main(){
	int t;
	cin >> t;
	int a = t;
	while(t--){
        cin >> bol >> nut; 
		n = bol + nut;
	    Inicializa(n);
        nempmax = 0; nempmaxa = 0;
        memset(pre, 0, sizeof(pre));  
		while(true){                  
			while (nemp = CamAument(0))
		    	nempmax +=nemp;
			if (nempmaxa == nempmax)
				break;
			nempmaxa = nempmax;
			memset(pre, 0, sizeof(pre)); 
			
		}
		cout<<"Case " << a-t <<": a maximum of " << nempmax <<" nuts and bolts can be fitted together"<<endl; 
    }
	return 0;
}
