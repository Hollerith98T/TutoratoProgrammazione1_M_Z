#include <iostream>
#include <string>
using namespace std;

int n = 3;
int m = 3;
int r = 5;

bool esercizio_3(string** S, char* C, float w){

	for(int i=0; i<n; i++){
		int tot_char = 0;
		float n_char_equal = 0;
		for(int j=0; j<m; j++){
			tot_char+=S[i][j].size();
			for(int k=0; k<S[i][j].size();k++){
				for(int h=0; h<r; h++){
					if(S[i][j][k]==C[h])n_char_equal++;
				}
			}
		}
		cout<<n_char_equal/tot_char<<"\n";
		if((n_char_equal/tot_char)>w) return true;
	}

	for(int j=0; j<m; j++){
		int tot_char = 0;
		float n_char_equal = 0;
		for(int i=0; i<n; i++){
			tot_char+=S[i][j].size();
			for(int k=0; k<S[i][j].size();k++){
				for(int h=0; h<r; h++){
					if(S[i][j][k]==C[h])n_char_equal++;
				}
			}
		}
		cout<<n_char_equal/tot_char<<"\n";
		if((n_char_equal/tot_char)>w) return true;
	}

	return false; 

}

int main(){

	string** A;
	char* C;

	A = new string*[n];
	C = new char[r];

	for(int i=0; i<n; i++) A[i]=new string[m];

	A[0][0] = "a"; A[0][1] = "a"; A[0][2] = "m";
	A[1][0] = "d"; A[1][1] = "h"; A[1][2] = "f";
	A[2][0] = "g"; A[2][1] = "h"; A[2][2] = "1";

	C[0] = 'a'; C[1] = 'b'; C[2] = 'c'; C[3] = 'd'; C[4] = 'e';

	bool a = esercizio_3(A,C,0.5);
	cout<<endl<< a << endl;

	return 0;

}