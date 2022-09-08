/* <1> 꼭 필요한 자료구조 기초
탐색: 많은 양의 데이터 중에서 원하는 데이터를 찾는 과정
탐색 알고리즘에 대표적인 DFS/BFS

자료구조: 데이터를 표현하고 관리하고 처리하기 위한 구조
자료구조 중 대표적인 스택과 큐

재귀함수: DFS와 BFS를 구현하려면 재귀 함수도 이해하고 있어야 한다. 자기 자신을 호출하는 함수
무한반복을 멈추는 조건이 함수 구현 앞부분에 있어야한다. 입력값이 커져서 종료되는 경우도 있고 작아져서 종료되는 경우도 있다.

그래프: 노드와 간선으로 이루어진 개념. 노드는 정점이라고도 말한다. 노드와 노드 사이가 간선으로 연결되어있으면 
두 노드는 서로 인접한다고 표현함.
인접 행렬과 인접 리스트로 그래프를 표현함.
인접 행렬: 각 행과 열은 노드번호를 의미하고 안에 들어있는 요소값은 간선의 가중치값이다.
0 7 5
7 0 inf
5 inf 0
여기서 inf는 간선으로 연결되어있지 않은 경우를 나타내는 무한대이다. 무한대는 int INF = 9999999; 과 같은 방식으로 정의해서 사용.
인접리스트: 노드의 개수만큼 요소를 가진 리스트를 생성하고 각 노드번호는 인덱스가 된다. 
그 인덱스로 접근하면 숫자쌍(인접노드, 간선가중치)을 요소로 가지도록 2차원 리스트를 만든다.
a[0] = {{1, 7}, {2,5}};     a[1] = {{0,7}};     a[2] = {{0,5}}
2차원 인접 행렬은 자기 자신 노드에는 0, 인접노드에는 간선가중치, 비인접 노드에는 INF를 저장하여 메모리를 많이 차지.
하지만 각 행렬인덱스로 빠르게 접근 가능한게 장점.
2차원 인접 리스트는 자기 자신 노드 인덱스마다 인접한 노드의 정보만 저장하기에 메모리 적게 차지.
하지만 각 행인덱스로 접근은 하되 열 정보는 일일히 탐색해야 되기에 검색 시간은 조금 더 잡아먹음.
*/

// <스택>
// 후입선출 LIFO
#if 0
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main() {
    stack<int> s;
    // 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7) - 삭제() - 삽입(1) - 삽입(4) - 삭제()
    s.push(5);  s.push(2);  s.push(3);  s.push(7);  s.pop();    s.push(1);  s.push(4);  s.pop();
    // 스택의 최상단 원소부터 출력
    while (!s.empty()) {
        cout << s.top() << ' ';     s.pop();
    }
}
#endif

// <큐>
// 대기줄 선입선출 FIFO
#if 0
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
    queue<int> q;
    // 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7) - 삭제() - 삽입(1) - 삽입(4) - 삭제()
    q.push(5);  q.push(2);  q.push(3);  q.push(7);  q.pop();    q.push(1);  q.push(4);  q.pop();
    // 먼저 들어온 원소부터 추출
    while (!q.empty()) {
        cout << q.front() << ' ';       q.pop();
    }
}
#endif

// <재귀로 구현한 팩토리얼>
// 종료조건은 1이하일때 1을 리턴함으로써 거꾸로 종료
#if 0
#include<iostream>
#include<vector>
using namespace std;

int solution(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * solution(n - 1);
}
int main() {
    int n = 5;
    cout << solution(5);
}
#endif

/* <2> 탐색 알고리즘 DFS/BFS
결국 모든 자료를 탐색하고 싶을때 복잡한 구조로 얽혀있는 모든 자료를 다 탐색하고 싶을때 사용하는 알고리즘이라고 보면 된다.

DFS: Depth First Search, 깊이 우선 탐색, 그래프에서 깊은 부분을 우선적으로 탐색하는 알고리즘
1. 탐색 시작 노드를 스택에 삽입하고 방문 처리를 한다.
2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 있으면 그 인접 노드를 스택에 넣고 방문 처리를 한다. 
방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼낸다.
3. 2번 과정을 더이상 할 수 없을때까지 반복한다.

결국 방문처리와 인접데이터가 핵심. 인접되어있는지를 체크할 수 있게 노드와 간선의 형태로 자료를 배치하고
방문처리를 기록하고 올바르게 해석하는 자료구조를 만들어야함.

스택 방식은 방문한 데이터 위에 또 다른 데이터가 쌓이면 그 데이터가 완료될때까지 
아래 데이터는 사라지지 않는다는 특성은 마치 재귀와 비슷하다.
재귀 방식은 호출한 함수가 다른 함수를 또 호출하면 마치 스택처럼 그 함수 위에 함수가 쌓여서 맨 위에 함수가 하나씩 
완료되지 않는 이상 아래 함수의 종료가 일어나지 않는다. 이런 특성은 스택과 재귀가 같은 원리이기 때문에 생기는 현상.

*/
#if 0
#include<iostream>
#include<vector>
using namespace std;

