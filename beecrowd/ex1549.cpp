#include <iostream>
#include <iomanip> 
#include <math.h>


using namespace std;

#define dif 0.00001

double solve(double N, double L, double b, double B, double H){
	double h1, h2, hm, B1, l1;
	h1 = 0; h2 = H;
	while (true){
		hm = (h1+h2)/2.0;
		B1 = b+hm*(B-b)/H;
		l1 =  N*M_PI*hm*(b*b + b*B1+B1*B1)/3.0;
		
		if (abs(l1-L) < dif) return hm;
		else if (L < l1) h2 = hm;
		else h1 = hm;
	}
}

int main(){
	int c;
	double N, L, b, B, H, sol;
	cin >> c;
	while (c--){
		cin >> N >> L;
		cin >> b >> B >> H;		
		cout << fixed << setprecision(2) << solve(N, L, b, B, H) << endl;
	}
	
	
	return 0;
}

