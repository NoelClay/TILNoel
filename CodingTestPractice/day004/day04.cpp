//�Ű������� 2���� �迭 ���ڸ� ���� �迭�� i, j , k�� ���� �迭�� 2�������� �־����� solution�Լ� �ۼ�
#if 1
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> Solution(vector<int> array, vector<vector<int>> commands) 
{
	vector<int> answer;
	vector<int> temp;

	for (int i = 0; i < commands.size(); i++) {
		//array�� ���� ����
		vector<int> temp(array);
		
		//�������� �ε�����
		sort(temp.begin() + (commands[i][0] - 1), temp.end() - (commands[i][1] - 1));

		//�ε��� ��� ���ؾߵȴ�.
		answer.push_back(temp[(commands[i][0] - 1) + (commands[i][2] - 1)]);
	}
	return answer;
}

#endif