vector<bool> visited(9); //그래서 9개 요소의 방문 여부를 표현할 불벡터
vector<vector<int>> graph(9);

void dfs(int startIdx) {
    visited[startIdx] = true; //처음 시작 노드는 방문 처리한다.
    cout << startIdx << ' '; //방문한 노드를 순서대로 출력할것.
    for (auto n : graph[startIdx]) { //현재 방문한 노드가 어떤 노드와 인접했는지 정보를 체크할 graph
        if (!visited[n]) {//만약 인접한 노드에 방문한 적이 없는 상태라면 
            dfs(n);
        }
    }
}
int main() {
    graph = { {},{2,3,8},{1,7},{1,4,5},{3,5},{3,4},{7},{2,6,8},{1,7} }; //9개의 요소
//위에서 배운 인접 리스트와 다른점은 간선의 가중치가 주어지지 않은 경우이다. 가중치가 있다면 pair와 같은 자료구조가 필요.
   
    dfs(1);
    //c++의 함수로 전달하는 인수 전달받는 매개변수는 복사된 형태를 받는다. 따라서 참조형의 형태일거라고 착각하면 안된다.
    //참조의 간편화를 위해 전역변수로 하고 실인수로는 지금 접근하려는 노드만 받는다.
}

#endif
/* 스택을 이용한 DFS처리
*/

#if 0
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<bool> visited(9); //그래서 9개 요소의 방문 여부를 표현할 불벡터
vector<vector<int>> graph(9);
stack<int> nodeStack;

void dfs(int startIdx) {
    visited[startIdx] = true; //처음 시작 노드는 방문 처리한다.
    cout << startIdx << ' '; //방문한 노드를 순서대로 출력할것.
    nodeStack.push(startIdx); //현재 방문한 노드!
    int idx = 0;
    while(!nodeStack.empty()){ //스택을 다 비우면 탐색끝
        //현재 방문한 노드가 어떤 노드와 인접했는지 정보를 체크할 graph
        auto n = graph[nodeStack.top()][idx];

        if (!visited[n]) {//만약 인접한 노드에 방문한 적이 없는 상태라면 
            //방문해야지. 방문한 노드 되고 방문 노드 처리하고, 출력까지
            nodeStack.push(n);
            visited[n] = true;
            cout << n << ' ';
            idx = 0;
        }
        else if (visited[n]) { //만약 지금 검색하는 노드에서 접근한 인접노드가 방문한 적이 있는 상태라면
            //다음 인접노드를 탐색할것이다. 그런데 인덱스 탐색에서 인덱스 오버플로가 발생하는걸 막아야함.
            if (idx < graph[nodeStack.top()].size() - 1) {
                idx++;
            }
            else {
                nodeStack.pop();
                //다시 처음부터 탐색할것이므로 또 이래야 오버플로가 안일어남
                idx = 0;
            }
        }
    }
}

int main() {
    graph = { {},{2,3,8},{1,7},{1,4,5},{3,5},{3,4},{7},{2,6,8},{1,7} }; //9개의 요소
//위에서 배운 인접 리스트와 다른점은 간선의 가중치가 주어지지 않은 경우이다. 가중치가 있다면 pair와 같은 자료구조가 필요.

    dfs(1);
}

#endif
/* 
BFS : Breadth First Search , 너비우선 탐색. 지금 현재 탐색한 노드에 인접한 가장 가까운 노드들을 전부 탐색하고나서야
다음 깊이만큼 떨어진 노드를 탐색하고 또 그 노드와 가장 가까운 노드를 다 탐색하는 방식으로 돈다.
핵심은 큐, 방문처리, 반복
1. 탐색 시작 노드를 큐에 넣고 방문처리한다.
2. 큐에서 노드를 맨 앞에거를 빼고 나서 해당노드에 인접한 노드 중 방문처리되지 않은 노드들을 전부 큐에 삽입하고 방문처리한다.
3. 2번을 반복하면서 앞에거가 하나씩 제거될때마다 뒤에 노드들이 추가되어 결국 모두 방문처리.

*/
#if 0
#include<queue>
#include<iostream>
#include<vector>
using namespace std;

