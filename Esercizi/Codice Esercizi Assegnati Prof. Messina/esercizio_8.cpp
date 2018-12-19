/*
 * Esercizio 8 
 * Alessandro Lauria
 * 
 */
#include <iostream>
using namespace std;

const int n = 3;
const int m = 4;

void print_matrix(int A[][m]){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<< A[i][j] << " ";
		}
		cout<<endl;
	}

	cout<<endl;
}

bool esercizio8(int A[][m], short k, short w){

	int count_col = 0;

	for(int j = 0; j<m; j++){
		int prec = 0;
		int count_num = 0;
		for(int i = 0; i<n; i++){
			if(A[i][j]>=prec){
				count_num++;
				prec = A[i][j];
			}
			else break;
		}
		if(count_num>=k)count_col++;
	}

	if(count_col>=w)return true;

	return false;

}

int main(){
	
	int A[n][m]={{1,5,7,15},
				 {2,3,4,5},
				 {6,7,8,9}};

	print_matrix(A);
	cout<<esercizio8(A,2,2)<<endl;


}