#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define N 100000*2 + 1
vector<vector<int>> G;
bool V[N+1] = {false}; // Visited
int C[N+1] = {0}; // Color of ith element


bool BP(int v){
    int w;
    V[v] = true;
	for(w=1; w<G[v].size(); w++){ // v = 1
		int k = G[v][w];
	    if(V[k] == false){
	    	if (C[v] == 1) C[k] = 2; // C[2] = 2
	    	else C[k] = 1;
	    	BP(k);
		}
		if (C[v] == C[k]) return false;
	}
	return true;
} 

int main(){
	int t; cin >> t;
	int a, b, i;
	int n;
	while(t--){	
		cin >> n;
		G.resize(n+1, vector<int>(1,0));
		memset(V, false, (n+1)*sizeof(bool));
		memset(C, 0, (n+1)*sizeof(int));
		for(i=0; i<n; i++){
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		
		bool u = true;
		
		for(i=1; i<=n; i++){
			if(G[i].size()-1 > 2){
				u = false;
				break;
			}
		}
		
		
		C[1] = 1;
		
		for(i=1; i<=n; i++){
			if (V[i] == false){
				if (!u) break;
				C[i] = 1;
				u = BP(i);
			}
		}	
		
		if (u) cout << "YES" << endl;
		else cout << "NO" << endl;
		G.clear();

	}
}

