#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <list>
using namespace std;


//仿函数   什么是仿函数？？其实是一个类
class mycompare{
public:
	bool operator()(int v1,int v2){
	
		return v1 > v2;
	}
};


//set容器初始化
void test01(){

	
	set<int, mycompare> s1;  //自动进行排序   默认是从小到大
	s1.insert(7);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(1);

	for (set<int>::iterator it = s1.begin(); it != s1.end();it ++){
		cout << *it << " ";
	}
	cout << endl;
#if 0
	//赋值操作
	set<int> s2;
	s2 = s1;

	//删除操作
	s1.erase(s1.begin()); 
	s1.erase(7);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//先序遍历 中序遍历 后序遍历
	//如何改变默认排序？
#endif
}


//set查找
void test02(){
	
	set<int> s1;
	s1.insert(7);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(1);

	set<int>::iterator ret = s1.find(14);  //find(key)  查找键 key 是否存在,若存在，返回该键的元素的迭代器；若不存在，返回 map.end();
	if (ret == s1.end()){
		cout << "没有找到!" << endl;
	}
	else{
		cout << "ret:" << *ret << endl;
	}

	//找第一个大于等于key的元素
	ret = s1.lower_bound(2);     //lower_bound(keyElem) 返回第一个 key>=keyElem 元素的迭代器。
	if (ret == s1.end()){
		cout << "没有找到!" << endl;
	}
	else{
		cout << "ret:" << *ret << endl;
	}

	//找第一个大于key的值
	ret = s1.upper_bound(2);    //upper_bound(keyElem) 返回第一个 key>keyElem 元素的迭代器。
	if (ret == s1.end()){
		cout << "没有找到!" << endl;
	}
	else{
		cout << "ret:" << *ret << endl;
	}

	//equal_range 返回Lower_bound 和 upper_bound值
	pair<set<int>::iterator,set<int>::iterator> myret = s1.equal_range(2);   //equal_range(keyElem)  返回容器中 key 与 keyElem 相等的上下限的两个迭代器。
	if (myret.first == s1.end()){
		cout << "没有找到！" << endl;
	}
	else{
		cout << "myret:" << *(myret.first) << endl;
	}

	if (myret.second == s1.end()){
		cout << "没有找到！" << endl;
	}
	else{
		cout << "myret:" << *(myret.second) << endl;
	}

}


class Person{                                    //为什么由两个public??
public:
	Person(int age,int id):id(id),age(age){}
public:
	int id;
	int age;
};


class mycompare2{
public:
	bool operator()(Person p1,Person p2){
		if (p1.id == p2.id){
			return p1.age > p2.age; //如果id相等，则根据age排序
		}
		else{
			return p1.id > p2.id;  //第一个值相等，则比较第二个值
		}
	}
};


void test03(){

	set<Person, mycompare2> sp; //set需要排序，当你放对象，set知道怎么排吗？

	Person p1(10, 20), p2(20, 20), p3(50, 60);
	sp.insert(p1);
	sp.insert(p2);
	sp.insert(p3);

	Person p4(10, 30);

	for (set<Person, mycompare2>::iterator it = sp.begin(); it != sp.end();it++){
		cout << (*it).age << " " << (*it).id << endl;
	}

	
	
	//查找
	set<Person, mycompare2>::iterator ret =  sp.find(p4);
	if (ret == sp.end()){
		cout << "没有找到!" << endl;
	}
	else{
		cout << "找到：" << (*ret).id << " " << (*ret).age << endl;
	}
}


int main(void){

	test01();
	cout << "-------------" << endl;
	test02();
	cout << "-------------" << endl;
	test03();
	cout << "-------------" << endl;

	return 0;
}

//set/multiset 的特性是所有元素会根据元素的值自动进行排序。set 是以 RB-tree（红黑树，平衡二叉树的一种）为底层机制，其查找效率非常好。set 容器中不允许重复元素,multiset 允许重复元素。
/*
问：我们可以通过 set 的迭代器改变元素的值吗？
答: 不行，因为 set 集合是根据元素值进行排序，关系到 set 的排序规则，如果任意改变 set 的元素值，会严重破坏 set 组织。
*/

