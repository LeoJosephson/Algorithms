#include <iostream>
#include <math.h>
using namespace std;

int MDC(int a, int b){
	int r;
	while (b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

unsigned long long int mmc(unsigned long long int a,  unsigned long long int b){
	unsigned long long int d = MDC(a, b);
	unsigned long long int p = a * b;
	return p/d;
}

int main(){	
	int N, A, B, res;
	cin >> N >> A >> B;
	while (N != 0){
		unsigned long long int d = floor(N/mmc(A, B));
		A = floor(N/A);
		B = floor(N/B);
		res = A + B - d;
		cout << res << endl;
		cin >> N >> A >> B;
	}
	return 0;
}
