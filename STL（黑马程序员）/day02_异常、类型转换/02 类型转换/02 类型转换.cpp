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

	//基础数据类型指针
	//int* p = NULL;
	//char* sp = static_cast<char*>(p);

	//对象指针
	//Building* building = NULL;
	//Animal* ani = static_cast<Animal*>(building);

	//转换具有继承关系的对象指针
	//父类指针转成子类指针
	Animal* ani = NULL;
	Cat* cat = static_cast<Cat*>(ani);
	//子类指针转成父类指针
	Cat* soncat = NULL;
	Animal* anifather = static_cast<Animal*>(soncat);

	Animal aniobj;
	Animal& aniref = aniobj;
	Cat& cat = static_cast<Cat&>(aniref);

	Cat catobj;
	Cat& catref = catobj;
	Animal& anifather2 = static_cast<Animal&>(catref);

	//static_cast 用于内置的数据类型，
	//还有具有继承关系的指针或者引用
}

//dynamic_cast 转换具有继承关系的指针或者引用，在转换前会进行对象类型检查
void test02(){

	//基础数据类型
	//int a = 10;
	//char c = dynamic_cast<char>(a);

	//非继承关系的指针
	//Animal* ani = NULL;
	//Building* building = dynamic_cast<Building*>(ani);


	//具有继承关系指针
	//Animal* ani = NULL;
	//Cat* cat = dynamic_cast<Cat*>(ani);
	//原因在于 dynamic做类型安全检查

	Cat* cat = NULL;
	Animal* ani = dynamic_cast<Animal*>(cat);

	//结论:dynamic只能转换具有继承关系的指针或者引用，并且
	//只能由子类型转成基类型
}



int main(void)
{

	test01();
	
	return 0;
}