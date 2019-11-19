#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<class T> class Person;
template<class T> void PrintPerson(Person<T>& p);

template<class T>
class Person{
public:

	//��ͨ��Ԫ����
	//template<class T>
	friend void PrintPerson<T>(Person<T>& p);

	//�������Ʋ�����
	template<class T>
	friend ostream& operator<<(ostream& os, Person<T>& p); 
	Person(T age, T id);
	void Show();

private:
	T mAge;
	T mID;
};

template<class T>
Person<T>::Person(T age, T id){
	this->mID = id;
	this->mAge = age;
}

template<class T>
void Person<T>::Show(){
	cout << "Age:" << mAge << " ID:" << mID << endl;
}


//�����������������
template<class T>
ostream& operator<<(ostream& os, Person<T>& p){
	os << "Age:" << p.mAge << " ID:" << p.mID << endl;
	return os;
}

template<class T>
void PrintPerson(Person<T>& p){
	cout << "Age:" << p.mAge << " ID:" << p.mID << endl;
}


//��Ҫ������Ԫ
void test01(){

	Person<int> p(10,20);
	//p.Show();
	//cout << p;
	PrintPerson(p);

}


int main(void){
	
	test01();
	return 0;
}