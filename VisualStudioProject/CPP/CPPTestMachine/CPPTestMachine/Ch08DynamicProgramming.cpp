/*<< 다이나믹 프로그래밍 >>
<중복되는 연산을 줄이자>
현실 세계의 다양한 문제가 있는데 컴퓨터는 엄청나게 빠른 계산속도로 여러 문제를 해결한다.
그런데 컴퓨터가 너무 많은 경우의 수를 탐색해야되다보니 해결하기 어려운 문제들도 있다. 그런경우는
최적의 해를 구하기 까지 시간이 너무 많이걸리고, 공간도 너무 많이 필요할 것이다.
그래서 최적의 길을 제시해주어야 되고, 그게 알고리즘을 공부하는 이유이다.

여기에 미리 몇개의 공간만 확보해서 값을 동적으로 저장하고 동적으로 사용하는 알고리즘이 있다.
이렇게 하면 엄청나게 돌아가야될 길을 비약적으로 간소화 시킬 수 있다. 바로 동적 프로그래밍이다.

동적할당의 다이나믹과는 조금 다른 의미로 사용된다는 것만 알아두고 동적 프로그래밍으로 바로 넘어간다.

1.다이나믹 프로그래밍은 2가지 방식이 있다. 탑다운과 바텀업.
2.다이나믹 프로그래밍은 임시저장공간이 필요하다. 탑다운에선 메모이제이션기법이라 하고 바텀없에선 DP테이블이라고 하는데
그냥 학술적 의미라고만 생각하고 핵심은 임시공간이 필요하다는 것 뿐이다.
3.필수조건을 만족할때 다이나믹 프로그래밍을 짤 수 있다. 첫째 큰 문제를 작은 문제로 나눌 수 있어야 하며
둘째 작은 문제에서 구한 답을 저장해놓으면 그 답을 포함하는 어떠한 문제에서도 그 답은 유효하다.

대표적인 유형으로 피보나치 수열이 있다. "세번째수 = 첫번째수 + 두번째수" 맨처음과 그다음 수는 1로 고정 따라서
1 1 2 3 5 8 13 21 34 로 수열이 이어지면 기하급수적으로 커질 것이다. 피보나치 수열의 n번째를 구하기 위해선
작은 문제인 n-1번째 n-2번째를 구해야하며 그것들은 또 n-2 n-3 n-4 n-5 등을 계속 구해야 한다.

그런데 이걸 동적 프로그래밍으로 하지 않을 경우에, 즉 구해진 정답을 저장하고 바로 활용하는게 아니라 호출될때마다
일일히 계속 반복해나가는 방법으로 구한다면 계산이 너무 많아진다.
*/

//동적프로그래밍 없는 피보나치 함수 코드
#if 0
#include<iostream>
using namespace std;

int fibo(int N) {
	if (N == 1 || N == 2)	return 1;
	return fibo(N - 1) + fibo(N - 2);
}

int main() {
	cout << "몇 번째 피보나치 수를 알고 싶은지? ";
	int N = 0;
	cin >> N;
	int result = fibo(N);
	cout << result;
}
#endif

//동적 프로그래밍으로 구한 재귀적 피보나치 함수
//동적 프로그래밍은 어떻게 만들까? 간단하다 동적으로 배열에저장하고 동적으로 배열내용 쓰면된다. 
//똑같은 호출이 일어나지 않게 동적으로 저장된 이력이 있다면 바로 값을 반환하며 재귀를 막고 쓰면 된다.
#if 0
#include<iostream>
using namespace std;

//전역 배열 변수를 사용해도 되지만 참조로도 가능하기에 해보았다. 아마 호출이 잦을 수록 전역이 나을거다.
//참조형 매개변수인데 배열이다? 안에 있는 요소 개수까지 맞춰줘야 정확한 참조가 가능하다.
int fibo(int N, int(&dp)[101]) {
	if (N == 1 || N == 2)	return 1;
	if (dp[N] != 0) return dp[N];
	dp[N] = fibo(N - 1, dp) + fibo(N - 2, dp);
	return dp[N];
}

int main() {
	int dp[101] = { 0 };
	//피보나치 수열엔 0이 없기에 일단 가능한 선언 만약 0도 유효한 값이라면 체크를 위한 다른 방식이 필요할것

	cout << "몇 번째 피보나치 수를 알고 싶은지? ";
	int N = 0;
	cin >> N;
	int result = fibo(N, dp);
	cout << result;
}
#endif

