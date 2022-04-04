#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
	
	int r;
	cin >> r;
		
	while (r != 0){
		
		int arr1[3];
		int arr2[3];
		
		cin >> arr1[0] >> arr1[1] >> arr1[2];
		cin >> arr2[0] >> arr2[1] >> arr2[2];
		

		sort(arr1, arr1+3);
		sort(arr2, arr2+3);

		
		if (arr1[0] < arr2[1] && arr1[1] < arr2[2] && arr2[0] < arr1[1] && arr2[1] < arr1[2]){
			cout << 3;
		} else if (arr1[0] < arr2[1] && arr1[1] < arr2[2]){
			cout << 1;
		} else if (arr2[0] < arr1[1] && arr2[1] < arr1[2]){
			cout << 2;
		} else {
			cout << 0;
		} 
		
		cout << endl;
		
		r--; 
	} 

    return 0;
}
//20 30 10 63 20 11
// 10 20 30 11 20 63
