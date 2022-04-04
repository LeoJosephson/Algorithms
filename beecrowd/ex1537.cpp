#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100001
#define REST 1000000009

int fatmod[MAX];

int MDCE(int a, int b, int &x, int &y){
	int d;
	if(b == 0){
		x =1;
		y = 0;
		return a;
	} else{
		int e, f;
		d = MDCE(b, a%b, e, f);
		x = f;
		y = e - f * (floor(a/b));
	}
	return d;
	
}

int invMod(int b){
	int x, y;
	int d = MDCE(b, REST, x, y);
	return (x+REST) % REST;
}	

void modFact(int n){
	fatmod[0] = 1;
	
	for (int i=1; i<=n; i++){
		int a = i % REST;
		long long int b = fatmod[i-1] % REST;
		fatmod[i] = (a * b)% REST;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	modFact(MAX);
	int n;
	long long int res;

	cin >> n;
	
	int inv6b = invMod(6) % REST;
	while (n != 0){
		long long int a = fatmod[n] % REST;
		res = (a*inv6b) % REST;
		cout << res << endl;
		cin >> n;
	}
	
	return 0;
}
