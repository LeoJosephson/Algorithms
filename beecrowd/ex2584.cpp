#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
	int t;
	double n;
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> n;
		cout << fixed << setprecision(3) << 5*((n * (n/2) * tan(54*M_PI/180.0))/2) << endl;
	}
}
