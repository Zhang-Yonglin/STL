#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Person.h"


//����ģ����α��� �����ɾ��庯��

int main(void){

	//����������ȥ��
	Person<int> p(10); //���캯�������ڵ�ǰ�ļ�û���ҵ���������Ϊ��������������ļ��ж���
	//�������������ӵ�ʱ�� ȥ����������ľ���λ��
	p.Show();

	
	return 0;
}