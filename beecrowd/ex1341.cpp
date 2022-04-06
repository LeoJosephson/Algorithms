#include <iostream>
using namespace std;

string line1;
string line2;
short T[1001][1001];
char path[20][20];

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

string cpath(int n, int x0, int y0, string s){
	string line = "";
	x0 --;
	y0 --;
	line += path[x0][y0];
	for (int i=0; i<n; i++){
		if (s[i] == 'N') x0 --;
		else if (s[i] == 'S') x0 ++;
		else if (s[i] == 'E') y0 ++;
		else y0 --;
		line += path[x0][y0];
	}
	
	return line;
	
}	

int main(){
	short t, h, w, n, x0, y0, k;
	cin >> t;
	string line;
	for (int i=0; i<t; i++){
		cin >> h >> w;
		cin.ignore();
		for (int j=0; j<h; j++){
			getline(cin, line);
			for (int n=0; n<w; n++){
				path[j][n] = line[n];
			}
		}
		
		cin >> n >> x0 >> y0;
		cin.ignore();
		getline(cin, line);
		line1 = cpath(n, x0, y0, line);
		
		cin >> n >> x0 >> y0;
		cin.ignore();
		getline(cin, line);
		line2 = cpath(n, x0, y0, line);

		k = SCM(line1.length(), line2.length());
		cout << "Case " << i+1 << ": " << line1.length()-k  << ' ' << line2.length()-k << endl; 
	}
}
