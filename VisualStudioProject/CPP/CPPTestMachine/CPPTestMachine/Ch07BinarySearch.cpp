/* <1> 범위를 반씩 자르며 나아가는 탐색

먼저 다른 탐색법을 알기 전에 가장 먼저 알아야되는 기초는 순차탐색이다.
순차탐색은 너무 많은 자료에는 적합하지 않지만 해야만 하는 경우에는 해야한다.
리스트 자료형에서 특정 원소가 몇개인지를 찾는 연산인 count()를 수행할때 이런 순차탐색이
사용된다. 무작위로 펼쳐진 자료들에서 특정 자료를 세는 특별한 규칙이 없는 한 이 방법이 유일한 일반해이다.

이제 이진탐색을 알아본다. 기본적으로 정렬되어있다는 가정이 되어 있어야 의미가 있는 탐색법이다.
핵심 위치 인덱스는 시작점 중간점 끝점이다. 중간점의 원소를 비교하여 타겟보다 작으면 중간점 끝점으로 범위설정을 하고
타겟보다 크면 시작점 중간점으로 범위설정을 하여 다시 중간점을 기준으로 찾는다. 그러다가 원소를 발견하면 반환하고
결국 중간점을 구할 수 없는 경우까지 가버리면 찾을 수 없다고 반환한다.
이진탐색을 구현하는 방법 2가지. 재귀와 반복문이 있다. 재귀는 보기에는 편하지만 스택을 많이 차지하고 호출자를 사용하기에
느려지는 단점이 있고, 반복문은 데이터의 조건이 많아질 수록 보기 어려워질 가능성이 농후하다.
*/
//1-1 재귀 이진탐색 (시도 실패)
#if 0
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int midIdx;

int binarySearch(vector<int> arr, int start, int end, int target) {
	if (start > end) {
		return -1;
	}

	if (arr[midIdx] == target) {
		return midIdx;
	}
	else if (arr[midIdx] > target) {
		midIdx = (start + midIdx - 1) / 2;
		binarySearch(arr, start, (start + end - 2) / 2, target);
	}
	else if (arr[midIdx] < target) {
		midIdx = (midIdx + 1 + end) / 2;
		binarySearch(arr, (start + end + 2) / 2, end, target);
	}
}

int main()
{
	vector<int> array = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int target;
	cout << "찾으려는 원소 입력하세요 : ";
	cin >> target;

	midIdx = (0 + 15 - 1) / 2;
	auto result = binarySearch(array, 0, 15 - 1, target);
	cout << result;

}

#endif
/*고찰(실패 원인)
재귀적으로 호출하는것 까지는 맞았고 논리적 구조도 이상은 없지만 
결국 반환하는 것 없이 끝나느 함수가 되어버린다.
else if문을 통해 계속 재귀가 일어나지만 그래서 결국 가장 바깥쪽에 있는 함수가 무엇을 반환하는가?
반환하는것 없이 그냥 재귀종료자 발동하면 종료되는거다.
재귀문을 그냥 호출하는게 아니라 return으로 호출해야한다. 그래야 그 재귀의 반환이 바깥쪽 재귀호출함수의
반환값이 되는 것이다.
*/

//1-1 재귀 이진탐색 (책보고 수정보완)
#if 0
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int midIdx;

int binarySearch(vector<int> arr, int start, int end, int target) {
	if (start > end) {
		return -1;
	}

	if (arr[midIdx] == target) {
		return midIdx;
	}
	else if (arr[midIdx] > target) {
		midIdx = (start + midIdx - 1) / 2;
		return binarySearch(arr, start, (start + end - 2) / 2, target);
	}
	else if (arr[midIdx] < target) {
		midIdx = (midIdx + 1 + end) / 2;
		return binarySearch(arr, (start + end + 2) / 2, end, target);
	}
}

int main()
{
	vector<int> array = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int target;
	cout << "찾으려는 원소 입력하세요 : ";
	cin >> target;

	midIdx = (0 + 15 - 1) / 2;
	auto result = binarySearch(array, 0, 15 - 1, target);
	cout << "배열의 인덱스 값은 : " << result;

}

#endif

