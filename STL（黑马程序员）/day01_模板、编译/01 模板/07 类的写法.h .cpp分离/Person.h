#pragma once //��ֹͷ�ļ����ظ�����
#include<iostream>
#include<string>

using namespace std;

class Person{
public:
	Person(string name, int age);
	void Show();
public:
	string mName;
	int mAge;
	int mID;
};
