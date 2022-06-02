//매개변수는 2차원 배열 숫자를 담은 배열과 i, j , k를 담은 배열이 2차원으로 주어질때 solution함수 작성
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
		//array를 깊은 복사
		vector<int> temp(array);
		
		//시작점의 인덱스값
		sort(temp.begin() + (commands[i][0] - 1), temp.end() - (commands[i][1] - 1));

		//인덱스 계산 잘해야된다.
		answer.push_back(temp[(commands[i][0] - 1) + (commands[i][2] - 1)]);
	}
	return answer;
}

#endif