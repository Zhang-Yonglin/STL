#include "Person.h"

//����ģ�� ����2�α���
//��û�����ɾ���ĺ���
template<class T>
Person<T>::Person(T age){
	this->age = age;
}

template<class T>
void Person<T>::Show(){
	cout << "Age��" << age << endl;
}

