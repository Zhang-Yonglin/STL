#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<class T>
class Animal{
public:
	void Jiao(){
		cout << mAge << "�궯���ڽ�!" << endl;
	}
public:
	T mAge;
};


template<class T>
class Cat : public Animal<T>{};



int main(void)
{
	
	Cat<int> cat;
	return 0;
}