#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;


//map容器初始化
void test01(){

	//map容器模板参数，第一个参数key的类型，第二参数value类型
	map<int, int> mymap;

	//插入数据  pair.first key值   piar.second value值
	//第一种
	pair<map<int, int>::iterator, bool> ret = mymap.insert(pair<int, int>(10, 10));
	if (ret.second){
		cout << "第一次插入成功!" << endl;
	}
	else{
		cout << "插入失败!" << endl;
	}
	
	ret = mymap.insert(pair<int, int>(10, 20));
	if (ret.second){
		cout << "第二次插入成功!" << endl;
	}
	else{
		cout << "插入失败!" << endl;
	}
	
	//第二种
	mymap.insert(make_pair(20, 20));
	
	//第三种
	mymap.insert(map<int, int>::value_type(30,30));
	
	//第四种
	mymap[40] = 40;
	mymap[10] = 20; 
	mymap[50] = 50;
	//发现如果key不存在，创建pair插入到map容器中
	//如果发现key存在，那么会修改key对应的value

	//打印
	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end();it ++){
		// *it 取出来的是一个pair
		cout << "key:" << (*it).first << " value:" << it->second << endl;
	}

	//如果通过【】方式去访问map中一个不存在key，
	//那么map会将这个访问的key插入到map中,并且给value一个默认值(一般为0)
	cout << " mymap[60]: " <<  mymap[60] << endl;

	//打印
	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++){
		// *it 取出来的是一个pair
		cout << "key:" << (*it).first << " value:" << it->second << endl;
	}

}


class MyKey{
public:
	MyKey(int index,int id){
		this->mIndex = index;
		this->mID = id;
	}
public:
	int mIndex;
	int mID;
};


struct mycompare{    //struct的默认是public
	bool operator()(MyKey key1, MyKey key2){
	
		return key1.mIndex > key2.mIndex;
	}
};


void test02(){
	
	map<MyKey, int, mycompare> mymap; //自动排序，自定数据类型，咋排?

	mymap.insert(make_pair(MyKey(1, 2), 10));  //使用对象作为键值
	mymap.insert(make_pair(MyKey(4, 5), 20));

	for (map<MyKey, int, mycompare>::iterator it = mymap.begin(); it != mymap.end();it ++){
		cout << it->first.mIndex << ":" << it->first.mID << " = " << it->second << endl;
	}
}


//equal_range
void test03(){

	map<int, int> mymap;
	mymap.insert(make_pair(1, 4));
	mymap.insert(make_pair(2, 5));
	mymap.insert(make_pair(3, 6));

	pair<map<int, int>::iterator, map<int, int>::iterator> ret =  mymap.equal_range(2);  //equal_range(keyElem)  返回容器中 key 与 keyElem 相等的上下限的两个迭代器。
	//也可以：if (ret.first->second)   ////ret.first->second表示找到的键值
	if (ret.first != mymap.end()){
		cout << "找到lower_bound！" << endl;
	}
	else{
		cout << "没有找到";
	}
	//也可以：if (ret.second->second)  //ret.second->second表示找到的键值
	if (ret.second != mymap.end()){
		cout << "找到upper_bound！" << endl;
	}
	else{
		cout << "没有找到";
	}

}


int main(void){
		
	test01();
	cout << "----------------" << endl;
	test02();
	cout << "----------------" << endl;
	test03();

	return 0;
	
}

//map 相对于 set 区别，map 具有键值和实值，所有元素根据键值自动排序。pair 的第一元素被称为键值，第二元素被称为实值。map 也是以红黑树为底层实现机制。
//插入时将数据封装成pair放入到map里面
//map会根据key进行自动排序：如果数据是基本类型，则可以自动排序，若为对象，则需要进行指定
//不能通过map的迭代器修改map的键值，键值关系到容器内元素的排列规则，任意改变键值会破坏容器的排列规则，但是可以改变实值。
//如果想要修改键值，则可以删除再插入进去




