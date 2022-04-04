#include <iostream>
using namespace std;
#define size 5 * 100000

int S[size+1];
int O[size+1];
int T[size+1];
int k;

int bSearch(int i, int f, int x){
	if (i > f)  return i;
	else{
		int m = (i+f)/2;
		if (T[m] < x) return bSearch(m+1, f, x);
		else return bSearch(i, m-1, x);
	}
}

void SCM(int n){
	k = 1; T[1] = S[1]; O[1] = 1;
	int j;
	for (int i=2; i <= n; i++){
		if (S[i] > T[k]){

			k ++;
			T[k] = S[i];
			O[i] = k;
		} else{
			j = bSearch(1, k, S[i]);
			T[j] = S[i];
			O[i] = j;
		}
	}
}

int main(){

	int n;
	while (cin >> n){
		
		for (int i=1; i<=n; i++){
			cin >> S[i];
		}
		
		SCM(n);
		
		cout << k << endl;
	}
}
