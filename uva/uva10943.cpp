#include <iostream>
using namespace std;

int solve(int n, int k){
	int T[101][101] = {0};
	int i, j;
	for (j=0; j<=k; j++){
		T[0][j] = 1;
	}

	for (i=1; i<=n; i++){
		for(j=1; j<=k; j++){
			T[i][j] = (T[i][j-1] + T[i-1][j]) %  1000000;
		}
	}
	return T[n][k];
}

int main(){
	int n, k;
	cin >> n >> k;
	while (n != 0){
		cout << solve(n, k) << endl;
		cin >> n >> k;
	}
	return 0;
}
