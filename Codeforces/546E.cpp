#include <iostream>
#include <string.h>
using namespace std;
int n, m, i, tot = 0, tot2=0;
int A[101], B[101], CC[205][205], F[205][205];
bool V[205];

int INF = 10000000;

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
    int i, j;
    int nm = n;
    n = 2*n+2;
	for(i=1; i<=n; i++) for (j=1; j<=n; j++){ CC[i][j]=0;  F[i][j]=0; }
	
    for(i=2; i<=nm+1; i++) CC[1][i]= A[i-1];
    for(i=nm+2; i<=nm+nm+1; i++) CC[i][n]=B[i-nm-1];
    for(i=0; i<m; i++){ 
		int a, b;
		cin >> a >> b; // estrada entre cidade a e b
		CC[a+1][nm+1+b] = INF;
		CC[b+1][nm+1+a] = INF;
	}
	for(i=2; i<=nm+1; i++) CC[i][nm+i] = INF; // estrada entre mesmas cidades
       
}


int main(){
	cin >> n >> m;
	for (i=1; i<=n; i++){
		cin >> A[i];
		tot += A[i];
	} 
	for (i=1; i<=n; i++){
		cin >> B[i];
		tot2 += B[i];	
	}
	
	CriaRede();
	int fmax = 0;
	memset(V, 0, sizeof(V));
	while (int fm= MFDFS(1, n, INF)){
		fmax += fm;
		memset(V, 0, sizeof(V));
	}
	
	// print solution
	if (fmax == tot && tot == tot2){
		cout << "YES" << endl;
		for(int i=2; i<=(n-2)/2 + 1; i++){
			for(int j=n/2+1; j<=n-1; j++){
				cout << F[i][j];
				if (j <= n) cout << ' ';
			}cout << endl;
		}
	} 
	else cout << "NO" << endl;
	return 0;
}
