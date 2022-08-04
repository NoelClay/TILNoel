// 1번
/*
코니의 처음위치 C, 브라운의 처음위치 B가 주어진다. 코니는 처음 위치 C에서 1초 후 1만큼 움직이고, 
이후에는 가속이 붙어 1씩 빨라짐 브라운은 현재 위치 B에서 B-1 B+1 B*2 셋 중 하나로 움직일 수 있다.

위치값은 0~20만 브라운은 범위를 벗어나는 위치로 갈 수 없고, 코니가 범위를 넘어서면 -1리턴 게임끝 혹은 브라운이 코니 잡으면 게임끝

브라운은 1이상이면 *2가 무조건 더 많이 가는 방법이다.

<접근방법>
테스트 케이스를 살펴보니 일정한 규칙성이 보이질 않는다. 그렇다면 모든 경우의 수를 다 구하는 방법인데.. 
브라운의 경우엔 3^n 형태의 입력값이 생성. 20만 까지니까 
*/
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int C, int B) {
    int answer = 0;
    int step = 0;
    while (C != B) {
        answer++;
        step++;
        C += step;
        if (C - B >= B) {
            B *= 2;
        }
        else if (C < B) {
            B--;
        }
    }
    return answer;
}

int main()
{
    cout << solution(11, 2) << endl; // 정답 : 5
    cout << solution(10, 3) << endl; // 정답 : 3
    cout << solution(51, 50) << endl; // 정답 : 8
    cout << solution(550, 500) << endl; // 정답 : 28
    // 11 2 1
    // 12 3 2
    // 14 6 3
    // 17 12 4
    // 21 13 5
    // 26 26
    // 10 3 1
    // 11 4 2
    // 13 8 3
    // 16 16
    // 51 50 1
    // 52 49 2
    // 54 48 3
    // 57 47 4
    // 61 46 5
    // 66 45 6
    // 72 44 7
    // 79 88 8
    // 87 87
    //
}
#endif

// 2번
/*
NxN 인 체스판에서 진행되고, 사용하는 말의 개수는 k개 하나의 말 위에 다른 말을 올릴 수 있다. 각 칸은 흰색, 빨간색, 파란색
중 하나로 색칠되어 있음. 체스판 위에 말 k개를 놓고 시작한다. 말은 1번부터 k번까지 번호가 있음. 이동 방향 미리 정해져있음.
턴 한번은 1번부터 k번까지 순서대로 이동시키는 것. 한 말이 이동할 때 위에 올려져 있는 말도 함께 이동한다. 
말의 이동방향에 있는 칸에 따라서 말의 이동이 다르며 아래와 같다. 말이 4개 이상 쌓이면 게임 종료.

1) 이동하려는 판이 흰색인 경우에는 그 칸으로 이동한다. 이동하려는 칸에 말이 이미 있는 경우에는 
가장 위에 이동하려는 말을 올려놓는다. 이동하려는 말 위에 다른 말이 이미 있는 경우에는 모든 말들이 같이 이동한다.
예를들어 abc가 쌓여있는 상태에서 흰색이라 그 칸으로 이동하려는데 이미 de가 있는 경우면 deabc가 쌓인다.

2) 이동하려는 판이 빨간색인 경우 이동한 후에 말의 쌓여있는 순서를 반대로 바꾼다.
예를들어 abc가 이동하면 cba가 됨.
abc가 이동하고 그 칸에 이미 ed가 있으면 edcba가 됨.

3)이동하려는 판이 파란색인 경우 말의 이동 방향을 반대로 하여 한칸 이동함. 
방향을 바꾼 후에 이동하려는 칸이 파란색이면 혹은 바깥이면 가만히.

4) 체스판을 벗어나는 경우에는 파란색과 같은 경우 즉 이동하려는 판이 체스판 바깥이면 
말의 이동 방향을 반대로 하여 한칸 이동함. 방향을 바꾼 후에 이동하려는 칸이 파란색이면 가만히. 혹은 바깥이면 가만히

chess_map의 각 정수는 칸의 색을 의미 0흰 1빨 2파
말의 개수를 뜻하는 k와 현재 말의 정보를 담은 배열 start_horse가 주어짐.
말의 정보는 세 개의 정수로 이루어짐 행 열 이동방향
이동방향은 0오 1왼 2위 3아
턴의 번호가 1000을 넘기면 -1 return

<접근 방법>
일단 턴이 진행될때마다 순서는 정해져있다. start_horse[0]~start_horse[k-1] 까지 순서대로 
방향 값과 현재 체스맵 발판 상태에따라 그다음 위치값과 방향값이 갱신된다.
위치값은 알겠는데 쌓여있는걸 어떻게 컨트롤할까
쌓여있는 정보를 저장하는 스택이나 배열을 활용하면 어떨까? 예를들어 말이 4개라면 각 말마다 4개의 배열을 만들고
쌓일때마다 그 인덱스들을 리스트처럼 순서대로 저장하는 방식.
*/