//동적 프로그래밍으로 피보나치 수열 구현하기 (바텀업) 전역변수 사용해보기
//단순하게 재귀로 호출하는 것보다 원하는 횟수와 방향대로 반복이 일어나게 조건식을 잘짜야함.
#if 0
#include<iostream>
using namespace std;

int dp[101] = { 0 };

int fibo(int N) {
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < N + 1; i++) { //바텀업의 대표사례 
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[N];
}

int main() {

	cout << "몇 번째 피보나치 수를 알고 싶은지? ";
	int N = 0;
	cin >> N;
	int result = fibo(N);
	cout << result;
}
#endif
//반드시 dp테이블을 사용할 필요는 없다. 여기서는 배열이 유용하기에 공간복잡도를 늘리더라도 추가를 하였지만
//어떠한 경우에는 딕셔너리형이나 해쉬형을 활용할 수도 있다. 반드시 연속적일 필요 없이 좀 무작위하다면 고려해볼만하다.

/*<<2> <1로 만들기>>
정수 x가 주어질때 정수 x에 사용할 수 있는 연산은 다음과 같이 4가지이다.
1. x가 5로 나누어 떨어지면 5로 나눈다.
2. x가 3으로 나누어 떨어지면 3으로 나누다.
3. x가 2로 나누어 떨어지면 2로 나눈다.
4. x에서 1을 뺀다.

x를 1로 만들려고할때 연산 횟수의 최솟값을 출력하라.

입력조건
첫째 줄에 정수 x가 주어진다 3만 이하
출력조건
첫째 줄에 최솟값을 출력한다.

26 25 5 1

<접근방법>
이거는 수학적인 어떠한 접근으로 정당한 최적해가 나오기는 힘든거 같다. 26인데 여기에서 무슨 조건이 있다고
먼저 1을 뺀다는 접근이 가능한가? 28이라고 치자 1빼고 27 3나눠 9 3나눠 3 3나눠 1
2나눠 14 2나눠 7 1빼 6 3나눠 2 2나눠 1
21이라고 치자 1빼 20 5나눠 4 2나눠 2 2나눠 1
3나눠 7 1빼 6 3나눠 2 2나눠 1
52라고 치자 1빼 51 1빼 50 5나눠 10 5나눠 2 2나눠 1 -> 5
1빼 51 3나눠 17 1빼 16 1빼 15 5나눠 3 3나눠 1 ->6
2나눠 26 1빼 25 5나눠 5 5나눠 1 ->4

아무리 몇번씩 해봐도 왜 어쩔땐 앞에 2개를 빼고 3개를 빼서라도 5로나누는게 이득이고 어쩔땐 바로 2로 나누는게 이득인지
일반해를 구할 수 없으니까. 완전 탐색법이 필요한것, 그런데 그 완전탐색한 결과를 dp 테이블에 저장해서 계산 속도를 줄이는거지.

모든 경우의 수를 다 구하는 방법을 구현하기가 힘들다.. 스택구조의 재귀를 써보려고하니 오히려 더 복잡해질거 같다.
1턴 2턴 3턴마다 반복가지의 수는 4의 n승으로 증가할것이다. 그러다가 딱 1이 되는 경우의 턴을 반환하는 방법
그게 제일 나을거 같은데... 최악은 3만번인데 3만번까지 갈일이 없다. 왜냐하면 뭐가되었든 결국 5로 나눠지는 경우의 수에 걸리고
그렇게 되면 획기적으로 수가 줄어들기 때문이다. 

1턴에 5, 3, 2, 1이 돌고 2턴에 (5-5 5-3 5-2 5-1) (3-5 3-3 3-2 3-1) (2-5 2-3 2-2 2-1) (1-5 1-3 1-2 1-1) ...

*/
//재귀로 접근해볼려고 했으나 폐기
#if 0
#include<iostream>
using namespace std;

int arr[4] = { 1, 5, 3, 2 };
int dp[300000] = { 0 };
void solution(int n, int cnt) {
	
	if (n == 1) {
		cout << cnt;
	}
	else if (n < 1) {
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int x = n;
			if (i == 0) {
				x--;
				return solution(x, ++cnt);
			}
			else if (x % arr[i] == 0) {
				x /= arr[i];
				return solution(x, ++cnt);
			}
		}
	}
}

int main() {
	int N = 0;
	cout << "정수를 입력하면 최소 연산횟수를 출력한다. ";
	cin >> N;
    solution(N, 0);
}
#endif

