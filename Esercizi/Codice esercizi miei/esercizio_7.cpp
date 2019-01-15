#include <iostream>
#include <string>
using namespace std;

int n = 3;
int m = 3;

int esercizio_7(char**** A){

	int sum = 0;

	for(int j=0;j<m;j++){
		int count=0;
		for(int i=0; i<n; i++){
			for(int k=i+1; k<n-1; k++){
				if((**A[i][j])==(**A[k][j])) count++;
			}
		}
		cout<<count<<endl;
		sum+=count;
	}

	return sum;

}

int main(){

	char**** A;

	A = new char***[n];

	for(int i=0; i<n; i++) A[i]=new char**[m];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			A[i][j]=new char*;
			*A[i][j] = new char;
		}
	}

	**A[0][0] = 'a'; **A[0][1] = 'b'; **A[0][2] = 'c';
	**A[1][0] = 'a'; **A[1][1] = 'd'; **A[1][2] = 'e';
	**A[2][0] = 'b'; **A[2][1] = 'g'; **A[2][2] = 'h';

	cout<<esercizio_7(A)<< endl;

}