#if 0
//
// 한 심사대에서는 동시에 한명만 심사를 받는다.
// 모든 사람이 심사를 받는데 걸리는 시간을 최소로 한다.
// 입국심사를 기다리는 사람 수 n, 각 검사관이 한 명을 심사하는데 걸리는 시간이 담긴 배열 times
// 모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 리턴
// 심사관은 십만명까지 있다.
// 주어지는 수가 많기 때문에 일반적인 배열 구조는 아닐거 같다.
// 
// 그냥 수식으로 7과 10이 동시에 돌아갈때 7,4 10,2 로 분배되어 7*4=28로 가장 최소시간이 됨.
// 
// 벡터 초기화 선언 https://blockdmask.tistory.com/70
//
// 반복문을 돌면서 시간을 체크하고 일일히 n--하는 방식으로는 시간초과를 아득히 넘어감
//
// 잠시만 times를 내림차순으로 정렬하고 나서 관찰을 해보면 가장 최솟값이 맨앞에 들어가고 그 다음요소는 무조건
// 그 횟수보다는 같거나 많을 것이다.
// 
// times[i] 들을 전부 더한 뒤에 
//

#include<vector>
#include<iostream>

using namespace std;

int solution(int n, vector<int> times) {
	//vector<int> count(times.size()); //타임즈 배열의 개수만큼 count 요소개수를 초기화함.
	int i = 0;
	int part = n / times.size();

	while (true) {
		if(times[i])
		i++;
	}


}
#endif