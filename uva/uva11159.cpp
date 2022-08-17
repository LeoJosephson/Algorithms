#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int v1[105];
int v2[105];
int Ni, Mi;

const int NVM=1005;


vector<int> G[NVM];
int n, expt[NVM], pre[NVM]; 
int nempmax, nempmaxa, nemp;

void Inicializa(int n){
    int i, j;
	for (int i=0; i<=n; i++) {
	    expt[i]=1;  G[i].clear();
	}
	for (i=0; i<Ni; i++){
		G[0].push_back(i+1);
		for (j=0; j<Mi; j++){
			if (v2[j]==0 || (v1[i]!=0 && ((v2[j] % v1[i] == 0)))){
				G[i+1].push_back(j+1+Ni);
			}
		}
	}
}


int CamAument(int v){
    if (v > Ni && expt[v]) return 1;
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
	int T, i, j;
	cin >> T;
	int a=T;
	while (T--){
		
		cin >> Ni;
		for(i=0; i<Ni; i++) cin >> v1[i];	
		cin >> Mi;
		for(i=0; i<Mi; i++) cin >> v2[i];
		n = Ni + Mi;
		
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
		cout << "Case " << a-T << ": " << nempmax << endl;
	}
	
	
	return 0;
}
