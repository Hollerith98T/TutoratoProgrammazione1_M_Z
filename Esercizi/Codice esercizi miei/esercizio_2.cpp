/*
 * Esercizio 2 - Esercizi miei
 * Alessandro Lauria
 * 
 */
#include <iostream>
using namespace std;

void print_matrix(int **A, int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<< A[i][j] << " ";
		}
		cout<<endl;
	}

	cout<<endl;
}

bool esercizio_2(int **A, int n, int m, int k){

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(k == A[i][j])return true;
		}
	}

	return false;

}

int main(){

	int n = 4;
	int m = 3;
	int **A;

	A = new int*[n];
	for(int i=0; i<n; i++) A[i] = new int[m];

	A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
	A[1][0] = 4; A[1][1] = 5; A[1][2] = 3;
	A[2][0] = 10; A[2][1] = 2; A[2][2] = 3;
	A[3][0] = 20; A[3][1] = 9; A[3][2] = 3;

	print_matrix(A, n, m);
	cout << esercizio_2(A,n,m,20) << endl;
	

}