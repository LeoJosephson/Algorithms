#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define PI 3.14159265

double T[101];
int O[101];
int k;

typedef struct{
	short x;
	short y;
	double a;
	double b;
} coord;

coord S[101];

int bSearch(int i, int f, double x){
	if (i > f)  return i;
	else{
		int m = (i+f)/2;
		if (T[m] < x) return bSearch(m+1, f, x);
		else return bSearch(i, m-1, x);
	}
}

void SCM(int n){
	k = 1; T[1] = S[1].b; O[1] = 1;
	int j;
	for (int i=2; i <= n; i++){
		if (S[i].b > T[k]){

			k ++;
			T[k] = S[i].b;
			O[i] = k;
		} else{
			j = bSearch(1, k, S[i].b);
			T[j] = S[i].b;
			O[i] = j;
		}
	}
}

bool compare(coord a, coord b){
    return (a.a < b.a);
}

int main(){
	short n;
	int xa, xb, i, adj;
	double hip;
	
	while(cin >> n){
		cin >> xa >> xb;
		for (i=1; i<=n; i++){
			cin >> S[i].x;
			cin >> S[i].y;
			adj = S[i].x - xa; 
			hip = sqrt(pow(adj, 2) + pow(S[i].y, 2)); 
			S[i].a = acos (adj/hip) * 180.0 / PI;
			adj = xb - S[i].x;
			hip = sqrt(pow(adj, 2) + pow(S[i].y, 2)); 
			S[i].b = acos(adj/hip);			
		}
		sort(S+1, S+n+1, compare);		
		SCM(n);
		cout << k << endl;
	}
	return 0;
}
