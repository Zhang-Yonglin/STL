#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//��char���ͺ�Int���������������

//��ӡ����
template<class T>
void PrintArray(T* arr,int len){
	for (int i = 0; i < len;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

//����
template<class T>
void MySort(T* arr,int len){

	for (int i = 0; i < len;i ++){
		for (int j = i + 1; j < len;j++){
			
			//�Ӵ�С����
			if (arr[i] < arr[j]){
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}
	}

}


int main(void)
{

	//����
	int arr[] = {2,6,1,8,9,2};
	//���鳤��
	int len = sizeof(arr) / sizeof(int);

	cout << "����֮ǰ:" << endl;
	PrintArray(arr,len);
	//����
	MySort(arr,len);
	//����֮��
	cout << "����֮��:" << endl;
	PrintArray(arr, len);

	cout << "--------------------" << endl;
	char chArr[] = {'a','c','b','p','t'};
	len = sizeof(chArr) / sizeof(char);
	PrintArray(chArr, len);
	MySort(chArr, len);
	PrintArray(chArr, len);
	
	return 0;
}