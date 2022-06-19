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
    char* c = strtok((char*)s.c_str(), " ");
    //공백기준으로 문자열 나누기 반복횟수 : 공백의 수 최대 n
    while (c) {
        v.push_back(c);
        c = strtok(NULL, " ");
    }
    //각 문자열을 대소만들기
    for (int i = 0; i < v.size(); i++) { //바깥 for문 : 공백의 수 m
        for (int j = 0; j < v[i].size(); j++) {//안쪽 for문은 쌍으로다가 변경
            if (v[i][j] < 91 && j % 2 == 1)//대문자이고, 홀수인덱스라면
                v[i][j] += 32;
            if (j % 2 == 0 && v[i][j] > 96)//짝수 인덱스에 소문자라면
                v[i][j] -= 32;
        }
        //i값 증가하기전에 answer에 공백이랑 함께 더해서 반환
        answer += v[i];
    }
    //완전 마지막에 공백 하나 제거
    answer.pop_back();
    
    return answer;
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
#if 0
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stack;
    //vector<stack<int>> sboard;    //스택 벡터는 만들어지지 않는구나.
    //각 열별로 top인덱스 정보를 기억한다면

    

    for (int i = 0; i < moves.size(); i++) {
        if (stack.empty())   stack.push(board[i][moves[i]]);
        else if (stack.top() == moves[i]) {
        stack.pop();
}
    }

    return answer;
}
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
#endif