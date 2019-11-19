#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;


class Person{
public:
        
	Person(char* name,int age){     //初始化
		this->pName = new char[strlen(name) + 1];  //开辟内存
		strcpy(this->pName, name);  //拷贝数据
		this->mAge = age;
	}

	Person(const Person& p){
		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);
		this->mAge = p.mAge;
	}
	
	Person& operator=(const Person& p){  //重载？？怎么用的？
		
		if (this->pName != NULL){
			delete[] this->pName;
		}

		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);
		this->mAge = p.mAge;

		return *this;
	}

	~Person(){  //析构
		if (this->pName != NULL){
			delete[] this->pName;
		}
	}
public:
	char* pName; //指针 容易出现浅拷贝的问题
	int mAge;
};


void test01(){

	Person p("aaa",20);
	vector<Person> vPerson;
	vPerson.push_back(p);
}


int main(void){

	test01();
	
	return 0;
	
}