vector<bool> visited(9); //그래서 9개 요소의 방문 여부를 표현할 불벡터
vector<vector<int>> graph(9);
queue<int> nodeQueue;

void bfs(int node) {
    //탐색 시작된 노드는 일단 방문처리하고 큐에 추가 방문처리하면 출력
    visited[node] = true;
    nodeQueue.push(node);
    cout << node << ' ';
    while (!nodeQueue.empty()) {
        //지금 탐색하고 있는 노드를 바탕으로 인접노드 중에 방문처리되지 않은 노드를 알아보려한다.
        node = nodeQueue.front();

        for (auto n : graph[node]) {
            if (!visited[n]) {
                visited[n] = true;
                nodeQueue.push(n);
                cout << n << ' ';
            }
        }
        //지금 탐색하고 있는 노드를 바탕으로 인접노드를 다 탐색했으면 지금 탐색하고 있는 노드를 뺀다.
        nodeQueue.pop();
    }
}

int main() {
    graph = { {},{2,3,8},{1,7},{1,4,5},{3,5},{3,4},{7},{2,6,8},{1,7} }; //9개의 요소
//위에서 배운 인접 리스트와 다른점은 간선의 가중치가 주어지지 않은 경우이다. 가중치가 있다면 pair와 같은 자료구조가 필요.
    bfs(1);
}

#endif

/*<3> 음료수 얼려 먹기
NxM 크기의 얼음틀이 있다. 구멍이 뚫려 있는 부분은 0 칸막이에 막혀 있는 부분은 1이라고 할때 
구멍이 뚤린 0이 서로 상하좌우로 붙어있을 경우에 연결되어있는 것으로 간주한다. 이때 얼음 틀의 모양이 주어지면
생성되는 얼음 덩어리들의 개수를 구하는 프로그램 작성.

입력조건: 첫번째 줄에 얼음틀의 N, M 크기 주어짐. 1000이하
둘째줄부터 얼음 틀의 형태가 주어진다. 이때 구멍이 뚫려있는 부분은 0 그렇지 않은 부분은 1

출력조건: 한번에 만들 수 있는 아이스크림의 개수 출력

입력예시
4 5
00110
00011
11111
00000
출력예시
3

입력예시
15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111
출력예시
8
*/

/*
접근방법
인접한 0의 정보를 담을 자료구조가 필요하다. n m은 1000이하이므로 연속적으로 중복된 데이터 있을 위험있음 따라서
인접 리스트형태가 좋아보임.
규칙성이라곤 찾아볼수 없는 모든 경우의 수를 다 탐색해야되기때문에 dfs bfs가 적절
<인접리스트 만들기>
인접리스트를 만들려고하다보니... 이미 1000x1000은 백만으로 백만개의 데이터를 다뤄야한다. 일단 데이터를 전부 그래프에 넣는다.
<탐색방법>
일차 선형자료와 달리 애초에 자료가 2차원 벡터이다. 행 열 인덱스 2개를 참조해야한다.
<상하좌우에 0이 있다면>
0의 상하좌우에 0이 있다면 연결되었다는 소리. 어떤 한 노드가 0이여서 스택에 집어넣었다면 
상하좌우 순서대로 탐색하면서 0이라면 스택에 추가할 것이다.
만약 상하좌우 순서대로 탐색했는데 0이 없다? 그러면 스택을 팝
그렇게 스택이 비게 된다면 그게 얼음 한덩이
<전체적으로는 행열 전체를 탐색하면서 상하좌우 스택로직을 돌린다.>
*/
#if 0
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited(15, vector<bool>(14));
stack<pair<int, int>> nodeStack;
int row = 15, col = 14;

