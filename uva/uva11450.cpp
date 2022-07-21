#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> V[20];
	int K[201][21];
	int t, m, c, i, j, k;
	cin >> t;
	while (t--){
		cin >> m >> c;
		for(i=0; i<c; i++){
			cin >> k;
			V[i].resize(k);
			for(j=0; j<k; j++){
				cin >> V[i][j];
			}
		}
		
		K[0][0] = 0;
		for(i=0; i<=m; i++) for(j=0; i<=c; j++) K[i][j] = -1;
		
		for(int i=0; i<=m; i++){ // i = m
			K[i][0] = 0;
			for(int j=1; j<=c; j++){ // j = c
				for(int p=0; p<V[j-1].size(); p++){ // p = i
					int val = V[j-1][p];
					if (i>= val && K[i-val][j-1] != -1){
						K[i][j] = max(K[i][j], K[i-val][j-1] + val);
					}
				}
			}
		
		}
		if (K[m][c] == -1) cout << "no solution" << endl;
    	else cout << K[m][c] << endl;
		
		
	}

	return 0;
}
