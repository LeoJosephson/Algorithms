#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G;

void construct(int start, int end){
	int send = end-2;
	for(int i=start; i<send; i+=2){
		G[i][i+1] = 0;
		G[i+1][i] = 0;
	}
	G[send][start] =0;
	G[start][send] =0;
	G[end][end-1] = 0;
	G[end-1][end] = 0; 
}

int main(){
	int k;
	cin >> k;
	if (k%2==0) cout << "NO" << endl;
	else if (k==1){
		cout << "YES" << endl;
		cout << "2 1" << endl;
		cout << "1 2" << endl;
	}
	else{
		int N = 2*k + 4;
		G.resize(N+1, vector<int>(N+1, 1));
		int i, j;

		construct(1, k+2);
		construct(k+3, N);
		
		for(i=1; i<=N/2; i++){
			for(j=N/2+1; j<=N; j++){
				G[i][j] = 0;
				G[j][i] = 0;
			}
		}
		
		cout << "YES" << endl;
		cout << N << ' ' << N*k/2 << endl;
		
		G[1][N/2+1] = 1;
		G[N/2+1][1] = 1;
		for(i=1; i<=N; i++){
			for(j=1; j<=N; j++){
				if (i < j && G[i][j] == 1){
					cout << i << ' ' << j << endl;
				}
			}
		}
		 		
	}	
	return 0;
}