int solution(int n, int m) {
    graph = { 
    {0,0,0,0,0,1,1,1,1,0,0,0,0,0}, {1,1,1,1,1,1,0,1,1,1,1,1,1,0}, {1,1,0,1,1,1,0,1,1,0,1,1,1,0},
    {1,1,0,1,1,1,0,1,1,0,0,0,0,0}, {1,1,0,1,1,1,1,1,1,1,1,1,1,1}, {1,1,0,1,1,1,1,1,1,1,1,1,0,0},
    {1,1,0,0,0,0,0,0,0,1,1,1,1,1}, {0,1,1,1,1,1,1,1,1,1,1,1,1,1}, {0,0,0,0,0,0,0,0,0,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,0,0,0}, {0,0,0,1,1,1,1,1,1,1,1,0,0,0}, {0,0,0,0,0,0,0,1,1,1,1,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,0,0,1,1}, {1,1,1,0,0,0,1,1,1,1,1,1,1,1}, {1,1,1,0,0,0,1,1,1,1,1,1,1,1} };

    int answer = 0;
    int dRow[] = { -1, 1, 0, 0 };   //상하좌우
    int dCol[] = { 0, 0, -1, 1 };

    //visited[n][m] = true;
    //nodeStack.push(make_pair(n,m));
    //cout << n <<':' << m << ' ';

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (graph[i][j] == 0 && visited[i][j] == false) {
                visited[i][j] = true;
                nodeStack.push(make_pair(i, j));
                cout << i << ':' << j << endl;
                while (!nodeStack.empty()) {
                    auto newn = nodeStack.top().first;
                    auto newm = nodeStack.top().second;
                    //새로운 노드가 쌓여서 돌아가게 하기 위해 여기서 popp한다
                    nodeStack.pop();
                    for (int k = 0; k < 4; k++) {
                        auto udlrRow = newn + dRow[k];
                        if (udlrRow < 0) udlrRow = 0;
                        else if (udlrRow >= row) udlrRow = row - 1;
                        auto udlrCol = newm + dCol[k];
                        if (udlrCol < 0) udlrCol = 0;
                        else if (udlrCol >= col) udlrCol = col - 1;
                        if (graph[udlrRow][udlrCol] == 0 && visited[udlrRow][udlrCol] == false) {
                            visited[udlrRow][udlrCol] = true;
                            nodeStack.push(make_pair(udlrRow,udlrCol));
                            cout << udlrRow << ':' << udlrCol << endl;
                            //만약 조건에 맞는 연결된 0이 상하좌우 안에 있으면 스택들이 쌓이고
                            //그 새로운 노드로 다시 상하좌우가 돌아가야함.
                        }
                    }
                }
                //그렇게 0인접이 끝나면, answer은 하나 증가
                answer++;
            }
        }
    }
    return answer;
}

int main() {

    cout << solution(0, 0);
}

#endif
/*고찰
얼떨결에 풀려버렸다. stack 구조와 visited로 방문을 체크한다하더라도 주어진 데이터에 맞는 탐색방식구조를 만들기가
쉽지 않았다. 1.pop의 위치 선정이 햇갈렸고 2. 인덱스오버플로에서도 오래걸렸다. 여러 dfs 문제를 풀면서 익숙해지는 수밖에..
답지 확인
메인 메모리에서 함수호출처리는 스택구조를 사용하여 처리된다. 따라서 재귀적으로 함수를 호출함으로서 깊이탐색을 수행함.
확실히 재귀다보니까 오버플로 언더플로 뿐만 아니라 구현도 깔끔해진다. 하지만 오래걸릴거를 고려하여 실무에서는 
재귀함수를 잘 쓰지 않는다길래 stack을 만들어서 풀어보았다. 논리자체는 크게 다르지 않은거 같다.

*/
//<답지 풀이 dfs>
#if 0
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int graph[1000][1000];

// DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
bool dfs(int x, int y) {
    // 주어진 범위를 벗어나는 경우에는 즉시 종료
    if (x <= -1 || x >= n || y <= -1 || y >= m) {
        return false;
    }
    // 현재 노드를 아직 방문하지 않았다면
    if (graph[x][y] == 0) {
        // 해당 노드 방문 처리
        // 어차피 graph 자료가 바뀌더라도 상관 없으니 visited 만드는거 대신에 그냥 1로 바꾸는 처리.
        graph[x][y] = 1;
        // 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
        
        dfs(x - 1, y);
        dfs(x, y - 1);
        dfs(x + 1, y);
        dfs(x, y + 1);
        return true;
    }
    //방문한 인덱스라면 혹은 칸막이라면 그냥 false 반환해서 result가 증가하는 일은 없다.
    return false;
}

int main() {
    // N, M을 공백을 기준으로 구분하여 입력 받기
    cin >> n >> m;
    // 2차원 리스트의 맵 정보 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
    // 모든 노드(위치)에 대하여 음료수 채우기
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 현재 위치에서 DFS 수행
            if (dfs(i, j)) {
                result += 1;
            }
        }
    }
    cout << result << '\n'; // 정답 출력 
}
#endif

