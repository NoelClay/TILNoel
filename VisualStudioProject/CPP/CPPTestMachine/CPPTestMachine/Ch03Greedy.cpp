//<1> 당장 좋은 것만 선택하는 그리디
// 거스름돈으로 사용할 500원 100원 50원 10원을 이용해서 최소의 동전개수로 거스름돈을 구성한다고 할때
// 최소의 개수를 반환해라.
// 
// 가장 큰 화폐단위부터 거슬러주면 해결. 하지만 이건 거스름 동전 개수의 일반해가 될 수 없다. 400원짜리라는 표본이 있을 경우에
// 400원으로 거스를지 500 원으로 거스를지 명확히 하는 방식이 아니기 때문이다.
// 
// 가장 큰 화폐단위부터 거슬러 주면 해결되는 이유는 순차적으로 큰 단위가 작은 단위를 온전히 포함하는 관계이기 때문이다.
// 
#if 0
#include<iostream>
#include<vector>
using namespace std;

int solution(int a) {
	int answer = 0;
	int coins[4] = { 500, 100, 50, 10 };
	for(auto n : coins) {
		if (a == 0) {
			break;
		}
		answer += a / n;
		a %= n;
	}

	return answer;
}

int main()
{
	int nums[] = { 1000, 1260, 2330, 4120 };
	for (auto n : nums) {
		cout << solution(n) << endl;
	}
}
#endif

// <2> 큰 수의 법칙
// 
// 다양한 수의 배열이 있을 때 주어진 수들을 M번 더하여 가장 큰 수를 만드는 법칙. 
// 배열의 특정한 인덱스에 해당하는 수가 연속적으로 더할 수 있는 제한이 존재하고, 
// 그 제한만 넘지 않는다면 몇번을 다시 반복해서라도 가장 큰 수를 만들면 되는 문제
// 
// 입력조건 첫째 줄에  N(배열요소 개수), M(총 더해야하는 개수), k(한 인덱스를 연속참조할 수 있는 제한)의 자연수가 주어진다.
// 둘째 줄에 N개의 자연수가 주어진다. 공백으로 구분함.
// 
// 출력 조건 문제에 해당하는 값을 반환한다.
// 
// <랜덤값 생성>
// https://velog.io/@t1won/C-11-%EB%82%9C%EC%88%98-%EC%83%9D%EC%84%B1-random-%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC
//
#if 0
#include<iostream>
#include<vector>
#include<random>
#include<algorithm>

using namespace std;

//내가 짠 솔루션
int solution(int N, int M, int K, vector<int> list)
{
	int answer = 0;
	sort(list.begin(), list.end());

	//최대 M번 더해야하고 연속으로는 K번까지 가능. 최대값을 찾고 작은최대값을 찾으면
	//최대값k번 작은 최대값1번 을 계속 반복해서 M번까지 수행하면 된다.
	//일단 통반복 횟수는 m/(k+1) 번을 통으로 반복할 것이고, 나머지는 그냥 최대값을 누적합 하면 된다.

	int reCount = M / (K + 1);
	answer += (list[N-1] * K) * reCount;
	answer += list[N-2] * reCount;
	answer += list[N-1] * (M % (K + 1));
	// 이상은 내가 짠 코드들. 

	//<이하는 책 내용 결론을 토대로한 최적화 솔루션>
	//최대값이 더해지는 총수를 구해서 곱하고 그 총수를 다 더해야되는 총수에서 뺀 만큼이 바로 그다음 최대값이 더해지는 횟수
	//
	int count = (M / (K + 1)) * K;
	count += M % (K + 1);

	answer = 0;
	answer += list[N - 1] * count;
	answer += list[N - 2] * (M - count);

	return answer;
}
int main()
{
	random_device rd;
	auto gen(rd());
	uniform_int_distribution<> ndist(2, 1000);
	uniform_int_distribution<> mdist(1, 10000);

	//int N = ndist(gen);
	//int M = mdist(gen);
	int N = 5, M = 8;
	int K = 3;

	vector<int> alist = { 2, 4, 5, 5, 6 };
	cout << solution(N, M, K, alist);
}
#endif

//<3> 숫자 카드 게임
// 1. 숫자가 쓰인 카드들이 N X M 형태로 놓여있다. 이때 N은 행의 개수를 의미하고, M은 열의 개수를 의미한다.
// 2. 먼저 뽑고자 하는 카드가 포함되어 있는 행을 선택한다.
// 3. 그다음 선택된 행에 포함된 카드들 중 가장 숫자가 낮은 카드를 뽑아야한다.
// 4. 따라서 처음에 카드를 골라낼 행을 선택할 때, 이후에 해당 행에서 가장 낮은 카드를 뽑을 것을 고려하여 최종적으로는
// 가장 높은 숫자의 카드가 뽑히도록 고려하는 전략이 필요.
// 
// 입력 조건
// 1. 첫째 줄에 숫자 카드들이 놓인 행의 개수와 열의 개수가 주어진다.
// 2. 둘째 줄에 N개의 줄에 걸쳐 각 카드에 적힌 숫자가 주어진다.
// 
// 출력조건
// 가장 높은 숫자의 카드가 뽑히도록 고려된 프로그램을 통해 뽑힌 카드의 숫자를 반환한다.
// 
// 예시
// N=3, M=3, {3 1 2}{4 1 4}{2 2 2}		출력: 2
// N=2, M=4, {7 3 1 8}{3 3 3 4}			출력: 3
// 
// <구현 전략>
// 어차피 출력해야되는건 각 행의 가장 작은 값들이 그 후보이고, 그 후보들 중에서 가장 큰 값을 출력하면 된다.
// 행을 상대로는 최소값 찾기로 배열을 만들고 만들어진 배열에서 최대값 찾기로 출력이 이루어진다.
//
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(int n, int m, vector<vector<int>> cards) {
	vector<int> mins;
	for (int i = 0; i < n; i++) {
		int min = cards[i][0];
		for (int j = 0; j < m; j++) {
			if (min > cards[i][j]) {
				min = cards[i][j];
			}
		}
		mins.push_back(min);
	}
	sort(mins.begin(), mins.end());

	return mins[mins.size() - 1];
}

