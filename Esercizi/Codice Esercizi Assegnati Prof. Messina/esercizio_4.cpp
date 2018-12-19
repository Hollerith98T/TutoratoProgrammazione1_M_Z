/*
 *	Esercizio 4
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void print_array_int(int* a, int dim){
	for(int i=0; i<dim; i++)cout<<" "<<a[i]<<" ";
	cout<<endl;
}

void print_array(double* a, int dim){
	for(int i=0; i<dim; i++)cout<<" "<<a[i]<<" ";
	cout<<endl;
}

double* esercizio4(int** A, int** B, int n, int m, int k){

	double* C = new double[n];
	int sum[n];
	int prod[n];

	for(int i=0; i<n; i++) {
		sum[i]=0;
		prod[i]=0;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			sum[i] += A[i][j];
		}
	}

	for(int j=0; j<n; j++){
		int tmp = 1;
		for(int i=0; i<k; i++){
			tmp = tmp*B[i][j];
		}
		prod[j] = tmp;

	}

	/*cout<<"\nsum:\n";
	print_array_int(sum,n);
	cout<<"prod:\n";
	print_array_int(prod,n);
	cout<<"\n";*/

	for(int i=0; i<n; i++) C[i] = ((double)sum[i])/(prod[i]);

	return C;
}

int main(){

	int n = 4;
	int m = 3;
	int k = 2;

	int** A;
	int** B;

	A = new int*[n];
	B = new int*[k];

	for(int i=0; i<n;i++) A[i] = new int[m];
	for(int i=0; i<k;i++) B[i] = new int[n];

	A[0][0] = 1; A[0][1] = 1; A[0][2] = 2; 
	A[1][0] = 1; A[1][1] = 1; A[1][2] = 1;
	A[2][0] = 1; A[2][1] = 1; A[2][2] = 1;
	A[3][0] = 1; A[3][1] = 1; A[3][2] = 1;

	B[0][0] = 2; B[0][1] = 1; B[0][2] = 1; B[0][3] = 1;
	B[1][0] = 2; B[1][1] = 2; B[1][2] = 2; B[1][3] = 2;

	double* c = esercizio4(A,B,n,m,k);
	print_array(c,n);

	//cout << esercizio4(A,B,n,m,k);

}