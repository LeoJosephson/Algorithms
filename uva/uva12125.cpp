#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int PI, CC[205][205], F[205][205], n, C[205][205];
bool V[205];
double D;

typedef struct{
	int x;
	int y;
	int n;
	int m;	
}ip;

ip A[101];

void CriaRede(){
    int i, j; 
    n = 1+PI+PI;
	for(i=1; i<=n; i++) for (j=1; j<=n; j++){ CC[i][j]=0;  F[i][j]=0; }
	
	for(i=2; i<=PI+1; i++){
		CC[i][i+PI] = A[i-1].m; // vértice com peso
		CC[1][i] = A[i-1].n;
	}
	for(i=2; i<=PI+1; i++){
		for(j=2; j<=PI+1; j++){
			if (i > j){
				double dist = sqrt(pow(A[i-1].x-A[j-1].x,2) + pow(A[i-1].y - A[j-1].y, 2));
				if (dist <= D){
					CC[i+PI][j] = A[i-1].m;
					CC[j+PI][i] = A[j-1].m;
				}
			}
		}
	}
}


int MFDFS(int s, int t, int minn) {
    V[s] = true; 
    if (s==t) return minn;
    for(int i=1; i<=n; i++) {
        if (!V[i] && C[s][i] > 0) {
            if (int fm = MFDFS(i, t, min(minn, C[s][i]))) {
                C[s][i] -= fm;  C[i][s] += fm;
                F[s][i] += fm;  F[i][s] -= fm;                
                return fm;
            }
        }
    }
    return 0;
}

int main(){
	int t, i, j, k;
	cin >> t;
	while (t--){
		cin >> PI >> D;
		int sum_p = 0;
		for(i=1; i<=PI; i++){
			cin >> A[i].x >> A[i].y >> A[i].n >> A[i].m;
			sum_p += A[i].n;
		}
		
		CriaRede();

		bool tem_sol = false;
		for(i=2; i<=PI+1; i++){
			int fmax = 0;
			memset(V, 0, sizeof(V));
			for(k=1; k<=n; k++){
				for(j=1; j<=n; j++){
					C[k][j] = CC[k][j];
					F[k][j] = 0;
				}
			}
			C[i][i+PI] = 0;
			while (int fm= MFDFS(1, i, 1000000)){
				fmax += fm;
				memset(V, 0, sizeof(V));
			}
			if (fmax == sum_p){
				if (tem_sol) cout << ' ' << i-2;
				else cout << i-2;
				tem_sol = true;
			}
		}
		if (!tem_sol) cout << -1 << endl;
		else cout << endl;
	}
	return 0;
}
