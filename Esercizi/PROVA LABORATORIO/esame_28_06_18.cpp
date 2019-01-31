/*
 *	Esame 26_06_18
 *	Alessandro Lauria
 */

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

#define DIM 30

class A{
private:
	int* p;
	short l;
	float y;

public:
	A(short i1, short i2){
		l = i1+i2;
		p = new int[l];

		int max = (i1 > i2) ? i1 : i2;
		int min = (i1 > i2) ? i2 : i1;

		/*if(i1 > i2) {
			max = i1;
			min = i2;
		}
		else{
			max = i2;
			min = i1;
		}*/

		for(int i=0; i<l; i++){
			p[i] = (int)(rand()%(max-min+1) + min);
		}
		y = log((i1+i2)/2);
	}

	virtual float f(short i, float x) = 0;

	virtual ostream& put(ostream& os){
		stringstream ss;
		ss << "p[ ";
		for(int i=0; i<l; i++) ss << p[i] << " ";
		ss << "] l: "<<l<<" y: "<<y;
		return os << ss.str();
	}

protected:
	int val(short j){
		if(j>=0 && j<l) return p[j];
		return p[(int)(rand()%j)];
	}
};

class B : public A{
private:
	string str;

public:
	B(string w, short a, short b) : A(a,b){
		for(int i=0; i<w.size(); i++){
			char c = w[i];
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
				str+=c;
			}
		}
	}

	float f(short i, float x){ return (sin(val(i))*x);}

	ostream& put(ostream& os){
		stringstream ss;
		ss << "Class B: ";
		A::put(ss);
		ss << " str: "<<str<<endl;
		return os << ss.str();
	}
};

class C : public A{

private:
	float m;

public:
	C(float z) : A((int)(z+0.5),5*(int)(z+0.5)){
		int b = (int)(z+0.5);
		m = val(2*((int)(z+0.5)))/2.0;
	}

	float f(short i, float x){
		if(x!=0){
			if(i%2==0) return sin(val(i)*x);
			else return val(i)/x;
		}
		return 0;
	}

	float g() {return log(m);}

	ostream& put(ostream& os){
		stringstream ss;
		ss << "Class C: ";
		A::put(ss);
		ss << " m: "<<m<<endl;
		return os << ss.str();
	}

};


ostream& operator<<(ostream& os, A* obj){
	return obj->put(os);
}



int main(){

	srand (111222333);
	A *vett[DIM];
	string w; 
	short s1, s2;
	for(int i=0; i<DIM; i++){ 
		if (rand()%2==0){ //B
			w = "";
			s1 = rand()%20 + 5;
			s2 = rand()%20 + 5;
			short len = rand()%50 + 10; for(int j=0; j<len; j++)
			w+=((rand()%2) ? (char) (rand()%26 + 'a') : (char) (rand()%10 + '0')); vett[i] = new B(w, s1, s2);
		}
		else{ // C
			int max = 10;
			float z = ((float) rand())/INT_MAX * (rand()%max) + 1.0; vett[i] = new C(z);
		} 
	}

	//prima domanda
	cout<< endl;
	for(int i=0; i<DIM; i++) cout<<vett[i];
	cout<< endl;

	//seconda domanda
	cout<< endl;
	for(int i=0; i<DIM; i++){
		if(vett[i]->f(5,0.5) < 0.5) cout<< i <<" ";
	}
	cout<< endl;

	//terza domanda
	int count = 0;
	float sum = 0;

	for(int i=0; i<DIM; i++){
		if(C* obj = dynamic_cast<C*>(vett[i])){
			sum += obj->g();
			count++;
		}
	}

	cout<< "media: "<< sum/count<<endl;

}