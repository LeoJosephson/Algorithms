#include <iostream>
#include <string.h>
using namespace std;
int NR, NM, n, R[102];
int CC[205][205], F[205][205];
bool V[205];


void CriaRede(){
    int i, j; 
    n = 2+NR+NR;
	for(i=1; i<=n; i++) for (j=1; j<=n; j++){ CC[i][j]=0;  F[i][j]=0; }
	
	for(i=1; i<=NM; i++){
		int x, y, z;
		cin >> x >> y >> z;
		CC[x+NR+1][y+1] = z;
	}
	int B, D, k;
	cin >> B >> D;
	for(i=1; i<=B; i++){
		cin >> k;
		CC[1][k+1] = R[k];
	}
	
	for(i=B+1; i<=B+D; i++){
		cin >> k;
		CC[k+1][n] = R[k];
	}
	
	for(i=2; i<=NR+1; i++) CC[i][i+NR] = R[i-1];
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

int main(){
	int i, j;
	while(cin >> NR){
		for(i=1; i<=NR; i++) cin >> R[i];
		cin >> NM;
		CriaRede();
		int fmax = 0;
		memset(V, 0, sizeof(V));
		while (int fm= MFDFS(1, n, 1000000)){
			fmax += fm;
			memset(V, 0, sizeof(V));
		}
		cout << fmax << endl;
	}
	
	return 0;
}
