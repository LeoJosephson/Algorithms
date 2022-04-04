#include <iostream>
#include <math.h>
#define REST 100000007
#define MAX 10000
using namespace std;

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
	
	
	string line;
	modFact(MAX);
	int i;
	long long int inv;
	
	while(getline(cin, line) && line[0] != '0'){
		long long int res = fatmod[line.length()];
		int alf[26] = {};
		

		for (i=0; i<line.length(); i++){
			alf[(int)line[i] - 97] += 1;			
		}
		for (i=0; i<26; i++){
			if (alf[i] != 0){
				res *= invMod(fatmod[alf[i]]) % REST;
				res = res % REST;
			}
		}
		
		cout << res << endl;
		
	}
	
	return 0;
}
