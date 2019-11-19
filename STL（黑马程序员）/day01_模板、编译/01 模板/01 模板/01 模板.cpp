#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#if 0 
//int�������ݽ���
void MySwap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

//double����
void MySwap(double& a, double& b){
	double temp = a;
	a = b;
	b = temp;
}
#endif

//ģ�弼�� ���Ͳ����� ��д������Ժ�������
//Ϊ���ñ�������������ͨ����  ģ�庯��
template<class T1,class T2> //template<typename T>  //���߱����� ������дģ�庯����������ֶ�����Ҫ��㱨��
void MySwap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

void test01(){

	int a = 10;
	int b = 20;
	//1 �Զ������Ƶ�
	cout << "a:" << a << " b:" << b << endl;
	MySwap(a, b); //�����������㴫��ֵ ���������Զ��Ƶ�
	cout << "a:" << a << " b:" << b << endl;

	double da = 1.13;
	double db = 1.14;
	cout << "da:" << da << " db:" << db << endl;
	MySwap(da, db);
	cout << "da:" << da << " db:" << db << endl;

	//2. ��ʽ��ָ������
	MySwap<int>(a, b);
}

int main(void){
	
	test01();





	return 0;
}