#include <iostream>
using namespace std;

int solve(int wo, int w, int h){
	int path[101][101] = {0};
	bool wolfs[101][101] = {false};
	int i, j, x, y;

	for (i=0; i<wo; i++){
			cin >> x >> y;
			wolfs[x][y] = true;
	}
	
	path[0][0] = 1;
	for (i=0; i<=w; i++){ 
		for(j=0; j<=h; j++){ 
			if (i-1 >= 0 and wolfs[i-1][j] == false){
				path[i][j] += path[i-1][j];
			}	
			if (j-1 >= 0 and wolfs[i][j-1] == false){
				path[i][j] += path[i][j-1];
			}
			
		}
	}
	
	return path[w][h];	
}

void pprint(int s){
	if (s == 0) cout << "There is no path."; 
	else if (s == 1) cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.";
	else cout << "There are " << s <<" paths from Little Red Riding Hood's house to her grandmother's house.";
	cout << endl;
}

int main(){	
	int w, h, wo, s;
	cin >> w >> h;
	while (w != 0 && h!= 0){
		cin >> wo;
		s = solve(wo, w, h);
		pprint(s);
		cin >> w >> h;
	}
	return 0;
}
