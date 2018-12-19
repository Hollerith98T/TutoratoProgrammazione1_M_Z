/*
 *	Esercizio 2
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void print_array(int* a, int dim){
	for(int i=0; i<dim; i++)cout<<" "<<a[i]<<" ";
	cout<<endl;
}

bool palindromo(string s){

	for(int i=0; i<s.size()/2; i++){
		if(s[i] != s[s.size()- i -1]) return false;
	}

	return true;

}


bool esercizio2(string*** M, int row, int col){

	int count_row = 0;
	int count_col = 0;

	int pal_row[row];
	int pal_col[col];

	for(int i=0; i<row; i++){

		count_row = 0;
		for(int j=0; j<col; j++){
			if(palindromo(*M[i][j])) count_row++;
		}
		pal_row[i] = count_row;

	}

	for(int j=0; j<col; j++){

		count_col = 0;
		for(int i=0; i<row; i++){
			if(palindromo(*M[i][j])) count_col++;
		}
		pal_col[j] = count_col;

	}

	print_array(pal_row,row);
	print_array(pal_col,col);

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(pal_row[i]==pal_col[j]) return true;
		}

	}

	return false;
}


int main(){

	int n = 3;
	int m = 4;

	string*** M;

	M = new string**[n];

	for(int i=0; i<n;i++) M[i] = new string*[m];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			M[i][j]= new string;
		}
	}

	*M[0][0] = "ciao"; *M[0][1] = "ala"; *M[0][2] = "ala"; *M[0][3] = "ala";
	*M[1][0] = "ciao"; *M[1][1] = "ala"; *M[1][2] = "ciao"; *M[1][3] = "ciao";
	*M[2][0] = "ciao"; *M[2][1] = "ala"; *M[2][2] = "ciao"; *M[2][3] = "ciao";

	cout << esercizio2(M,n,m) << endl;

}

