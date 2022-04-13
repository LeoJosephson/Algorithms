#include <iostream> 
using namespace std;
string M[2];
short res;

void split(string str){
	string word = "";
	short ind = 0;
	for (int i=0; i<=str.length(); i++){
		if (str[i] == ' ' || i == str.length()){
			M[ind] = word;
			ind ++;
			word="";
		} else{
			word += str[i];
		}
	}
}

void count(string a, string b){
	short ac = 0;
	short la = a.length() -1;
	short lb = b.length() -1;
	while ((la >= 0 || lb>= 0)){
		// 454 989765
		if (la >= 0 && lb >=0) ac = ((int)a[la]-48) + ((int)b[lb]-48) + ac;
		else if (la >= 0) ac = ((int)a[la]-48) + ac;
		else ac = ((int)b[lb]-48) + ac;
		
		if (ac >= 10){
			ac = 1;
			res ++;
		} else{
			ac = 0;
			if (la < 0 || lb < 0) break;
		}
		la --;
		lb --;
	}
}

int main(){
	string line;
	while (getline(cin,line)){
		if (line[0] == '0' && line[2] == '0') break;
		res = 0;
		split(line);
		count(M[0], M[1]);
		if (res>0){
			if (res == 1)cout << res << " carry operation.";
			else cout << res << " carry operations.";
		} else{
			cout << "No carry operation.";
		}
		cout << endl;
	}
}
