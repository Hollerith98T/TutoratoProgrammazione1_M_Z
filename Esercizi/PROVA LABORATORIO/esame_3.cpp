/*
 *	Esame programmazione 1 laboratorio - Esame 3
 *	Alessandro Lauria
 */

#include <iostream>
#include <string>
using namespace std;


#define DIM 50

class A{

protected:
	int x;

public:
	A(int i){
		x=i;
	}

	int getX(){return x;}
	virtual const int f() = 0 ;
};


class B : public A{

private:
	char b;

public:
	B(int i, char c) : A(i){
		b = c;
	}

	char getB(){return b;}

	const int f(){
		if(x%2==0) return (int)b;
		return (int)(b*2);
	}

	B operator++(int){
		B obj = *this;
		obj.x+=1;
		return obj;
	}

};

template <class T> class C : public A{

private:
	T c;

public:

	C(int i, T t) : A(i){
		c = t;
	}

	T getC(){return c;}

	const int f(){
		return x+((int)(c)*20);
	}

	const T f(double eps){
		if(typeid(c)==typeid(char)) return c+1;
		return (T)(f()+eps);
	}

};

ostream& operator<<(ostream& os, A* a){

	if(C<char>* obj = dynamic_cast<C<char>*>(a)){
		if(typeid(obj->getC())==typeid(char)){
			return os << "Class C<char>: x: " << obj->getX() << " c: " << obj->getC() << " f(): "<<obj->f()<<" f(0.03)"<<obj->f(0.03)<<endl;
		}
	}

	if(B* b = dynamic_cast<B*>(a)){
		return os << "Class B: x: " << b->getX() << " c: " << b->getB() << " f(): "<<b->f()<<endl;
	}

	return os << "Class C<>: x: " << a->getX() << " c: " << " f(): "<<a->f()<<endl;

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

	B b(5,'a');
	cout<< endl<<b.getX()<<endl;
	cout<< endl<<(b++).getX()<<endl;



}