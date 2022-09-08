/*<1> <가장 빠른 길 찾기>
<가장 빠르게 도달하는 방법>
최단 경로 알고리즘은 가장 빠르게 도달하는 경로를 찾는 알고리즘이다. 상황에 맞는 효율적인 알고리즘은
이미 정립되어 있다.
보통 그래프로 표현하는데 지점은 노드 도로는 간선으로 표현된다.
보통 코딩테스트에서 요구하는 것은 최단 경로를 표현하라는 것보다는 최단거리를 출력하는 수준으로 많이 출제
컴공학부수준에서 배우는 건 3가지가 있다. 다익스트라, 플로이드워셜, 벨만포드
여기서는 다익스트라 플로이드 워셜만 다룬다.
앞서 공부한 그리디와 다이나믹 프로그래밍의 개념을 알고 있어야 적용할 수 있다.

다양한 문제 상황
1. 한 지점에서 다른 한 지점까지의 최단 경로
2. 한 지점에서 다른 모든 지점까지의 최단 경로
3. 모든 지점에서 다른 모든 지점까지의 최단 경로

<다익스트라 최단 경로 알고리즘>
특정한 노드에서 출발하여 다른 모든 노드로 가는 최단 경로를 계산한다.
다익스트라 최단 경로 알고리즘은 음의 간선이 없을 때 정상적으로 동작합니다.
현실 세계의 도로는 음의 간선으로 표현되지 않기 때문에 현실문제에 적합하다.
다익스트라 알고리즘은 그리디 알고리즘으로 분류된다.
매 상황에서 가장 비용이 적은 노드를 선택해 임의의 과정을 반복합니다.

그리고 다이나믹 프로그래밍의 원리가 아예 안쓰일 수 가 없는게 결국 DP테이블을 수정 참조 하면서 접근하기 때문이다.

동작과정
1. 출발 노드를 설정한다.
2. 최단 거리 테이블을 초기화한다.
3. 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 선택한다.
 -> 이 과정을 반복할때 마다 선택한 노드를 가는 방법은 확실하게 정해지는것과 마찬가지이다.
4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신한다.
5. 위 과정에서 3번과 4번을 반복한다.

- 알고리즘 동작과정에서 최단 거리 테이블은 지금 선택한 노드를 기준으로 지점까지 가는 최단 거리 정보를 가지고 있다.
- 계속해서 선택해 나가는 과정에서 더 짧은 경로를 찾으면 갱신하는 방법으로 최단 경로 거리를 항상 확보한다.
- 예를들어 처음 출발노드를 선택한 과정에서 출발노드에서 갈수 있는 인접한 노드들을 싸그리 간선 거리로 초기화한다.
이때까지는 가장 짧은 거리는 그게 맞는거다.
- 저장되어있는 테이블 중에서 가장 작은 값을 가진 노드를 선택하여 그 노드를 기준으로 인접한 노드까지 가는 방법들을
초기화한다. 이때 이미 선택되어진 적이 있는 출발 노드는 갱신대상에서 제외한다. 아 이미 현재 선택한 노드까지 오는 방법으로
채택된 가장 짧은 방법이기에 한번 선택된 적이 있는 노드들은 갱신대상에서 제외하는 것이다.
- 만약 이때 현재 선택한 노드 기준으로 다른 지점을 탐색해보니 기존에 저장한 최단 경로보다 이쪽 노드를 거쳐서 가는 방법이
더짧은 것으로 확인되면 현재 노드를 거치는 경우의 거리로 갱신한다. 이 과정을 계속반복하다보면 경로자체를 다 일일이 기록갱신하는건 아니지만
그 지점을 가는 거리 자체는 항상 최단거리로 갱신되는 셈이다. 가장 간단하게 이해를 하기 위해 간소화하였다.
만약에 경로를 다 기록하려면 DP테이블 자체가 더 커져야 할 것이다.

*/

//직접 짠 다익스트라 알고리즘
#if 0
#include<vector>
#include<iostream>
using namespace std;
int N = 6, M = 11, k; //N은 노드(지점)의 개수 M은 간선의 개수 K는 간선당 가중치

