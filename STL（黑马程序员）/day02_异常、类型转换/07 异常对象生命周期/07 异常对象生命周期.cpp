#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyException{
public:
	MyException(){
		cout << "���캯��!" << endl;
	}

	MyException(const MyException& ex){
		cout << "��������!" << endl;
	}

	~MyException(){
		cout << "����������" << endl;
	}
};

void func(){
	//throw &(MyException()); //������������ ���ù���
	throw MyException();
}

void test01(){

	//��ͨ����Ԫ��  ����  ָ��  
	//��ͨԪ�� �쳣����catch������֮�������
	//���õĻ� ���õ��ÿ������죬�쳣����catch������֮�������
	//ָ�� 
	try{
		func();
	}
	catch (MyException& e){
		cout << "�쳣����!" << endl;
		//delete e;
	}

}

int main(void){

	test01();
	return 0;
}