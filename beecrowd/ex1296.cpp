#include <iostream>
using namespace std;
#include <math.h>
#include <iomanip> 

int main(){
	double a, b, c;
	double res;
	int i = 0;
	while(cin >> a >> b >> c){
		double s = (a + b+ c)/2;
		if (s-a <=0 || s-b<=0 || s-c <=0) res= -1;
		else{
			res = 4.0/3.0 * sqrt(s*(s-a)*(s-b)*(s-c));
		}
	cout << fixed;
	cout << setprecision(3);
	cout << res << endl;
	}
}
