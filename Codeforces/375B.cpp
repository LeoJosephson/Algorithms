#include <iostream>
#include <algorithm>
using namespace std;

int M[5005][5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, i, j, sum;
	string line;
	
	cin >> n >> m;
	
	for (i=1; i<=n; i++){
		sum = 0;
		cin >> line;
		for(j=m; j>=1; j--){
			M[i][j] = line[j-1] - '0';
			if (M[i][j] != 0){
				sum += M[i][j];
				M[i][j] = sum;
			} else sum = 0;	
		}
	}
	int mxtot = 0;
	// sort matrix and find biggest rect
	for (j=1; j<=m; j++){
		int L[n] = {0};
		for(i=1; i<=n; i++){
			L[i-1] = M[i][j];
		}
		int mxcol = 0;
		sort(L, L+(sizeof(L) / sizeof(L[0])));
		for(int k=0; k<n; k++){
			M[k+1][j] = L[k];
			mxcol = max(mxcol, M[k+1][j]*(n-k));
		}
		mxtot = max(mxtot, mxcol);
	}
	cout << mxtot << endl;
	
}
