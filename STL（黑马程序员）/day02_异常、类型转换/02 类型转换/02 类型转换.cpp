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

	Animal aniobj;
	Animal& aniref = aniobj;
	Cat& cat = static_cast<Cat&>(aniref);

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



int main(void)
{

	test01();
	
	return 0;
}