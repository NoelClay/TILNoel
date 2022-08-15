// 1번
/*
크기가 NxN개인 도시가 있다. 각 칸은 빈칸 0, 집 1, 치킨집 2 로 채워져 있다. 도시의 각칸은 (r,c) 행,렬로 표기하고
맨왼쪽 위는 1,1 맨 오른쪽 아래는 r,c로 표기한다.
집과 치킨집 사이의 가장 가까운 거리는 치킨거리다. 치킨 거리는 .행차이 + 열차이 로 구한다.
도시에서 최대 치킨집의 개수 M이 주어지면 주어진 배열에서 M개를 제외한 나머지 치킨집을 삭제한다.
도시의 총치킨거리가 가장 작게되는 함수를 만들어라.
입력조건
2 <= N <= 50, 1 <= M <=13
도시배열 city가 주어짐. 집의 개수는 2N개를 넘지 않고, 적어도 1개이상 존재.  M <= 치킨집의 개수 <= 13
출력조건
치킨거리의 총합이 출력됨.

<접근방법>
탐색을 해야한다.
결국 1은 남아있고 2는 삭제된다. 각 1을 기준으로 2까지 거리를 계산하여 저장해둔다.
m값에 따라 2를 선택하는 경우의 수를 전부 찾고 그때마다 각 1이 가질 수 있는 가장 최소값을 반환하면 되지 않을까?
(실패)어떤구조로 저장해서 어떤 구조로 찾아서 어떻게 해야될지 전부 막막

<접근방법2>
city에서 2인 경우의 좌표를 저장해두고 M개만큼 뽑는 경우의 수의 2차원 벡터를 전부 만든다. 
그 다음에 1의 인덱스와 2의 인덱스사이의 거리를 전부 계산하고 최소값을 반환해서 answer에 카운트한다.
그렇게하면 결국 최소 치킨거리들이 구해질 것.
이제 가장 최소 치킨거리의 합이 가장작을때의 그 값이 최소값.
<경우의 수><조합>
https://ansohxxn.github.io/algorithm/combination/

*/
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//조합 저장소
vector<vector<pair<int, int>>> combTank;

void Combination(vector<pair<int, int>> arr, vector<pair<int,int>> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        combTank.push_back(comb);
    }
    else if (depth == arr.size())  // depth == n // 계속 안뽑다가 r 개를 채우지 못한 경우는 이 곳에 걸려야 한다.
    {
        return;
    }
    else
    {
        // arr[depth] 를 뽑은 경우
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);
        //한번 들어간 combination은 재귀적으로 계속 진행되며 호출하고 종료된다.

        // arr[depth] 를 뽑지 않은 경우
        Combination(arr, comb, r, index, depth + 1);
    }
}


int solution(int N, int M, vector<vector<int>> city_map) {
    vector<pair<int, int>> comb(M);
    vector<pair<int, int>> twoVector;
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (city_map[i][j] == 2) {
                twoVector.push_back({ i, j });
            }
        }
    }
    Combination(twoVector, comb, M, 0, 0);

    return answer;
}

int main()
{
    vector<vector<int>> city_1 = { {0, 0, 1, 0, 0},
                                   {0, 0, 2, 0, 1},
                                   {0, 1, 2, 0, 0},
                                   {0, 0, 1, 0, 0},
                                   {0, 0, 0, 0, 2}, };

    vector<vector<int>> city_2 = { {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0}, };

    vector<vector<int>> city_3 = { {0, 2, 0, 1, 0},
                                   {1, 0, 1, 0, 0},
                                   {0, 0, 0, 0, 0},
                                   {2, 0, 0, 1, 1},
                                   {2, 2, 0, 1, 2}, };

    cout << solution(5, 3, city_1) << endl; // 정답 : 5
    cout << solution(5, 1, city_2) << endl; // 정답 : 11
    cout << solution(5, 2, city_3) << endl; // 정답 : 10
}
#endif

// 2번
/*
롤케이크를 두 조각으로 잘라서 한 조각씩 나눠 먹으려고 함. 여러 토핑들이 일렬로 올려져 있다. 롤케이크를 공평하게 나눠먹으려는데
롤케이크의 크기보다 토핑의 개수에 더 관심이 많다. 어떻게 잘렸는지 상관없고 오로지 두 조각에 토핑의 가지수(종류)가 
공평하게 올라가 있는지에 관심이 있다.
예를들어 12131412 가 있을때 1213 / 1412 or 12131/ 412 두개 다 전부 3가지씩 존재하는 공평한 방법이고 공평한 방법의수는 
2가지 이다. 공평한 방법의 수를 리턴하는 솔루션 함수

입력조건
1<=topping.size() <= 백만 ,   1<=topping의 각 원소 크기 <= 10000

입력예시    출력예시
12131412        2
12314           0

<접근방법>
중복을 제한하기 위해 map을 사용하고 (left, int) (right, int)를 각각 왼쪽에서 오른쪽에서 오면서 저장하고
left >= right 조건에 해당하면 인덱스가 서로 만났다는 뜻. 이때 더하는걸 멈추고 각 부분 사이즈 비교해서..
(실패)
*/
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = -1;

    return answer;
}

int main()
{
    cout << solution({ 1, 2, 1, 3, 1, 4, 1, 2 }); // 정답 : 2
    cout << solution({ 1, 2, 3, 1, 4 }); // 정답 : 0
}
#endif

// 3번
/* 초단위로 기록된 주식 가격이 담긴 배열 prices, 가격이 떨어지지 않은 기간은 몇 초인가를 return
<접근방법>

프라이스를 스택에 추가되어있는 것보다 크면 추가하고 작으면 카운팅이 끝나면서 스택에 팝이 일어난다. 이때 반복문으로 작을때까지
반복문을 돌리면서 카운팅은 자동으로 인덱스로 이루어진다.

*/
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> count(5);
    int cnt = 0;

    stack<int> istack;
    //22311
    for (int i = 0; i < prices.size(); i++) {
        if (istack.empty() || istack.top() <= prices[i]) {
            istack.push(prices[i]);
        }
        else {
            while (!(istack.top() > prices[i])) {
                
            }
            count[i] = cnt;
            istack.pop();
        }
        cnt++;
    }

    return answer;
}

int main()
{
    // 정답 : 4 3 1 1 0
    for (auto iter : solution({ 1, 2, 3, 2, 3 }))
    {
        cout << iter << " ";
    }
}
#endif