#include <iostream>
using namespace std;


typedef struct {
    int val;
    int calls = 0;
} fibTuple;

fibTuple f[40];

void fib(int n){
	f[0].val = 0;
	f[1].val = 1;
	for(int i=2; i<=n; i++){
		f[i].val = f[i-1].val + f[i-2].val;
		f[i].calls = f[i-1].calls + f[i-2].calls + 2;
	}

}
int main(){	
	int n, x;
	cin >> n;
	fib(39);
	for(int i=0; i<n; i++){ 
		cin >> x;
		cout << "fib(" << x << ") = " << f[x].calls << " calls = " << f[x].val << endl;
	}
	
	
	return 0;
}
