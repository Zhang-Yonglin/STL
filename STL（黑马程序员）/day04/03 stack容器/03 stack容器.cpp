#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

void test01(){

	//初始化
	stack<int> s1;
	stack<int> s2(s1);

	//stack操作
	s1.push(10);  //压栈
	s1.push(20);
	s1.push(30);
	s1.push(100);
	cout << "栈顶元素:" << s1.top() << endl;
	s1.pop();    //删除栈顶元素  出栈

	//打印栈容器的数据
	while (!s1.empty()){
		cout << s1.top() << " ";     //empty() 判断堆栈是否为空   size() 返回堆栈的大小
		s1.pop();
	}

	cout << "size：" << s1.size() << endl;

	//作业1 栈容器存放对象指针
	//作业2 栈容器存放对象

}



int main(void){

	test01();

	return 0;
}

//stack容器  先进后出
//栈顶  栈底
//压栈  出栈
//栈不能遍历（不提供迭代器） 不支持随机存取   只能通过top从栈顶获取和删除元素
