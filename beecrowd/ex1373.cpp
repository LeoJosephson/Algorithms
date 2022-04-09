#include <iostream>
using namespace std;

string line1;
string line2;
int T[1001][1001] = {0};
int subs;

int SCM(int n, int m){
	int i, j;

	for (i=0; i<=n; i++) T[i][0] = 0;
	for (j=0; j<=m; j++) T[0][j] = 0;
	for (i=1; i<=n; i++){
		for (j=1; j<=m; j++){	
			int k = 0;		
			int mx = 0;
			while(i-k>0 && j-k >0 && line1[i-1-k] == line2[j-1-k]){
				k++;
				if (k >= subs){
					mx = max(mx, T[i-k][j-k]+k);
					T[i][j] = mx;
				}
			}
			if (k >= subs) T[i][j] = max(max(T[i-1][j], T[i][j-1]), mx);
			else T[i][j] = max(T[i-1][j], T[i][j-1]);

			}
	}
	return T[n][m];
}


int main(){

	cin >> subs;
	while(subs != 0){
		cin.ignore();
		getline(cin, line1);
		getline(cin, line2);
		int k = SCM(line1.length(), line2.length());
		cout << k << endl;
		cin >> subs;
	}
}
