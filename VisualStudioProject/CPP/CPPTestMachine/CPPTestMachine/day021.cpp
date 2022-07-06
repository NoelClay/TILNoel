#if 0
// 응경이가 조합하고 싶어하는 코스의 배열대로 코스를 짜는데
// 그 조합으로 가장많이 조합된 조합이 선택된다.
// 
// orders의 길이는 20, 각 원소의 길이는 10 = 총 문자의 개수는 200
// 코스배열의 길이는 10 각원소는 2~10 이하인 자연수가 오름차순으로 정렬 
// 정답배열의 원소들은 문자열이고, 사전순으로 정렬된다. 
// 각코스의 조합의 최대 개수를 선발하되 만약 최대 개수가 중복된다면 모두 정답배열에 들어간다.
// 
// 진짜 접근조차 못하겠다. 모르겠다.
//
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> Solution(vector<string>orders, vector<int>course) {

}

int main()
{
	vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	vector<int> course = { 2, 3, 4 };
	vector<string> result = Solution(orders, course);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}
#endif