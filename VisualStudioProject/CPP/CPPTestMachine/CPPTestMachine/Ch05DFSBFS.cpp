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
DFS: Depth First Search, 깊이 우선 탐색, 그래프에서 깊은 부분을 우선적으로 탐색하는 알고리즘
BFS: B
*/
#if 0
#include<iostream>
#include<vector>
using namespace std;

int main() {

}

#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;

int main() {

}

#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;

int main() {

}

#endif
