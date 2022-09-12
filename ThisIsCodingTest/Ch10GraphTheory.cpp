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
int myFind(vector<pair<int, int>> dp, int a) {
	//최종 루트 노드 반환하는 연산
	while (dp[a].first != dp[a].second) {
		a = dp[a].second;
	}
	return a;
}
void solution(vector<pair<int, int>>(&dp)) {
	//초기화 과정 각 노드들의 루트 노드는 자기 자신이다.
	int cnt = 0;
	for (auto& n : dp) {
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
		cout << myFind(dp, i) << ' ';
	}
	cout << endl;
	cout << "부모테이블: ";
	for (int i = 1; i < V + 1; i++)	cout << dp[i].second << ' ';
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

/* 위의 일반적인 서로소 집합의 문제점 : find() 함수의 비효율성
find()함수는 부모노드 배열의 값을 보고 자기자신이 부모노드인 즉 최종 노드인 루트노드를 발견할때까지
재귀적으로 반복하는데 이는 최악의 경우 노드의 개수만큼 반복하게 되어 비효율적으로 늘어날 가능성이 크다.
그래서 개념적인 구현보다 실용적인 구현은 부모노드를 저장하는게 아니라 링크배열로 루트노드를 그냥 저장하는
방법으로 개선가능하다. 그게 바로 경로 압축 path compression 기법이다. find()함수를 재귀적으로
호출할때 갱신을 하지 않던 코드에 반환값을 갱신하는 형태로 하면 갱신이 되다가 최종 루트 노드가 저장될것.
*/
#if 0
int new_find_Parent(int i) {
	if (i != dp[i]) return dp[i] = find_Parent(dp[i]);
	else return dp[i];
}
#endif // 1
/* 서로소 집합의 응용 : 무방향 그래프에서 사이클 판별
방향 그래프에서는 DFS를 이용하여 모든 경우의 수를 탐색하며 사이클 관계임을 확인 가능하지만
무방향 그래프라면 서로소 집합의 union-find만으로 확인 할 수 있다.
1. 노드와 간선들이 주어진 무방향 그래프 정보가 있다.
2. 모든 간선들의 관계에 대해서 합집합 연산을 수행해본다.
3. 합집합 연산을 통해 루트노드가 갱신되게 되는데 그때 마다 어떤 검사를 하나 한다.
그 검사 내용은 같은 루트노드를 가지고 있느냐 이다. 즉 이미 합집합으로 만들어져 동일한 집합하에 있는
노드와 노드 사이에 간선이라면 그건 사이클 상태라고 판별하는 것.

예를 들어 1. 1 2 3이 있고 (1,2) (2,3)에 간선 정보가 있다면 dp = {1, 2, 3}이다.
2. (1,2)를 합집합 하면 {1, 1, 3} (2,3)을 합집합 하면 {1, 1, 1}
3. 루트노드가 전부 1로 통일 되었지만 같은 루트노드를 가지고 있는 상태를 합집합 하는 과정은 없었다.
따라서 사이클 상태가 아니다.

예2 1. 1 2 3이 있고 (1,2) (2,3) (1,3)에 간선 정보가 있다면 dp = {1 2 3}
2. (1,2) (2,3) 각각 union하면 dp= {1 1 1}
3. 그 상태에서 (1,3)을 union할려보니 루트노드가 같은 상태 따라서 1 2 3은 사이클 상태
*/
//직접 구현해보기 무방향 그래프에서 사이클을 판별하기위해 union-find를 활용하는 예제
#if 0
#include<iostream>
#include<vector>
using namespace std;

using namespace std;
int V, E;
vector<int> dp(10001);

int find_Parent(int i) {
	if (i != dp[i]) return dp[i] = find_Parent(dp[i]);
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
void checkCycle(int a, int b) {
	if (dp[a] == dp[b]) cout << "사이클 생성" << endl;
	union_Parent(a, b);
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
		checkCycle(a, b);
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
//고찰 : 책내용도 별거 없다.

/*<신장트리>
신장트리란 : 모든 노드가 간선으로 전부 연결되어 있고 사이클은 발생하지 않는 상태

<크루스칼 알고리즘>: 대표적인 신장트리 알고리즘
노드와 간선과 가중치비용이 주어졌을때 최소의 가중치 비용으로 신장트리를 만드는 알고리즘
그리디 알고리즘의 탐욕법이 쓰이고, 루트노드 테이블을 계속 갱신하며 영향을 주므로
다이나믹 프로그래밍 기법도 활용된다. 최종적으로는 노드의 개수-1개의 간선이 있으면
모든 노드를 연결하면서 사이클은 없는 트리가 만들어질 수 있다.

1. 탐욕법을 위해 간선 가중치 비용이 가장 작은 것부터 오름차순으로 정렬한다.
2. 가장 작은 비용의 간선을 우선순위로 하여 그래프 union-find 연산을 통해 루트노드값을
확인하고 같은 루트노드가 아니라면 신장트리 간선으로 포함하고, 같은 루트노드값을 이미
가지고 있다면 이번 간선은 사이클을 만드는 간선이므로 제외하고 다음 그리디로 넘어간다.
3. 그렇게 하여 신장트리 간선이 노드-1개 만큼 채워지면 그게 바로 신장트리이다.

입력예시			출력 예시
7 9				159
1 2 29
1 5 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25

*/
//직접구현한 크루스칼 알고리즘
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using namespace std;
int V, E, K, totalWeight = 0;
vector<pair<int, int>> graph[10001]; //graph정보를 저장할 벡터
vector<int> dp(10001, 10001); //루트노드가 저장되는 dp테이블
vector<int> weight;//가중치를 저장할 테이블
vector<pair<int, int>> SpaningTree;

int find_Parent(int i) {
	if (i != dp[i]) return dp[i] = find_Parent(dp[i]);
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
bool checkCycle(int a, int b) {
	if (dp[a] == dp[b]) return false; //이 노드들이 사이클이므로 펄스
	union_Parent(a, b);//이 노드들이 연결되어도 사이클이 아니므로 합집합
	return true; //연결을 실행했으므로 트루
}
void kruskal() {
	int cnt = V - 1;//감소하다가 0개 되면 더 이상 할필요가 없어진다.
	//초기화 공정 각 노드의 루트노드값은 자기 자신
	for (int i = 1; i < V + 1; i++) dp[i] = i;
	//graph의 간선 가중치를 기반으로 graph 비교 테이블을 만듬.
	//가중치들을 기반으로 오름차순 정렬하는건 맞는데 어떻게? graph에 접근 하기위한 
	//인덱스 정보를 저장하나?
	sort(weight.begin(), weight.end()); //그리디를 위한 오름차순 가중치

	for (auto n : weight) { //가중치 테이블을 이용한 인덱스 탐색
		for (auto m : graph[n]) { //m은 pair {시작, 도달}
			bool isCycle = checkCycle(m.first, m.second);
			if (isCycle) {
				totalWeight += n; cnt--;
				SpaningTree.push_back(m);
			}
			else	continue;
		}
		if (cnt <= 0) break;
	}
	cout << endl;
	if (cnt > 0) cout << "이 그래프는 신장트리가 될 수 없습니다." << endl;
	else
	{
		cout << "이 그래프는 신장트리를 만족합니다." << endl;
		cout << "가중치 비용은 : " << totalWeight << endl;
	}
}
int main() {
	cout << "노드의 개수 V 와 간선의 개수 E를 입력하라" << endl;
	cin >> V >> E;
	cout << "합집합 관계를 간선의 개수만큼 입력하라." << endl;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[c].push_back({ a, b }); //가중치를 인덱스로 하는 2차원 벡터 
		//각 요소값은 pair 벡터로 기준노드와 인접노드를 저장할 것이다.
		weight.push_back(c); //가중치를 저장할 테이블
	}
	kruskal();

	cout << "각 원소가 속한 집합: ";
	for (int i = 1; i < V + 1; i++) {
		cout << find_Parent(i) << ' ';
	}
	cout << endl;
	cout << "부모테이블: ";
	for (int i = 1; i < V + 1; i++)	cout << dp[i] << ' ';
	cout << endl;
	sort(SpaningTree.begin(), SpaningTree.end());
	cout << "신장트리의 구성" << endl;
	for (auto n : SpaningTree)
	{
		cout << n.first << ' ' << n.second << endl;
	}
}
#endif // 1
/*고찰
<막혔던 부분>
1. graph 정보를 받긴 받았는데 간선 가중치를 어떻게 오름차순 배치를 할지가 고민
2. 배치를 했다면 그걸 이용해서 어떻게 노드에 접근할지 고민
-> 그래프의 저장 구조를 아예 바꾸자. 간선 가중치 값을 이용해 접근해야 되니까
graph의 인덱스 접근을 가중치값으로 바꾸면 된다.
해결
<책 내용을 보고>
책에서는 배열을 2개 3개 이용해서 서로 다른 정보를 저장하고 인덱스로 접근하고
이런 방식이 아니라 애초에 vector<pair<int, pair<int, int>>> 이런 구조로
인덱스로 접근하면 인트와 페어쌍을 페어쌍으로 가진 3쌍 자료구조를 사용하였다.

*/
//책내용을 보고 최적화한 크루스칼 알고리즘
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using namespace std;
int V, E, K, totalWeight = 0;
vector<pair<int, pair<int, int>>> graph; //graph정보를 저장할 벡터
vector<int> dp(10001, 10001); //루트노드가 저장되는 dp테이블
vector<int> weight;//가중치를 저장할 테이블
vector<pair<int, int>> SpaningTree;

int find_Parent(int i) {
	if (i != dp[i]) return dp[i] = find_Parent(dp[i]);
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
bool checkCycle(int a, int b) {
	if (dp[a] == dp[b]) return false; //이 노드들이 사이클이므로 펄스
	union_Parent(a, b);//이 노드들이 연결되어도 사이클이 아니므로 합집합
	return true; //연결을 실행했으므로 트루
}
void kruskal() {
	int cnt = V - 1;//감소하다가 0개 되면 더 이상 할필요가 없어진다.
	//초기화 공정 각 노드의 루트노드값은 자기 자신
	for (int i = 1; i < V + 1; i++) dp[i] = i;
	//graph의 간선 가중치를 기반으로 graph 비교 테이블을 만듬.
	//가중치들을 기반으로 오름차순 정렬하는건 맞는데 어떻게? graph에 접근 하기위한 
	//인덱스 정보를 저장하나?
	sort(graph.begin(), graph.end()); //그리디를 위한 오름차순 가중치

	for (auto n : graph) { //가중치 테이블을 이용한 인덱스 탐색
		bool isCycle = checkCycle(n.second.first, n.second.second);
		if (isCycle) {
			totalWeight += n.first;		cnt--;
			SpaningTree.push_back(n.second);
		}
		else	continue;

		if (cnt <= 0) break;
	}
	cout << endl;
	if (cnt > 0) cout << "이 그래프는 신장트리가 될 수 없습니다." << endl;
	else
	{
		cout << "이 그래프는 신장트리를 만족합니다." << endl;
		cout << "가중치 비용은 : " << totalWeight << endl;
	}
}
int main() {
	cout << "노드의 개수 V 와 간선의 개수 E를 입력하라" << endl;
	cin >> V >> E;
	cout << "합집합 관계를 간선의 개수만큼 입력하라." << endl;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ c, { a, b } }); //가중치를 인덱스로 하는 2차원 벡터 
		//각 요소값은 pair 벡터로 기준노드와 인접노드를 저장할 것이다.
		//weight.push_back(c); //가중치를 저장할 테이블
	}
	kruskal();

	cout << "각 원소가 속한 집합: ";
	for (int i = 1; i < V + 1; i++) {
		cout << find_Parent(i) << ' ';
	}
	cout << endl;
	cout << "부모테이블: ";
	for (int i = 1; i < V + 1; i++)	cout << dp[i] << ' ';
	cout << endl;
	sort(SpaningTree.begin(), SpaningTree.end());
	cout << "신장트리의 구성" << endl;
	for (auto n : SpaningTree)
	{
		cout << n.first << ' ' << n.second << endl;
	}
}
#endif // 1

/*<위상 정렬 Topology Sort>
우선순위가 정해진 작업이 있다고 하자. 그때 1번 2번 3번 4번 등 순서가 정해질텐데
이 순서를 어떻게 정의할지 정렬하는 알고리즘.
예를들어 선수과목의 예시가 있다. 자료구조 -> 알고리즘 
자료구조, 알고리즘-> 고급알고리즘 의 관계가 있다면 알고리즘만 배워서는
고급 알고리즘을 배울 수 없다. 자료구조를 배워서 알고리즘을 배우고 고급알고리즘을
배워야하는 순서가 생긴다.
이런 방식은 방향 그래프로 표현할 수 있는데 이런 방향 그래프 개념에서 모든 
작업을 찾아가기 위한 순서정렬이 위상 정렬이다.

특징
1.DAG(Direct Acyclic Graph): 사이클이 존재하지 않는 방향그래프 여야한다.
2. 여러가지 답이 나올 수 있다. 한 단계에서 다음 단계로 가는 가지수가 여러개라면
여러 순위가 나올 수도 있다.
3. 모든 원소에 대해 만족하기 전에 더이상 진행할 수 없다면 중간에 사이클이 존재하는 것
만약 처음부터 시작할 수 없다면 전체가 사이클집합으로 존재하는 것이다.
4. 큐를 이용하여 위상 정렬을 수행할 수 있고 스택을 활용한 DFS도 가능하다.

방법
1. 진입차수가 0인 노드를 전부 찾아 큐에 먼저 넣는다.
2. 큐에 존재하는 노드를 하나씩 순서대로 꺼내면서 그 꺼낸 노드의 진출차수가
0이 되도록 진출간선을 찾아 제거한다.
3. 제거한 간선에 의해 진입 차수가 0이된 노드들이 존재 할 수 있다. 그 노드를 찾아
검색하며 만약 진입차수가 0이라면 큐에 넣는다. 이는 1번의 반복이다.
4. 다시 2번을 반복하며 큐가 빌때까지 1번 2번을 계속 반복한다. 만약 비었을때 모든 
노드가 큐에서 푸쉬팝이 된 것이확인 된다면 사이클이 존재하지 않고 알맞게 정렬 최적해를
찾은 셈이다. 만약 사이클이 존재하여 진행이 안된다면 정렬최적해를 보장할 수 없다.

입력예시		출력예시
7 8			1 2 5 3 6 4 7
1 2 
1 5
2 3
2 6
3 4
4 7
5 6
6 4
*/

//큐를 활용한 직접 구현 위상정렬(topology sort)
#if 0
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int V, E;
vector<int> topologySort(vector<pair<int, vector<int>>> graph) {
	//초기화 과정.
	vector<int> answer;
	queue<int> topologyQ;
	for (int node = 1; node < V + 1; node++) {
		if (graph[node - 1].first == 0) topologyQ.push(node); //진입차수가 0이면 추가
	}
	if (topologyQ.empty()) {
		cout << "전체가 사이클로 구성된 그래프입니다." << endl;
		return answer;
	}
	while (!topologyQ.empty()) {
		vector<int> temp;
		int node = topologyQ.front();
		topologyQ.pop();
		answer.push_back(node);
		for (auto n : graph[node - 1].second) {
			graph[n - 1].first--;
			if (graph[n - 1].first == 0) temp.push_back(n);
		}
		for (auto n : temp) topologyQ.push(n);
	}
	if(answer.size()==V){
		cout << "위상 정렬 완료" << endl;
		for (auto n : answer) cout << n << ' ';
		return answer;
	}
	else {
		cout << "중간에 사이클이 존재하여 완료하지 못함" << endl;
		return answer;
	}
	
}
int main() {
	cout << "노드의 개수와 간선의 개수를 공백으로 구별하여 입력" << endl;
	cin >> V >> E;
	vector<pair<int,vector<int>>> graph(V);//진입차수가 first, 인접노드배열이 second
	cout << "노드와 그 노드에서 나가는 진출간선이 어느 노드로 가는지를" <<endl;
	cout << "공백으로 구별하여 간선의 개수만큼 입력" << endl;
	for (int i = 0; i < E; i++) {
		int a, b;	cin >> a >> b;
		graph[a - 1].second.push_back(b);
		graph[b-1].first++;
	}
	auto result = topologySort(graph);
}
#endif // 1

/*<2> <팀 결성>
학교에서 학생들에게 0번부터 N번까지의 번호를 부여했다. 처음에는 모든 학생이
서로 다른 팀으로 구분되어, 총 N+1개의 팀이 존재한다. 이때 선생님은 '팀 합치기'
연산과 '같은 팀 여부확인'연산을 사용할 수 있다.
1. 팀 합치기 연산은 두 팀을 합치는 것
2. 같은 팀 여부 확인은 두 학생이 같은 팀에 속하는지를 확인하는 연산

선생님이 M개의 연산을 수행할 수 있을때, 같은 팀 여부 확인 연산에 대한 연산 결과를 
출력하는 프로그램을 작성하시오.
입력조건
1. 첫째 줄에 N,M이 주어진다. M은 입력으로 주어지는 연산의 개수이다. 10만 이하
0번부터 N번까지니까 N+1개의 번호를 부여받은 학생들이 처음에 존재한다.
2. 다음 M개의 줄에는 각각의 연산이 주어짐.
3.팀 합치기 연산은 0 a b 형태로 주어짐. 이는 a와 b를 합친다는 뜻
4. 같은 팀 여부 확인은 1 a b로 주어짐.
5. a와 b는 N 이하의 양의 정수
출력조건
같은 팀 여부 확인 연산에 대하여 한 줄에 하나씩 YES 혹은 NO로 결과를 출력한다.

입력예시		출력예시
7 8			NO NO YES
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

<접근방법>
대놓고 Union-find 사용하라는 문제니까 서로소 집합개념을 사용한다.
find는 루트노드를 탐색할때 자기자신노드와 루트노드가 일치할때까지 그 루트노드 번호로
계속 탐색하며 갱신하는 코드
union은 루트노드를 가지고 서로 비교하며 더 작은 루트노드로 루트노드를 갱신하여
같은 집합에 속하도록 하는 합집합 연산. 이미 같은 루트노드를 가지고 있는데 또
합집합 연산을 하는건 사이클 생성을 하는 연산이 된다.

*/
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int find_parent(int i, vector<int>(&dp)) {
	if (i == dp[i]) return i;
	else return find_parent(dp[i], dp);
}
void union_parent(int i, int j, vector<int>(&dp)) {
	int a = find_parent(i, dp);
	int b = find_parent(j, dp);
	if (a < b) { dp[j] = dp[i]; /*cout << "NO ";*/ }
	else { dp[i] = dp[j]; /*cout << "NO";*/ }
}
string isSameRoot(int i, int j, vector<int>(&dp)) {
	int a = find_parent(i, dp);
	int b = find_parent(j, dp);
	if (a == b)		return "YES ";
	else if (a < b)	return "NO ";
	else			return "NO ";
}
int main() {
	int N, M;
	cout << "학생의 마지막 번호 N과 총 연산의 개수 M을 공백으로 구분하여 입력" << endl;
	cin >> N >> M;
	vector<int>dp(N + 1);//루트노드를 저장하는 벡터
	vector<string>result;
	for (int i = 1; i < N + 1; i++) {
		dp[i] = i;
	}
	cout << "M개의 연산들이 주어진다. 앞번호가 0이면 합치기 1이면 확인" << endl;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {//합집합
			union_parent(b, c, dp);
		}
		else {//같은 팀 여부 확인
			result.push_back(isSameRoot(b, c, dp));
		}
	}
	for (auto n : result) cout << n;
}
#endif // 1
/*<3> <도시 분할 계획>
동물원에서 막 탈출한 원숭이 한 마리가 세상 구경을 한다.
마을은 N개의 집과 그 집들을 연결하는 M개의 길로 이루어져 있다. 길은 어느 방향으로든지
다닐 수 있는 편리한 길(무방향 그래프) 그리고 길을 유지하는 유지비가 있다.
마을 이장은 2개의 분리된 마을로 분할할 계획을 세우고 있다. 마을이 너무 커서 혼자서는
관리하기 어렵기 때문이다. 마을을 분할할 때 각 분리된 마을 안에 집들이 서로 연결되도록
분할해야 한다. 각 분리된 마을 안에 있는 임의의 두 집 사이에 경로가 항상 존재해야 한다는 뜻
마을에는 집이 하나 이상 있어야 한다.(모두 연결되어 있어야함.)
그렇게 계획을 세우다가 마을 안에 길이 너무 많다는 생각을 하여 필요없는 길은 없애려고한다.
일단 분리된 두 마을 사이에 연결된 길은 없어도 상관없다. 개별적인 마을이기 때문이다.
마을안에서도 굳이 필요없는길은 없애도 된다.
유지비의 합을 최소로 유지하고 싶을때 그것을 항상 구하는 프로그램 작성.

입력조건
1. 첫째 줄에 집의 개수 M, 길의 개수 M이 주어진다. N은 10만이하 M은 100만이하
2. M개의 줄을 거쳐 길의 정보가 A, B, C 3개의 정수로 공백으로 구분되어 주어지는데
A번 집과 B번 집을 연결하는 길의 유지비가 C라는 뜻 1000이하
출력조건
첫째 줄에 길을 없애고 남은 유지비 합의 최솟값을 출력한다.

<접근방법>
무방향 그래프가 나오면 크루스칼 알고리즘을 떠올려라.
크루스칼 알고리즘은 신장트리를 만드는 알고리즘이다.
신장트리란 모든 노드를 노드-1개의 간선을 이용하여 연결되어 있는 트리이다.
이장님이 원하는 도시계획은 신장 트리 2개를 만드는 것과 동일하기에 쓰기 적절하다.
그런데 어떤 기준으로 2개를 나누고 또 어떻게해야 최적해를 만족할 수 있을지..
생각해보니 신장트리를 만들고 그 사이를 끊으면 그냥 2개의 신장트리가 만들어지는 것이다.
그럼 처음부터 신장트리를 만들면 된다. 만약 못만드는 경우가 생기면 그 경우를 시작노드로
다시 신장트리를 만들면되고 만약 다 만들어졌으면 가장 가중치 값이 큰 녀석을 자르면 그게 신장트리지.

1. 탐욕법을 위해 간선 가중치 비용이 가장 작은 것부터 오름차순으로 정렬한다.
2. 가장 작은 비용의 간선을 우선순위로 하여 그래프 union-find 연산을 통해 루트노드값을
확인하고 같은 루트노드가 아니라면 신장트리 간선으로 포함하고, 같은 루트노드값을 이미
가지고 있다면 이번 간선은 사이클을 만드는 간선이므로 제외하고 다음 그리디로 넘어간다.
3. 그렇게 하여 신장트리 간선이 노드-1개 만큼 채워지면 그게 바로 신장트리이다.

입력예시			출력예시
7 12			8
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4
*/
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, pair<int, int>>> graph; //가중치값을 first 노드들을 second
vector<int>dp;
vector<pair<int, pair<int, int>>> spanningtree;
int cnt,answer;