int INF = 1e9; //도달할 수 없는 경우
vector<int>dp(N + 1, INF); //초기에 다 INF로 초기화
vector<pair<int, int>> graph[10001]; //페어백터를 요소로가지는 배열 그래프 이차원 배열이고 각 열의 요소는 페어다.
vector<bool> visited(N + 1); //방문한 노드는 다시 접근하는 비효율을 막는다.

void shortestPath() {
	//그래프 정보를 조회하여 각 단계별로 dp테이블을 갱신하고 갱신한 dp테이블을 참조하여 다음 노드를 선택한다.
	int i = 1;
	for (int j = 1; j < N; j++) {//마지막인덱스는 굳이 할필요 없다. 이미 그 이전 인덱스에서 최단경로를 만들었기에.
		for (int k = 1; k < N + 1; k++) {
			if (!visited[k] && (dp[k] < dp[i])) {
				i = k;
			}
		}
		visited[i] = true;
		for (auto n : graph[i]) { //22 35 41
			//현재 노드까지 오는데 걸리는 최단경로길이에 간선 가중치를 더하면 현재 시작지점에서 현재 노드를 거쳐서
			//가는 경로길이가 나온다. 그 길이가 지금 저장되어 있는길이보다 짧다면 그 길이가 최단경로 길이가 될 것이다.
			if ((!visited[n.first]) && (dp[i] + n.second) < dp[n.first]) {
				dp[n.first] = dp[i] + n.second;
			}
		}
	}
	for (int j = 1; j < N + 1; j++) {
		cout << dp[j];
	}
}
int main() {
	cout << "간단한 다익스트라 알고리즘. 노드와 인접노드 가중치로 그래프를 초기화 " << endl;
	for (int i = 0; i < 11; i++) {
		int n, m, k; //각 요소는 시작 노드와 인접노드 그리고 간선 가중치를 입력하면
		cin >> n >> m >> k;
		//그래프에 행인덱스로 시작 노드를 넣고 푸쉬백으로 인접노드와 가중치를 요소로갖는 벡터요소값이 하나 추가된다.
		graph[n].push_back({ m,k });
	}
	dp[1] = 0;//시작노드의 최단경로는 그냥 0;
	shortestPath();
}
#endif // 1
/* 고찰
내가 스스로 짜볼려했으나 자꾸 뭔가 인덱스 참조에서 오류가 나는거 같은데 그 원인을 못찾아서 결국 책에 나오는 내용 그대로를
암기하기로 했다.
*/
#if 0
#include<vector>
#include<iostream>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정
int n, m, start;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열 여기서 너무 햇갈렸다. 2차원벡터와 유사한 벡터배열 선언방법이다.
vector<pair<int, int>> graph[100001];

// 방문한 적이 있는지 체크하는 목적의 배열 만들기
bool visited[100001];
// 최단 거리 테이블 만들기
int d[100001];

// 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환
int getSmallestNode() {
	int min_value = INF;
	int index = 0; // 가장 최단 거리가 짧은 노드(인덱스)
	for (int i = 1; i <= n; i++) {
		if (d[i] < min_value && !visited[i]) {
			min_value = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	// 시작 노드에 대해서 초기화
	d[start] = 0;
	visited[start] = true;
	for (int j = 0; j < graph[start].size(); j++) {
		d[graph[start][j].first] = graph[start][j].second;
	}
	// 시작 노드를 제외한 전체 n - 1개의 노드에 대해 반복
	for (int i = 0; i < n - 1; i++) {
		// 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
		int now = getSmallestNode();
		visited[now] = true;
		// 현재 노드와 연결된 다른 노드를 확인
		for (int j = 0; j < graph[now].size(); j++) {
			int cost = d[now] + graph[now][j].second;
			// 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
			if (cost < d[graph[now][j].first]) {
				d[graph[now][j].first] = cost;
			}
		}
	}
}

int main(void) {
	cin >> n >> m >> start;

	// 모든 간선 정보를 입력받기
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// a번 노드에서 b번 노드로 가는 비용이 c라는 의미
		graph[a].push_back({ b, c });
	}

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill_n(d, 100001, INF);

	// 다익스트라 알고리즘을 수행
	dijkstra(start);

	// 모든 노드로 가기 위한 최단 거리를 출력
	for (int i = 1; i <= n; i++) {
		// 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
		if (d[i] == INF) {
			cout << "INFINITY" << '\n';
		}
		// 도달할 수 있는 경우 거리를 출력
		else {
			cout << d[i] << '\n';
		}
	}
}
#endif
/*
1 2 2
1 3 5
1 4 1
2 3 3
2 4 2
3 2 3
3 6 5
4 3 3
4 5 1
5 3 1
5 6 2
*/

//다시 써보는 다익스트라 알고리즘
#if 0
#include<vector>
#include<iostream>
#define inf 1e9
using namespace std;

int N, M, start;

int shortestPathNode(vector<int>(&dp), vector<bool>(&visited)) {
	int targetIdx = 0;//dp[0] == inf
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		else if (dp[targetIdx] > dp[i])  targetIdx = i;
	}
	if (dp[targetIdx] == inf)   return -1;
	else    return targetIdx;
}

