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
	if (ln >= rn) {
		return;
	}
	int lp = ln + 1;
	int rp = rn;
	while (true) {
		while (lp<=rn&&arr[lp] <= arr[ln]){
			//arr[lp]가 피벗보다 큰 경우에 반복 종료
			lp++;
		}
		while (rp>ln&&arr[rp] >= arr[ln]){
			 //arr[rp]가 피벗보다 작은 경우에 반복 종료
			rp--;
		}
		if (lp > rp) {
			swap(arr[ln], arr[rp]);
			break;
		}
		else {
			swap(arr[lp], arr[rp]);
		}
	}
	quickSort( ln, rp-1);
	quickSort( rp + 1, rn);
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
//범위 체크 문제에서 오류가 났다. 디버깅과정을 통해서도 답이 나오지 않았다.
//책의 내용을 보고나서 같은 논리로 짜도 오류가 반복되었다. 천천히 디버깅을 하면 오류가 날 일이 없는데, 그냥 프로그램을 돌리면
//범위 초과 오류가 나는 현상이다.
//for문을 사용하면 적절하지 않은것 같아 while문으로 바꾸어도 여전히 범위 초과 오류가 난다.
//
//최종적으로 피벗과 교환하는 인덱스는 right 인덱스이다. 이 right 인덱스는 그래서 start 인덱스보다 절대 작아져서는 안된다.
//하지만 left인덱스는 다르다. left는 마지막 인덱스보다 커져야 될 때도 있는가? 그렇다. 반드시 커져야 한다. 예를들어
// 6 7 짜리를 돌때. start=0 end=1 left=1 right=1 이다. 이때 left가 right를 넘어서지 않는다면 종료되지 않는다. 그렇기에 
//left는 범위를 넘어도 되고 right는 범위를 넘지 말게 설계해야한다.

/*책 6.4 퀵정렬*/
#if 0
#include<vector>
#include<iostream>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

void quickSort(int* arr, int start, int end) { //포인터 매개변수인 것은 저 이름의 주소를 찾아가서 사용할 거라는 뜻
	if (start >= end) return; // 원소가 1개인 경우 종료
	//start가 end보다 커지는 경우가 있을까?
	//실제로 start == end 하게 되면 무한 재귀를 탈출 할 수 없다. 왜냐하면
	//분할 이후 재귀를 소환하는건 right-1과 right +1 을 하기 때문.
	//예를들어 2개짜리 배열에서 피벗은 1인덱스로 가게되어 분할하여 나눠서 호출하게 될경우
	//quickSort(arr, 0, 1-1); quickSort(arr, 1+1, 1); 이 되는데 이때 오른쪽부분 호출에서 커지게 된다.

	int pivot = start; // 피벗은 첫 번째 원소
	int left = start + 1;
	int right = end;
	//여기까지는 내가 한 것과 동일.

	while (left <= right) {
		//반복종료 조건도 나와 동일함. left가 right를 지나쳐 넘어설때 종료.

		// 피벗보다 큰 데이터를 찾을 때까지 반복
		while (left <= end && arr[left] <= arr[pivot]) left++;
		//여기부터 디테일하게 다르다. 나는 left < end 까지만 반복했고, arr[left] > arr[pivot]이면 종료하는 조건은 같다.
		//왜 end와 같은 인덱스까지 반복을 진행했을까? 마지막 원소도 비교의 대상이기 때문이다. 내가 마지막 원소를 비교하지 않은건
		//범위 오버플로를 인식한 대처였지만 논리오류의 원인이었다. 실제 left는 end 이상을 넘어서 증가하지 않게 된다.

		// 피벗보다 작은 데이터를 찾을 때까지 반복
		while (right > start && arr[right] >= arr[pivot]) right--;

		// 엇갈렸다면 작은 데이터와 피벗을 교체
		if (left > right) swap(arr[pivot], arr[right]);
		// 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
		else swap(arr[left], arr[right]);
		//여기까지도 오류가 없다.
	}
	// 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);
	//여기서 나는 right가 아닌 left로 피벗을 보냈다고 착각해서 구현에 실수가 있었다.

	//여기까지 논리는 다 같은데 이상하게 범위 오버플로우 오류가 발생한다.
}

