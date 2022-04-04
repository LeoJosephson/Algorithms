#include <iostream> 
#include <cmath>
using namespace std;
#include <algorithm>
#define sizec (int) (pow(10,6))

int tab_c[sizec+1];
int fats[sizec];
long long int divs[sizec];


int mdc(int a, int b){	
	int r;
	while (b!=0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;

}

int mmc(long long int a, long int b){
	long long int d = mdc(a, b);
	unsigned long long int p = a * b;
	return p/d;
}


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

void fatora(int n, int c[], int f[], int &nf){
	nf = 0;
	while (n!= 1){
		nf += 1;
		f[nf] = c[n];
		n = n/c[n];
	}
}

void divisores(int n, int f[], int nf, long long int d[], int &nd){
	f[0] = 1;
	nd = 1;
	d[1] = 1;
	int nda = 1;
	int k = 1;
	for(int i=1; i<=nf; i++){
		if (f[i] == f[i-1]){
			k = k*f[i];
		} else{
			k = f[i];
			nda = nd;
			}
		for (int j=1; j<=nda; j++){
			nd ++;	
			d[nd] = k*d[j];
		}
		
	}
}



int main() {

	
	
	crivo(sizec, tab_c);
	while (true){
		int T, a, b, nf, nd;
		cin >> T >> a >> b;
		if (T == 0 && a==0 && b==0)break;
		
		int mab = mmc(a, b);

		fatora(T, tab_c, fats, nf);
		divisores(T, fats, nf, divs, nd);
		

		sort(divs, divs + nd);
		int c = 0;

		
		for(int i=0; i<=nd; i++){
			if (mmc(mab, divs[i]) == T){
				if (c != 0){
					cout << ' '<< divs[i];
				} else cout << divs[i];
				c++;
			}
					
		}
		cout << endl;
	
	}
	return 0;
}