//1-2 반복문으로 이진탐색 구현
#if 0
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int binarySearch(vector<int> arr, int target) {
	int start = 0;
	int end = arr.size() - 1;
	int midIdx = 0;

	while (start <= end) {
		midIdx = (start + end) / 2;
		if (arr[midIdx] == target) {
			break;
		}
		else if(target > arr[midIdx]) {
			start = midIdx + 1;
		}
		else if (target < arr[midIdx]) {
			end = midIdx - 1;
		}
	}
	return midIdx;
}

int main()
{
	vector<int> array = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int target;
	cout << "찾으려는 원소 입력하세요 : ";
	cin >> target;

	auto result = binarySearch(array, target);
	cout << "배열의 인덱스 값은 : " << result;
}
#endif

/*코딩테스트에서 이진탐색
이진탐색의 원리는 원초적이고 간단하지만, 실제 코딩테스트에서 구현하라고 하면 구현난이도가 높은 편
단순히 정수형탐색 문제가 나오는것 뿐만 아니라 자료형이 복잡해지고 그리디 알고리즘 등 여러 개념이 섞이기
시작하면 이진탐색을 얼마나 잘 이해하고 있냐에 따라 시간단축량이 달라진다. 이진탐색은 그냥 생각 없이
구현 가능할 정도로 형태를 외우고 있는게 유리하다.*/

/*<트리 자료구조>
데이터베이스는 기본적으로 트리자료구조를 바탕으로 데이터를 저장한다. 따라서 검색에서 상당한 속도적 이점을
가지게 된다. 트리 자료구조는 노드와 노드간에 부모노드 자식노드의 관계를 지니며 이 사이에 유의미한 규칙들을
유지함으로서 자료관리에 효과를 높인다.

<이진 탐색 트리>
트리 자료구조중에 가장 간단한 트리이다. 왼쪽자식노드 < 부모노드 < 오른쪽자식노드 의 규칙성을 유지한채로
저장하는 트리구조이다. 이 트리구조를 탐색하는 방법은 일단 타겟을 부모노드와 비교하고 대소관계에 따라
어느쪽 자식노드에 저장할지를 결정하는 탐색법을 따른다.
루트 노드부터 시작해서 타겟과 일치하는 노드를 찾을때까지 반복하는데 결국 자식노드가 없을 지경까지 가면
원소가 없는 것이므로 탐색을 종료한다.
*/

/*<2> 부품 찾기
동빈이네 전자매장에는 부품이 N개있다. 각 부품은 정수 형태의 고유한 번호가 있다.
어느 날 손님이 M개 종류의 부품을 대량으로 구매하겠다며 당일 날 견적서를 요청했다. 동빈이는 때를 놓치지 않고
손님이 문의한 부품 M개 종류를 모두 확인해서 견적서를 작성해야 한다. 이때 가게 안에 부품이 모두 있는지
확인하는 프로그램을 작성해보자. 
예를 들어 가게의 부품이 총 5개일때 부품 번호가 다음과 같다.
N=5
8, 3, 7, 9, 2
손님은 총 3개의 부품이 있는지 확인 요청했다.
M=3
5, 7, 9
이때 손님이 요청한 부품을 순서대로 확인해 부품이 있으면 yes 없으면 no 출력한다.

입력조건
첫째 줄에 정수 N이 주어진다. 백만 이하
둘째 줄에 공백으로 구분하여 N개의 정수가 주어짐 백만 이하
셋째 줄에 정수 M이 주어진다. 십만 이하
넷째 줄에 공백으로 구분하여 M개의 정수가 주어진다. 백만 이하
출력 조건
첫째 줄에 공백으로 구분하여 각 부품의 존재여부가 yes or no로 나옴

<접근방법>
일단 이분탐색 문제인건 둘째치고 항상 입력자료양이 많을 수록 선형탐색은 배재해도 된다.
어차피 시간초과가 날것이기 때문이다.
같은 논리의 탐색을 여러번 반복 할 것이기 때문에 이진탐색을 위해선 무조건 정렬이 되어 있어야지
*/
#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void solution(vector<int> store, vector<int> findList) {
	sort(store.begin(), store.end());

	for (auto n : findList) {
		int start = 0;
		int end = store.size() - 1;
		int mid = 0;
		while (1) {
			if (start > end) {
				cout << "no ";
					break;
			}
			mid = (start + end) / 2;
			if (n == store[mid]) {
				cout << "yes ";
				break;
			}
			else if (n < store[mid]) {
				end = mid - 1;
			}
			else if (n > store[mid]) {
				start = mid + 1;
			}
		}
	}
}

