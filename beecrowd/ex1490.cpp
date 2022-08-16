#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

typedef struct{
	int h; // h colum or h row
	int start;
	int end;
} l;

const int NVM = 10000;
vector<string> L;
vector<l> LR;
vector<l> LC;
int ROWS = 0;
int COLS = 0;
vector<int> G[NVM];
int n, expt[NVM], pre[NVM]; 
int nempmax, nempmaxa, nemp;


bool Intersect(l row, l column){
	if (row.start > column.h) return false;
	if (row.end < column.h) return false;
	if (row.h < column.start) return false;
	if (row.h > column.end) return false;
	return true;
	
}

void Inicializa(int n){
    int i, j;
	for (int i=0; i<=n; i++) {
	    expt[i]=1;  G[i].clear();
	}
	for (i=1; i<=ROWS; i++){
		G[0].push_back(i);
		for (j=ROWS+1; j<=n; j++){ 
			if (Intersect(LR[i-1], LC[j-ROWS-1]))G[i].push_back(j);
		}
	}
}

int CamAument(int v){
    if (v > ROWS && expt[v]) return 1;
    pre[v]=1;
	for (int j = 0; j < G[v].size(); j++) {
        int w = G[v][j];
        if (!pre[w]){
			if ( CamAument(w) )  {
			    expt[w]=0;
				G[v].erase(G[v].begin()+j);
				G[w].push_back(v);
			    return 1;	 				
			}
		}
    }
    return 0;
}

int totl(int N){
	int h = 0;
	for (int j=0; j<N; j++){
		string str = L[j];
		bool sameR = false;
		bool sameC = false;
		int st=0, stC=0;
		for(int i=0; i<N; i++){
		
			if(str[i] == '.' && sameR==false){
				st = i;
				sameR=true;
			}
			if ( (str[i]=='X' && sameR == true) | i == N-1 && sameR == true){
				sameR = false;
				l line;
				line.start = st;
				if (str[i] == 'X') line.end = i-1;
				else line.end = i;
				line.h = h;
				LR.push_back(line);
				ROWS += 1;
				st = i+1;
			}
			
			if(L[i][j] == '.' && sameC==false){
				stC = i;
				sameC=true;
			}
			if ( (L[i][j]=='X' && sameC == true) | i == N-1){ // COLUMNS
				sameC = false;
				l line;
				line.start = stC;
				if (L[i][j] == 'X') line.end = i-1;
				else line.end = i;
				line.h = h;
				LC.push_back(line);
				COLS++;
				stC=i+1;
			}	
		}
	
		h++;
	}	
	return 1;
}

int main(){

	int N, i, j;
	string line;

	while(cin >> N){

		LR.clear();
		LC.clear();
		L.clear();
		ROWS = 0; COLS = 0;
		getline(cin, line);
		for(i=0; i<N; i++){
			getline(cin, line);
			L.push_back(line);
		}
		totl(N);
		n = ROWS + COLS;
		
		Inicializa(n);
		
		nempmax = 0; nempmaxa = 0;
        memset(pre, 0, sizeof(pre));  
		while(true){                  
			while (nemp = CamAument(0))
		    	nempmax +=nemp;
			if (nempmaxa == nempmax)
				break;
			nempmaxa = nempmax;
			memset(pre, 0, sizeof(pre)); 
			
		}
		cout << nempmax << endl;
	}
	return 0;
}
