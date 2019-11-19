//1.pop_back()&push_back(elem)实例在容器最后移除和插入数据
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;
 
int main()
{
    vector<int>obj;//创建一个向量存储容器 int
    for(int i=0;i<10;i++) // push_back(elem)在数组最后添加数据 
    {
        obj.push_back(i);
        cout<<obj[i]<<",";    
    }
 
    for(int i=0;i<5;i++)//去掉数组最后一个数据 
    {
        obj.pop_back();
    }
 
    cout<<"\n"<<endl;
 
    for(int i=0;i<obj.size();i++)//size()容器中实际数据个数 
    {
        cout<<obj[i]<<",";
    }
    
    cout<<"\n"<<endl;
    
    return 0;
}

/*
常用函数：
    1.push_back 在数组的最后添加一个数据

    2.pop_back 去掉数组的最后一个数据

    3.at 得到编号位置的数据

    4.begin 得到数组头的指针

    5.end 得到数组的最后一个单元+1的指针

    6．front 得到数组头的引用

    7.back 得到数组的最后一个单元的引用

    8.max_size 得到vector最大可以是多大

    9.capacity 当前vector分配的大小

    10.size 当前使用数据的大小

    11.resize 改变当前使用数据的大小，如果它比当前使用的大，者填充默认值

    12.reserve 改变当前vecotr所分配空间的大小

    13.erase 删除指针指向的数据项

    14.clear 清空当前的vector

    15.rbegin 将vector反转后的开始指针返回(其实就是原来的end-1)

    16.rend 将vector反转构的结束指针返回(其实就是原来的begin-1)

    17.empty 判断vector是否为空

    18.swap 与另一个vector交换数据

基本用法：

#include < vector> 
using namespace std;

简单介绍：

   1 Vector<类型>标识符
   2 Vector<类型>标识符(最大容量)
   3 Vector<类型>标识符(最大容量,初始所有值)
   4 Int i[5]={1,2,3,4,5}
   5 Vector<类型>vi(I,i+2);//得到i索引值为3以后的值
   6 Vector< vector< int> >v; 二维向量//这里最外的<>要有空格。否则在比较旧的编译器下无法通过

实例

*/