int main() {
	int N = 0;
	cout << "전체 부품의 개수 N 입력. N : ";
	cin >> N;
	vector<int> store(N);
	cout << "부품을 공백으로 구별하여 N개의 부품을 입력하라." << endl;
	for (auto& n : store) {
		cin >> n;
	}
	int M = 0;
	cout << "찾고자 하는 부품의 개수 M 입력. M : ";
	cin >> M;
	vector<int> findList(M);
	cout << "M개의 찾고자하는 부품을 공백으로 구별하여 입력하라." << endl;
	for (auto& n : findList) {
		cin >> n;
	}

	solution(store, findList);
}
#endif
/*고찰(책 내용)
생각보다 다양한 방법으로 풀 수 있다. 책은 계수 정렬과 집합 자료형을 활용한 제시도 있다.
직접 구현해본다.*/

//계수정렬 풀이
//아마 계수 정렬을 위한 계수 리스트를 만들고 찾고자 하는 원소의 계수값이 있는지로 예스 노를 출력하는 방법일것.
#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void countSolution(vector<int> store, vector<int> findList) {
	vector<int> countList(100001);

	for (auto n : store) {
		countList[n]++;
	}
	for (auto n : findList) {
		if (countList[n] != 0) {
			cout << "yes ";
		}
		else {
			cout << "no ";
		}
	}
}

int main() {
	int N = 0;
	cout << "전체 부품의 개수 N 입력. N : ";
	cin >> N;
	vector<int> store(N);
	cout << "부품을 공백으로 구별하여 N개의 부품을 입력하라." << endl;
	for (auto& n : store) {
		cin >> n;
	}
	int M = 0;
	cout << "찾고자 하는 부품의 개수 M 입력. M : ";
	cin >> M;
	vector<int> findList(M);
	cout << "M개의 찾고자하는 부품을 공백으로 구별하여 입력하라." << endl;
	for (auto& n : findList) {
		cin >> n;
	}

	countSolution(store, findList);
}
#endif

//집합 자료형
//집합 자료형 풀이는 집합은 중복을 허용하지 않는다는 방법을 이용한 것이다. 이것은 집합에 의해 원소 감소 효과를
//노릴 수 있으며, 어차피 존재하는지만 반환하기에 적합하다고 볼 수 있다.
#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

void setSolution(set<int> store, vector<int> findList) {
	for (auto n : findList) {
		if (store.find(n) != store.end()) {
			cout << "yes ";
		}
		else {
			cout << "no ";
		}
	}
}

int main() {
	int temp;
	int N = 0;
	cout << "전체 부품의 개수 N 입력. N : ";
	cin >> N;
	set<int> store;
	cout << "부품을 공백으로 구별하여 N개의 부품을 입력하라." << endl;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		store.insert(temp);
	}
	int M = 0;
	cout << "찾고자 하는 부품의 개수 M 입력. M : ";
	cin >> M;
	vector<int> findList;
	cout << "M개의 찾고자하는 부품을 공백으로 구별하여 입력하라." << endl;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		findList.push_back(temp);
	}

	setSolution(store, findList);
}
#endif
/*고찰(인터넷 서칭)
set은 그 자체로 이미 이진탐색 트리를 구성한다. 키값과 밸류값을 자체적으로 가지면서 규칙을 유지하며
저장되고, 내부함수 find()는 이진탐색의 수행속도를 갖는다.
*/