/* <4> 미로 탈출
동빈이는 N x M 크기의 직사각형 형태의 미로에 갇혀 있다. 미로에는 여러 마리의 괴물이 있어 이를 피해 탈출해야한다.
동빈이의 위치는 (1,1)이고 미로의 출구는 (N,M)의 위치에 존재하며 한번에 한 칸씩 이동할 수 있다. 이 때 괴물이 있는 
부분은 0으로, 괴물이 없는 부분은 1로 표시되어 있다. 미로는 반드시 탈출할 수 있는 형태로 제시된다.
이때 동빈이가 탈출하기 위해서  움직여야 하는 최소 칸의 개수를 구하시오. 
칸을 셀 때는 시작 칸과 마지막 칸을 모두 포함해서 계산한다.

입력조건: 첫째 줄에 두 정수 N,M 이 주어짐. 200이하
두번째 줄부터 각각 M개의 정수로 미로의 정보가 주어짐. 각각의 수들은 공백 없이 붙어서 입력으로 제시됨. 
또한 시작 칸과 마지막 칸은 항상 1이다.

출력조건: 최소 이동 칸의 개수를 출력한다. 출발칸과 탈출칸 2개는 반드시 포함됨.

입력예시
5 6
101010
111111
000001
111111
111111
출력예시
10
*/
/*접근방법
BFS 문제라는 사전정보가 있었다. 입력예시에 따라 로직은 천차만별일것이므로 무수히 많은 경우의 수를 
전부 탐색하는 방법만이 일반해를 도출할 수 있을것이다. 그럴때 쓰는게 dfs bfs
한칸씩 이동할때마다 카운팅 하지만 갔던길을 다시 돌아가는 방식은 루트로 쓰이지 않을것이다. 뭐하러 그렇게해
<카운팅을 저장해서 반환하는 구조 필요.>
<상하좌우에 1이 있는지를 탐색해서 그때 마다 bfs 경우의 수로 추가됨>
<하다가 상하좌우에 갈수 있는 길이 없게 되어버린경우는 -1 반환하고 종료>
<모든 데이터를 탐색하는 자료구조이다. 그런데 탐색을 하던 도중에 n-1,m-1 인덱스에 도달한 녀석은 그대로 반환 종료>
<상하좌우 중 어디를 선택할지는 어떻게 정할까>
<visited를 어떻게 구현해야될지 도저히 모르겠다. 그걸 해야... 의미없는 탐색이 줄어들고 무한반복이 일어나지 않을텐데..>
*/
#if 0
#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<int>> ways;
queue<pair<int,int>> nodeQueue;
vector<vector<bool>> visited;

//상하좌우
int dRow[] = { -1,1, 0, 0 };
int dCol[] = { 0, 0, -1, 1 };

int solution(int Row, int Col) {
    int answer = 0;
    int turn = 0;
    //현재 탐색위치는 일단 큐에 저장해.
    nodeQueue.push({ 0,0 });
    turn++;
    ways[0][0] = turn;
    /*visited[0][0] = true;*/
    //방문했는지 안했는지는 graph를 0으로 바꿔서
    graph[0][0] == 0;
    while (!nodeQueue.empty()) {
        auto curRow = nodeQueue.front().first;
        auto curCol = nodeQueue.front().second;
        //큐에 저장된 정보 빼냈으면 실제로도 빼낸다.
        nodeQueue.pop();

        for (int i = 0; i < 4; i++) {
            auto newRow = curRow + dRow[i];
            if (newRow < 0 || newRow > n - 1)  continue;
            auto newCol = curCol + dCol[i];
            if (newCol < 0 || newCol > m - 1) continue;

            if (graph[newRow][newCol] == 1) {//1이면 큐에 추가할것이야.
                nodeQueue.push({ newRow, newCol });
                ways[newRow][newCol] = ways[curRow][curCol] + 1;
                graph[newRow][newCol] == 0;
            }
            if (newRow == n - 1 && newCol == m - 1) {
                return ways[newRow][newCol];
            }
        }
    }
    return answer;
}

int main() {
    cin >> n >> m;
    //vector<int>temp;
    //vector<bool>boolTemp;
    //int t;
    ////for (int i = 0; i < n; i++) {
    ////    for (int j = 0; j < m; j++) {
    ////        cin >> t;
    ////        temp.push_back(t);
    ////    }
    ////    graph.push_back(temp);
    ////    temp.clear();
    ////}
    //for (int j = 0; j < m; j++) {
    //    boolTemp.push_back(false);
    //}
    //for (int i = 0; i < n; i++) {
    //    visited.push_back(boolTemp);        
    //}
    graph = { {1,0,1,0,1,0},{1,1,1,1,1,1},{0,0,0,0,0,1},{1,1,1,1,1,1},{1,1,1,1,1,1} };
    ways = { {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} };

    cout << solution(n,m);
}
#endif
/*고찰
방문을 어떻게 처리할지, 카운트는 어떻게 저장할지 등에서 굉장히 오래 막히었다.
graph의 요소를 직접 변경하는 방식으로 로직을 생각하는걸 자주 해야겠다.
*/