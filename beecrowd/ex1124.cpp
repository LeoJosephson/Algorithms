#include <iostream>
#include <math.h>
using namespace std;


int main(){
	short l, c, r1, r2;
	bool res;
	
	cin>> l >> c >> r1 >> r2;
	while(l !=0 ){
		res = true;
		if (r1 < r2){
			short tmp = r1;
			r1 = r2;
			r2 = tmp;
		} // 7 8 3 2
		res = (r1*2) <= c && r1*2 <=l;
		
		if (res){
			res = r1+r2 <= sqrt(pow((l-(r1+r2)),2) + pow((c-(r1+r2)),2));		
		}
		if (res == true) cout << 'S';
		else cout << 'N';
		cout << endl;
		cin>> l >> c >> r1 >> r2;
	}
}
