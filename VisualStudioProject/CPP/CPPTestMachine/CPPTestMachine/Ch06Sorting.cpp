/*<1> 기준에 따라 데이터를 정렬
<정렬 알고리즘 개요>
정렬이란 데이터를 특정한 기준에 따라서 순서대로 나열하는 것.
정렬은 가장 많이 적용되는 알고리즘 중 하나. 이진 탐색을 할때도 정렬 전처리과정이 필요하다.
알고리즘의 효율성을 쉽게 이해할수 있어 앞부분에서 배우는 첫번째 알고리즘이기도 하다.

<선택 정렬>
정렬되지 않은 부분 정렬된 부분 두가지로 나누고 정렬되지 않은 부분에서 가장 작은 값을 정렬된 부분으로 하나씩 삽입하면
결국 오름차순으로 정렬된다.
1.최소값 구하기 2.맨 앞인덱스와 데이터 교환 3.정렬되지 않은 부분의 처음 인덱스가 하나 증가 4.교환하려는 인덱스가 하나증가
*/
//6.1 선택 정렬 구현
#if 0
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> array = { 7,5,9,0,3,1,6,2,4,8 };
	int min = 999999;
	int minIdx = 0;

	for (int startidx = 0; startidx < array.size(); startidx++) { //내부 요소의 개수만큼 반복하면서
		min = 999999;
		for (int i = startidx; i < array.size(); i++) { //내부에선 시작 지점을 1씩 증가하 반복 탐색한다.
			if (min > array[i]) {
				min = array[i];		minIdx = i;
			}
		}//내부 반복문이 끝나면 정렬되지 않은 부분중 가장 작은 값이 min에 저장되고 그때의 인덱스도 저장

		array[minIdx] = array[startidx]; //최소값이 들어있던 인덱스에 맨 처음 값을 넣고
		//미리 저장해둔 최소값을 맨처음 값에 넣으면 교환 완료.
		array[startidx] = min;
	}

	for (auto n : array) {
		cout << n << endl;
	}
}
#endif
/*고찰, 책의 예재를 보고
굳이 값을 저장할 필요없이 인덱스만을 저장하는 구조로도 접근하여 값비교가 가능하다는 것을 캐치했어야 한다.
*/

