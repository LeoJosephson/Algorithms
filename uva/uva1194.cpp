#include<iostream>
#include <string.h>
#include<vector>
using namespace std;
const int NVM=1005;

vector<int> G[NVM];
int n, expt[NVM], pre[NVM], N, M, K;
int nempmax, nempmaxa, nemp;

void Inicializa(int n){
    int i, j;
	for (int i=0; i<=n; i++) {
	    expt[i]=1;  G[i].clear();
	}
	for (i=1; i<=N; i++){
		G[0].push_back(i);
	}
	for(i=1; i<=K; i++){
		int nm, mx, my;
		cin >> nm >> mx >> my;
		if (mx != 0 && my !=0){ 
			G[mx].push_back(my+N);
			//G[my+N].push_back(mx);
		}
	}
	

}

int CamAument(int v){
    if (v > N && expt[v]) return 1;
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
	cin >> N;
	while(N != 0){
		cin >> M >> K;
		N -=1; M -=1; // ignore mode 0
        n = N + M;
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
		cout<<nempmax<<endl;
		cin >> N; 
    }
	return 0;
}
