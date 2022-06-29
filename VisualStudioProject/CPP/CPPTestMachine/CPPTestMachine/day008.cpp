#if 1
//�����ڵ��� ������ ��´�. ���� ���� ��� ����� ������ ����.
// ���� �迭�� �־����� ���� ���� ������ ���� �����ڸ� �����Ѵ�.
// ������ �ִ� 10000���� ���� n�� Ž�� �����ϰ� n������ �ʹ� ����.
// 
// ����迭�� ������ Ž���Ҷ����� ���ڼ����ڵ��� ��Ĵ�� ��ġ�ϸ� ���䰳���� ī���� �ϴ� ������� �ϰ�
// ���� �����ڵ��� ī��Ʈ�� ���� ���� ��� return �迭�� �����Ѵ�.
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