int find_Parent(int i) {
	if (i == dp[i]) return dp[i];
	else return find_Parent(dp[i]);
}
void union_Parent(int i, int j, int k) {
	int a = find_Parent(i);
	int b = find_Parent(j);
	if (a == b) { return; }
	else if (a < b) { dp[j] = a; }//같은 집합에 속할때 간선을 연결하면 사이클이되어 망함.
	else { dp[i] = b; }
	spanningtree.push_back({ k, {i, j} });//어찌되었든 스패닝트리의 간선으로 되었으니 추가한다.
	cnt++;//카운트 증가
}
int kruscal() {
	cnt = 0;
	sort(graph.begin(), graph.end()); //가중치를 오름차순으로 정렬
	for (int i = 0; i < graph.size(); i++) { //그래프를 선형탐색한다. 그래프는 간선의 개수만큼 들어있다.
		auto n = graph[i].second;//그래프에서 노드정보를 저장한다.
		union_Parent(n.first, n.second, graph[i].first); //노드,노드,간선으로 합집합
		if (cnt == dp.size() - 2) break; //만약 노드-1개를 결국 만족하게 되면 뒤에건 볼것도 없이 종료.
	}
	if (cnt < dp.size() - 2) { //반복문이 다 돌았음에도 불구하고 노드-1개만큼 충족하지 못했다.
		//이는 마을 하나가 신장트리를 다 만족할 수 없었음을 뜻한다. 즉 신장트리를 만들기위한 간선 부족
		//하지만 군데 군데 결국 2개 이상의 신장트리들을 생성했을것. 사이클은 만들지 않았으니.
		//하지만 그럼 문제의 오류 아닌가? 항상 마을은 신장트리 그 이상의 간선을 보유하고 있을 것이다.
		cout << "신장트리를 만들지 못했음" << endl;
		return -1;
	}
	else {
		//만들어진 신장트리에서 반을 자를 차례. 가장 긴 루트를 잘라버린다. 그러면서 동시에 합도 계산한다.
		answer = 0;
		int mnum = 0;
		for (auto n : spanningtree) {
			mnum = max(mnum, n.first);
			answer += n.first;
		}
		answer -= mnum;
		return answer;
	}
}

