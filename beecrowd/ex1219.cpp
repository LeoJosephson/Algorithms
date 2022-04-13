#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	double a, b, c;
	
	while(cin>> a >> b >> c){
		double s = (a + b + c)/2;
		double at = sqrt(s*(s-a)*(s-b)*(s-c));
		double r1 = at/s;
		double r2 = a*b*c/(4.0*at);
		double ros = M_PI * pow(r1,2);
		double vio = at - ros;
		double sun = (M_PI * pow(r2,2)) - at;
		cout << fixed;
		cout << setprecision(4);
		cout << sun << " " << vio << " " << ros << endl;

	}
}
