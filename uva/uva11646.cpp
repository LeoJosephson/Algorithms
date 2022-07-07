#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double solve(double a, double b){
	double l1, l2, lm, w;
	l1 = 0; 
	l2 = (400*a)/ (2*(b+a));
	while (true){
		lm = (l1+l2)/2.0;
		
		w = (lm*b)/a;
		double r = sqrt(0.5*lm*0.5*lm + 0.5*w*0.5*w);
    	double angle = 2.0 * atan(0.5*w/0.5/lm)*180/M_PI;
        double arc = angle / 360 * M_PI * (2.0*r);
        
		double p = 2*lm + arc*2;
		
		if (abs(p - 400) < 0.00000001) return lm;
		else if (p > 400) l2 = lm;
		else l1 = lm;
	}
	
	
}


int main(){
	int a, b;
	int t = 1;
	char tmp;
	while(cin >> a >> tmp >> b){				
		cout << fixed << setprecision(10);
		double sol = solve(a, b);
		cout << "Case" << t << ": " << sol << " "<< sol*b/a << endl;
		t ++;
	}
	return 0;
}