/*<3> 떡볶이 떡 만들기
오늘 동빈이는 여행가신 부모님을 대신해서 떡집 일을 하기로 했다. 오늘은 떡볶이 떡을
만드는 날이다. 동빈이네 떡볶이 떡은 재밌게도 떡볶이 떡의 길이가 제각각이다. 
대신에 한 봉지에 들어가는 떡의 총 길이는 절단기를 이용해서라도 맞춘다.
절단기에 높이를 지정하면 줄지어진 떡을 한번에 절단한다. 높이가 H보다 긴 떡은 H의 위 부분이 잘리고, 
낮은 떡은 잘리지 않는다. 예를들어 높이가 19, 14, 10, 17 인 떡이 나란히 있고 절단기의 높이를 
15cm로 지정하면 자른 뒤 떡의 높이는 15 14 10 15가 된다. 잘린떡의 길이는 나란히 4 0 0 2 이다. 
손님은 6만큼의 길이를 가져간다.
손님이 왔을 때 요청한 총 길이가 M일때 적어도 M만큼의 떡을 얻기 위해 절단기에 설정할 수 있는 높이의 
최댓값을 구하는 프로그램을 작성하라.

입력조건
첫째 줄에 떡의 개수 N과 요청한 떡의 길이 M이 주어진다. N은 백만이하 M은 Int형 범위내
둘째 줄에 떡의 개별 높이가 공백을 기준으로 나뉘어 주어진다. 떡 높이의 총합은 항상 M이상이어야 잘랐을때 적어도
손님이 원하는 길이가 나오는것이 가능하다. 그래서 그 조건을 충족한 떡 길이 조합이 항상 나온다.
출력조건
적어도 M만큼의 떡을 집에 가져가기 위해 절단기에 설정할 수 있는 높이의 최대값을 출력한다.

입력예시
4 6
19 15 10 17
출력예시
15

<접근 방법>
주어진 배열을 일일히 다 탐색을 해야지 어떤 길이로 잘라야 M을 충족하는지 알 수 있을 것이다.
정렬된 상태를 만든 뒤에 사장 긴 떡을 소거하는 방식으로 탐색하면 어떨까 예를들어 
10 15 17 19로 만든 다음 19cm 하면 0이다. 다음 18cm하면 1이고 17 하면 2, 16하면 4, 15하면 6이다.
그럼 m을 충족하게 된다. 이건 선형탐색의 이야기이다. 이분탐색이 가능할까?
이분탐색이라 함은 3나누기 2하면 1이므로 1인덱스 15로 접근 15하면 M보다 크냐 작냐로 탐색 크면 더 올려도 된다.
작으면 내리면 된다. 예를들어 9를 찾는다면? 15일때 6이므로 9보다 작다 따라서 내린다. 이때 얼만큼 내리느냐..15에서 내릴때 남는 떡의 크기는 3만큼 증가한다.
왜냐하면 1 인덱스 앞의 개수와 1인덱스 포함 뒤의 개수에 따라서 증감 폭이 달라지기 때문이다.이걸 어떻게 구현하여 일반해식을
구할까
너무 복잡하게 구현하려하지 말고 애초에 각 길이의 평균값으로 접근해보는건 어떨까? 최대길이 M은 answer가 0일때고,
최소 길이 M은 answer가 마지막 인덱스 요소값이면 될 거니까. 0<=answer<=마지막요소값 범위를 2분탐색하면 되지 않을까?
마지막 요소 최대값은 해봐야 int 최대값일 텐데 그거를 이분탐색하면 logN의 시간이 소요되는데 이는 계산하면 작은 값이 나올거라 예상한다.
*/
#if 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> arr, int N, int M) {
	sort(arr.begin(), arr.end());
	//탑다운 말고 바텀업 방식으로 한번 생각해보자.
	int answer = 0;
	int max = arr[N - 1];
	int min = 0;
	int mid = (max + min) / 2;
	while (answer == 0) { //일단 반복할거야
		mid = (max + min) / 2;
		if(mid == M) answer
	}
}
int main() {
	int N = 0, M = 0;
	cout << "요소의 개수 N과 가져갈 길이 M을 공백을 기준으로 입력" << endl;
	cin >> N >> M;
	vector<int> arr(N);
	cout << "벡터의 요소들을 공백을 기준으로 N개 입력" << endl;
	for (auto& n : arr) {
		cin >> n;
	}
	auto result = solution(arr, N, M);
	cout << result;
}

#endif