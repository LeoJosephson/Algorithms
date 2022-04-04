#include <iostream>
#include <math.h> 
using namespace std;

int V[100000];


int MDCE(int a, int b, long long int &x, long long int &y){
	int d;
	if(b == 0){
		x =1;
		y = 0;
		return a;
	} else{
		long long int e, f;
		d = MDCE(b, a%b, e, f);
		x = f;
		y = e - f * (floor(a/b));
	}
	return d;
	
}

int MDC(int a, int b){
	int r;
	while (b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, T, A, B;
	cin >> N;
	
	
	for (int i=0; i<N; i++){
		cin >> V[i];
	}
	
	cin >> T >> A >> B;
	
	if (MDC(A, T) != 1){
		cout << "DECIFRAGEM AMBIGUA";
	} else{
		long long int x, y;
		MDCE(A, T, x, y);

		for (int i=0; i<N; i++){
			long long int res = ((V[i] - B) * x ) % T;
			if (i != 0){
				cout << ' ';
			}
			if (res < 0){
				
				cout << (res + T ) % T;
			} else{
				cout << res;
			}

		}
	}
	
	return 0;
}