int main(void) {
	quickSort(arr, 0, n - 1); //정렬하고자하는 배열, 첫번째 인덱스, 마지막 인덱스
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
#endif

/*계수 정렬
원리는 간단하다. 정수데이터의 배열이 있을때 0~ 최대값으로 범위가 정해져 있다면, 최대값+1개의 요소를 갖는 검사리스트를 생성하고
주어진 배열을 0인덱스부터 길이까지 탐색하면서 각각 들어있는 값을 검사리스트의 인덱스로 사용하여 카운트를 '계수'한다.
그래서 카운트 정렬 계수 정렬 이다.
주어진 배열을 선형탐색하는 N, 범위만큼 요소의 개수가 있는 계수리스트 선형탐색 K번 탐색하면서 각 인덱스의 요소값이 인덱스 갯수가 되어 출력

하지만 공간복잡도에서만큼은 자유로울순 없는 것은 계수리스트 자체가 필요하기 때문이다.
그리고, 정수 자료형에만 적용이 가능하며, 최대값과 최소값의 간극이 클 수록 그런데 요소의 개수는 적을 수록 비효율적으로 퇴색된다.
왜냐하면 n+k 만큼의 시간복잡도를 갖는데, n제곱보다 오히려 더 커질 수 도 있기 때문이다.
*/
#if 0
#include<vector>
#include<iostream>
using namespace std;
auto countSort(vector<int> arr) {
	cout << "0~최대값의 배열을 정렬하는 계수 정렬" << endl;
	cout << "최대값을 입력하세요." << endl;
	int k = 0;
	cin >> k;
	vector<int> array(k + 1);
	vector<int> result;
	for (auto n : arr) {
		array[n]++;
	}
	for (int i = 0; i < k + 1; i++) {
		if (array[i] != 0) {
			for (int j = 0; j < array[i]; j++) {
				result.push_back(i);
			}
		}
	}
	return result;
}

int main() {
	vector<int> arr = { 7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2 };
	auto arr2 = countSort(arr);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < arr2.size(); i++) {
		cout << arr2[i] << ' ';
	}
}
#endif
/*C++의 sort는 알고리즘 라이브러리에 있다.
*/
#if 0
#include<iostream>
#include<algorithm>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
#endif
/*코딩 테스트에서 정렬 알고리즘이 사용되는 경우
1. 정렬 라이브러리를 사용해서 푸는 문제
2. 정렬 알고리즘의 원리에 대해 물어보는 문제
3. 더 빠른 정렬이 필요한 문제*/

/*<2> 위에서 아래로
하나의 수열에는 다양한 수가 존재한다. 이러한 수는 크기에 상관없이 나열되어 있다. 이 수를 큰 수 부터 작은 수의 순서로
정렬해야 한다. 수열을 내림차순으로 정렬하는 프로그램을 만드시오.
입력조건: 첫째줄에 수열에 속해 있는 수의 개수 N이 주어진다. 500이하
둘째 줄에 N+1번째 줄까지 N개의 수가 입력된다. 수의 범위는 십만이하의 자연수이다.
출력조건: 수열이 내림차순으로 정렬된 결과를 공백으로 출력. 동일한 수의 순서는 자유롭게 출력
입력예시
3
15
27
12
출력예시
27 15 12

<접근방법>
오름차순의 대소 비교조건을 반대로 한다. 1.선택정렬 2.삽입정렬 3.퀵정렬 4.알고리즘 라이브러리
*/

//1.선택정렬
// 일정한 속도로 반복, 정렬되지 않은 부분과 정렬된 부분으로 구별되고 각자 하나씩 증가감소 
// 최대값을 찾아서 하나씩 교환해 넣으면 해결
#if 0
#include<iostream>
#include<vector>
using namespace std;

auto selectSort(vector<int> arr) {
	vector<int> answer = arr;
	int maxIdx;
	for (int i = 0; i < arr.size(); i++) { //저장할 인덱스 하나씩 증가
		maxIdx = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (answer[j] > answer[maxIdx]) {
				maxIdx = j;
			}
		}//내부 반복문이 돌고나면 i인덱스에 저장할 maxidx를 교환한다.
		swap(answer[i], answer[maxIdx]);
	}
	return answer;
}

int main() {
	int N;
	cout << "요소 개수" << endl;
	cin >> N;
	cout << "차례대로 숫자 입력" << endl;
	vector<int> arr(N);
	for (auto &n : arr) {
		cin >> n;
	}
	auto result = selectSort(arr);

	for (auto n : result) {
		cout << n << ' ';
	}

}
#endif
//고찰
//메인함수에서 정의한 배열을 함수로 인자로 보낼때 참조형이 아닌 복사형으로 가져가기때문에 생기는 현상을 어떻게 참조형으로
//바꿔야할지는 몰라서 추가로 리스트를 만들어서 반환하고 받음.
//벡터 자료형을 안쓰면 동적으로 배열을 선언하는 방법을 아직 잘 모르겠음.

