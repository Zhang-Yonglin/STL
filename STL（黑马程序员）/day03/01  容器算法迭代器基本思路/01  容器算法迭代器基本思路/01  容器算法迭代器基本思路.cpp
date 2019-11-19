#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//算法，负责统计某个元素的个数
int mycount(int* start,int* end,int val){
	int num = 0;
	while (start != end){
		if (*start == val){
			num++;
		}
		start++;
	}

	return num;
}

int main(void){


	//数组 容器
	int arr[] = { 0, 7, 5, 4, 9, 2, 0 };
	int* pBegin = arr; //指向容器的第一个位置
	int* pEnd = &(arr[sizeof(arr) / sizeof(int)]);
	
	int num = mycount(pBegin, pEnd, 0);
	cout << "num ：" << num << endl;

	return 0;
}
