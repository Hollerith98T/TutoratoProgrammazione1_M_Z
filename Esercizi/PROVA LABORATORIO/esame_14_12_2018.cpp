/*#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

#define DIM 10


class A{

protected:
	double* ptr;
	short len;

public:
	A(short n){
		len=n;
		ptr = new double[n];
		for(int i=0; i<n; i++)ptr[i]=rand()/(double)RAND_MAX;
	}

	virtual ostream &put(ostream &os){
		stringstream ss;
		ss<< "ptr [";
		for(int i=0; i<len; i++)ss << ptr[i] << ", "; 
		ss<<"]";
		return os << ss.str();
	}

	virtual double foo(short a) const = 0;

	double& operator[](short i){
		return ptr[i];
	}

};

class B :  public A{

private:
	double alpha;

	double extract(short s) const{
		return (ptr[s%len]+alpha)/2;
	}

public:
	B(short m, double d) : A(m){ alpha=d; }

	double foo(short b) const{
		return log(1+extract(b));
	}

	ostream &put(ostream &os){
		stringstream ss;
		ss << "B, ";
		A::put(ss);
		ss << " alpha: "<< alpha<< ", foo(5): "<<foo(5)<<endl;
		return os << ss.str();
	}

};


template <typename T>class C : public A{

private:
	T x;

public:

	C(short n) : A(n){
		if(typeid(T)==typeid(short))this->x = g(n);
		else this->x = log(1+n);
	}

	double foo(short r) const{
		return g(r*x);
	}

	T g(T k) const{
		return 3*k;
	}

	ostream &put(ostream &os){
		stringstream ss;
		string type = "double";
		if(typeid(T).name() == typeid(int).name())type="int";
		ss <<"C <"<<type<<"> ";
		A::put(ss);
		ss << " x: "<< this->x<< " foo(5): "<< foo(5) <<" g(5): "<<g(5)<<endl;
		return os<<ss.str();
	}

};

ostream& operator<<(ostream& os, A* a){
	return a->put(os);
}


int main(){

	srand (328832748);
	A* vett[DIM];
	for(int i=0; i<DIM; i++) {
		short n=1+rand()%5; switch ( rand ()%3) {
			case 0: vett[i]= new B(n, n/100.0); break; 
			case 1: vett[i]= new C<double>(n);break; 
			case 2: vett[i]= new C<int>(n);
		} 
	}

	for(int i=0; i<DIM; i++)cout<<vett[i];

	double max = 0;
	double sum = 0;
	
	for(int i=0; i<DIM; i++){
		if(vett[i]->foo(5)>=max)max=vett[i]->foo(5);

		if(dynamic_cast<C<double>*>(vett[i])){
			sum+=((C<double>*) vett[i]) -> g(5);
		}
	}

	cout<<"Max: "<<max<<endl;
	cout<<"Sum: "<<sum<<endl;

	cout<< "vett[2][0]: "<<(*vett[2])[0] <<endl;

}*/

/***** IL SEGUENTE ESAME E' DA COMPLETARE ******/
/*
 * Esame 14/12/2018
 * Alessandro Lauria
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

#define DIM 10

class A{

protected:
	double* ptr;
	short len;

public:
	A(short n){
		len=n;
		ptr = new double[n];
		for(int i=0; i<n; i++) ptr[i]=rand()/(double)RAND_MAX;
	}

	virtual double foo(short a) const = 0;

	virtual ostream& put(ostream& os){
		stringstream ss;
		ss<<"ptr=[";
		for(int i=0; i<len; i++) {ss<<ptr[i]<<" ";}
		ss<<"] ";
		return os << ss.str();

	}

	double operator[](int i){
		return ptr[i];
	}

};

class B : public A{

private:
	double alpha;
	double extract(short s) const {return (ptr[s%len]+alpha)/2;}

public:
	B(short m,double d) : A(m){alpha=d;}
	double foo(short b) const{
		return log(1+extract(b));
	}

	ostream& put(ostream& os){
		stringstream ss;
		ss<<"B, ";
		A::put(ss);
		ss<<"alpha: "<<alpha<<" foo(5):"<<foo(5)<<endl;
		return os << ss.str();
	}

};

template <typename T> class C : public A{
	
private:
	T x;

public:
	C(short n) : A(n){
		if(typeid(x).name()==typeid(short).name()){
			x = g(n);
		}
		else{
			x = log(1+n);
		}
	}

	T g(T k) const {return 3*k;}

	double foo(short r) const{return g(r*x);}

	ostream& put(ostream& os){
		stringstream ss;
		string type="";

		if(typeid(x).name()==typeid(int).name())type="int";
		else type="double";

		ss << "C<"<<type<<">, ";
		A::put(ss);
		ss << " x: "<< x<<" foo(5): "<<foo(5)<<" g(5): "<<g(5)<<endl;

		return os << ss.str();
	}

};

ostream& operator<< (ostream& os, A* obj){
	return obj->put(os);
}

int main(){

	A* vett[DIM];

	srand (328832748);
	for(int i=0; i<DIM; i++) {
		short n=1+rand()%5; 
		switch ( rand ()%3) {
			case 0: vett[i]= new B(n, n/100.0); break;
			case 1: vett[i]= new C<double>(n);break;
			case 2: vett[i]= new C<int>(n);break;
		} 	
	}

	cout<<endl;
	for(int i=0; i<DIM; i++) cout<<vett[i];
	cout<<endl;

	double max = vett[0]->foo(5);
	double sum = 0;
	for(int i=1; i<DIM; i++) {
		if(vett[i]->foo(5) >= max) max = vett[i]->foo(5);

		if(C<double>* obj = dynamic_cast<C<double>*>(vett[i])){
			sum += obj->g(5);
		}
	}

	cout<< "max: "<<max<<endl;
	cout<< "sum: "<<sum<<endl;

	cout<< (*vett[0])[5]<<endl;
}