int main() {
	int N, M;
	cout << "집의 개수 N과 간선의 개수 M을 공백으로 구분하여 입력" << endl;
	cin >> N >> M;
	for (int i = 0; i < N + 1; i++) {
		dp.push_back(i);
	}
	cout << "간선의 개수 만큼 a b c를 공백으로 구별해서 입력 a와 b를 잇는 길의 유지비는 c" << endl;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ c,{a, b} });
	}
	auto result = kruscal();
	cout << result;
	
}
#endif // 1
/*<4><커리큘럼>
동빈이는 온라인으로 컴퓨터공학 강의를 듣고 있다. 이때 각 온라인 강의는 선수 강의가
있을 수 있는데, 선수 강의가 있는 강의는 선수 강의를 먼저 들어야만 해당 강의를
들을 수 있다.
총 N개의 강의를 듣고자 한다. 모든 강의는 1번부터 N번까지의 번호를 가진다. 또한 동시에
여러 개의 강의를 들을 수 있다고 가정한다. 예를 들어 N=3일때, 3번 강의의 선수과목이
1번 2번이고, 그 둘은 선수강의가 없다. 각 강의 시간은 번호순으로 30 20 40이다.
1번강의와 2번강의는 동시에 들을 수 있다. 결국 1번강의인 30시간 후에 3번강의 40시간을
들을 수 있으므로 70시간이 최소 시간이다. 이런 최소시간을 출력하는 프로그램 작성

입력조건
1. 첫째 줄에 강의의 수 N 500이하 
2. 다음 N개의 줄에는 각 강의의 강의시간과 그 강의를 듣기 위해 먼저 들어야하는
선수 강의들의 번호가 자연수로 주어짐. 각 자연수들은 공백으로 구분한다.
강의시간은 10만이하
3. 각 강의 번호는 1~N으로 구성되며, 각 줄은 -1로 끝난다.
출력조건
N개의 강의에 대하여 수강하기까지 걸리는 최소 시간을 한줄에 하나씩 출력

입력 예시			출력예시
5					10 20 14 18 17
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

<접근방법>
1. 입력이 특이하다. 워낙 변칙적으로 한 줄에 들어가는 숫자의 양이 달라지므로
-1로 단계를 구분하는 코드가 필요하다.
2. 선수강의 문제는 위상정렬! 진입노드가 없는 녀석이 스타트이고 인접노드를 향하는
간선을 가진 진입간선을 제거한 노드를 체크하여 처리하는 방식으로 진행되면 정렬이 이루어진다.
3.이때 각 순위체크를 하여 동등 순위 등을 체크하는 테이블을 만들 필요가 있다. 
그 중 가장 큰 시간값을 누적합하여 최종 최소시간을 구한다.
4.위상정렬의 원리 왜 큐를 사용할까?
큐는 검사 순서가 정해져있을때 아주 최적의 효율을 보인다. 만약 위상정렬 만들시에 끝까지
도달하지 못했는데 중간에 진입차수가 0인 녀석들이 없어진다면, 반드시 그 안에서 사이클이 돌고 있어서
진입차수가 0이 되는 애들이 없는것이다.
그리고 진입차수가 0인 애들이 동시 우선순위를 가지게 된다. 그럴때 그녀석들을 구분하는
테이블만 갖춰지면 누적합 추적도 쉽게 가능하다.
5. 입력을 할때 -1을 기준으로 인덱스 증가하는거 오케이 처음에 저장할건 바로 진입차수
둘째로 강의 시간 셋째로 듣기위한 강의 시간 넷째로 선수강의 번호가 나오면 선수강의의
진입차수가 올라가는게 아니라 지금 인덱스 강의의 진입차수가 올라가는 것이다.
지금 인덱스강의의 최소강의시간은 선수강의들의 최적시간에 달려있다.
6.위상정렬을 마치고나서 최소시간 계산하는 반복문을 하나 더 만들어야될거 같다.
*/
#if 0
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

