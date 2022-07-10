#include <iostream>
#define mod 1000000007

using namespace std;
unsigned int T[100005][55] = {0};

int main(){
	unsigned int t, m, n, i, j;
	cin >> t >> m >> n;
	for (i=m; i<=n; i++)T[i][1] = 1;

	
	for (j=2; j<=t; j++){
		for (i=m; i<=n; i++){
			T[i][j] = ((T[i-1][j-1] % mod) + (T[i+1][j-1] % mod)) %mod;	
		}
	}
	unsigned int sum = 0;
	
	for (i=m; i<=n; i++) sum = ((sum%mod) + (T[i][t] % mod)) % mod;
	
	cout << sum << endl;
	
	return 0;
}
