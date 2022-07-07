#include <iostream>
#include <math.h>


using namespace std;
int A[602];

int solve(int n, int k){
	m1 = 0;
	m2 = 1000000;
	while(m1 <= m2){
		int m = floor((m1+m2)/2);
		int sum = 0;
	}
}



int main(){
	int n, k, i;
	int m, m1, m2;
	while (cin >> n >> k){
		A[0] = 0;
		for(i=1; i<=n+1; i++){
			cin >> A[i];		
		}
		
		int sum = 0;


		if (k == 0){
			for (i=1; i<=n+1; i++) sum+=A[i];
			cout << sum << endl;
		}else{
			solve(n, k);
			for(i=1; i<=n+1; i++){
				if (i > t){
					m2 = min(m2, sum);
					sum -= A[i-t];
				}
				sum += A[i];
			}
			cout << m2 << endl;
		}
		
		//cout << m2 << endl;
		
		/*
		sum = 0;
		tmpM = 0;
		while (true){
			m = floor((m1+m2)/2);
			
			for(i=1; i<=n; i++){
				if (i >= (m)){
					m2 = max(m2, sum);
				sum -= A[n-k+i];
			} else sum += A[i];
		}*/
			
	}
		
	
	

	
}
