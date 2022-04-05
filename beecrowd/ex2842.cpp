#include <iostream>
using namespace std;

string line1;
string line2;
short T[1001][1001];

short SCM(int n, int m){
	int i, j;
	for (i=0; i<=n; i++) T[i][0] = 0;
	for (j=0; j<=m; j++) T[0][j] = 0;
	for (i=1; i<=n; i++){
		for (j=1; j<=m; j++){
			if (line1[i-1] == line2[j-1]) T[i][j] = T[i-1][j-1]+1;
			else T[i][j] = max(T[i-1][j], T[i][j-1]);
			
		}
	}
	return T[n][m];
}
	

int main(){
	getline(cin, line1);
	getline(cin, line2);
	short k = SCM(line1.length(), line2.length());
	cout << k + (line1.length() - k) + (line2.length() - k) << endl;
}
