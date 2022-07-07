#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	int t;
	string str;
	
	cin >> t;
	cin.ignore();
	
	getline(cin, str);
	
	
	while (t --){
		vector<vector<int> > M;
		vector<vector<int> > CM;
		int CM_SIZE = 0;
		while (getline(cin, str) && str != ""){
			M.push_back(vector<int>());
			CM.push_back(vector<int>());
			
			for (int i=0; i< str.size(); i++){
				int ch = str[i] - 48;
				M[CM_SIZE].push_back(ch);
				CM[CM_SIZE].push_back(ch);
				if (i > 0) CM[CM_SIZE][i] += CM[CM_SIZE][i-1];
				if (CM_SIZE > 0) CM[CM_SIZE][i] += CM[CM_SIZE-1][i];
				if (CM_SIZE > 0 && i > 0) CM[CM_SIZE][i] -= CM[CM_SIZE - 1][i - 1]; // Subtract repetitions
			}
			CM_SIZE++;
		}
		/* Test CM
		for (int i = 0; i < CM.size(); i++)
			{
			    for (int j = 0; j < CM[i].size(); j++)
			    {
			        cout << CM[i][j] << ' ';
			    }
			    cout << endl;
			}*/
		// CM[h][l] - CM[h][j-1] - CM[i-1][l] + CM[i-1][j-1]
		int c = 1; // 1 
		int f = CM_SIZE*CM_SIZE; // 64
		int maxr = 0; // Biggest submatrix
		while (c < f){ // Binary Search
			int v = floor((c+f)/2); // qtd elem
			bool exist = false;
			for (int l=1; l<=v; l++){
				int h = floor(v/l);
				if (l*h < v) h+=1;
				
				for (int i=1; i<=CM_SIZE; i++){
					for (int j=1; j<=CM_SIZE; j++){
						int sum = CM[h][l] - CM[h][j-1] - CM[i-1][l] + CM[i-1][j-1];
						if (l*h == sum) {
							cout << maxr << endl;
							maxr = max(maxr, l*h);
							exist = true;
						}
					}
				}
			}
			if (exist) c = maxr;
			else f = v;
		}
		
		cout << maxr;
		
	}
	
}
