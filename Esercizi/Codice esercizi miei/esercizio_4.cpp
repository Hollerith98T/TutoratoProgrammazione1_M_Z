/*
 * Esercizio 4 - Esercizi miei
 * Alessandro Lauria
 * 
 */
#include <iostream>
using namespace std;

void print_matrix(int ***A, int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<< *A[i][j] << " ";
		}
		cout<<endl;
	}

	cout<<endl;
}

int esercizio_4(int ***A, int n, int m, int k){

	int somma = 0;
	for(int i=0; i<n; i++){
		int prod = 1;
		for(int j=0; j<m; j++){
			prod *= *A[i][j];
		}
		somma += prod;
	}

	return somma;

}

int main(){

	int n = 4;
	int m = 3;
	int ***A;

	A = new int**[n];
	for(int i=0; i<n; i++) A[i] = new int*[m];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			A[i][j] = new int;
		}
	}

	*A[0][0] = 1; *A[0][1] = 2; *A[0][2] = 3;
	*A[1][0] = 1; *A[1][1] = 2; *A[1][2] = 3;
	*A[2][0] = 1; *A[2][1] = 2; *A[2][2] = 3;
	*A[3][0] = 1; *A[3][1] = 2; *A[3][2] = 3;

	print_matrix(A, n, m);
	cout << esercizio_4(A,n,m,20) << endl;
	

}