void dijkstra(vector<int>(&dp), vector<bool>(&visited), vector<vector<pair<int, int>>>(&graph)) {
	//시작노드를 기준으로 각 노드까지 가는데 걸리는 최소 시간을 반환하여 dp테이블을 만들것이다.
	//먼저 start값을 기준으로 초기화 작업을 한다.
	dp[start] = 0; //처음시작노드 최소경로값 확정
	visited[start] = true;
	for (auto n : graph[start]) dp[n.first] = n.second;

	for (int i = 0; i < N - 2; i++) {
		//이제 dp값을 참조하여 방문하지 않은 노드들 중에서 가장 최소경로값을 가진 노드로 방문한다.
		start = shortestPathNode(dp, visited);
		//start 노드는 가장 최소경로값임을 확정한 노드이다. 이 노드를 기준으로 인접한 경로거리가
		//이전에 수정했던 dp값보다 작다면 현재 start노드를 거쳐가야지 최소경로라는 소리가 된다.
		//먼저 graph[start]로 인접 정보를 확인한다.
		visited[start] = true;
		for (auto n : graph[start]) {
			if (visited[n.first]) continue;
			else if ((n.second + dp[start]) < dp[n.first]) dp[n.first] = n.second + dp[start];
		}
	}
}

int main() {
	cout << "노드의 개수 N과 간선의 개수 M을 공백을 기준으로 입력" << endl;
	cin >> N >> M;
	cout << "시작노드는 몇번 노드인가?";
	cin >> start;
	vector<int> dp(N + 1, inf); //각 노드마다 최소 경로값을 저장할 dp테이블
	vector<bool> visited(N + 1); //각 노드마다 방문하여 그 노드의 최소경로값을 확정했는지 여부를 저장할 벡터

	//각 노드마다 어떤 노드와 인접하고 있는지 그리고 간선 가중치를 저장하는 2차원 벡터 그래프
	vector<vector<pair<int, int>>> graph(N + 1);

	cout << "그래프를 작성하기 위한 요소값들인 현재노드, 인접노드, 간선길이를 공백을 기준으로 작성하고 다음 요소는 엔터로 구별하라." << endl;
	for (int k = 0; k < M; k++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	dijkstra(dp, visited, graph);

	cout << "dp테이블은 다음과 같다" << endl;
	for (int i = 1; i < dp.size(); i++) {
		cout << dp[i] << endl;
	}
}
#endif // 1


/*방법2. 개선된 다익스트라 알고리즘
위의 간단한 다익스트라 알고리즘은 시간복잡도가 v제곱이다. 노드의 개수와 간선의 개수가 많아지면 개선된 방법을 이용해야 된다.
개선된 방법은 ELogV의 복잡도를 따른다. E는 간선의 개수 V는 노드의 개수이다.
간단한 방식이 v제곱의 시간이 걸렸던건 가장 거리가 짧은 노드를 찾기위해서는 노드를 하나 확정할때마다 또 계속해서 선형탐색을
하기 때문이다. 이 선형탐색의 시간을 줄일 수 있다면이 개선의 핵심이다.

개선된 방식에서는 Heap자료구조를 사용한다. 힙 자료구조를 이용하면 특정 노드까지의 최단거리에 관한 정보를 힙에 담아서
처리한다. 이 방식을 쓰면 로그의 시간이 걸리게 된다.

힙?
힙 자료구조는 대표적으로 '우선순위 큐'를 처리하기 위해 사용하는 자료구조이다. 우선순위가 가장 높은 데이터를 가장 먼저 삭제하는 큐이다.
스택 -> LIFO, 큐 -> FIFO, 우선순위 큐 -> PRFO(priority first out)

우선순위를 값과 함께 우선순위 큐에 넣어서 사용하는데 이때 (가치, 값)의 형태로 우선순위 큐에 넣으면 가치를 기준으로 최대값 혹은 최소값의
자료가 먼저 나오게끔 되어있다. 이걸 탐색이나 정렬의 과정을 생략하고 한다는 점이 우수한 점이다.
최소힙은 가치가 가장 낮은 값이 우선순위이고 최대힙은 가치가 가장 높은 값이 우선순위이다.
C++에서는 기본적으로 최대힙으로 구현되어 있기 때문에 최소힙을 이용하는 아주 간단한 방법이 하나 있다. 가치값에 해당하는 부분에 -를곱해서
저장한 뒤에 꺼내 쓸때는 다시 -를 붙여서 사용하면 간단하게 사용가능.
[리스트] 삽입 -> 1, 삭제 -> N, [힙] 삽입 -> logN, 삭제 -> logN

힙 자료구조는 모든 원소를 저장하고 삭제할때 우선순위를 구현하기 쉬워서 우선순위 큐에 이용된다.

*/

//직접 구현해보기 개선된 다익스트라 알고리즘
#if 0
#include<vector>
#include<queue>
#include<iostream>
#define inf 1e9
using namespace std;

int N, M, start;
priority_queue<pair<int, int>> pq; //선형탐색을 안하고 우선순위 큐의 pop을 활용할것이다. (최소길이, 노드)

void dijkstra(vector<int> (&dp), vector<bool>(&visited), vector<vector<pair<int, int>>>(&graph)) {
	//start정보를 기준으로 초기화 세팅
	dp[start] = 0;
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		dp[graph[start][i].first] = graph[start][i].second;
		pq.push({ graph[start][i].second * -1, graph[start][i].first }); //가중치, 노드값으로 초기화
	}
	while (!pq.empty()) {
		//pq에서 가장 짧은 놈으로 한번 방문해보자.
		start = pq.top().second;	//현재 방문할 노드
		int confirmed = pq.top().first * -1; //방문할 노드의 확정된 최소 경로거리
		pq.pop();
		visited[start] = true;
		for (int i = 0; i < graph[start].size(); i++) {
			if (dp[graph[start][i].first] > confirmed + graph[start][i].second) {
				dp[graph[start][i].first] = confirmed + graph[start][i].second;
				pq.push({ (confirmed + graph[start][i].second) * -1, graph[start][i].first });
			}
		}
	}
}

