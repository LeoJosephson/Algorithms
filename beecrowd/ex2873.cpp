#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	while(a != 0){
		cout << fixed << setprecision(5) << c * ((b + a/2)/d) << endl;
		cin >> a >> b >> c >> d;
	}
}
