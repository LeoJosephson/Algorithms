#include <iostream>
using namespace std;

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
