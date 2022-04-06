#include <iostream>  
#include <map>
#include <algorithm>

using namespace std; 
map<string, int> colors;
string line1, line2;
double R;
char M[100], N[100];
double D[101][101];

void split(string str, char M[100]){
	string word = "";
	short ind = 0;
	for (int i=0; i<=str.length(); i++){
		if (str[i] == ' ' || i == str.length()){
			auto x = colors.find(word);
			if (x == colors.end()){
				M[ind] = (char)colors.size() +97;
				colors.insert(make_pair(word, colors.size()));	
			} else{
				M[ind] = (char)x ->second + 97;
			} 
			ind ++;
			word="";
		} else{
			word += str[i];
		}
	}
}

double dist(short n, short m){
	int i, j;
	for (i=0; i<=n; i++){
		D[i][0] = i*0.5;
	}
	for (j = 0; j <= m; j++){
		D[0][j] = j*2.5;
	}
	for (i=1; i<=n; i++){
		for (j=1; j<=m; j++){
			if (M[i-1] == N[j-1]) D[i][j] = D[i-1][j-1];
			else{
				D[i][j] = min(min(0.5 + D[i-1][j], 1.0 + D[i-1][j-1]), 2.5 + D[i][j-1]);
			}
		}
	}
	return D[n][m];
}

int main()  
{  
	short t, i, r, m, n;
	cin >> t;
	
	for (i=0; i<t; i++){
		colors.clear();
		cin >> r;
		cin >> m;
		cin.ignore();
		if (m != 0) getline(cin ,line1);
		cin >> n;
		cin.ignore();
		if (n !=0) getline(cin, line2);
		
		
		
		if (m == 0){
			R = 2.5 * n;
		} if (n == 0){
			R = 0.5 * m;
		}
		 else if (line1 == line2) R = 0;
		else
		{
			split(line1, M);
			split(line2, N);
			R = dist(m, n);
		}
		R *= r;
		string s = to_string(R);
		short pos = s.find('.');
		cout << "Caso #"<< i+1 << ": R$ ";
		cout << s.substr(0, pos) << ',' << s.substr(pos+1, 2) << endl;	
	}  
}  
