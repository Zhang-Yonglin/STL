#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>

using namespace std;

//打印函数
void PrintDeque(deque<int>& d){

	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}


//deque初始化
void test01(){

	deque<int> d1;    //默认构造形式
	deque<int> d2(10, 5); //deque(n, elem) 构造函数将n个elem拷贝给本身
	deque<int> d3(d2.begin(),d2.end()); //构造函数将[beg, end)区间中的元素拷贝给本身
	deque<int> d4(d3);  //拷贝构造函数

	//打印d4
	PrintDeque(d4);

}


//赋值 大小操作
void test02(){
	
	deque<int> d1;
	deque<int> d2;
	deque<int> d3;
	d1.assign(10, 5);                 //d1.assign(n,num)将n个num拷贝复制到容器d1
	d2.assign(d1.begin(), d1.end()); //迭代器指定区间赋值  c.assign(beg,end)将[beg,end)区间的数据拷贝复制到容器c
	d3 = d2;                        //等号赋值

	d1.swap(d2);                   //交换两个空间元素

	if (d1.empty()){
		cout << "空!" << endl;
	}
	else{
		cout << "size:" << d1.size() << endl;
	}

	d1.resize(5);              //10个元素，后五个元素扔掉

}


//deque容器插入和删除
void test03(){
	
	deque<int> d1;
	d1.push_back(100);
	d1.push_front(200);
	d1.push_back(300);
	d1.push_back(400);
	d1.push_front(500);

	//500 200 100 300 400
	PrintDeque(d1);

	int val = d1.front();   //拿到被删除的数据
	d1.pop_front();         //删除

	val = d1.back();
	d1.pop_back();         //删除最后一个元素

}


int main(void){

	//test01();
	test03();


	return 0;
}

//deque容器 双口容器 push_front  pop_front  push_back  pop_back
//front()和back()  首尾元素   begin和end  首尾迭代器

