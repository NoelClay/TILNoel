#if 0
//각 부서별로 지원해야되는 금액의 배열 d, 전체 예산에 해당되는 budget
// 예산 내에서 최대한 많은 부서를 지원할 수 있는 수를 반환해야한다.
// 부서가 요구한 금액보다 모자를거면 지원자체가 안되며, 예산을 넘어가는 지원은 없다.
// 
// 어차피 반환해야되는 값은 결국 몇개의 부서까지 지원가능한가의 문제.
// 부서배열을 오름차순으로 정렬한 다음에 가장 적은 금액부터 차례대로 예산에서 까되
// 예산이 음수가 되기직전까지의 지원가능 부서수를 카운팅하고 반환한다.
// 배열의 길이는 100이하이므로 오름차순 정렬을 하더라도 700회
// 배열 탐사를 하면서 예산에서 마이너스 하는것, 그리고 예산이 0보다 작은지 비교 그리고 카운트 ++ 총 3회를 실행
// 따라서 전체 횟수는 700 + 300 = 1000회 
//
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
	sort(d.begin(), d.end());
	int cnt = 0;

	for (int i = 0; i < d.size(); i++) {
		budget -= d[i];
		if (budget < 0) {
			break;
		}
		else {
			cnt++;
		}
	}
	return cnt;
}
int main() {
	vector<int> d = { 2, 2, 3, 3 };
	int budget = 10;

	cout << solution(d, budget);
}
// 푸는데 걸리는 시간은 20분 정도 생각보다 빨리 끝났다. 스택이나 큐로 풀기엔 딱히 적절해 보이진 않는다.
#endif