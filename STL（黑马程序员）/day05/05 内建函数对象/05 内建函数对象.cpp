#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <functional>  
//使用内建函数对象，需要引入头文件 #include<functional>
using namespace std;


void test01(){

	plus<int> myplus;                     //使用内建函数对象声明一个对象
	cout << myplus(10, 20) << endl;
	
	//使用匿名临时对象
	cout << plus<int>()(5, 6) << endl;
}


int main(void){
	
	test01();

	return 0;
}
/*
STL 内建了一些函数对象。分为:算数类函数对象,关系运算类函数对象，逻辑运算类仿
函数。这些仿函数所产生的对象，用法和一般函数完全相同，当然我们还可以产生无名的临
时对象来履行函数功能。使用内建函数对象，需要引入头文件 #include<functional>。
*/
