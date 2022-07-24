//1번
// 정렬알고리즘 일정 인덱스 이후부터
// sort는 문자열 정렬을 지원한다. https://www.delftstack.com/ko/howto/cpp/sort-string-in-cpp/
// 일정 인덱스 이후부터 정렬하고나서 그걸 원본과의 관계성을 어떻게..
// 
// <2차시도>
// 원본의 인덱스를 저장하는 딕셔너리 튜플 페어 같은 자료구조를 이용할수 있을거 같다.
// strings의 입력은 총 50번이고
// 각 원소의 길이는 100 이하.
// 각 문자는 아스키 코드로 이루어져 있고 대소 비교가 가능하다. 사전식 정렬이란 오름차순 정렬과도 마찬가지이다.
// 오름차순 정렬 방법 중에 효율적인 방식은 합병정렬, 퀵정렬, 
// - 추가 정보 - 문자열의 대소비교 https://dojang.io/mod/page/view.php?id=346
// 문자열의 사전식 정렬은 단순하다. 문자열의 대소비교를 하면 문자열을 순차적으로 비교하면서 사전식으로 뒤에가야할 문자는
// 더 큰 문자열로 구분해준다. 문제는 그 대소비교를 어떤 인덱스부터 시작할지 이다. 그래서.. 아예 그 인덱스를 기준으로 자른
// 문자열을 만드는것도 방법일거 같다.
// 문자열 자르는 방법 https://velog.io/@qoehdcjswp/C-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%A0%95%EB%A6%AC
//
#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    //for (int i = 0; i < strings.size(); i++) {
    //    sort(strings.begin(), strings.end());
    //}
    vector<pair<string, int>> temp;

    for (int i = 0; i < strings.size(); i++) {
        temp.push_back(make_pair(strings[i].substr(n), i));
    }

    sort(temp.begin(), temp.end());

    for (int i = 0; i < strings.size(); i++) {//총 50번 반복하면서
    //정렬된 템프의 두번째 원소인 원래 저장되어있던 인덱스 정보를 참고해 그 스트링에 접근하여 pushback
        answer.push_back(strings[temp[i].second]);
    }

    return answer;
}

int main() {
    vector <vector<string>> s = { { "sun", "bed", "car" }, {"abcd", "abce", "cdx"}};
    int n[] = { 1,2 };
    auto result = solution(s[1], n[1]);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}

//고찰
//기본적으로 딕셔너리에 대한 정보없이 접근하면 너무 어려웠을거 같다. 문자열 대소비교가 이루어지는 과정을 검색해보고나서야
//어떻게 사전정렬이 이루어질지를 알수 있었다.
#endif

//2번
// 다트 게임은 3번 진행되고 각 점수 x=0~10 각 점수마다 제곱영역이 존재 sdt
// 운빨요소 스타상 아차상 스타상 당첨시 해당 점수와 바로 직전 점수를 각 2배로
// 아차상은 해당점수는 마이너스로 스타상은 처음부터 나올 수 있고 이때는 처음점수만 2배로
// 운빨요소는 여러번 나오는게 가능하며 중첩되서 계산 가능. 마이너스인 값은 똑같이 -2배로
// sdt는 점수마다 하나씩 있고 운빨요소는 둘 중 하나만 존재 가능하고 존재 안할 수도 있음.
// 
// 문자열 dartResult는 길이가 중구남방이다. 기본적으로 가장 적은 길이는 6개 가장 긴 문자열은 12개까지(10의 경우) 가능
// 숫자를 기준으로 각 스테이지 구별 가능할 것 각 스테이지의 첫 시작은 숫자.
// 아스키코드표 https://stepbystep1.tistory.com/10
//
#if 0
#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[4] = { 0 };
    int j = 0;
    
    for (int i = 0; i < dartResult.size(); i++)
    {
        if (47 < dartResult[i] && dartResult[i] < 58) //스테이지의 시작 즉 숫자라면
        {
            j++;    //score[0] 은 무조건 0이다.
            if (dartResult[i + 1] == '0') {//10인 경우
                score[j] == 10;
                i++;
            }
            else {
                score[j] += dartResult[i] -'0';
            }
        }
        else if (dartResult[i] == 'S')  score[j] = score[j];
        else if (dartResult[i] == 'D')  score[j] *= score[j];
        else if (dartResult[i] == 'T')  score[j] = score[j] * score[j] * score[j];
        else if (dartResult[i] == '#')  score[j] *= -1;
        else if (dartResult[i] == '*') {
            score[j - 1] *= 2;  score[j] *= 2;
        }
    }
    answer = score[1] + score[2] + score[3];
    return answer;
}

int main() {
    cout << solution("1S2D*3T");
}
//고찰
// 단순 로직 실수. 조건절에서 대소 비교를 할때 부등호의 방향이 잘못되어 항상 거짓으로 들어가 이상한 계산을 했었다.
//
#endif

//3번 -미해결-
//최단거리 길찾기 
// 1. 지나온 길을 다시 돌아갈 필요 없다. 
// 2. 도착점과 현재 위치를 비교해서 더 많이 남은쪽을 선택?
// 3. 캐릭터와 도착점을 동시에 진행
// dfs bfs
#if 0
#include<vector>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int curpos[2] = { 0 };
    int n = maps.size(), m = maps[0].size();
    for (int i = 0, j = 0; i < n;) 
    {
        if (n-i>m-j) {//세로로 가야할 길이 더 많이 남은
            if (maps[i + 1][j] == 1) curpos[0]++;
            else if (maps[i][j + 1] == 1) curpos[1]++;
        }
        else {//가로로 가야할 길이 더 많이 남은

        }
        maps[i][j];
        if (curpos[0] == n && curpos[1] == m) break;
        answer++;

    }

    return answer;
}
#endif