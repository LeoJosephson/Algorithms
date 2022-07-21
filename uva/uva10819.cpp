// I got the idea of this algorithm by looking at the solution at the link below
// https://github.com/ajahuang/UVa/blob/master/UVa%2010819%20-%20Trouble%20of%2013-Dots.cpp

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int m, n, i, j;
	
	while (cin >> m >> n){
		vector<int> KP(n), KF(n);
		int M = m;
		if (m >= 1801) M+= 200;
		for(i=0; i<n; i++)
		cin >> KP[i] >> KF[i];
		vector<int> K(M+1, 0);
		
		for (i=0; i<n; i++){
			for(j=M; j>=KP[i]; j--){
				if (K[j-KP[i]] != 0 || j == KP[i]){
					K[j] = max(K[j], K[j-KP[i]] + KF[i]);
				}
			}
		}
		
		int MAX = 0;
		
		if (m >= 1801 && m <= 2000)
        {
            MAX = *max_element(K.begin(), K.begin() + m); // find the max without using the 200dolars bonus
            for (j = 2001; j <= M; ++j) // uses the 200 dolar
                MAX = max(MAX, K[j]);
        }
        else
            MAX = *max_element(K.begin(), K.end());
		cout << MAX << endl;
		
		
	}
	return 0;
}
