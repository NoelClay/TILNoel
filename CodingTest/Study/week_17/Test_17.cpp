/*1번
카카오에 신입 개발자로 입사한 남영이는 선배 개발자로부터 과제를 받음.
문제는 소스 코드내 작성된 괄호가 개수는 맞지만 짝이 맞지 않은 형태로 작성되어
오류가 나는 것을 알았다.
소스 코드 내에 모든 괄호를 뽑아서 올바른 순서대로 배치된 괄호 문자열을 알려주는 프로그램
개발하면 된다.
용어의 정의
'('와')' 로만 이루어진 문자열이 있는 경우, '('의 개수와 ')'의 개수가 같다면 이를 균형잡힌
괄호 문자열이라고 부른다.
그리고 여기에 '('와')'의 괄호의 짝도 모두 맞을 경우 이를 올바른 괄호 문자열이라고 부른다.
예를들어, "(()))("와 같은 문자열은 균형잡힌 문자열이지만 올바른 괄호 문자열은 아니다.
'('와')'로만 이루어진 문자열 w가 "균형잡힌 괄호 문자열이라면" 다음과 같은 과정을 통해
올바른 괄호 문자열로 변환가능하다.
1. 입력이 빈 문자열인 경우 빈문자열 반환
2. 문자열 w를 두 균형잡힌 괄호 문자열 u, v로 분리한다. 
단 u는 군형잡힌 문자열로 더이상 분리할 수 없어야하고 v는 빈문자열상태가 가능하다.
3. 문자열 u가 올바르다면 문자열 v를 가지고 다시 1단계부터 수행
3-1. 수행한 결과 문자열을 u에 이어붙임.
4. 문자열 u가 올바르지 않다면 아래 과정을 수행
4-1. 빈 문자열에 첫 문자로 '('를 붙인다.
4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어붙인다.
4-3. ')'를 다시 붙인다.
4-4. u의 첫번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 
뒤에 붙임.
4-5. 생성된 문자열을 반환한다.

w의 길이는 1000이하인 짝수. 항상 균형잡힌 문자열만 주어짐. 올바른 문자열이면 그대로 return

*/
#if 0
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool firstcheck(string p) {
    if (p == "") return true;
}
//스택으로 수정, 인덱스로 분리
pair<string, string> secondcheck(string p) {
    bool isend = false;
    int lcnt = 0, rcnt = 0;
    string u, v;
    for (auto n:p) {
        if (isend) v += n;
        else {
            if (n == '(') lcnt++;
            else rcnt++;
            u += n;
            if (lcnt == rcnt) isend = true;
        }
    }
    return { u, v };
}
void finalcheck(pair<string, string> spair) {
    string u = spair.first, v = spair.second;
    int lcnt = 0, rcnt = 0;
    bool isRight = false;
    for (auto n : u) {
        if (n == '(') lcnt++;
        else rcnt++;
        if (lcnt == rcnt) break;
    }

    if (lcnt + rcnt == u.size()) isRight = true;
    //3번
    if (isRight) {
        bool isblank = firstcheck(v);
    }
    //4번
    else
    {

    }
}


string solution(string p) {
    
    string answer = "";
    return answer;
}

int main()
{
    cout << solution("(()())()");
    cout << solution(")(");
    cout << solution("()))((()");
}
#endif
/*고찰

*/

// 2번
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int n = survey.size();
    map<char, int> dp = { {'R',0},{'T',0},{"CF",0},{"FC",0},
        {"JM",0},{"MJ",0},{"AN",0},{"NA",0}};
    for (int i = 0; i < n; i++) {
        if (choices[i] == 4) { continue; }
        else if (choices[i] > 4) { //동의한다는 뜻 5는 1점 6은 2점 7은 3점
            dp[survey[i][1]] += (choices[i] - 4);
        }
        else {
            dp[survey[i]] += (4 - choices[i]);
        }
    }
    if (dp["RT"] >= dp["TR"]) answer += 'T';
    else answer += 'R';
    if (dp["CF"] >= dp["FC"]) answer += 'F';
    else answer += 'C';    
    if (dp["JM"] >= dp["MJ"]) answer += 'M';
    else answer += 'J';    
    if (dp["AN"] >= dp["NA"]) answer += 'N';
    else answer += 'A';
    return answer;
}

int main()
{
    cout << solution({ "AN", "CF", "MJ", "RT", "NA" }, { 5,3,2,7,5 }) << endl;
    cout << solution({ "TR", "RT", "TR" }, { 7,1,3 })<<endl;
}
#endif