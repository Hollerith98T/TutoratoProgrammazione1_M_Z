/*
 *	Esame programmazione 1 laboratorio - 19/09/17
 *	Alessandro Lauria
 */

#include <iostream>
#include <string>
using namespace std;

#define DIM 30

class A{
private:
	string s;

public:
	A(string str){
		s = str;
	}

	string getS() {return s;}

	bool doppia() {
		for(int i=0; i<s.size(); i++){
			for(int j=i+1; j<s.size(); j++){
				if(s[i]==s[j]) return true;
			}
		}

		return false;
	}

	virtual string nuova();
};

class B : public A{

private:
	int i;

public:
	B(string str, int x) : A(str){
		i = x;
	}

	bool doppia(){
		string str = getS();
		for(int i=0; i<str.size(); i++){
			for(int j=i+1; j<str.size(); j++){
				if(str[i]==str[j] && (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')) return true;
			}
		}

		return false;
	}

	string nuova(){
		string str = getS();
		if(i%3==0){
			return str.substr(str.size()-3,str.size());
		}
		
		return str.substr(0,3);
	}

};

class C : public A{

protected:
	char c;

public:

	C(string str, char ch) : A(str){
		c = ch;
	}

	string nuova(){
		string str = getS();
		string tmp = "";
		tmp += str[0];
		for(int i=1; i<str.size(); i++){
			tmp += "*";
		}

		return tmp;
	}

};

class D : public C{

public:
	D(string str, char ch) : C(str,ch){}

	string nuova(){
		return "ciao";
	}
	string nuova(short d){
		string tmp = "";
		tmp+=c;
		for(int i=0; i<d; i++){
			tmp+=(char)(getS()[i]+1);
		}

		return tmp;
	}
};

ostream & operator<< (ostream & os, A* a){
	return os << a->getS();
}


int main(){

	/*A testA("ciaor");
	cout<< testA.getS()<< endl << testA.doppia() <<endl;
	*/

	/*
	B testB("ciaociao",8);
	cout<< testB.getS()<< endl << testB.doppia() <<endl<< testB.nuova()<<endl;
	*/

	/*
	C testC("ciaociao",'a');
	cout<< testC.getS()<< endl << testC.doppia() <<endl<< testC.nuova()<<endl;
	*/

	A* vett[DIM];
	char type[DIM];

	srand(111222333);
	for(int i=0; i<DIM; i++){
		int p = rand()%5+3;
		string str = "";
		for(int j=0; j<p; j++) str += (char)('a' + rand()%26);

		if(rand()%2==1){
			vett[i] = new D(str,(char)('a' + rand()%26));
			type[i]	= 'D';
		} 
		else {
			vett[i] = new B(str, rand()%15);
			type[i] = 'B';
		}
	}

	//0
	string tmp = "";
	for(int i=0; i<DIM; i++) {
		tmp+=(vett[i]->nuova())[0];
		tmp+=(vett[i]->nuova())[1];
	}

	//1
	string tmp2 = "";
	for(int i=0; i<DIM; i++){
		if(type[i]=='D'){
			string str = vett[i]->nuova(3);
			tmp2+=str[0];
			tmp2+=str[1];
			tmp2+=str[2];
		}
	}

	for(int i=0; i<DIM; i++) cout<< vett[i]->getS()<<endl;

	cout<< endl << tmp << endl;
	cout<< endl << tmp2 <<endl;

}