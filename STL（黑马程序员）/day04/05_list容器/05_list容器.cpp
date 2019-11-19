#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;


//初始化
void test01(){
	
	list<int> mlist1;
	list<int> mlist2(10,10); //有参构造
	list<int> mlist3(mlist2);//拷贝构造
	list<int> mlist4(mlist2.begin(), mlist2.end());

	for (list<int>::iterator it = mlist4.begin(); it != mlist4.end();it ++){
		cout << *it << " ";
	}
	cout << endl;
}


//list容器插入删除
void test02(){

	list<int> mlist;

	//插入操作
	mlist.push_back(100);  //在容器尾部加入一个元素
	mlist.push_front(200); //在容器开头插入一个元素

	mlist.insert(mlist.begin(),300);
	mlist.insert(mlist.end(),400);
	mlist.insert(mlist.end(), 200);

	list<int>::iterator it = mlist.begin();
	it++;
	it++;
	mlist.insert(it, 500);
	mlist.insert(mlist.end(), 200);
	//删除
	//mlist.pop_back();
	//mlist.pop_front();
	//mlist.erase(mlist.begin(), mlist.end());   //erase(beg,end) 删除[beg,end)区间的数据，返回下一个数据的位置。
	//mlist.clear();    //移除容器的所有数据         //erase(pos) 删除 pos 位置的数据，返回下一个数据的位置。
	mlist.remove(200); //删除匹配所有值

	list<int>::iterator testit = mlist.begin();
	for (int i = 0; i < mlist.size() - 1;i++){
		testit++;
	}

	//(*(mlist.end()));

	cout << "------------" << endl;
	cout << (*testit) << endl;
	cout << mlist.back() << endl;
	cout << "------------" << endl;

	//删除所有200 还是删除第一次出现的200
	/*
		for (list<int>::iterator lit = mlist.begin(); lit != mlist.end(); lit++){
		cout << *lit << " ";
		}
		cout << endl;
	*/
	
}


//赋值操作
void test03(){

	list<int> mlist;
	//cout << mlist.size() << endl;  //mlist长度为0
	mlist.assign(10, 10);   //assign(n, elem) 将 n 个 elem 拷贝赋值给本身。


	list<int> mlist2;
	mlist2 = mlist;

	mlist2.swap(mlist);

}


//排序 翻转
void test04(){

	list<int> mlist;
	for (int i = 0; i < 10;i++){
		mlist.push_back(i);
	}

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//容器元素反转
	mlist.reverse();

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

}


//自定义排序函数（回调函数）
bool mycompare05(int v1,int v2){

	return v1 > v2;
}


//排序
void test05(){

	list<int> mlist;
	mlist.push_back(2);
	mlist.push_back(1);
	mlist.push_back(7);
	mlist.push_back(5);
        
        //打印list容器
	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//排序  对象怎么排序? 默认从小到大
	mlist.sort();


	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//从大到小
	mlist.sort(mycompare05);

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//算法sort 支持可随机访问的容器

}


int main(void){
	
	test01();
	cout << "-------------------------" << endl;
	test02();
	test03();
	test04();
	test05();

	return 0;
	
}

//链表是由一系列的节点组成，节点包含两个域，一个数据域，一个指针域。
//1.链表内存是连续的还是非连续的？非连续，添加删除元素，时间复杂度都是常熟项，比数组添加删除效率高
//2.链表只有在需要的时候，才分配内存
//链表只要拿到第一个节点，相当于拿到整个链表
//3.链表需要额外的空间保存节点关系  前驱 后继关系
/*

链表和数组有什么区别？
1) 数组必须事先定义固定的长度（元素个数），不能适应数据动态地增减的情况。当数据
增加时，可能超出原先定义的元素个数；当数据减少时，造成内存浪费。
2) 链表动态地进行存储分配，可以适应数据动态地增减的情况，且可以方便地插入、删除
数据元素。（数组中插入、删除数据项时，需要移动其它数据项）
*/