//2. 삽입정렬
//선택정렬과 비슷한점은 정렬된 부분과 정렬되지 않은 부분이 나뉜다는 점.
//처음 시작할때 맨 왼쪽 인덱스는 정렬되어 있는것으로 간주 따라서 1부터 시작한다. 1의 밸류가 0의 밸류보다 작은지 큰지를 비교하여
//작다면 swap 작지 않다면 거기서 종료 왜? 정렬되어있는 부분에서 이미 정렬되어 속하게 되어짐.
//이 로직대로 내림차순으로 바꿈.
#if 0
#include<iostream>
#include<vector>
using namespace std;

auto insertSort(vector<int> arr) {
	vector<int> answer =arr;
	for (int i = 1; i < arr.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (answer[j] > answer[j - 1]) {
				swap(answer[j], answer[j - 1]);
			}
			else {
				break;
			}
		}
	}
	return answer;
}

int main() {
	int N;
	cout << "요소 개수" << endl;
	cin >> N;
	cout << "차례대로 숫자 입력" << endl;
	vector<int> arr(N);
	for (auto& n : arr) {
		cin >> n;
	}
	auto result = insertSort(arr);

	for (auto n : result) {
		cout << n << ' ';
	}
}
#endif

//3. 퀵정렬
//첫번째 요소를 피벗으로 정하고 왼쪽인덱스는 피벗값보다 큰 요소를 찾을때까지 증가하고 오른쪽인덱스는 피벗값보다 작은 요소를 
//찾을때까지 감소하면서 그렇게 반복이 끝나면 왼쪽 인덱스와 오른쪽인덱스를 비교. 이때 왼쪽이 오른쪽보다 커졌으면 피벗보다 작은 요소인
//오른쪽값을 피벗값과 교환하고, 오른쪽 인덱스를 기준으로 왼쪽 오른쪽 재귀를 호출한다.
//이때 교환하는 오른쪽값은 인덱스 초과가 일어나면 안되고, 왼쪽 인덱스는 오른쪽보다 커져야되는게 종료 조건이므로 인덱스범위초과허용
//이걸 내림차순으로
#if 0
#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> answer;
vector<int> arr;

void quickSort(int start, int end) {
	if (start >= end) {
		return;
	}

	int left = start + 1;
	int right = end;
	int pivot = start;

	while (left <= right) {
		while (left <= end &&arr[left] >= arr[pivot]) { 
			//내림차순으로 정렬해야하기에 왼쪽엔 큰값이 와야됨. 따라서 작을때까지 반복
			//그래서 왼쪽값과 피벗값을 비교해서 왼쪽값이 더 크다면 그냥 지나쳐간다. 왜냐하면 작은값을 오른쪽으로 넘겨야되서
			left++;
		}
		while (right > start &&arr[right] <= arr[pivot]) {
			//그런데 반복조건이 마냥 값비교만 하면 되는건 아니다. 무한반복과 오버플로우를
			//방지하기 위해 추가 종료조건을 넣어줘야된다. 바로 인덱스 범위 체크이다. 그런데 교환하는건 피벗보다 큰값을
			//가리키는 right와 바꿀것이기때문에 right 인덱스의 범위를 1개 더 줄이는걸로 제약.
			right--;
		}
		if (left > right) {
			swap(arr[pivot], arr[right]);
		}
		else {
			swap(arr[left], arr[right]);
		}
	}
	quickSort( start, right - 1);
	quickSort( right + 1, end);

	return;
}

int main() {
	cout << "요소 개수" << endl;
	cin >> N;
	cout << "차례대로 숫자 입력" << endl;
	vector<int>temp(N);
	arr = temp;
	for (auto& n : arr) {
		cin >> n;
	}
    quickSort( 0, N-1);

	for (auto n : arr) {
		cout << n << ' ';
	}
}
#endif
/*고찰
left++ right--에서 햇갈림
*/

//4. 알고리즘 라이브러리
// 알고리즘 라이브러리에 sort함수 사용, 여기에 컴패어 함수를 정의해서 커스터마이징 할 수 있다.
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> answer;
vector<int> arr;

//내림차순을 위한 컴패어 함수
bool comp(int a, int b) {
	return a > b;
}

int main() {
	cout << "요소 개수" << endl;
	cin >> N;
	cout << "차례대로 숫자 입력" << endl;
	vector<int>temp(N);
	arr = temp;
	for (auto& n : arr) {
		cin >> n;
	}
	sort(arr.begin(), arr.end(), comp);

	for (auto n : arr) {
		cout << n << ' ';
	}
}
#endif

