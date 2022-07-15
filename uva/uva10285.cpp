#include <iostream>
using namespace std;
int grid[102][102], mem[102][102];

int solve(int row, int col){
	if (mem[row][col] != -1) return mem[row][col];	
	int sol = 0;
	// doing a clockwise search for best values starting on top
	if (grid[row][col] > grid[row-1][col]) sol = max(sol, solve(row-1, col) + 1); // +1 so that its a new possible path
	if (grid[row][col] > grid[row][col+1]) sol = max(sol, solve(row, col+1) + 1);
	if (grid[row][col] > grid[row+1][col]) sol = max(sol, solve(row+1, col) + 1);
	if (grid[row][col] > grid[row][col-1]) sol = max(sol, solve(row, col-1) + 1);

	return mem[row][col] = sol;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	short t, row, col, i, j;
	string tn;
	cin >> t;
	while (t--){
		int sol = 0;
		cin >> tn >> row >> col;
		for(i=0; i<102; i++) for(j=0; j<102; j++) grid[i][j] = 101, mem[i][j] = -1; // max value of grid[i][j] = 100 -> so 101 is kind of a barrier in the grid
		for(i=1; i<=row; i++) for(j=1; j<=col; j++) cin >> grid[i][j];
		for(i=1; i<=row; i++) 
		
		for(i=1; i<=row; i++){
			for(j=1; j<=col; j++){
				sol = max(sol, solve(i, j) + 1);
			}
		}
		cout << tn << ": " << sol << endl;
	}
	
	return 0;
}
