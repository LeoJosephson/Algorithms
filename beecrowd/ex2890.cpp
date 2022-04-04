#include <iostream>
#include <math.h>
#define REST 1000007
using namespace std;

int multMod(int a, int b){
	long long int la, lb;
	la = a; 
	lb = b;
	return (la*lb)%REST;
}

int exp(int a, int b){
	if (b==0) return 1;
	else if (b % 2 != 0) return multMod(exp(a, b-1), a);
	else{
		int x = exp(a, floor(b/2));
		return multMod(x, x);
	}
}

int main(){
	
	
	int n;	

	cin >> n;
	
	while(n != 0){
		unsigned long long int a = exp(n, 4);
		unsigned long long int b = 11* exp(n, 2);
		unsigned long long int res = ((a+b) * 83334 ) % REST;	
		cout << res << endl;
		cin >> n;
		
	}
	
	return 0;
}