//반복문으로 접근
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> repo;
int arr[4] = { 5, 3, 2, 1 };
int turn = 0;
int solution(int n) {
	//turn=0 일때는 n이 저장된다.
	vector<int> turnNum;
	turnNum.push_back(n);
	repo.push_back(turnNum);
	while (1)
	{
		turnNum.clear();
		//turn이 증가할때마다 2차원 벡터에서 속벡터 길이가 증가하므로 그 요소값에 대하여 4번씩 연산또 할거다.
		//turn=0일때 한번
		for (int i = 0; i < repo[turn].size(); i++) {
			for (int j = 0; j < 4; j++) {
				int temp = 0;
				if (j == 3) {
					temp = repo[turn][i]-1;
				}
				else if (repo[turn][i] % arr[j] == 0) {
					temp = repo[turn][i] / arr[j];
				}

				if (temp == 1) {
					return turn + 1;
				}
				else if(temp > 1){ turnNum.push_back(temp); }
			}
		}
		turn++;
		repo.push_back(turnNum);
	}
}
//어차피 어떠 연산루트 그러니까 무슨길을 따라서 왔는지는 중요하지 않다. 최소 턴이 언제인지만 반환하면 된다.
//따라서 각 턴에 발생하는 모든 연산의 결과를 매 턴을 키워드로 싸르기 저장하고 그 턴의 요소들로 또 싸그리 연산해서 
//저장하는 방식으로 해결한다. DP테이블을 사용한다고도 볼 수 있다.

int main() {
	int N = 0;
	cout << "정수를 입력하면 최소 연산횟수를 출력한다. ";
	cin >> N;
	cout << solution(N);
}
#endif

/* 고찰(책 문제해설)
잘 알려진 다이나믹 프로그램이 문제. 피보나치 수열을 도식화 했던 것처럼 문제를 도식화하는게 중요하다.
그 과정을 그림으로 그리는게 이해는 제일 빠르다.

처음에는 그림을 봐도 뭔말인지 이해할수 없었으나 영상까지 보고나서야 이해가 되었다.
https://www.youtube.com/watch?v=5Lu34WIx2Us&t=2607s

아닌것 같아도 이 문제는 점화식으로 표현할 수 있다. 6이라는 숫자가 있다고 치자 이것의 최적해는 2이다. 그냥 간단히 생각하면
6 - 2 - 1 로 3으로 나누고 2로 나누는 프로세스만으로 1을 도출한다. 이때 2를 보자 2의 최적해는 몇인가? 1이다 그냥 2로 나누면 된다.
1의 최적해는? 상수값 바로 0이다. 아무 연산도 필요없고 이미 정해져있다. 감이 오는가?
6의 최적해는 2의 최적해 +1이고 2의 최적해는 1의 최적해 +1이다. 
6에서 바로 2의 최적해로 도달한다는 생각은 어떻게 하는가? 그건 바로 할 수 없지만 완전탐색에서 이만한 쾌거가 없지 않은가?
그리고 적어도 6은 5로 나누어 떨어지지 않으므로 5의 최적해 3의 최적해 2의 최적해 중에서 최소값을 선택하면 올바른 루트가 되지 않을까?
근데 전부다 최적해는 1이므로 어떤 방법으로 가더라도 괜찮다.
f(12)
f(11)				                                                               f(6)				                   f(4)
f(10)				                                                               f(5)            f(3)      f(2)	   f(3)      f(2)
f(9)                                                      f(5)             f(2)    f(4)f(1)        f(2)f(1)  f(1)      f(2)f(1)  f(1)
f(8)                                            f(3)      f(4)f(1)         f(1)    f(3)      f(2)  f(1)                f(1)
f(7)                             f(4)           f(2)f(1)  f(3)      f(2)           f(2)f(1)  f(1)
f(6)                             f(3)     f(2)  f(1)      f(2)f(1)  f(1)           f(1)
f(5)               f(3)     f(2) f(2)f(1) f(1)            f(1)
f(4)f(1)           f(2)f(1) f(1) f(1)
f(3)      f(2)     f(1)
f(2)f(1)  f(1)
f(1)

스크립트로 노드를 표현할 길이 없어 이렇게 표현한다 복잡해 보이지만 f(12)를 찾기위한 여정을 전부 그렸다.
이걸 점화식으로 나타내면 f(n) = min(f(n-1), f(n/2), f(n/3), f(n/5)) + 1 이다.
n이 주어졌을때 n이 각 경우의 수를 충족만 한다면 그 경우의 수로 갔을때 최적해에 +1 만하면 n의 최적해가 나온다.
위의 f(12) = f(12/2)+1 = f(2)+2 = f(1)+3 = 3
그런데 가만 보면 엄청나게 중복적인 호출이 많이 생기고 있다. 그래서 dp테이블을 활용하는것 dp[30001] 만들고
각 인덱스가 n이 되면 f(1) = 0 넣고 f(2)= 1 들어가고 f(3)=1 들어가고 하도록 dp테이블을 짜면 
바텀업 형태로 올라가면서 최종적으로 n번째에 적은 반복횟수로 들어가게 된다.
*/