//책 6.1 선택 정렬 구현
#if 0
#include<iostream>
#include<vector>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {
	for (int i = 0; i < n; i++) { //총 원소개수만큼 반복할것이고
		int min_index = i; // 가장 작은 원소의 인덱스 일단은 처음에 접근할 인덱스로 i로 설정
		for (int j = i + 1; j < n; j++) {//i인덱스와 다음부터 비교의 대상
			if (arr[min_index] > arr[j]) {
				min_index = j;//직접 값을 저장할 필요 없이 인덱스 정보만 가지고 비교해서 인덱스 정보를 저장.
			}
		}
		//가장 작은 값의 인덱스를 찾았고 교환해서 저장할 i인덱스랑 비교해서 교환해야함.
		swap(arr[i], arr[min_index]); // 스와프 배열의 인덱스를 기반으로 두 개를 교환하는 함수
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
#endif

/* 삽입정렬
데이터를 하나씩 확인하며, 각 데이터를 적절한 위치에 삽입하면 어떨까?
무조건 n제곱번 정해진 횟수를 반복하며 일정한 속도로 움직이는 선택정렬과 달리. 동적으로 비교횟수가 결정된다.
미리 오름차순과 가까울 수록 훨씬 적은 움직임으로 완료가 일어난다.
1.맨 왼쪽은 정렬된 부분으로 반복이 일어날 수록 정렬된 부분은 하나씩 늘어나 결국 모든 요소가 정렬된다.
2. 첫 번째 데이터는 그 자체로 정렬되어 있다고 판단하고, 두 번째 데이터부터 
첫번째 데이터의 왼쪽에 들어가야할지 오른쪽에 들어가야할지 판단한다.
3. 이어서 세번째 데이터를 가지고 거꾸로 두번째 데이터 첫번째 데이터랑 비교하면서 어디에 들어갈지를 판단한다.
4. 이어서 네번째 데이터이다. 인덱스를 거꾸로 줄여가면서 자기보다 작은 값이 나올때까지 비교하면된다. 왜냐
이미 자기 왼쪽에 있는 비교 데이터들은 전부 오름차순으로 이미 정렬되어 있는 상태이기 때문에 자기보다 큰 녀석들을 지나쳐와서 
처음으로 자기보다 작은 데이터를 만난다면 바로 그자리가 그 오른쪽이 자기보다 작은건 왼쪽에 있고 자기보다 큰건 오른쪽에 있는
바로 자기의 자리이기 때문이다.
*/
//6.3 삽입정렬 구현
//구현의 어려움
//1. 삽입을 한다면 뒤쪽으로 밀려야되는데 그것을 어떻게 구현할까?
#if 0
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> array = { 7,5,9,0,3,1,6,2,4,8 };
	for (int i = 1; i < array.size(); i++) {
		for (int j = i-1; j >= 0; j--) {
			if (array[j] < array[i]) {
				
			}
		}//j를 0까지해도 작은 값을 못찾았으면 
	}
}
#endif
//고찰(실패)
// 배열구조에서 인덱스 옮기는 방법을 못하겠다.
// 책에서 말한 삽입정렬을 보니 우리의 개념상으로는 작은것을 찾으면 그 인덱스에 삽입하고
// 오른쪽을 밀어내는걸 개념상으로 생각했지만, 구현상으로는 그렇게 어려운 조건을 만들기는 어렵다
// 따라서 계속해서 스왑을 여러번 하는걸로 구현한다.
// i는 1부터 증가하고 j는 i부터 시작하며 1씩 감소한다.
// 만약 j-1인덱스와 j를 비교할때 왼쪽이 더 크면 스왑하면 된다.
// 이렇게 진행하다가 왼쪽이 더 작은걸 만날때는 안쪽 반복문 탈출로 반복중지하면 원하는 삽입정렬이 구현.
//6-3 책 삽입 정렬
#if 0
#include<iostream>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {
	for (int i = 1; i < n; i++) {
		// 인덱스 i부터 1까지 감소하며 반복하는 문법
		for (int j = i; j > 0; j--) {
			// 한 칸씩 왼쪽으로 이동
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
			// 자기보다 작은 데이터를 만나면 그 위치에서 멈춤
			else break;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
#endif

/*<퀵 정렬>
퀵 정렬은 합병정렬과 함께 가장 빠른 알고리즘 중 하나이다.
핵심은 1. 피벗 2. 분할 3. 재귀 이다.
1. 피벗은 기준이 되는 원소로 일반적으로 첫번째 원소가 피벗이되며, 왼쪽 인덱스와 오른쪽 인덱스가
동시에 움직인다. 피벗을 기준으로 피벗보다 큰원소를 왼쪽에서 찾고 피벗보다 작은 원소를 오른쪽에서 찾는다.
그렇게 찾으면 그 둘을 교환한다. 그 전에 두 인덱스가 서로 교차하게 되면 교환 과정없이 첫번째 요소인
피벗을 오른쪽부터 찾아온 작은 값과 교환을한다. 피벗이 찾아간 자리는 왼쪽에는 피벗보다 전부 작은값이고
오른쪽은 피벗보다 전부 큰값인 셈이 된다.
2. 개념적으로 피벗을 기준으로 분할이 된 셈이다. 왼쪽에서 퀵정렬 오른쪽에서 퀵정렬이 이루어져야한다.
3. 재귀에는 반드시 종료조건이 있어야 한다. 만약 퀵정렬을 수행하려는 데이터의 개수가 1개라면
종료하는 방식으로 짜면 완성.
*/
#if 0
#include<iostream>
#include<vector>
using namespace std;

vector<int> arr = { 7,5,9,0,3,1,6,2,4,8 };
void quickSort( int ln, int rn) {
	if (ln == rn) {
		return;
	}
	int lp = ln + 1;
	int rp = rn;
	while (true) {
		for (; lp<rn;lp++) {
			//arr[lp]가 피벗보다 큰 경우에 반복 종료
			if (arr[lp] > arr[ln]) { break; }
		}
		for (; rp > ln; rp--) {
			 //arr[rp]가 피벗보다 작은 경우에 반복 종료
			if (arr[rp] < arr[ln]) { break; }
		}
		if (lp > rp) {
			swap(arr[ln], arr[rp]);
			break;
		}
		else {
			swap(arr[lp], arr[rp]);
		}
	}
	quickSort( ln, lp-1);
	quickSort( lp + 1, rn);
	return;
}
int main()
{
	
	quickSort( 0, arr.size()-1);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}
#endif
//고찰(실패)
//인덱스 오류가 계속 나고 중간 중간 교환되지 않는 문제가 발생
//