//큐를 활용한 토폴로지소트
vector<int> topologySort(vector<pair<int, vector<int>>> graph, vector<int> times) {
	//초기화 관련 코드 진입차수가 0인 노드들을 찾아 큐에 넣는다.
	int start, rank=0;
	vector<int> samerank;
	vector<int> answer(times.size());
	vector<vector<int>> ranklist;
	for (int i = 1; i < times.size(); i++) {
		answer[i] = times[i];
	}
	queue<int> startnodeQ;
	int V = graph.size() - 1;//노드의 개수
	for (int i=0; i < graph.size(); i++) {//진입차수가 0인 놈 즉 최우선 선수강의가 들어간다.
		if (graph[i].first == 0) {
			startnodeQ.push(i);
		}
	}
	if (startnodeQ.empty()) {//진입차수가 0인놈이 없다면
		cout << "완전히 사이클화 되어 순서를 정할수가 없는 수강표입니다." << endl;
		cout << "이는 오류로 입력값의 검토가 필요합니다." << endl;
		return { -1 };
	}
	while (!startnodeQ.empty()) { //빌때까지 반복한다.
		samerank.clear();
		while (!startnodeQ.empty()) {
			start = startnodeQ.front();//최우선강의 노드번호
			startnodeQ.pop();
			//answer.push_back(start);
			samerank.push_back(start);
		}
		ranklist.push_back(samerank);
		for (auto n : samerank) {
			//선수강의의 정보를 받을때마다 선수강의 인덱스로 후수강의 노드번호를 추가했다.
			for (auto m : graph[n].second) {//이건 그 후수강의 노드번호이다.
				graph[n].first--;//후수강의 진입차수 하나 제거
				if (graph[n].first == 0) startnodeQ.push(n);
			}
		}
	}
	//랭크 리스트를 탐색해 나가며 타임 테이블을 정리한다. 첫번째 진입노드가 0인놈들은 아무 영향없이 본값일 것이고
	//진입노드가 있는 애들은 그 노드값에 자기 값을 더한 값이 될 것이다.
	//그래프에 저장되어 있는 정보는 후위 강의 번호 일테니까 랭크 리스트 0번에서 시작하는 음 한번 해볼까
	for (int i = 0; i < ranklist.size(); i++) {
		for (int j = 0; j < ranklist[i].size(); j++) {
			//처음은 한번만 반복할 것이지.
			int startnode = ranklist[i][j];
			int startnodetime = times[startnode];
			answer[startnode];
		}
	}
}