int main() {
	cout << "노드의 개수 N과 간선의 개수 M을 공백을 기준으로 입력" << endl;
	cin >> N >> M;
	cout << "시작노드는 몇번 노드인가?";
	cin >> start;
	vector<int> dp(N + 1, inf); //각 노드마다 최소 경로값을 저장할 dp테이블//각 노드마다 최소 경로값을 저장할 dp테이블.
	vector<bool> visited(N + 1); //각 노드마다 방문하여 그 노드의 최소경로값을 확정했는지 여부를 저장할 벡터

	//각 노드마다 어떤 노드와 인접하고 있는지 그리고 간선 가중치를 저장하는 2차원 벡터 그래프
	vector<vector<pair<int, int>>> graph(N + 1);

	cout << "그래프를 작성하기 위한 요소값들인 현재노드, 인접노드, 간선길이를 공백을 기준으로 작성하고 다음 요소는 엔터로 구별하라." << endl;
	for (int k = 0; k < M; k++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	dijkstra(dp, visited, graph);

	cout << "dp테이블은 다음과 같다" << endl;
	for (int i = 1; i < dp.size(); i++) {
		cout << dp[i] << endl;
	}
}
#endif // 1

/*<플로이드 워셜 알고리즘>
다익스트라는 한 지점에서 다른 목적지까지의 최단 경로를 구해야 하는 경우에 사용할 수 있는 최단 경로 알고리즘
플로이드는 모든 지점에서 모든 지점까지의 최단 경로를 구해야 하는 경우에 사용하는 알고리즘
소스코드는 오히려 간단해서 다익스트라보다 구현이 더 쉽다. 하지만 그 본질을 이해하는게 여기서는 중요.

다익스트라는 현재 방문한 노드를 최소 경로거리라고 확정을 하고 탐색하기를 노드의 개수만큼 반복한다.
플로이드 워셜은 거쳐가는 노드를 기준으로 생각하여 최소 거리값을 갱신하기를 반복하는데 모든 노드가 다른 모든 노드까지 가는 비용을
다 갱신하다보니 2차원배열이 사용되며 그만큼 N제곱번을 N번 탐색하므로 N세제곱이란 시간복잡도가 나온다.

다익스트라는 dp테이블도 사용하지만 기본적으로 일단 가장 원하는 작은 값으로 계속 갱신한다는 점은 그리디 알고리즘이라고 할 수 있다.
하지만 플로이드 워셜은 철저하게 다이나믹 프로그래밍이다. 점화식을 따라 구현되기 때문이다.
k노드를 거쳐가는 경우의 수를 탐색중일때, f(a->b) = min(f(a->k)+f(k->b), f(a->b))


*/

//직접 구현해보는 플로이드 워셜 알고리즘
#if 0
#include<iostream>
#include<vector>
#define INF 1e8
using namespace std;
int N, M; //노드의 개수와 간선의 개수

void FloydWarshall(vector<vector<pair<int, int>>> graph, vector<vector<int>> (&dp)) {
	//초기화 작업 : 각 그래프 탐색하면서 갈 수 있는 곳은 다 할당하고 자기 자신은 0으로 만들고
	for (int i = 1; i < N + 1; i++) {
		dp[i][i] = 0;
		for (auto n : graph[i]) {
			dp[i][n.first] = n.second;
		}
	}
	//반복하면서 해야될 것. dp테이블 최소값으로 갱신작업, 1번 노드를 거쳐가는 경우에는 1번을 제외한 녀석들이
	//각자 도생의 방법으로 갈수 있는 경우에 dp테이블 최소값을 비교하며 저장
	for (int i = 1; i < N + 1; i++) { //i는 지금 선택된 노드 거쳐가는 경우
		for (int j = 1; j < N + 1; j++) { //j와 k는 i를 제외한 모든 노드의 경우를 탐색하기 위해서 
			if (j == i) {//i는 거쳐가는 경우이지 스타트도 도달도 되어선 안된다.
				continue;
			}
			for (int k = 1; k < N + 1; k++) { //j는 스타트 노드이고 k는 도달 노드일것이다.
				if (k == i || j==k) {//j와 k가 같은 경우도 따져볼 필요가 없다. 그냥 0이다.
					continue;
				}
				dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
			}
		}
	}
}

int main() {
	cout << "노드의 개수와 간선의 개수를 공백을 기준으로 구별하여 입력" << endl;
	cin >> N >> M;
	vector<vector<pair<int, int>>> graph(N + 1);
	vector<int> temp(N + 1, INF);
	vector<vector<int>> dp(N + 1, temp);
	cout << "출발 노드, 도착 노드, 간선의 가중치 공백을 기준으로 구별하여 입력하기를 엔터로 구별하여 총 간선의 개수만큼 반복" << endl;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	FloydWarshall(graph, dp);
	cout << "dp 테이블은 다음과 같다." << endl;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cout.width(5);
			cout << dp[i][j];
		}
		cout << endl;
	}
}
#endif // 1
/*
1 2 4
1 4 6
2 1 3
2 3 7
3 1 5
3 4 4
4 3 2
*/
/*고찰 : 책을 읽고
구현을 더 단순하게 할 수 있었다. 초기의 그래프 상태를 계속 보면서 비교할 필요없이 초기화 이후에는 계속 갱신된 테이블을
가지고서 최소값을 만들어내고 최종 갱신 테이블이 답이기에 애초에 문제에 필요한 테이블은 하나면 된다. 그리고 반박문의 조건도
더 단순해졌다. 어차피 최소값만 가지고 비교할 것이기 때문에 dp[i][i]를 참조하든 말든 항상 0을 갱신하게 될것이다. 
구현을 더 단순히 해보자
*/
//책보고 다시써보는 플로이드 워셜 알고리즘
#if 0
#include<iostream>
#include<vector>
#define INF 1e8
using namespace std;
int N, M; //노드의 개수와 간선의 개수

