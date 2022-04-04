#include <iostream>
#include <iomanip>
using namespace std;
#define max ((4999+1)*4999)/2
double arr[max] = {0.0};
int main(){
	int s, i, c = 1, k=1;	
	cin >> s;
	arr[0] = 100.0;
	for (i=0; i<((s+1)*s)/2 - s; i++){
		arr[i+k] += arr[i] * 0.5;
		arr[i+k+1] += arr[i] * 0.5;
		c--;
		if (c == 0){
			k+= 1;
			c +=k;
		}
	}
	cout << fixed << setprecision(2) << arr[(s * (s-1))/2 + s/2] << endl;
}
