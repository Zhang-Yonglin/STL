#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

//����ʵ��
template<class T1,class T2>
class Person{
public:
	Person(T1 name,T2 age){
		this->mName = name;
		this->mAge = age;
	}
	void Show(){
		cout << "Name:" << this->mName << " Age:" << this->mAge << endl;
	}
public:
	T1 mName;
	T2 mAge;
};

void test01(){
	Person<string, int> p("AAA", 20);
	p.Show();
}


int main(void){

	test01();
	
	return 0;
}