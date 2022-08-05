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

#if 0
#include<iostream>
#include<vector>
using namespace std;

int main() {

}

#endif
