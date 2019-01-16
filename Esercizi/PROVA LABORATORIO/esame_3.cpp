/*
 *	Esame programmazione 1 laboratorio - Esame 3
 *	Alessandro Lauria
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


#define DIM 50

class A{

protected:
	int x;

public:
	A(int i){
		x=i;
	}
	virtual int f() const = 0;
	virtual ostream &put(ostream &s) const{
		stringstream ss;
		ss << "x: "<<this->x<<" ";
		return s << ss.str();
	}
};


class B : public A{

private:
	char b;

public:
	B(int i, char c) : A(i){
		b = c;
	}

	int f() const{
		if(x%2==0) return (int)b;
		return (int)(b*2);
	}

	B operator++(int){
		B obj = *this;
		obj.x+=1;
		return obj;
	}

	ostream &put(ostream &s) const{
		stringstream ss;
		ss << "Class B: ";
		A::put(ss);
		ss << "f(): " << f() <<endl;
		return s << ss.str();
	}

};

template <typename T> class C : public A{

private:
	T c;

public:

	C(int i, T t) : A(i){
		c = t;
	}

	int f() const{
		return x+((int)(c)*20);
	}

	T f(double eps) const{
		if(typeid(c)==typeid(char)) return c+1;
		return (T)(f()+eps);
	}

	ostream &put(ostream &s) const{
		stringstream ss;

		string type = "";
		if(typeid(T)==typeid(char))type="char";
		else type="double";

		ss << "Class C<"<<type<<">: ";
		A::put(ss);
		ss << "f(): " << f()<< " f(0.03):"<< f(0.03) <<endl;
		return s << ss.str();
	}

};

ostream& operator<<(ostream& os, const A* a){

	return a->put(os);

}



int main(){

	A* vett[DIM];

	srand(328832748);

	for(int i=0; i<DIM; i++){
		int x=1+rand()%100;
		int c='a'+rand()%26;
		switch(rand()%3){
			case 0: vett[i]=new B(x,c); break;
			case 1: vett[i]=new C<double>(x,rand()/(double)RAND_MAX); break;
			case 2: vett[i]=new C<char>(x,c+1);
		}
	}

	int max = 0;
	string tmp ="";

	for(int i=0; i<DIM; i++){
		cout<<vett[i];
		if(vett[i]->f()>=max)max = vett[i]->f();

		if(C<char>* obj = dynamic_cast<C<char>*>(vett[i])){
			tmp+=obj->f(0.03);
		}
	}

	cout<< endl<<"max: "<< max <<endl;
	cout<< endl<<"tmp: "<< tmp <<endl;

	A* a = new B(5,'a');
	cout<< endl<< a <<endl;

	B* b = dynamic_cast<B*>(a);
	B new_b = (*b)++;
	a = &new_b;
	cout<< a <<endl;



}