#include <iostream>
#include <math.h>

using namespace std;
int A[602];
int k;

int solve(int m, int n){
	int i;
	int sum=0;
	int c = 0;
	for (i=1; i<=n+1; i++){
		if (A[i] > m) return 0;
		if (sum + A[i] > m){
			sum = A[i];
			c++;
		} else{
			sum += A[i];
		}
	}
	return c <= k;
}

int main(){
	int n, i;
	int m, m1, m2;
	while (cin >> n >> k){
		A[0] = 0;
		for(i=1; i<=n+1; i++){
			cin >> A[i];		
		}	
		int sum = 0;
		int m1 = 0;
		int m2 = 0;

		if (k == 0){
			for (i=1; i<=n+1; i++) sum+=A[i];
			cout << sum << endl;
		}else{
			int t = n-k+1; 
			for(i=1; i<=n+1; i++){
				if (i > t){ 
					m2 = max(m2, sum);
					sum -= A[i-t];
				}
				sum += A[i];
			}
			m2 = max(m2, sum);
			
			while(m1 <= m2){
			int m = floor((m1+m2)/2);
			
			if (solve(m, n)) m2 = m-1;
			else m1 = m+1;
		}
		cout << m2+1 << endl;
		}		
	}		
}
