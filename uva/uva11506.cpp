#include <iostream>
#include <string.h>
using namespace std;
int n, M, W, CC[105][105], F[105][105];
bool V[105];
int A[50];

void CriaRede(){
    int i, j; 
    int NM = M-2;
    n = M + NM;
	for(i=1; i<=n; i++) for (j=1; j<=n; j++){ CC[i][j]=0;  F[i][j]=0; }
	for(i=1; i<=M-2; i++){
		int id, v;
		cin >> id >> v;
		CC[id][id+NM] = v;
	}
	
	for(i=1; i<= W; i++){
		int j, k, d;
		cin >> j >> k >> d; // j < k
		if(j==1 && k == M) CC[j][n] = d;
		else if(j==1){
			CC[j][k] = d;
		} else if(k==M){
			CC[j+NM][n] = d;		
		}else{
			CC[j+NM][k] = d;
			CC[k+NM][j] = d;
		}
	}
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
	cin >> M >> W;
	while(M != 0){
		CriaRede();
		int fmax = 0;
		memset(V, 0, sizeof(V));
		while (int fm= MFDFS(1, n, 1000000)){
			fmax += fm;
			memset(V, 0, sizeof(V));
		}
		cout << fmax << endl;
		cin >> M >> W;
	}
	return 0;
}