#if 0
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(int K, vector<vector<int>> chess_map, vector<vector<int>> start_horse) {
    int answer = 1;
    vector<int> horse0;
    vector<int> horse1;
    vector<int> horse2;
    vector<int> horse3;
    vector<vector<int>> horses(4);

    stack<int> hStack0;

    //0오 1왼 2위 3아
    vector<vector<int>> moves = { {0,1}, {0,-1}, {-1,0}, {1,0} };

    for (int i = 0; i < K; i++) { //4개의 말에 순서대로 접근하기 위해
        //일단 이동하고자하는 방향대로 이동을 했을 경우에 바닥 새깔에 따라 바뀌므로
        start_horse[i][0] += moves[start_horse[i][2]][0];
        start_horse[i][1] += moves[start_horse[i][2]][1];
        if (chess_map[start_horse[i][0]][start_horse[i][1]] == 0) { //0번째말의 행열위치가 흰색이라면
            //만약 그 위치에 어떠한 말이 있다면 그 말 위에 쌓는다. 그걸 일일히 탐색?
            for (int j = 0; j < K; j++) {//이동 할때마다 start_horse의 상태를 확인해서 인덱스 체크?
                if (i == j) continue;
                else if(start_horse[j][0] == start_horse[i][0] and start_horse[j][1] == start_horse[i][1]){
                    horses[j].push_back(i); //j번째 horse배열에 i를 넣는다.
                }
            }
        }
    }

    return answer;
}

int main()
{
    int K = 4;
    vector<vector<int>> chess_map_1 = { {0, 0, 2, 0},
                                        {0, 0, 1, 0},
                                        {0, 0, 1, 2},
                                        {0, 2, 0, 0} };

    vector<vector<int>> chess_map_2 = { {0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0} };

    vector<vector<int>> start_horse_1 = { {0, 0, 0},
                                          {0, 1, 0},
                                          {0, 2, 0},
                                          {2, 2, 2} };

    vector<vector<int>> start_horse_2 = { {1, 0, 0},
                                          {2, 1, 2},
                                          {1, 1, 0},
                                          {3, 0, 1} };

    vector<vector<int>> start_horse_3 = { {0, 1, 0},
                                          {1, 1, 0},
                                          {0, 2, 0},
                                          {2, 2, 2} };

    vector<vector<int>> start_horse_4 = { {0, 1, 0},
                                          {0, 1, 1},
                                          {0, 1, 0},
                                          {2, 1, 2} };

    cout << solution(K, chess_map_2, start_horse_1) << endl; // 정답 : 2
    cout << solution(K, chess_map_1, start_horse_2) << endl; // 정답 : -1
    cout << solution(K, chess_map_2, start_horse_3) << endl; // 정답 : 9
    cout << solution(K, chess_map_2, start_horse_4) << endl; // 정답 : 3
}
#endif