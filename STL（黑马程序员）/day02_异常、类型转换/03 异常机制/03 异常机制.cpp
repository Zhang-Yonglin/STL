#include<iostream>
using namespace std;


//�쳣�����﷨

int divide(int x ,int y){
	if (y == 0){
		throw -1;  //���쳣
	}

	return x / y;
}
void test01(){

	//����ȥ�����쳣
	try{
		divide(10, 0);
	}
	catch (int e){ //�쳣ʱ�������ͽ���ƥ��
		cout << "����Ϊ" << e << "!" << endl;
	}
	
}

void CallDivide(int x,int y){
	
	divide(x, y);

}

//a -> b - >c  -> d

void test02(){
	
	try{
		CallDivide(10,0);
	}
	catch (int e){
		cout << "����Ϊ" << e << endl;
	}

}


//�쳣�纯��
//�쳣���봦��
int main(){
	
	//test01();
	test02();


}