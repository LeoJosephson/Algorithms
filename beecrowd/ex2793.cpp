#include <iostream>
#include <math.h>
using namespace std;

int main(){
	string line;
	getline(cin, line);
	int F = 0, M = 0, p = 0;	
	for (int i=0; i<line.length(); i++){
		if (line[i] == 'F') F++;
		else M++;
		
		if (M == F){
			p ++;
			F = 0;
			M = 0;
		} 
	}
	cout << (int) pow(2, p-1) % 1000000007 << endl;
}
