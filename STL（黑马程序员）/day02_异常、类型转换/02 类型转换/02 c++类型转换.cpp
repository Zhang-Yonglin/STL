#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Building{};
class Animal{};
class Cat : public Animal{};

//static_cast
void test01(){

	int a = 97;
	char c = static_cast<char>(a);
	cout << c << endl;

	//������������ָ��
	//int* p = NULL;
	//char* sp = static_cast<char*>(p);

	//����ָ��
	//Building* building = NULL;
	//Animal* ani = static_cast<Animal*>(building);

	//ת�����м̳й�ϵ�Ķ���ָ��
	//����ָ��ת������ָ��
	Animal* ani = NULL;
	Cat* cat = static_cast<Cat*>(ani);
	//����ָ��ת�ɸ���ָ��
	Cat* soncat = NULL;
	Animal* anifather = static_cast<Animal*>(soncat);

	//Animal aniobj;
	//Animal& aniref = aniobj;
	//Cat& cat = static_cast<Cat&>(aniref);

	Cat catobj;
	Cat& catref = catobj;
	Animal& anifather2 = static_cast<Animal&>(catref);

	//static_cast �������õ��������ͣ�
	//���о��м̳й�ϵ��ָ���������
}

//dynamic_cast ת�����м̳й�ϵ��ָ��������ã���ת��ǰ����ж������ͼ��
void test02(){

	//������������
	//int a = 10;
	//char c = dynamic_cast<char>(a);

	//�Ǽ̳й�ϵ��ָ��
	//Animal* ani = NULL;
	//Building* building = dynamic_cast<Building*>(ani);


	//���м̳й�ϵָ��
	//Animal* ani = NULL;
	//Cat* cat = dynamic_cast<Cat*>(ani);
	//ԭ������ dynamic�����Ͱ�ȫ���

	Cat* cat = NULL;
	Animal* ani = dynamic_cast<Animal*>(cat);

	//����:dynamicֻ��ת�����м̳й�ϵ��ָ��������ã�����
	//ֻ����������ת�ɻ�����
}

//const_cast ָ�� ���û��߶���ָ��
void test03(){

	//1 ������������
#if 0
	int a = 10;
	const int& b = a;
	//b = 10;
	int& c = const_cast<int&>(b);
	c = 20;
#endif
	const int a = 10;
	const int& pp = a;
	int& cc = const_cast<int&>(pp);
	cc = 100;

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;

	//��ָ��
	const int* p = NULL;
	int* p2 = const_cast<int*>(p);

	int* p3 = NULL;
	const int* p4 = const_cast<const int*>(p3);

	//���ӻ���ȥ��������const��

}

//reinterpret_cast ǿ������ת�� �޹ص�ָ�����ͣ���������ָ�붼���Խ���ת��
typedef void(*FUNC1)(int, int);
typedef int(*FUNC2)(int, char*);
void test04(){

	//1. �޹ص�ָ�����Ͷ����Խ���ת��
	Building* building = NULL;
	Animal* ani = reinterpret_cast<Animal*>(building);

	//2. ����ָ��ת��
	FUNC1 func1;
	FUNC2 func2 = reinterpret_cast<FUNC2>(func1);
}


#if 0
1 ������
2 �Լ��밸�� demo
3 �������� һ�����Լ�˼����� ���ĵ� ��ٶ�
4 ������дһ������
5 ����Ŀ һ����¼����(����ʼǱ�)  ��������������ʽ
#endif


int main(void)
{

	//test01();
	test03();

	return 0;
}