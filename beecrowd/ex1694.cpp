#include <iostream> 
#include <cmath>
using namespace std;


long long int binomial(int n, int k) {
   if (k == 0) return 1;
   return binomial(n, k-1) * (n-k+1)/(k);
}

bool isprime(int n){
	if (n==2) return true;
	for(int i=2; i<= ceil((sqrt(n))); i++){
		if (n % i == 0){
			return false;
		}
	}
	if (n >= 2)return true;
	else return false;

}

int main() {
	
	

	while (true) {
		int n, m, k, i, j;
		long long int res = 0;
		cin >> n >> m >> k;
		
		if (n == 0 && m == 0 && k == 0){
			break;
		}
		int v[n][m];
		int c = 0;
		
		for (i = 0; i<n; i++){
			for (j=0; j<m; j++){
				v[i][j] = c;
				c++;
			}
		}
		
			
		int count = 0;
		
		
		if (m > 1){
			for (i=0; i<n; i++){
				for (j = 0; j<m; j++){
					if (!isprime(v[i][j])){
						count ++;
					}
				}
	
				if (k == 1){
						res += count;
					} else{
						res += binomial(count, k);
					}
				count = 0;
			}
		}

		
		if (n > 1){
			for (j = 0; j<m; j++){
				for (i=0; i<n; i++){
					if (!isprime(v[i][j])){
						count ++;
					}
				}
				
	
				if (count >= k){
					if (k == 1){
						res += count;
					} else{
						res += binomial(count, k);
					}
					
	
				}
				count = 0;
			}
		}
		
		if (n==1 && m == 1 && k == 1){
			res += 1;
		}
		
		if (n > 1 && m > 1 && k ==1){
			res = res/2;
		}
		cout << res << endl;
		

	
	}
    return 0;
}





