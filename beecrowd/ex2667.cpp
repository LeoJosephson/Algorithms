#include <iostream> 
using namespace std;

int main(){
	string line;
	getline(cin, line);
	
	int r = 0;
	for (int i=0; i < line.length(); i++){
		r = (r*10 + ((int) line[i]-48)) % 3;
	}
	cout << r << endl;
	
	return 0;
}
