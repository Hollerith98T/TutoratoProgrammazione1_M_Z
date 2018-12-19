#include <iostream>
using namespace std;

int esercizio_5(int ****A, int n, int m){

	int somma = 0;
	for(int j=0;j<m;j++){
		int prod = 1;
		for(int i=0; i<n;i++){
			prod *= (**A[i][j]);
		}
		somma += prod;
	}

	return somma;

}

int main(){

	int**** A;
	int n = 2;
	int m = 2;

	A = new int***[n];

	for(int i=0; i<n; i++) A[i] = new int**[m];

	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			A[i][j] = new *int; //contrlare come inizializzare
		}
	}

	**A[0][0] = 1; **A[0][1] = 1;
	**A[1][0] = 1; **A[1][1] = 1;

	cout<< esercizio_5(A, n, m);

}