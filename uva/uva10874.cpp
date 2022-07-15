#include <iostream>
#include <algorithm>
using namespace std;

int ME[20001], MD[20001];

int solve(int n){
	int l1, r1, li, ri, ln, rn, i;
	if (n == 1){
		cin >> li >> ri;
		return 0;
	}
	cin >> l1 >> r1;
	ME[1] =  2*r1 - l1 -1;
	MD[1] =  r1-1;
	for (i=2; i<n; i++){
		cin >> li >> ri;
		ME[i] = min(ME[i-1]+abs(l1-ri)+ri-li, MD[i-1]+abs(r1-ri)+ri-li);
		MD[i] = min(ME[i-1]+abs(l1-li)+ri-li, MD[i-1]+abs(r1-li)+ri-li);
		l1 = li;
		r1 = ri;
	}
	cin >> ln >> rn;
	return min(ME[n-1]+abs(l1-ln)+n-ln, MD[n-1]+abs(r1-ln)+n-ln) + n -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n != 0){
		cout << solve(n) << endl;
		cin >> n;
	}	
	return 0;
}
