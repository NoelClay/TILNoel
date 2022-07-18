//1번
// 첫번째 풀이
// 공백 기준으로 나누어 짝수 인덱스는 Upper 홀수 인덱스는 Lower
// 문자열을 공백기준으로 나누는 함수 https://notepad96.tistory.com/22
// 
// 의문해결: 어떻게 연속으로 토큰을 추출할까? https://repilria.tistory.com/197
// 
// 추가자료: 아스키코드 https://maincodes.tistory.com/68
//          문자열 마지막 제거 https://www.delftstack.com/ko/howto/cpp/remove-last-character-from-a-string-in-cpp/
// 
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    vector<string> v;
    string answer = "";
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            temp.push_back(s[i]);
        }
        else {
            temp.push_back(' ');
            v.push_back(temp);
            temp = "";
        }
    }
    temp.push_back(' ');
    v.push_back(temp);
    temp = "";
    //각 문자열을 대소만들기
    for (int i = 0; i < v.size(); i++) { //바깥 for문 : 공백의 수 m
        for (int j = 0; j < v[i].size(); j++) {//안쪽 for문은 쌍으로다가 변경
            if (v[i][j] == ' ')
                continue;
            else if (v[i][j] < 91 && j % 2 == 1)//대문자이고, 홀수인덱스라면
                v[i][j] += 32;
            else if (j % 2 == 0 && v[i][j] > 96)//짝수 인덱스에 소문자라면
                v[i][j] -= 32;
        }
        //i값 증가하기전에 answer에 공백이랑 함께 더해서 반환
        answer += v[i];
    }
    //완전 마지막에 공백 하나 제거
    answer.pop_back();
    
    return answer;
}
int main() {
    string s = "try hello world";
    cout << solution(s);
}


#endif

//2번
// 왠지 스택을 이용해서 터지는 작업을 해야될거 같다.
// 과정:
// mov [15351214]
// box [431132 4]
// 스택사용하기: https://life-with-coding.tistory.com/406
// 
// moves에 들어온 횟수대로 비교와 이동 삭제가 이루어질 것이므로 moves의 크기는 1000 
// 딱 n제곱만 허용
// 
// 추가적으로 든 생각: board도 stack형태면 어떨까? 혹은 top인덱스를 기억하는 방법?
// moves의 요소는 열에대한 정보이지 행에대한 상태를 담고 있지는 못한다.

//2번 두번째 시도
// 사라지는 횟수*2 를 반환 항상 짝지어 터지니까
// 배열은 따로 스택일 필요는 없어보이고 쌓이는 바구니는 무조건 스택이어야할것
// 만들어야 되는 배열은 각 열별로 원소가 있는지 없는지를 알 수 있는 구조여야함.
// 보드를 만약 탐색한다고 치면 30*30 = 900 이다. 제곱번 탐색하면 이미 백만에 근사
// 무브배열 입력횟수만큼 반복을 할것 1000번
// 열별로 최종깊이까지 탐색할 수도 있으니 그 안에서 총 30번까지 반복할것 3만번
// 그러면서 스택에 저장할때 top검사만 하고 pop할것이니까 추가 반복은 없다.
//
#if 0
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stack;
    //vector<stack<int>> sboard;    //스택 벡터는 만들어지지 않는구나.
    //각 열별로 top인덱스 정보를 기억한다면

    //Legacy
    //for (int i = 0; i < moves.size(); i++) {
    //    if (stack.empty())   stack.push(board[i][moves[i]]);
    //    else if (stack.top() == moves[i]) {
    //    stack.pop();
    //    }
    //}

    //new
    for (int i = 0; i < moves.size(); i++) { //무브배열 입력으로 원소가 존재할때까지 탐색할것이고
        for (int j = 0; j < board.size(); j++) { 
            //보드 한 열의 사이즈만큼 반복 탐색할 것인데 원소가 발견되면 그 즉시 그 원소를 스택에 추가하고
            //0으로 초기화하여 2차원 board 벡터를 업데이트한다.
            if (board[j][moves[i]-1] != 0)//j는 행정보 계속해서 하나씩 커지면 안으로 들어가고 moves[i]는 탐색할 열정보
            {
                if (stack.empty() || stack.top() != board[j][moves[i]-1]) {
                    stack.push(board[j][moves[i]-1]);
                    board[j][moves[i] - 1] = 0;
                }
                else if (stack.top() == board[j][moves[i]-1]) {
                    stack.pop();
                    answer += 2;
                    board[j][moves[i] - 1] = 0;
                }
                break;
            }
        }  
    }
    return answer;
}
int main() {
    vector<vector<int>> board = { {0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };

    cout << solution(board, moves);
}

//고찰
// 처음엔 구조 생성을 고차원 자료구조를 써야된다는 생각에 어렵게 짯었고, 결국 다 못했었다.
// 두번째 시도에서는 좀더 가벼운 자료구조를 사용해서 해도 최악의 경우에도 백만번을 넘기지 않기에 
// 2차원배열을 일일히 탐색하는 방법으로 짜서 해결했다.
// 하지만 디버깅과정에서 오래걸렸는데 탐색하고자하는 인덱스에 접근하는것을 -1해줘야된다는걸 깨닫고 해결했다.
//

#endif

//3번
// 대각선이 그려질때 가로든 세로가 되었든 어쨌든 둘다 1cm 이상임을 만족하는 경우에 
// 이 대각선이 통과한 정사각형들은 못쓰게 된다.
// 가로가 길면 대각선도 가로가 길고 세로가 길면 대각선도 세로가 길다. 
// 12/8 = 1.5 가로가 1cm일때 세로는 1.5cm까지 가서 정사각형 2개를 지운다.
// 16/8 = 2   가로가 1cm일때 세로는 2cm까지 가서 정사각형 2개를 지운다.
// 20/8 = 2.5 가로가 1cm일때 세로는 2.5cm까지 가서 정사각형 3개를 지운다.
// 긴거/짧은거 에 반올림을 한거 곱하기 짧은거 하면 
// 대각선이 짧은거 1cm 이동하는 동안 지우는 정사각형의 개수 곱하기 짧은거 전부 이동하는거리
// 
// 두번째시도
// 
// 
//
#if 0

#include<iostream>

using namespace std;

long long solution(int w, int h) {
    long long answer = 1;
    int cnt = 0;

    if (w > h)//가로가 더 긴경우
    {
        if (w % h == 0)//나누어 떨어지는 경우
        {
            cnt = w / h;
        }
        else
        {
            cnt = w / h + 1;
        }
        answer = w * h - cnt * h;
    }
    else//세로가 더 긴경우 혹은 같은 경우
    {
        if (h % w == 0)//나누어 떨어지는 경우, 같다면 무조건 나누어떨어지고
        {
            cnt = h / w;
        }
        else
        {
            cnt = h / w + 1;
        }
        answer = w * h - cnt * h;
    }
    return answer;
}

int main() {
    int w = 8, h = 12;
    cout << solution(8, 12);
}

#endif