void FloydWarshall(vector<vector<int>> (&graph)) {
	//초기화 작업 : 각 그래프 탐색하면서 갈 수 있는 곳은 다 할당하고 자기 자신은 0으로 만들고
	for (int i = 1; i < N + 1; i++) {
		graph[i][i] = 0;
	}

	//반복하면서 해야될 것. dp테이블 최소값으로 갱신작업, 1번 노드를 거쳐가는 경우에는 1번을 제외한 녀석들이
	//각자 도생의 방법으로 갈수 있는 경우에 dp테이블 최소값을 비교하며 저장
	for (int i = 1; i < N + 1; i++) { //i는 지금 선택된 노드 거쳐가는 경우
		for (int j = 1; j < N + 1; j++) { //j와 k는 i를 제외한 모든 노드의 경우를 탐색하기 위해서 
			//if (j == i) {//i는 거쳐가는 경우이지 스타트도 도달도 되어선 안된다.
			//	continue;
			//}
			for (int k = 1; k < N + 1; k++) { //j는 스타트 노드이고 k는 도달 노드일것이다.
				//if (k == i || j == k) {//j와 k가 같은 경우도 따져볼 필요가 없다. 그냥 0이다.
				//	continue;
				//}
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
}

int main() {
	cout << "노드의 개수와 간선의 개수를 공백을 기준으로 구별하여 입력" << endl;
	cin >> N >> M;
	//출발 노드 도달 노드 간선 가중치를 기반으로한 초기 그래프는 딱 한번만 쓸것이고 계속 갱신되기에 그 정보를
	//두고 두고 사용할 그래프를 따로 만들필요가 없다. 그냥 2차원 벡터 하나면 된다.
	vector<int> temp(N + 1, INF);
	vector<vector<int>> graph(N + 1, temp);
	cout << "출발 노드, 도착 노드, 간선의 가중치 공백을 기준으로 구별하여 입력하기를 엔터로 구별하여 총 간선의 개수만큼 반복" << endl;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c; //초기화 간소화
	}
	FloydWarshall(graph);
	cout << "dp 테이블은 다음과 같다." << endl;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cout.width(5);
			if (graph[i][j] >= INF)	cout << "INF";
			else					cout << graph[i][j];

		}
		cout << endl;
	}
}
#endif

