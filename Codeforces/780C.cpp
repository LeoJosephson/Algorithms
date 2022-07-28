#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> colors; 

vector<vector<int>> G; 
int n;
int maxI = 0; 


void BP(int p, int v){ 
	queue<int> AV_COLORS; 
	for(int i=1; i<=maxI; i++){
		if (i != colors[p] && i != colors[v]) AV_COLORS.push(i); 
		if (AV_COLORS.size()==G[v].size()) break; 
	}

	for(int w=1; w<G[v].size(); w++){
		if (colors[G[v][w]] == 0){ 
			colors[G[v][w]] = AV_COLORS.front(); 
			AV_COLORS.pop(); 
			BP(v, G[v][w]);	
		}
	}
}

int main(){
	
	int i;
	int k1, k2;
	cin >> n;
	G.resize(n+1, vector<int>(1, 0)); 
	for(i=0; i<n-1; i++){
		cin >> k1 >> k2;	
		G[k1].push_back(k2);
		G[k2].push_back(k1);

	}
	
	colors.resize(n+1, 0); 
	colors[1] = 1;

	
	for(i=1; i<=n; i++){
		maxI = max(maxI, (int)G[i].size());
	}
	

	BP(1, 1);
	
	cout << maxI << endl;
	for(i=1; i<=n; i++){
		cout << colors[i] << ' ';
	}
	
	
	return 0;
}

