#include <iostream>
using namespace std;

#define mod 100000000
int sol[101][101][11][11] = {0};


int solve(int n1, int n2, int k1, int k2){
	int i, j, kn1, kn2, sum;
	for (i=0; i<=n1; i++){
		for (j=0; j<=n2; j++){
			for (kn1=0; kn1<=k1; kn1++){
				for (kn2=0; kn2<=k2; kn2++){
					sum = 0;
					if(i==0 && j==0) sum = 1;
	 				else{			
						if(kn1>0 && i>0) sum+=sol[i-1][j][kn1-1][k2]%mod;
                    	if(kn2>0 && j>0) sum+=sol[i][j-1][k1][kn2-1]%mod;
                    }  
					sol[i][j][kn1][kn2] = sum % mod;
				}
			}
		}
	}
	return sol[n1][n2][k1][k2];
}

int main()
{
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	cout << solve(n1,n2,k1,k2) << endl;

}

