#include <iostream>
using namespace std;

#define n 3

void print(int*** A){
	for(int i = 0; i<n; i++){
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

bool esercizio_8(int*** A){

	for(int i=0; i<n; i++){
		int sum=0;
		for(int j=0; j<n; j++){
			sum+=A[i][j][j];
		}
		cout<< sum <<endl;
		if(sum%5==0) return true;
	}

	return false;

}

int main(){

	int*** A;

	A = new int**[n];

	for(int i=0; i<n; i++) A[i]=new int*[n];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			A[i][j] = new int[n];
		}
	} 

	for(int i = 0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int s=0; s<n; s++){
				//A[i][j][s] = new int;
				A[i][j][s] = rand()%10 +1;
			}		
		}
	}

	//A[2][0][0]=0;
	print(A);
	cout<< esercizio_8(A) <<endl;

}