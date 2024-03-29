#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

//评委打分案例(sort 算法排序)
//创建 5 个选手(姓名，得分) ， 10 个评委对 5 个选手进行打分
//得分规则：去除最高分，去除最低分，取出平均分
//按得分对 5 名选手进行排名


//选手类
class Player{
public:
	Player(){}
	Player(string name,int score):mName(name),mScore(score){}   //mName(name),mScore(score) 表示初始化
public:
	string mName;
	int mScore;
};


//创建选手
void Create_Player(vector<Player>& v){

	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i ++){
		
		Player p;
		p.mName = "选手";
		p.mName += nameSeed[i];
		p.mScore = 0;

		v.push_back(p);
	}

}

//打印分数
void PrintScore(int val){

	cout << val << " ";
}


//打分
void Set_Score(vector<Player>& v){

	srand(time(NULL));

	for (vector<Player>::iterator it = v.begin(); it != v.end();it ++){  //评委对学生进行遍历并打分
		
		//当前学生进行打分
		deque<int> dScore;
		for (int i = 0; i < 10;i++){      // 10个评委
			int score = rand() % 41 + 60;
			cout << score << " ";     //打印评委的评分
			dScore.push_back(score);
		}
		cout << endl;

		//对分数排序 默认从小到大
		sort(dScore.begin(),dScore.end());
		//for_each(dScore.begin(), dScore.end(), PrintScore);  //调用回调函数
		//cout << endl;

		//去除最高分 去除最低分
		dScore.pop_front();
		dScore.pop_back();

		//求平均分
		int totalScore = 0;
		for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit++){
			totalScore += (*dit);
		}

		int avgScore = totalScore / dScore.size();
		//保存分数
		(*it).mScore = avgScore;
	}
}


//排序规则
bool mycompare(Player& p1,Player& p2){

	return p1.mScore > p2.mScore;  //逻辑判断
}


//根据选手分数排名 sort默认从小到大 希望从大到小
void Print_Rank(vector<Player>& v){
	
	//排序
	sort(v.begin(), v.end(), mycompare);  //调用回调函数   如果数据类型是int或者char,则sort可以不写第三个参数，sort知道如何进行排序，但是当前是对象，其不知如何排序，因此需要加第三个参数，即回调函数
	//打印
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++){
		
		cout << "姓名:" << (*it).mName << "得分:" << (*it).mScore << endl;

	}
}


int main(void){

	//定义vector容器，保存选手信息
	vector<Player> vPlist;
	Create_Player(vPlist);
	Set_Score(vPlist);
	Print_Rank(vPlist);
	
	return 0;
	
}
