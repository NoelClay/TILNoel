#if 0
// n마리 중에 n/2를 가져간다. 포켓몬은 종류별로 번호가 있음. 같은 종류는 같은 번호
// 최대한 많은 종류의 포켓몬을 포함해서 n/2개를 반드시 가져간다. nums는 항상 짝수개
// 선택할 수 있는 포켓몬 종류의 개수의 최대값을 리턴한다. 기본적으로 n/2개면 최대값이다. 
// 
// 어떤 조합인지를 반환할 필요는 없다. 그저 중복되지 않는 숫자를 뽑되 n/2개를 최대값으로 제한한 느낌.
// nums의 길이는 10000개 즉 n^2만 아니면 된다.
// nlogn = 13*10000, n번 탐색 총 14만번 반복
// 
// 왜 이럴까? 출력값이 이상하다. -> solution의 매개변수를 적어주지 않았던 단순 실수
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
	int answer = 0;
	int compNum = 0;
	int max = nums.size();
	
	sort(nums.begin(), nums.end());
	
	for (int i = 0; i < max; i++) {
		if (compNum < nums[i]) {
			compNum = nums[i];
			answer++;
		}
	}
	if (answer > (max / 2)) 
		return (max / 2);
	else	
		return answer;	
}

int main() {
	vector<int> nums = { 3, 4,3 ,2, 2, 3 };
	cout << solution(nums) <<endl;
	cout << nums.size();
}

#endif