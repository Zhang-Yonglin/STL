#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
using namespace std;


void test01(){
	
	queue<int> q; //创建队列

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	cout << "队尾：" << q.back() << endl;

	//输出顺序: 10 20 30 40
	while (q.size() > 0){
		
		cout << q.front() << " "; //输出队头元素
		q.pop(); //删除队头

	}
	cout << endl;
	//作业1 queue容器存放对象指针
	//作业2 queue容器存放stack容器
}


int main(void){
	
	test01();
	return 0;
}

//queue容器  队列容器  先进先出  一端插入另一端删除   队尾back()  队头front()
//push() 入队操作  pop()
//不能进行遍历---不提供迭代器  不支持随机访问
//队列和栈这两个容器不提供迭代器     