int main()
{
	int N = 2, M = 4;
	vector<vector<int>> cards;
	vector<int> nums1 = { 7, 3, 1, 8 };
	vector<int> nums2 = { 3, 3, 3, 4 };
	cards.push_back(nums1);
	cards.push_back(nums2);

	cout << solution(N, M, cards);
}
#endif

//<4> 1이 될 때까지
// 어떠한 수  N이 1이 될 때까지 다음의 두 과정 중 하나를 반복적으로 선택하여 수행하려고 한다. 
// 단, 두 번째 연산은 N이 K로 나누어 떨어질 때만 선택할 수 있다.
// 1. N에서 1을 뺀다
// 2. N을 K로 나눈다.
// 
// 입력 조건
// 첫째 줄에 N과 K가 주어진다. 각각 10만이하
// 
// 출력 조건
// 첫째 줄에 N이 1이 될때까지 1번 혹은 2번의 과정을 수행해야 하는 횟수의 최솟값을 출력한다.
// 
// 예시
// 입력 25 5			출력 2
// 
// <접근방법>
// 이 문제는 그리디 알고리즘 예제이다. 범용 일반해는 적용되지 않을 수 있으나, 특수해를 도출해 낼 순 있다.
// 빼기와 나누기로 나뉘는데 1번의 1을 뺀다는 가장 많은 연산횟수를 기록하는 빼기 방법이다. 
// 그에 반해 2이상의 수인 k로 나누는 방법은 주어진 N을 가장 빨리 1에 가깝게 만들 수 있는 방법이다.
// 마치 거스름돈 문제처럼 이것도 나누기를 먼저 진행하고 나서 빼고 다시 나누기하고 다시 빼고 하는 방법으로 진행될 것이다.
// 
// 위는 기본 아이디어이다. 업그레이드를 한다면 수학적인 접근을 할 수 있을거 같다. 어차피 서순아닌가. 
// 어떤 수를 나눌때 나머지가 남는다는것은 그 나머지를 빼주고 나면 나누어 떨어지는 수가 된다는 뜻이다.
// N = ak + b 라고 할때 어차피 b번 뺄셈하고 k로 한번 나누면 N은 a가 된다.
//
#if 1
#include<iostream>
using namespace std;

//내가 풀은 풀이
int solution(int n, int k) {
	int answer = 0;
	
	while (n != 1) {
		if (n >= k) {
			answer += n % k;
			n /= k;
			answer++;
		}
		else {
			answer += n % k;
			n = 1;
		}
	}

	return answer;
}
//책에서 제시한 최적화 풀이
int solution2(int n, int k) {
	int answer = 0;
	//나누어 떨어지는 수가 될때까지 반복적으로 뺄셈을 하는 것이 아니라
	//수학적으로 나누어떨어지는 수를 한번에 계산하는것은 위의 코드와 논리는 비슷하다.
	//나는 나머지를 이용해서 그 뺄셈을 구했고 이쪽은 n/k의 몫에다가 k를 곱해주면 
	//n보다 작거나 같으면서 k의 배수중 가장 큰 값을 구하고 그걸 target이라 정의하고
	//n-target은 뺄셈의 카운트가 되고, n=target으로 할당한 뒤에
	//무조건 k로 나누어떨어지는 target으로 초기화된 n을 k로 나눈 몫으로 초기화하고 카운팅한다.
	//그리고 반복.
	//반복의 종료는 k의 배수인 target으로 초기화된 n이 k보다 작은 아이러니가 발생할때 반복문을 종료한다.
	//n은 결국 1이 될때까지 빼야하므로 n-1 값을 누적 카운팅하면 끝
	int target = 0;
	while (1) {
		target = (n / k) * k;
		answer += n - target;
		n = target;
		if (n < k) {
			break;
		}
		else {
			answer++;
			n /= k;
		}
	}
	answer += n - 1;
	return answer;
}

int main()
{
	int n = 25, k = 5;
	cout << solution(n, k) << endl;
	cout << solution2(n, k) << endl;
}
#endif
#if 0
#include<iostream>

int main()
{

}
#endif
#if 0
#include<iostream>

int main()
{

}
#endif
#if 0
#include<iostream>

int main()
{

}
#endif
#if 0
#include<iostream>

int main()
{

}
#endif
