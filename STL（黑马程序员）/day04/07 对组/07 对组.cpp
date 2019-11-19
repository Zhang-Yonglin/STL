#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


//对组(pair)将一对值组合成一个值，这一对值可以具有不同的数据类型，两个值可以分别用 pair 的两个公有函数 first 和 second 访问。
void test01(){
        
        //创建对组方法：
	//第一种方法：构造方法
	pair<int, int> pair1(10,20);
	cout << pair1.first << " " << pair1.second << endl;
	
	//第二种方法：
	pair<int, string> pair2 = make_pair(10, "aaa");
	cout << pair2.first << " " << pair2.second << endl;

	//第三种方法：
	pair<int, string> pair3 = pair2;
}

int main(void){

	test01();
	
	return 0;
}
