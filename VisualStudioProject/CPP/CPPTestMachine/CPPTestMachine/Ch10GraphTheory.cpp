/*<1> 다양한 그래프 알고리즘

<이미 배운 내용을 훑어보자>

10장에서 배울 내용들은 그리디와 정렬 알고리즘 등 앞서 배운내용들을 활용한 그래프 이론

그래프란 노드와 간선으로 이루어진 자료구조이다. 문제에서 서로 다른 개체가 연결되어 있다는
내용이나오면 바로 그래프 문제를 떠올리면 됨.

그래프와 트리의 차이
					그래프							트리
방향성			방향그래프일수도 아닐수도			방향그래프				
순환성			순환일수도 아닐수도				비순환
루트노드 유무		루트 노드는 없음					루트 노드 있음
노드간 관계성		부모 자식관계 아님				부모 자식 관계
모델의 종류		네트워크 모델						계층 모델

그래프류의 개념을 컴퓨터 데이터화 하는 방법
1. 인접행렬 : 다차원 벡터 , 공간복잡도는 노드의 개수 제곱, 검색속도 우월
2. 인접리스트 : 링크드 리스트를 사용하는 방법, 공간복잡도는 간선의 개수만큼, 검색 속도 느림

<서로소 집합>
공통 원소가 없는 두 집합을 의미한다. 서로소 집합 자료구조를 알기위해선 서로소 집합 개념이 필요

서로소 집합 자료구조란 서로소 부분 집합들로 나누어진 원소 데이터들을 처리하기 위한 자료구조
서로소 집합 자료구조에는 핵심 기능 2개가 필요한데 바로 union과 find이다. 
union은 합집합 연산으로 서로소 개념을 유지한채로 데이터들을 합치는 연산이다.
find는 특정 원소가 어떤 집합에 있는지를 알려주는 연산이다.
서로소 집합은 union-find 집합이라고도 한다. 2개의 핵심기능은 
결국 두 집합이 서로소 관계인지 아닌지를 파악할 수 있다는 것은 각집합이 어떤 원소를 공통으로 가지는지 
안가지는지를 구별 할 수 있음을 의미한다.

서로소 집합 자료구조는 트리로 표현한다.
union A B 의 과정은
1. A의 루트노드 B의 루트노드를 재귀적으로 최종 루트노드를 찾는다.
2. 더 작은루트 노드가  더 큰 루트노드의 루트노드가 되도록 한다.

*/
//직접 구현해본 서로소 집합
/*입력예시			출력예시
6 4					각 원소가 속한 집합: 1 1 1 1 5 5
1 4					부모 테이블: 1 1 2 1 5 5
2 3
2 4
5 6*/
#if 0
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int V, E;

void myUnion(vector<pair<int, int>>(&dp), int a, int b) {
	//언제까지 재귀해야하는가? 루트노드가 더이상 없을때까지 즉 자기 자신과 루트노드가 같을때까지 루트노드를 찾아.
	int i, j;
	while (dp[a].first != dp[a].second) {
		a = dp[a].second;//루트 노드를 찾아가
	}
	while (dp[b].first != dp[b].second) {
		b = dp[b].second;//루트 노드를 찾아가
	}
	if (a < b) {
		dp[b].second = a;
	}
	else {
		dp[a].second = b;
	}
}
int myFind(vector<pair<int, int>> dp , int a) {
	//최종 루트 노드 반환하는 연산
	while (dp[a].first != dp[a].second) {
		a = dp[a].second;
	}
	return a;
}
void solution(vector<pair<int, int>> (&dp)) {
	//초기화 과정 각 노드들의 루트 노드는 자기 자신이다.
	int cnt = 0;
	for (auto &n : dp) {
		n.first = cnt;
		n.second = cnt;
		cnt++;
	}
	cout << "합집합 관계를 간선의 개수만큼 입력하라." << endl;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		myUnion(dp, a, b);
	}
}
int main() {
	cout << "노드의 개수 V 와 간선의 개수 E를 입력하라" << endl;
	cin >> V >> E;
	vector<pair<int, int>> dp(V + 1); //노드, 루트노드 관계를 저장할 테이블 
	solution(dp);
	cout << "각 원소가 속한 집합: ";
	for (int i = 1; i < V + 1; i++) {
		cout << myFind(dp, i)<<' ';
	}
	cout << endl;
	cout << "부모테이블: ";
	for (int i = 1; i < V + 1; i++)	cout << dp[i].second<<' ';
}

#endif // 1
/*고찰 (책 내용을 보고)
나와 많이 다른 방식으로 했다. 생각해보니 부모노드 테이블에서는 인덱스가 곧 자기 자신 노드이므로
pair자료형이 필요 없었으며, 재귀적으로도 짜면 코드가 더 깔끔해진다.*/

//책보고 다시 쓰는 Union-find 자료구조(재귀적)
#if 0
#include<iostream>
#include<vector>
using namespace std;
int V, E;
vector<int> dp(10001);

int find_Parent(int i) {
	if (i != dp[i]) return find_Parent(dp[i]);
	else return i;
}

void union_Parent(int a, int b) {
	//언제까지 재귀해야하는가? 루트노드가 더이상 없을때까지 즉 자기 자신과 루트노드가 같을때까지 루트노드를 찾아.
	int i, j;
	i = find_Parent(a);
	j = find_Parent(b);
	if (i < j)	dp[j] = i;
	else		dp[i] = j;	
}

void Union_Find_Tree() {
	//초기화 과정 각 노드들의 루트 노드는 자기 자신이다.
	int cnt = 0;
	for (auto& n : dp) {
		n = cnt;
		cnt++;
	}
	cout << "합집합 관계를 간선의 개수만큼 입력하라." << endl;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		union_Parent(a, b);
	}
}
int main() {
	cout << "노드의 개수 V 와 간선의 개수 E를 입력하라" << endl;
	cin >> V >> E;
	Union_Find_Tree();
	cout << "각 원소가 속한 집합: ";
	for (int i = 1; i < V + 1; i++) {
		cout << find_Parent(i) << ' ';
	}
	cout << endl;
	cout << "부모테이블: ";
	for (int i = 1; i < V + 1; i++)	cout << dp[i] << ' ';
}

#endif // 1

/*
*/