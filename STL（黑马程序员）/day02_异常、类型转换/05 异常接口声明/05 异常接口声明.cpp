#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//�������ֻ���׳�int float char���������쳣���׳������ľͱ���
void func() throw(int,float,char){
	throw "abc";
}

//�����׳��κ��쳣
void func02() throw(){
	throw -1;
}

//�����׳��κ������쳣
void func03(){

}

int main(void)
{
	try{
		func();
	}
	catch (char* str){
		cout << str << endl;
	}
	catch (int e){
		cout << "�쳣!" << endl;
	}
	catch (...){ //���������쳣
		cout << "δ֪�����쳣��" << endl;
	}
	

	return 0;
}