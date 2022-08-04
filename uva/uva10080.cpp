#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int GN, GM, n;
double v, S;

int CC[205][205], F[205][205];
double cx[101], cy[101];
bool V[205];

void CriaRede(){
    int i, j, ns; 
    n = 2+GN+GM;
	for(i=1; i<=n; i++) for (j=1; j<=n; j++){ CC[i][j]=0;  F[i][j]=0; }
	
    for(i=2; i<=GN+1; i++) CC[1][i]= 1;
    for(i=GN+2; i<=GN+GM+1; i++) CC[i][n]= 1;
    
	for(int i=1; i<=GM; i++){
		double x, y;
		cin >> x >> y;
		double distance;
		for (int j=1; j<=GN; j++){
			distance = sqrt(pow(x-cx[j], 2) + pow(y-cy[j], 2));
			if ((distance/v) < S) CC[j+1][i+1+GN] = 1;
			
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
	while(cin >> GN >> GM >> S >> v){
		for (int i=1; i<=GN; i++){
			cin >> cx[i] >> cy[i];
		}	
		CriaRede();	
		int fmax = 0;
		memset(V, 0, sizeof(V));
		while (int fm= MFDFS(1, n, 1000000)){
			fmax += fm;
			memset(V, 0, sizeof(V));
		}
		cout << GN - fmax << endl;
	}
	return 0;
}
