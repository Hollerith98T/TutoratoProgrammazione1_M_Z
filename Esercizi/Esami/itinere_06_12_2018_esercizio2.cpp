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

bool is_substring(string str, string sub){
	for(int i=0; i<str.size(); i++){
		if(str[i]==sub[0]){
			bool check = true;
			for(int j=1; j<sub.size(); j++){
				if(str[i+j]!=sub[j])check=false;
			}
			if(check) return true;
		}
	}
	return false;
}

bool* esercizio_2_ricerca(string*** A, short k, string s){

	bool* ar;

	ar = new bool[n]; 

	for(int i=0; i<n;i++){
		int count = 0;
		for(int j=0;j<m;j++){
			if(is_substring(*A[i][j],s)) count++;
		}
		if(count>=k)ar[i]=true;
		else ar[i]=false;
	}

	return ar;

}

bool* esercizio_2_substring(string*** A, short k, string s){

	bool* ar;

	ar = new bool[n]; 

	for(int i=0; i<n;i++){
		int count = 0;
		for(int j=0;j<m;j++){
			for(int h=0; h<(*A[i][j]).size();h++){
				if((*A[i][j]).substr(h,s.size())==s){
					count++;
					break;
				}
			}
		}
		if(count>=k)ar[i]=true;
		else ar[i]=false;
	}

	return ar;

}

bool* esercizio_2_find(string*** A, short k, string s){

	bool* ar;

	ar = new bool[n]; 

	for(int i=0; i<n;i++){
		int count = 0;
		for(int j=0;j<m;j++){
			if((*A[i][j]).find(s)!=string::npos)count++;
		}
		if(count>=k)ar[i]=true;
		else ar[i]=false;
	}

	return ar;

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
	*A[2][0] = "sdfciaosd"; *A[2][1] = "ciao"; *A[2][2] = "sdfds";

	//cout<<"risultato: \n"<<is_substring("bhjsdciohdbeyd","cia")<<endl; 
	cout<<"risultato: \n"; print(A);
	cout<<endl;
	bool* a = esercizio_2_find(A,2,"ciao");
	for(int i=0; i<n; i++) cout<<a[i]<<" ";
	cout<<endl;

	return 0;

}