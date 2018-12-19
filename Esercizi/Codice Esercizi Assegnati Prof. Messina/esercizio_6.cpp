/*
 *	Esercizio 6
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define n 2
#define m 3
#define k 4

void print_array(char*** A){

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int s=0; s<k; s++){
				cout<< A[i][j][s];
			}
			cout<<endl;
		}
		cout<<endl;
	}

}

bool esercizio6(char*** A, short w){

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			bool pal = true;
			short lenght = 0;
			for(int s=0; s<k/2; s++){
				if(A[i][j][s]!=A[i][j][k-s-1]) pal = false;
				if(pal==true)lenght++;
			}
			if(lenght >= w) return true; 
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			bool pal = true;
			short lenght = 0;
			for(int s=0; s<m/2; s++){
				if(A[i][s][j]!=A[i][m-s-1][j]) pal = false;
				if(pal==true)lenght++;
			}
			if(lenght >= w) return true; 
		}
	}

	return false;

}

int main(){

	char*** A;
	int w = 3;

	A = new char**[n];

	for(int i=0; i<n; i++) A[i] = new char*[m];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			A[i][j] = new char[k];		
		}
	}

	A[0][0][0] = 'a'; A[0][0][1]='b'; A[0][0][2]='b'; A[0][0][3]='a';
	A[0][1][0] = 'e'; A[0][1][1]='f'; A[0][1][2]='g'; A[0][1][3]='h';
	A[0][2][0] = 'i'; A[0][2][1]='l'; A[0][2][2]='m'; A[0][2][3]='n';

	A[1][0][0] = 'a'; A[1][0][1]='b'; A[1][0][2]='c'; A[1][0][3]='d';
	A[1][1][0] = 'a'; A[1][1][1]='t'; A[1][1][2]='u'; A[1][1][3]='q';
	A[1][2][0] = 'b'; A[1][2][1]='a'; A[1][2][2]='b'; A[1][2][3]='c';

	print_array(A);
	cout<<"serie palindroma maggiore/uguale di " << w << " : " << esercizio6(A, w) <<endl;

}