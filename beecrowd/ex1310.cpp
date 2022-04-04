#include <iostream>
using namespace std;

int arr[100];

int sm;
void scsm(int n){
	int im=0, fm = 0, ss=0, is=0, fs=0;
	for (int i=0; i<n; i++){
		if ( (ss + arr[i]) >= 0){
			ss = ss + arr[i];
			fs = i;
			
			if (is == 0) is = i;
			if (ss > sm){
				sm = ss;
				im = is;
				fm = fs;
			}
		} else{
			ss = is = fs = 0;
		}
	}
}

int main(){
	int n, k;
	while(cin >> n){
		sm = 0;
		cin >> k;
		for (int i=0; i<n; i++){
			cin >> arr[i];
			arr[i] -= k;
		}
		scsm(n);
		cout << sm << endl;
	}
	
	return 0;
}
