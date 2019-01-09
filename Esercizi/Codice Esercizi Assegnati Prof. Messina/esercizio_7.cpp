#include <iostream>
#include <string>
using namespace std;

int n = 3;
int m = 3;

bool esercizio_7(string*** S, short w, short k){

	bool row_found = false;
	bool col_found = false;

	for(int i=0; i<n; i++){
		int count=0;
		for(int j=0; j<m && !row_found; j++){
			if((*S[i][j]).size()<=k)count++;
		}
		if(count>=w)row_found = true;
	}

	for(int j=0; j<m; j++){
		int count=0;
		for(int i=0; i<n; i++){
			if((*S[i][j]).size()<=k)count++;
		}
		if(count>=w)col_found = true;
	}

	if(col_found==true && row_found==true) return true;

	return false;


}

int main(){

	string*** A;

	A = new string**[n];

	for(int i=0; i<n; i++) A[i]=new string*[m];

	for(int i=0; i<n;i++){
		for(int j=0; j<m;j++){
			A[i][j] = new string;
		}
	}

	*A[0][0] = "ahsdj"; *A[0][1] = "mwsws"; *A[0][2] = "rswsw";
	*A[1][0] = "dwdfegfew"; *A[1][1] = "hwswsws"; *A[1][2] = "fswswsws";
	*A[2][0] = "gswwedew"; *A[2][1] = "hswwwss"; *A[2][2] = "1swswsws";

	cout << esercizio_7(A,3,5) <<endl;
	
}