#if 0
// 의상의 종류 별로 의상의 이름이 들어가는 어떤 구조를 만들어야한다.
// 각각 의상별로 하나씩 입는 경우의 수를 각각 구해서 합연산
// 그리고 나서 하나씩 입는 경우의 수를 각각 곱연산 = 동시에 입을 경우의 수이다.
// 
// map 사용법 정리 https://life-with-coding.tistory.com/305
//
#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

int solution(vector<vector<string>> answers) 
{
	map<string, vector<string>> clothmap;
	map<string, int> cntmap;
	int cnt = 0;
	int reSum = 0, reMul = 1;
	
	for (int i = 0; i < answers.size(); i++) {
		if (cntmap.count(answers[i][1])) {
			//clothmap[answers[i][1]].push_back(answers[i][0]);
			cntmap[answers[i][1]]++;
		}
		else {
			//vector<string> str;
			//str.push_back(answers[i][0]);
			//clothmap.insert(answers[i][1], str[0]);
			cntmap.insert(make_pair(answers[i][1], 1));
		}
	}
	for (auto iter = cntmap.begin(); iter != cntmap.end(); iter++) {
		reSum += iter->second;
		reMul *= iter->second;
	}
	if (cntmap.size() < 2) reMul = 0;
	return reSum + reMul;
}

int main()
{
	vector<vector<string>> answers = { {"yell","head"},{"line","head"},{"blue","head"}, {"yond","line"}, {"yello","line"}};
	cout << solution(answers);
}

#endif