#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


template<class T>
class Person{
public:
	Person(){
		mAge = 0;
	}
public:
	T mAge;
};

//Ϊʲô��
//�������������������ǲ�����Ҫ��������ڴ�
//
class SubPerson : public Person<int>{};


int main(void){




	
	return 0;
}