/*<2> <미래 도시> <해결>
방문 판매원 A는 많은 회사가 모여 있는 공중 미래 도시에 있다. 공중 미래 도시에는 
1번부터 N번까지의 회사가 있는데 특정 회사끼리는 서로 도로를 통해 연결되어 있다.
방문 판매원 A는 현재 1번 회사에 위치해 있으며, X번 회사에 방문해 물건을 판매하고자한다. 

공중 미래 도시에서 특정 회사에 도착하기 위한 방법은 회사끼리 연결되어 있는 도로를 이용하는
방법이 유일하다. 또한 연결된 2개의 회사는 양방향으로 이동 가능하다. 공중 미래 도시에서의 
도로는 마하의 속도로 사람을 이동시켜주기 때문에 특정 회사와 다른 회사가 도로로 연결되어 있다면,
정확히 1만큼의 시간으로 이동할 수 있다.

또한 오늘 방문 판매원 A는 기대하던 소개팅에도 참석하고자 한다. 소개팅의 상대는 K번 회사에 존재한다.
방문 판매원 A는 X번 회사에 가서 물건을 판매하기 전에 먼저 소개팅 상대의 회사에 찾아가서 함께 커피를
마실 예정이다. 따라서 방문 판매원 A는 1번 회사에서 출발하여 K번 회사를 방문한 뒤에 X번 회사로 가는
것이 목표다. 이때 방문 판매원 A는 가능한 한 빠르게 이동하고자 한다. 방문 판매원이 회사 사이를 이동하게
되는 최소 시간을 계산하는 프로그램을 작성하시오. 이때 소개팅의 상대방과 커피를 마시는 시간 등은 고려하지
않는다. 예를들어 N=5, x=4, k=5이고 회사 간 도로가 7개면서 각 도로가 다음과 같이 연결되어 있을 때를 
가정할 수 있다.
(1번, 2번), (1번, 3번), (1번, 4번), (2번, 4번), (3번, 4번), (3번, 5번), (4번, 5번)
한마디로 K를 들렀다가 X를 가는 최소 시간

입력조건
첫째 줄에 전체 회사의 개수 N과 경로의 개수 M이 공백으로 구분되어 주어짐. N과 M은 100이하
둘째 줄부터 M+1번 줄까지 연결된 두 회사의 번호가 공백으로 구분되어 주어짐
M+2번 줄에는 X와 K가 공백으로 구분되어 주어짐. K와 X는 당연히 100이하
출력조건
K를 거쳐 X로 가는 최소 이동 시간 출력 만약 갈수 없다면 -1 출력
입력예시1
5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5
입력예시2
4 2
1 3
2 4
3 4

<접근방법>
목적지가 하나인 다익스트라 알고리즘으로 풀기엔 너무 비효율적이다. 어딘가를 거쳐간다는 아이디어는
플로이드 워셜에서 사용한다. 모든 노드까지 가는 최소 경로를 다 경우의 수를 따져 비교해놓고나서
나온 테이블을 가지고 조합하면 최소 경로 가는 길이가 될 것이다.
*/

