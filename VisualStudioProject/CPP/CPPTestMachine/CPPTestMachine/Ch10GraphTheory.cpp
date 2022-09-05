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