int main() {
	int N;
	cout << "강의의 개수 N을 입력하라" << endl;
	cin >> N;
	vector<int> times(N + 1, 1e8);//인덱스는 강의 넘버 요소는 강의시간
	vector<pair<int, vector<int>>> graph(N+1); //인덱스는 강의 넘버 요소는 진입차수, 진출노드배열
	//graph[i].first는 진입차수 

	cout << "줄로 나누어 n번째 강의시간 선수 강의들의 번호가 자연수로 주어짐. 각 수들은 공백으로 구분한다." << endl;
	for (int i = 0; i < N+1; i++) {
		if (i == 0) {
			graph[i] = { 10000000,{{0}} };
			continue;
		}
		int a, b;
		cin >> a; //첫번째 수는 반드시 강의 시간이다.
		times[i] = a;
		while (true) {
			cin >> b;
			if (b == -1) break;
			else {
				graph[b].second.push_back(i);//선수강의를 추가해서는 안된다. 선수강의에 후수강의를 추가해야한다.
				//후수강의의 진입차수는 하나 증가한다.
				graph[i].first++;
			}
		}
	}
	auto result = topologySort(graph, times);
	for (auto n : result) cout << n << ' ';
}
#endif // 1
/*고찰(미해결)
도저히 누적된 시간값을 반환하는 최적해 공식을 어떻게 만들어야 될지 모르겠다. 그러니까 어떤 절차를 거치는지는
알겠는데 그걸 컴퓨터적으로 어떻게 절차적으로 표현할지를 모르겠다. 절차적프로그래밍 구현개념이 부족한거 같다.
*/




