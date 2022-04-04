#include <iostream>
using namespace std;

int main(){
	
	string ciph, line;
	int amnt;
	cin >> ciph;
	cin >> amnt;
	getline(cin, line);
	int lenc = ciph.length();

	for (int m=0; m<amnt; m++){
		bool free = false;
		bool word_start = true;
		string message = "";
		int ind = 0;
		getline(cin, line);
		for (int c=0; c< line.length(); c++){
			if (line[c] == ' '){
				free = false;
				message += line[c];
				word_start = true;
			}  else {
				if (word_start && (line[c] =='a' || line[c] == 'e' || line[c] == 'i' || line[c] == 'o' || line[c] == 'u')){
					free = true;
				} else{
					word_start = false;
				}
				if (free) message += line[c];
				else{
					if (ind == lenc) ind = 0;
					int asc = (int) ciph[ind];
					int dist = (int) line[c] - 97;
					if ( ( asc + dist) < 123 ){
						message += char( asc +dist);
					}
					else{
						message += char( ((asc+dist) % 123) + 97);
					} 
					ind += 1;
				}
			}
		}		
		cout << message << endl;			
	}	
	return 0;
}
