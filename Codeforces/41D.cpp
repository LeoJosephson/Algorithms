#include <iostream>
#include <vector>
using namespace std;
int n, m, k, i, j, p;
typedef struct{
	int val = 0;
	vector<short> V = vector<short>(12,-1);
	vector<string> moves = vector<string>(12, "");
} divs;

divs path[102][102];

int main(){
	cin >> n >> m >> k;
	k++;
	string l;
	// input
	for (i=0; i<n; i++){
		cin >> l;
		for (j=0; j<m; j++){
			path[i][j].val = l[j] - '0';
		}
	}
	
	//last line
	for (j=0; j<m; j++){
		path[n-1][j].V[path[n-1][j].val % k] = path[n-1][j].val;
	}
	
	for (i=n-2; i>=0; i--){
		for (j=0; j<m; j++){
			
			if (j>0 && j<m-1){
				vector<string> submoves(12,"");
				for(p=0; p<=k; p++){
					if (path[i+1][j-1].V[p] != -1){
						int pos = (path[i][j].val + path[i+1][j-1].V[p]) % k;
						path[i][j].V[pos] = path[i][j].val + path[i+1][j-1].V[p];
						submoves[pos] = path[i+1][j-1].moves[p] + "R";
					}
				}
				for(p=0; p<=k; p++){
					if (path[i+1][j+1].V[p] != -1){
						int pos = (path[i][j].val + path[i+1][j+1].V[p]) % k;
						int tmp = path[i+1][j+1].V[p] + path[i][j].val;
						if (tmp > path[i][j].V[pos]){
							path[i][j].V[pos] = tmp;
							submoves[pos] = path[i+1][j+1].moves[p] + "L";
						}			
					}
				}
				for (int cc=0; cc<=k; cc++){
					
					path[i][j].moves[cc] = submoves[cc] + path[i][j].moves[cc];
				}
			}else{
				divs V1;
				string s = "L";
				if (j==0) V1 = path[i+1][j+1];
				else if(j==m-1){
					V1 = path[i+1][j-1]; 
					s = "R";
				}
				for(int p=0; p<=k; p++){
					if (V1.V[p] != -1){
						int pos = (path[i][j].val + V1.V[p]) % k;
						path[i][j].V[pos] = path[i][j].val + V1.V[p];
						path[i][j].moves[pos] = V1.moves[p] + s;
					}
				}
			}		
		}
	}
	int mx = -1;
	int jmx = 0;
	string pat = "";
	for(j=0; j<m; j++){
		if (path[0][j].V[0] > mx){
			mx = path[0][j].V[0];
			jmx = j+1;
			pat = path[0][j].moves[0];
		}
	}
	if (mx == -1){
		cout << -1 << endl;
	} else{
		cout << mx << endl;
		for (i=0; i<pat.length(); i++){
			if (pat[i] == 'R') jmx -=1;
			else jmx +=1;
		}
		cout << jmx << endl;
		cout << pat << endl;
	}
	return 0;
}
