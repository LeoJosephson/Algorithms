#include <iostream>
#include <vector>
#include <string.h>
#include <set>
using namespace std;
const int NVM=2015;

vector<int> G[NVM];
int n, expt[NVM], pre[NVM]; 
int nempmax, nempmaxa, nemp;
int R, C, NE;

void Inicializa(int n){
    int i, j;
	for (int i=0; i<=n; i++) {
	    expt[i]=1;  G[i].clear();
	}
	for (i=1; i<=R; i++){
		G[0].push_back(i);
	}
	for (j=1; j<=NE; j++){
		int c, r;
		cin >> r >> c;
		G[r].push_back(c+R);
				
	}
}

int CamAument(int v){
    if (v > R && expt[v]) return 1;
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

void BP(int v){
    pre[v] = true;
	for(int k : G[v]){ 
	    if(pre[k] == false){
	    	BP(k);
		}	
	}
}

int main(){
	int i, j;
	cin >> R >> C >> NE;
	while(R != 0){
		n = R + C;
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
		memset(pre, 0, sizeof(int)); // 
		vector<int> no_emp, T;
		for (int j : G[0]) no_emp.push_back(j); // Vértices não emparelhados
		for(int j : no_emp){
			if (pre[j] == false){
				BP(j);
			}
		}

		/* Min cover = C = {L\T}  U (S n T}
		L = rows     LTST   LT         ST
		S = columns
		T = alt path
		*/
		set <int>LTST;
		vector<int> LT, ST;
		for(i=1; i<=n; i++){
			if (pre[i] == true){
				T.push_back(i);	
				//cout << i << ' ';
			}
		}
		//cout << endl;
		bool found;
		for(i=1; i<=R; i++){
			found = false;
			for(int j : T){
				if (i == j) {
					found = true;
					break;
				}
			}
			if (!found) LTST.insert(i);
		}
		for(i=R+1; i<=R+C; i++){
			found = false;
			for(int j : T){
				if (i == j){
					found = true;
					break;
				}
			}
			if (found) LTST.insert(i);
		}		
		cout << nempmax;
		for(int j : LTST){
			if (j <= R) cout << " r" << j;
			else cout << " c" << j-R;
		}
		
		cout << endl;	
		cin >> R >> C >> NE;		
	}	
	return 0;
}
