#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
int NP, n, m, i;
int CC[50][50], F[50][50];
bool V[50];

int INF = 10000000;
int pos(string a){
	if (a == "S") return 1;
	if (a == "M") return 2;
	if (a == "L") return 3;
	if (a == "XL") return 4;
	if (a == "XXL") return 5;
	if (a == "XS") return 6;	
	return -1;
}

int MFDFS(int s, int t, int minn) {
    V[s] = true; 
    if (s==t) return minn;
    for(int i=1; i<=n; i++) {
        if (!V[i] && CC[s][i] > 0) {	
            if (int fm = MFDFS(i, t, min(minn, CC[s][i]))) {
                CC[s][i] -= fm;  CC[i][s] += fm;
                F[s][i] += fm;  F[i][s] -= fm;                
                return fm;
            }
        }
    }
    return 0;
}

void CriaRede(){
    int i, j, ns;
    ns = 6; 
    n = 2+NP+ns;
	for(i=1; i<=n; i++) for (j=1; j<=n; j++){ CC[i][j]=0;  F[i][j]=0; }
	
    for(i=2; i<=ns+1; i++) CC[1][i]= m/6;
    for(i=ns+2; i<=ns+NP+1; i++) CC[i][n]= 1;
    
	string str;
		for (i=1; i<=NP; i++){
			cin >> str;
			CC[pos(str)+1][ns+1+i] = 1;
			cin >> str;
			CC[pos(str)+1][ns+1+i] = 1;

	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--){
		cin >> m >> NP;
		CriaRede();
		int fmax = 0;
		memset(V, 0, sizeof(V));
		while (int fm= MFDFS(1, n, INF)){
			fmax += fm;
			memset(V, 0, sizeof(V));
		}
		if (fmax == NP) cout << "YES";
		else cout << "NO";
		cout << endl;		
	}
	
	
}
