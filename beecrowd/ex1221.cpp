#include <iostream> 
#include <cmath>
using namespace std;
#define sizec (int) ceil(sqrt(pow(2, 31) - 1))

int tab_c[sizec];
int primes[sizec];

void crivo(int n, int c[]){
	int i, d;
	for (i=1; i<=n; i++){
		c[i] = i;
	}
	int t = 2;
	
	for (i=1; i<=n/2; i++){
		c[t] = 2; t +=2;
	}
	for(i=3; i<=ceil(sqrt(n)); i++){
		if (c[i] == i){
			t = i*i;
			d = i+i;
			while(t <=n){
				if (c[t] == t){
					c[t] = i;
				}
				t += d;
				
			}
		}
	}
}


void generate_primes(int n, int c[], int p[], int &np){
	np = 0;
	for (int i=2; i<=n; i++){
		if (c[i] == i){
			np ++;
			p[np] = i;
		}
	}
}


bool isprime(int n, int p[], int np){
	if (n == 0 || n == 1){
		return false;
	}
	for (int i=1; i <= np; i++){
		if (p[i] > n){
			return true;
		}
		if (n%p[i] == 0){
			if (n != p[i]){
				return false;
			}
			return true;
		} 
	}
	return true;
}

int main() {
	int t;
	
	cin >> t;
	

	crivo(sizec, tab_c);
	int np;
	generate_primes(sizec, tab_c, primes, np);


	
	
	for(int i=0; i<t; i++){
		int number;
		cin >> number;
		if (isprime(number, primes, np)){
			cout << "Prime" << endl;
		} else cout << "Not Prime" << endl;
		
	}

	return 0;
}
