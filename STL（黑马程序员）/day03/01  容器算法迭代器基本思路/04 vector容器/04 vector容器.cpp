#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>


using namespace std;


//打印容器中的内容
void printVector(vector<int>& v){         //传入的参数是 vector<int> 类型的引用
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}


//初始化
void test01(){

	vector<int> vl;                                    //默认构造

	int arr[] = { 10, 20, 30, 40 };                    //数组初始化
	vector<int> v2(arr,arr + sizeof(arr)/sizeof(int)); //用数组进行初始化
	vector<int> v3(v2.begin(), v2.end());              //v2.end指向的是数组中40元素的后面一个位置，即\0位置
	vector<int> v4(v3);
	
	printVector(v2);
	printVector(v3);
	printVector(v4);
}


//常用赋值操作
void test02(){

	
	int arr[] = { 10, 20, 30, 40 };
	vector<int> vl1(arr,arr+sizeof(arr)/sizeof(int));      //默认构造

	//成员方法
	vector<int> v2;
	v2.assign(vl1.begin(), vl1.end());

	//重载=
	vector<int> v3;
	v3 = v2;

	int arr1[] = { 100, 200, 300, 400 };
	vector<int> v4(arr1, arr1 + sizeof(arr) / sizeof(int));//默认构造

	printVector(vl1);
	printVector(v2);
	printVector(v3);
	printVector(v4);

	cout << "------------------" << endl;

	v4.swap(vl1);      //v4和v1的值进行交换  其实是指向指针进行了交换
	printVector(vl1);
	printVector(v2);
	printVector(v3);
	printVector(v4);

}


//大小操作
void test03(){
	
	int arr1[] = { 100, 200, 300, 400 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int)); //默认构造

	cout << "size：" << v4.size() << endl;
	if (v4.empty() == true){
		cout << "空！" << endl;
	}
	else{
		cout << "不空！" << endl;
	} 

	printVector(v4);
	v4.resize(2);
	printVector(v4);
	v4.resize(6);   //超出长度，并且不设置默认值为，则默认值为0
	printVector(v4);
	v4.resize(6,1);  //超出长度，并且设置默认值为1
	printVector(v4);

	for (int i = 0; i < 10000; i++){
		v4.push_back(i);
	}
	cout << "size：" << v4.size() << endl;      //元素的个数 20
	cout << "容量:" << v4.capacity() << endl;   //容量 100


}


//vector存取数据
void test04(){
	
	int arr1[] = { 100, 200, 300, 400 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int)); //默认构造

	for (int i = 0; i < v4.size();i++){
		cout << v4[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v4.size(); i++){
		cout << v4.at(i) << " ";
	}
	cout << endl;


	//区别: at抛异常 []不抛异常

	cout << "front:" << v4.front() << endl;  //返回容器中第一个数据元素（不是返回指针）
	cout << "back:" << v4.back() << endl;    //返回容器中组后一个数据元素（不是返回指针）
}


//插入和删除
void test05(){
	
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	//头插法
	v.insert(v.begin(),30);  //用迭代器来表示位置
	v.insert(v.end(),40);

	v.insert(v.begin() + 2, 100); //vector支持随机访问，所以可以用首地址加2

	//支持数组下标，一般都支持随机访问
	//迭代器可以直接+2 +3 -2 -5操作
	printVector(v);

	//删除
	v.erase(v.begin());  //删除第一个元素   v.erase()传入指针参数？？
	printVector(v);
	v.erase(v.begin() + 1, v.end());  //删除两个位置之间的元素
	printVector(v);
	v.clear();
	cout << "size:" << v.size() << endl;
}


//巧用swap缩减空间
void test06(){

	//vector添加元素 他会自动增长 你删除元素时候，会自动减少吗？

	vector<int> v;
	for (int i = 0; i < 100000; i ++){
		v.push_back(i);
	}

	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;

	v.resize(10);   //size减小了，但是capacity没有减小
	cout << "--------------" << endl;
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;

	//收缩空间  根据size大小进行收缩
	vector<int>(v).swap(v);

	cout << "--------------" << endl;
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
}


void test07(){
	
	//reserve：预留空间              resize区别

	int num = 0;
	int* address = NULL; //定义指针变量

	vector<int> v;
	v.reserve(100000);  //开辟预留空间，则使用过程中可以减少申请内存次数，从而减小申请内存和拷贝次数，加快程序运行速度
	for (int i = 0; i < 100000;i++){
		v.push_back(i);
		if (address != &(v[0])){
			address = &(v[0]);  //重新申请内存时，对象v的首地址会发生变化
			num++;
		}
	}

	cout << "num:" << num << endl;

	//如果你知道容器大概要存储的元素个数，那么你可以用reserve预留空间
}


int main(void){
	
	test01();
	cout << "---------------------" << endl;
	test02();
	cout << "---------------------" << endl;
	test03();
	cout << "---------------------" << endl;
	test04();
	cout << "---------------------" << endl;
	test05();
	cout << "---------------------" << endl;
	test06();
	cout << "---------------------" << endl;
	test07();

	return 0;
}

//vector容器 单口容器
//vector动态增长基本原理：当插入新元素的时候，如果空间不足，那么vector会重新申请更大的一块内存空间，将原空间数据拷贝到新空间，释放旧空间的数据，再把新元素插入新申请空间。（默认申请两倍大小）

