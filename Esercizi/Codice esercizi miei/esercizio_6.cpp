#include <iostream>
#include <string>
using namespace std;

int n = 3;
int m = 3;

void print(string*** A){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<*A[i][j]<<" ";
		}
		cout<<endl;
	}
}


int Esercizio_6(string*** A, char x){

	int count = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int h=0; h<(*A[i][j]).size();h++) if((*A[i][j])[h]==x) count++;
		}
	}

	return count;

}

int main(){

	string*** A;

	A = new string**[n];

	for(int i=0; i<n; i++) A[i]=new string*[m];

	for(int i=0; i<n;i++){
		for(int j=0; j<m;j++){
			A[i][j] = new string;
		}
	}

	*A[0][0] = "hbjsnciaociao"; *A[0][1] = "dciaosjhdjs"; *A[0][2] = "ther";
	*A[1][0] = "sfs"; *A[1][1] = "dfciaoh"; *A[1][2] = "sdf";
	*A[2][0] = "asdfciaosd"; *A[2][1] = "ciao"; *A[2][2] = "sdfds";

	//cout<<"risultato: \n"<<is_substring("bhjsdciohdbeyd","cia")<<endl; 
	cout<<"risultato: \n"; print(A);
	cout<<endl;
	int a = Esercizio_6(A,'c');
	cout<<a<<"\n";

	return 0;

}