/*<3> 성적이 낮은 순서로 학생 출력하기
N명의 학생 정보가 있다. 학생 정보는 학생의 이름과 학생의 성적으로 구분된다. 
각 학생의 이름과 성적 정보가 주어졌을 때 성적이 낮은 순서대로 학생의 이름을 출력하는 프로그램을 작성하시오.
입력조건
첫째 줄에 학생의 수 N이 입력된다. 십만이하
둘쨀 N+1째 줄까지 학생의 이름을 나타내는 문자열 A와 학생의 성적을 나타내는 정수 B가 공백으로 구분되어 입력된다.
문자열 A의 길이와 학생의 성적은 100이하의 자연수이다.
출력조건
성적이 낮은 순서대로 출력한다. 성적이 동일한 학생들의 순서는 자유롭게 출력

<접근방법>
이름과 점수의 관계성을 연결시켜 놓는게 필요하다. pair 자료형 map 자료형 등이 있는데 여기서는 pair면 충분할듯
그렇게해서 1.선택정렬 2.삽입정렬 3.퀵정렬 4.sort라이브러리
*/
//1.선택정렬
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;

auto selectSort(vector<pair<string, int>> &(stScore)) { //참조형 매개변수의 선언방법
	for (int i = 0; i < stScore.size(); i++) {
		int min = INT_MAX;
		int minIdx = 0;
		for (int j = i; j < stScore.size(); j++) {
			if (stScore[j].second < min) {
				min = stScore[j].second;
				minIdx = j;
			}
		}
		swap(stScore[i], stScore[minIdx]);
	}

	return;
}

int main() {
	int N;
	cout << "원소의 개수 N을 입력하라: ";
	cin >> N;
	vector<pair<string, int>> stScore(N);
	cout << "학생 이름과 점수를 공백으로 구별하여 입력하고 각 원소는 엔터로 구별한다." << endl;
	string tString;
	int tScore;
	for (int i = 0; i < stScore.size(); i++) {
		cin >> tString;		cin >> tScore;
		stScore[i].first = tString;
		stScore[i].second = tScore;
	}
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;
	selectSort(stScore);
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;

}
#endif

//2. 삽입정렬
#if 0
#include<iostream>
#include<vector>
using namespace std;

void insertSort(vector<pair<string, int>>(&stScore)) {
	int left = 0;
	int right = stScore.size() - 1;
	for (int i = 1; i < stScore.size(); i++) {
		for (int j = i; j > 0; j--) {//어차피 탐색인덱스인 j는 --할것이다.
			if (stScore[j].second > stScore[j - 1].second) { 
				//만약 정렬된부분을 탐색하다 자기보다 작은 녀석을 만나면 종료
				break;
			}
			else {
				swap(stScore[j], stScore[j - 1]);
			}
		}
	}
}

int main() {
	int N;
	cout << "원소의 개수 N을 입력하라: ";
	cin >> N;
	vector<pair<string, int>> stScore(N);
	cout << "학생 이름과 점수를 공백으로 구별하여 입력하고 각 원소는 엔터로 구별한다." << endl;
	string tString;
	int tScore;
	for (int i = 0; i < stScore.size(); i++) {
		cin >> tString;		cin >> tScore;
		stScore[i].first = tString;
		stScore[i].second = tScore;
}
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;
	insertSort(stScore);
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;
}
#endif
//3. 퀵정렬
#if 0
#include<iostream>
#include<vector>
using namespace std;
void quickSort(vector<pair<string, int>> (&stScore), int start, int end) {
	//만약 left가 더 커진채로 들어오는게 있다면 걸러야겠지
	if (start >= end) {
		return;
	}
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right) {
		while (left <= end && stScore[pivot].second >= stScore[left].second) {
			left++;
		}
		while (right > start && stScore[pivot].second <= stScore[right].second) {
			right--;
		}
		if (left > right) {
			swap(stScore[pivot], stScore[right]);
			break;
		}
		else {
			swap(stScore[left], stScore[right]);
		}
	}
	quickSort(stScore, start, right - 1);
	quickSort(stScore, right + 1, end);
}

int main() {
	int N;
	cout << "원소의 개수 N을 입력하라: ";
	cin >> N;
	vector<pair<string, int>> stScore(N);
	cout << "학생 이름과 점수를 공백으로 구별하여 입력하고 각 원소는 엔터로 구별한다." << endl;
	string tString;
	int tScore;
	for (int i = 0; i < stScore.size(); i++) {
		cin >> tString;		cin >> tScore;
		stScore[i].first = tString;
		stScore[i].second = tScore;
}
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;
	quickSort(stScore, 0 , N-1);
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;
}
#endif
//4. sort라이브러리
#if 0
#include<iostream>
#include<vector>
using namespace std;
int main() {

}
#endif