#include <iostream>
using namespace std;

#define n 3
#define k 3

void print(int*** A){
	for(int i = 0; i<k; i++){
		for(int j=0; j<n; j++){
			for(int s=0; s<n; s++){
				cout<<A[i][j][s]<< " ";
			}
			cout<<endl;		
		}
		cout<< endl;
	}
	cout<<endl;

}

bool esercizio_1(int*** A, double w){

	for(int i=0; i<k; i++){
		int max = 0;
		int min = A[i][0][0];
		for(int j=0; j<n; j++){
			int tmp = A[i][j][j];
			if(tmp >= max) max = tmp;
			if(tmp <= min) min = tmp;
		}
		if(((double)(max+min))/2 >= w) return true;
	}

	return false;
}

int main(){

	int*** A;

	A = new int**[k];

	for(int i=0; i<k; i++) A[i]=new int*[n];

	for(int i=0; i<k; i++){
		for(int j=0; j<n; j++){
			A[i][j] = new int[n];
		}
	} 

	for(int i = 0; i<k; i++){
		for(int j=0; j<n; j++){
			for(int s=0; s<n; s++){
				//A[i][j][s] = new int;
				A[i][j][s] = rand()%10 +1;
			}		
		}
	}

	print(A);
	cout<< esercizio_1(A,5.5) <<endl;

}