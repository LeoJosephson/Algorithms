#include <iostream> 
#include <cmath>
#include <set>
using namespace std;
#define sizec (int) ceil(sqrt(pow(2, 31) - 1))

int tab_c[sizec+1];
int primes[sizec];
int fats [sizec];




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

void fatora(int n, int p[], int np, int f[], int &nf){
	f[0] = -1;
	nf = 0;
	for (int i=1; i <= np; i++){
		while (n % p[i] == 0){
			nf++;
			f[nf] = p[i];
			n = n/p[i];			
		}
		if (n==1 || p[i] >= ceil(sqrt(n))){
			break;
		}
	}
	if (n != 1){
		nf++;
		f[nf] = n;
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

int main(){
	
	int np;
	crivo(sizec, tab_c);
	
	generate_primes(sizec, tab_c, primes, np);
	long long int num;
	
	while(cin >> num){


		int nf;
		fatora(num, primes, np, fats, nf);

		long long int k =1;
		int t = 0;
		int nfd = 0;

		for (int i=1; i<=nf; i++){ 
			if (fats[i] != t){
				if (t != 0){
					k = k * (pow(t, nfd) - pow(t, nfd-1));
					nfd = 0;	
				}
				t = fats[i];
				nfd ++;
			} else{
				nfd += 1;
			}
		}
		
		if (nfd > 0){
			k = k * (pow(t, nfd) - pow(t, nfd-1));	
		}
		
	

		cout << k/2 << endl;
	}
	return 0;
}
