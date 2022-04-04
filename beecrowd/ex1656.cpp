#include <iostream> 
using namespace std;
#include <sstream>
#include <stdlib.h>
#define size 1000000

long long int sum[size];
int restos[size];


int main(){
	int c = 1;
	int n = 1;
	int i, j, k, rest;
	string line;
	string cs = "";
	string ns = "";
	while (n != 0 && c != 0){

		getline(cin, line);
		bool complete = false;
		
		
		string cs = "";
		string ns = "";
		for (i=0; i<line.length(); i++){
			if (line[i] == ' '){
				complete = true;
			} else{
				if (isdigit(line[i])){
					if (complete == false){
						cs += line[i];
					} else{
						ns += line[i];
					}
				}
			}
		}
		
		istringstream(cs) >> c;
		istringstream(ns) >> n;


		for(i=1; i<=n; i++){
			sum[i] = -1;
			restos[i] = -1;
		}
		
		
		for (i=1; i<=n; i++){
			cin >> k;
			
			if (i>1){
				sum[i] = sum[i-1] + k;
				rest = sum[i] % c;
			} else{
				sum[1] = k;
				rest = sum[1] % c;
			}
			if (rest == 0){
				for (j=1; j<= i; j++){
					if (j > 1){
						cout << ' ' << j;
					} else{
						cout << j;
					}
						
				}
				cout << endl;
				break;
			} else{
				if (restos[rest] != -1){
					for (j=restos[rest]+1; j<=i; j++){
						if (j > restos[rest]+1){
							cout << ' ' << j;
						} else{
							cout << j;
						}	
					}
					cout << endl;
					break; 
				} else{
					restos[rest] = i;
				}
			}
		}
		getline(cin, line);


	}
	
	return 0;
}
