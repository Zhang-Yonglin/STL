#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Person{
public:
	Person(){
		cout << "���󹹽�!" << endl;
	}
	~Person(){
		cout << "��������!" << endl;
	}
};

int divide(int x,int y){

	Person p1, p2;

	if (y == 0){
		throw y;
	}

	return  x / y;
}

void test01(){

	try{
		divide(10,0);
	}
	catch (int e){
		cout << "�쳣����" << endl;
	}
}

int main(void)
{
	test01();
	return 0;
}