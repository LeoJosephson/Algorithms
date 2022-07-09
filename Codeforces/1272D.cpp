// 1272D Remove One Element
#include <iostream>
#include <vector>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, i, m=0;
	cin >> n;
	vector<int> V(n);
	vector<int> E(n, 1);
	vector<int> D(n, 1);
	
	for (i=0; i<n; i++) cin >> V[i];
	
	//biggest sequence that end in V[i]
	for (i=1; i<n; i++){
		if (V[i-1] < V[i]) E[i] = E[i-1]+1;
		m = max(m, E[i]);
	}
		
	//biggest sequence that starts in V[i]
	for(i=n-2; i>=0; i--){
		if(V[i] < V[i+1]) D[i] = D[i+1]+1;
		m = max(m, D[i]);
	}
	
	for(i=0; i<n-2; i++){
		if(V[i]<V[i+2] )m=max(m, E[i]+D[i+2]);
	}
	cout << m << endl;
	return 0;
}
