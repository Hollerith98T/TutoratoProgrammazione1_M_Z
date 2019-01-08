#include <iostream>
using namespace std;

bool esercizio_1(int** A, int n, double w){

	int diag_sum = 0;
	for(int i=0; i<n; i++) diag_sum += A[i][i];

	for(int j=0; j<n; j++){
		double col_sum = 0;
		for(int i=0; i<n; i++){
			col_sum += A[i][j];
		}
		cout<<"divisione numero "<<j<<": "<<col_sum/diag_sum<<endl;
		if((col_sum/diag_sum) > w) return true;
	}

	return false;

}

int main(){

	int** A;
	int n = 3;

	A = new int*[n];

	for(int i=0; i<n; i++) A[i]=new int;

	A[0][0] = 1; A[0][1] = 1; A[0][2] = 3;
	A[1][0] = 4; A[1][1] = 4; A[1][2] = 1;
	A[2][0] = 5; A[2][1] = 1; A[2][2] = 1;

	cout<<"risultato: \n"<<esercizio_1(A,n,1.65)<<endl; 


}