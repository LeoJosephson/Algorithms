#include <iostream>
#include <vector>
using namespace std;

int cx, cy, n;

vector<vector<int>> M;
vector<vector<bool>> pre;

void BP(int x,int y){
    int i, j;
	pre[y][x] = true;
	for(i=y-1; i<=y+1; i++){
		for(j=x-1; j<=x+1; j++){
			if (M[i][j] == 1 && pre[i][j] == false){
				BP(j, i);				
			}
		}
	}
} 

int main(){
	int i, j;
	int ax, ay, bx, by;
	
	cin >> n;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	M.resize(n+2, vector<int>(n+2,1));
	pre.resize(n+2, vector<bool>(n+2,false));

	ay = n - ay + 1;
	by = n - by + 1;
	cy = n - cy + 1;
	
	for(j=1; j<=n; j++) M[ay][j] = -1;
	for(i=1; i<=n; i++) M[i][ax] = -1;
	
	i = ay;
	j = ax;
	while (i > 1 && j > 1){
		M[i-1][j-1] = -1;
		i--; j--;
	}
	
	i = ay;
	j = ax;
	while (i <n && j<n){
		M[i+1][j+1] = -1;
		i++; j++;
	}
	
	i = ay;
	j = ax;
	while (i < n && j > 1){
		M[i+1][j-1] = -1;
		i++; j--;
	}
	
	i = ay;
	j = ax;
	while (i > 1 && j < n){
		M[i-1][j+1] = -1;
		i--; j++;
	}
	
	M[ay][ax] = -1;
	M[by][bx] = 1;
	M[cy][cx] = 1;

	for(i=0; i<=n+1; i++){
		M[i][0] = -1; 
		M[i][n+1] = -1;	
	} 
	for(j=0; j<=n+1; j++){
		M[0][j] = -1; 
		M[n+1][j] = -1;
	} 

	BP(bx, by);	
	if (pre[cy][cx] == true) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
