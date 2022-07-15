#include <iostream>
using namespace std;
#define M 1000007
int s[10005] = {0, 0, 1, 1, 2, 5, 7, 12};

int mod(int a, int b){
	return (a+b) % M;
}
int solve(int n){
	if (s[n] != -1) return s[n];
	return s[n] = mod(mod(mod(mod(mod(solve(n-2), solve(n-3)),solve(n-4)),3 *solve(n-5)),(3*solve(n-6))),solve(n-7));	
}

//return s[n] = ((((((((((solve(n-2) % M+solve(n-3) % M) % M)+solve(n-4) % M)%M)+(3 *solve(n-5)) % M)%M)+(3*solve(n-6)) % M)%M)+solve(n-7) % M)%M);

int main(){
	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		for(int i=8; i<=n; i++) s[i] = -1;
		solve(n);
		if (n <= 7) cout << s[n] << endl;
		else cout << s[n] + s[n-6]<< endl;
		for(int i=8; i<=n; i++) cout << s[i] - s[i-6] << endl;
	}
	return 0;
}