//직접 풀이 플로이드 알고리즘으로 다시 구현해보기
#if 0
#include <vector>
#include<iostream>
#define INF 1e8
using namespace std;
int N, M, X, K;
void solution(vector<vector<int>>(&graph)) {
	//초기화 세팅
	for (int i = 1; i < N + 1; i++) {
		graph[i][i] = 0;
	}
	for (int i = 1; i < N + 1; i++) { //이거는 지금 거쳐가는 노드 값 최소값을 확인하기 위해.
		for (int j = 1; j < N + 1; j++) {
			for (int k = 1; k < N + 1; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
}
int main() {
	cout << "첫째 줄에 전체 회사의 개수 N과 경로의 개수 M이 공백으로 구분되어 주어짐." << endl;
	cin >> N >> M;
	vector<int> temp(N + 1, INF);
	vector<vector<int>> graph(N + 1, temp);
	cout << "둘째 줄부터 M+1번 줄까지 연결된 두 회사의 번호가 공백으로 구분되어 주어짐" << endl;
	cout << "M + 2번 줄에는 X와 K가 공백으로 구분되어 주어짐.K와 X는 당연히 100이하" << endl;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		//아 여기서 문제가 생겼었네. a에서 b를 가는 방법만 1이 아니라 b에서 a를 가는 방법 또한 1이다.
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	cin >> X >> K;
	solution(graph);
	cout << endl;
	int result = graph[1][K] + graph[K][X];
	if (result >= INF)	cout << -1;
	else	cout << result;
}
#endif // 1
/*고찰 -> 해설보고
 별거 없다.
*/

/*<3> <전보>
어떤 나라에는 N개의 도시가 있다. 그리고 각 도시는 보내고자 하는 메시지가 있는 경우,
다른 도시로 전보를 보내서 다른 도시로 해당 메시지를 전송할 수 있다. 하지만 X라는
도시에서 Y라는 도시로 전보를 보내고자 한다면, 도시X에서 Y로 향하는 통로가 설치되어
있어야 한다. 예를 들어 X에서 Y로 향하는 통로는 있지만, Y에서 X로 통하는 통로가 없다면
Y는 X로 메시지를 못보낸다. 또한 통로를 거쳐 메시지를 보낼때에는 일정 시간이 소요된다.

어느날 C라는 도시에서 위급상황이 발생했다. 그래서 최대한 많은 도시로 메시지를 보내고자 한다.
메시지는 도시 C에서 출발하여 각 도시 사이에 설치된 통로를 거쳐, 최대한 많이 퍼져나갈 것이다.
각 도시의 번호와 통로가 설치되어 있는 정보가 주어졌을 때, 도시 C에서 보낸 메시지를 받게 되는 
도시의 개수는 총 몇개이며 도시들이 모두 메시지를 받는 데 까지 걸리는 시간은 얼마인지 계산하는 
프로그램을 작성하시오.

입력조건
첫째 줄에 도시의 개수 N, 통로의 개수 M, 메시지를 보내고자하는 도시 C가 주어진다.
N은 3만이하, M은 2십만 이하, C는 당연히 N개 이하이다.
둘째 줄부터 M+1번째 줄까지 통로에 대한 정보 X Y Z가 주어짐. 
특정도시 X에서 특정도시 Y로이어지는 통로가 있다면 그때 걸리는 시간 Z라는 의미
X Y는 N 이하이고, Z는 천이하
출력조건
도시 C에서 보낸 메시지를 받는 도시의 총 개수와 총 걸리는 시간을 공백으로 구분하여 출력

입력예시			출력예시
3 2 1			2 4
1 2 4
1 3 2

<접근 방법>
일단 플로이드 알고리즘도 될거 같고 다익스트라도 될거 같은데 다익스트라는 N제곱을 만족하고(혹은 ElogV)
플로이드는 N세제곱을 만족해야한다. N은 3만개까지니까 이미 초과이고
다익스트라는 이십만 곱하기 log삼만 이니까 다익스트라가 월등히 시간복잡도에서 앞서간다. 그리고 시작점은 고정이므로
이미 충분하다.
*/
//직접구현
#if 0
#include<iostream>
#include<queue>
#include<algorithm>
#define INF 1e8
using namespace std;
int N, M, C;

void dijkstra(vector<vector<pair<int, int>>> graph, priority_queue<pair<int, int>> (&pq), vector<int> (&dp), vector<bool>(&visited)) {
	//초기화 첫번째 시작점상태를 초기화, 보내려는 도시는 C로 주어진다.
	int start = C, confirmed;
	dp[start] = 0;
	visited[start] = true;
	for (auto n: graph[start]) {
		dp[n.first] = n.second;
		pq.push({ -1 * n.second, n.first });
	}
	//pq에서 가장 작은 가중치를 하나뽑고 탐색하고를 반복
	while (!pq.empty()) {
		start = pq.top().second;
		confirmed = pq.top().first * -1;
		visited[start] = true;
		pq.pop();
		for (auto n : graph[start]) {
			dp[n.first] = min(dp[n.first], confirmed + dp[n.second]);
			pq.push({ dp[n.first] * -1, n.first });
		}
	}
	//dp테이블에서 가장 큰 값을 출력하면 된다. 정렬하는 방법이 있을거 같고, 우선순위 큐도 있고, 최대값도 있다.
	//아 정렬하는 방법은 안되는게 INF 도달할수 없는 값이 있는 경우도 있으니까. 우선순위 큐도 안된다.
	//선형탐색하면서 최대값을 가져오고 INF가 아닌 경우에 카운트도 해야된다.
	int cnt = 0, answer = 0;
	for (int i = 1; i < N + 1; i++) {
		if (dp[i] >= INF || i==C) continue;
		cnt++;
		if (answer < dp[i]) answer = dp[i];
	}
	cout << cnt << endl;
	cout << answer;
}
int main() {
	cout << "첫째 줄에 도시의 개수 N, 통로의 개수 M, 메시지를 보내고자하는 도시 C가 주어진다." << endl;
	cin >> N >> M >> C;
	vector<vector<pair<int, int>>> graph(N + 1);
	priority_queue<pair<int, int>> pq;
	vector<bool>visited(N + 1);
	vector<int> dp(N + 1 , INF);
	cout << "둘째 줄부터 M+1번째 줄까지 통로에 대한 정보 X Y Z가 주어짐." << endl;
	cout << "특정도시 X에서 특정도시 Y로이어지는 통로가 있다면 그때 걸리는 시간 Z라는 의미" << endl;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	dijkstra(graph, pq, dp, visited);
}
#endif // 1
/*고찰 (책내용) : 별거 없다.*/