//책을 읽고 다시 쓰는 바텀업 1로 만들기 (책보기 전에 것도 답은 나온다. 하지만 속도가 이쪽이 빨라)
//4개의 값을 받아서 최소값으로 초기화하는 방법
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int min(int a, int b, int c, int d) {
	int temp1 = b, temp2 = d;
	if (a < b) temp1 = a;
	if (c < d) temp2 = c;
	if (temp1 < temp2) return temp1;
	else
	{
		return temp2;
	}
}

int dp[30001] = { 0 };
int arr[4] = { 5, 3, 2, 1 };
int solution(int n) {
	for (int i = 2; i < n + 1; i++) {
		int temp5 = 99999, temp3 = 99999, temp2 = 99999, temp1 = 99999;
		if (i % 5 == 0) temp5 = dp[i / 5] + 1;
		if (i % 3 == 0)	temp3 = dp[i / 3] + 1;
		if (i % 2 == 0) temp2 = dp[i / 2] + 1;
		temp1 = dp[i - 1] + 1;
		dp[i] = min(temp1, temp2, temp3, temp5);
	}
	return dp[n];
}

int main() {
	int N = 0;
	cout << "정수를 입력하면 최소 연산횟수를 출력한다. ";
	cin >> N;
	cout << solution(N);
}
#endif

//불필요한 연산을 좀 줄인버전 <1로 만들기>
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int dp[30001] = { 0 };

int solution(int n) {
	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] + 1; //일단 딱 1작은 걸로 초기화
		if (i % 5 == 0) dp[i] = min(dp[i],dp[i / 5] + 1);
		if (i % 3 == 0)	dp[i] = min(dp[i],dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i],dp[i / 2] + 1);
		//결국 dp[i] 최소 루트를 따라가서 저장하게 되어있다. 한번 저장한 dp[i]는 다시 저장하지 않고
		//호출해서 쓰기만 하는 동적프로그래밍 완수
	}
	return dp[n];
}

int main() {
	int N = 0;
	cout << "정수를 입력하면 최소 연산횟수를 출력한다. ";
	cin >> N;
	cout << solution(N);
}
#endif

/*<<3><개미전사>>
개미 전사는 부족한 식량을 충다하고자 메뚜기 마을의 식량창고를 몰래 공격하려고 한다. 
메뚜기 마을에는 여러 개의 식량창고가 있는데 식량창고는 일직선으로 이어져 있다. 각 식량창고에는
정해진 수의 식량을 저장하고 있으며 개미 전사는 식량창고를 선택적으로 약탈하여 식량을 빼앗을 예정이다.
이때 메뚜기 정찰병들은 일직선상에 존재한 식량창고 중에서 서로 인접한 식량창고가 공격받으면 바로 알아챌 수 있다.
따라서 개미 전사가 정찰병에게 들키지 않고 식량창고를 약탈하기 위해서는 최소한 한 칸이상 떨어진 식량창고를 약탈해야 한다.
예를들어 식량 창고 4개가 {1, 3, 1, 5}로 존재한다고 하자. 이때 개미전사들은 떨어져있는 3과 5를 선택하여 8개를 가져간다.

개미전사를 위해 식량창고 N개에 대한 정보가 주어지면 얻을 수 있는 식량의 최댓값을 구하는 프로그램 작성하시오.

입력조건
첫째 줄에 식량창고의 개수 N이 주어진다 3개이상 100개이하
둘째 줄에 공백으로 구분하여 식량창고에 저장된 식량의 개수 K가 주어진다. 1000이하
출려조건
첫째 주에 개미 전사가 얻는 식량 최대값.

<접근방법> 
첫번째 인덱스를 고르면 홀수 인덱스들만 두번째 인덱스를 고르면 짝수 인덱스들만 그리고 그 2개만 비교해서 출력하면 되는줄 알았는데..
생각해보니 3 1 1 5 같은 경우에는 첫번째 네번째 고르는게 답이다...
규칙성을 나타내기 어렵다면 모든 경우의 수를 탐색하는게 답인데 소문제가 큰 문제를 간소화 시킬 수 있는가?
배열의 순서가 중요하기에 정렬도 제한된다.
*/