#if 1
//수포자들이 문제를 찍는다. 각자 문제 찍는 방식은 정해져 있음.
// 정답 배열이 주어질때 가장 많은 문제를 맞힌 수포자를 리턴한다.
// 시험은 최대 10000문제 따라서 n번 탐색 가능하고 n제곱은 너무 많다.
// 
// 정답배열을 일일히 탐색할때마다 각자수포자들의 방식대로 일치하면 정답개수를 카운팅 하는 방식으로 하고
// 각자 수포자들중 카운트가 가장 많은 경우 return 배열에 포함한다.
//

#include<vector>
#include<iostream>
using namespace std;

struct mathA {
	vector<int> check = { 1, 2, 3, 4, 5 };
	int cnt =0;
};
struct mathB {
	vector<int> check = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int cnt=0;
};
struct mathC {
	vector<int> check = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	int cnt=0;
};

vector<int> Solution(vector<int> answers) 
{
	vector<int> result;
	auto A = new mathA();	A->cnt = 0;
	auto B = new mathB();	B->cnt = 0;
	auto C = new mathC();	C->cnt = 0;

	for (int i = 0; i < answers.size(); i++)
	{
		if (A->check[i % A->check.size()] == answers[i])	A->cnt++;
		if (B->check[i % B->check.size()] == answers[i])	B->cnt++;
		if (C->check[i % C->check.size()] == answers[i])	C->cnt++;
	}

	int max = A->cnt;
	vector<int> temp; temp.push_back(A->cnt); temp.push_back(B->cnt); temp.push_back(C->cnt);
	for (int j = 0; j < 3; j++)
	{
		if (temp[j] > max)	max = temp[j];
	}
	for (int k = 0; k < 3; k++)
	{
		if (temp[k] == max)	result.push_back(k + 1);
	}

	return result;
}

#endif