#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

#define DIM 30

class A {
private:
	string w;

protected:
	short par;

public:
	A(string s, short n){
		w = s;
		par = n;
	}

	int getSum(){
		int sum = 0;
		int s1 = 0;
		int first = 0;
		for(int i=0; i<w.size(); i++){
			switch(w[i]){
				case 'A': case 'E': case 'I': case 'O': case 'U':
				case 'a': case 'e': case 'i': case 'o': case 'u':
				s1 += (int)w[i];
				break;
			}
			sum+=(int)w[i];
		}
		return (sum-s1);
	}

	virtual float* val(short* len) = 0;

	virtual ostream& put(ostream& os){
		stringstream ss;
		ss << " w: "<<w<<" par: "<<par<<" ";
		return os << ss.str();
	}
};

class B : public A{
private:
	string str;

public:
	B(string s, short n) :  A(s,n){
		string tmp = "";
		for(int i=0; i<s.size(); i++){
			if(!(s[i]>=48 && s[i]<=57) && (s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='0' && s[i]!='u')){
				tmp+=s[i];
			}
		}
		str = tmp;
	}

	float* val(short* len){
		float* arr = new float[str.size()];

		for(int i=0; i<str.size(); i++){
			arr[i] = (int)str[i]/(float)par;
		}

		*len = str.size();

		return arr;
	}

	ostream& put(ostream& os){
		stringstream ss;
		ss << "Class B: ";
		A::put(ss);
		ss << " { str="<<str<<" } getSum(): "<<getSum()<<endl;
		return os << ss.str();
	}
};


class C : public A{
private:
	float x;
	string sc;

public:
	C(string s,short n) : A(s,n){
		this->x = fabs(sin(s.length()/(float)par));
		sc =  s.substr(0,(int)(x*(float)n+0.5));
	}

	float* val(short* len){
	    int l = sc.length();
	    float *ret=new float[l];
	    for(int i=0; i<l; i++)ret[i] = log(((int)sc[i]/x));
	    *len = l;
	    return ret;
    }

	bool moreThan(float y){
		if(x>=y) return true;
		return false;
	}

	ostream& put(ostream& os){
		stringstream ss;
		ss << "Class C: ";
		A::put(ss);
		ss << " { x="<<x<<" sc="<<sc<<" } getSum(): "<<getSum()<<endl;
		return os << ss.str();
	}
};

ostream& operator<<(ostream& os, A* obj){
	return obj->put(os);
}

int main(){

	srand(111222333);
	A *vett[DIM];
	short r, r1, select;
	int l;
	string str;
	    
	for(int i=0; i<DIM; i++){
	  str = "";
	  r = rand()%5+5;
	  r1 = rand()%2;
	  l = rand()%8 + 5;
	    for(int j=0; j<l; j++){
	    	select = rand()%3;
	    	switch(select){           
				case 0:
				  str+=(char) ('a' + rand()%25);
				  break;
				case 1:
				  str+=(char) ('0' + rand()%10);
				  break;
				case 2:
				  str+=(char) ('A' + rand()%25);
				  break;
	    }
	    
	    if(r1)
	      vett[i] = new B(str, r);
	    else
	      vett[i] = new C(str, r);
	    }
	  }


	//1
	cout<<endl;
	for(int i=0; i<DIM; i++) cout<<vett[i];
	cout<<endl;

	//2
	for(int i=0; i<DIM; i++){
		short len;
		float *tmp = vett[i]->val(&len);
		float sum = 0.0;
		for(unsigned int j=0; j<len; j++){
			sum+=tmp[j];
		}
		cout<< sum/len <<" ";
	}
	cout<<endl;
	
	//3
	cout<<endl;
	for(int i=0; i<DIM; i++){
		if(C* obj = dynamic_cast<C*>(vett[i])){
			if(obj->moreThan(0.9))cout<<i<<" ";
		}
	}
	cout<<endl;


}
