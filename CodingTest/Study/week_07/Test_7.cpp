//1번
// 정렬알고리즘 일정 인덱스 이후부터
// sort는 문자열 정렬을 지원한다. https://www.delftstack.com/ko/howto/cpp/sort-string-in-cpp/
// 일정 인덱스 이후부터 정렬하고나서 그걸 원본과의 관계성을 어떻게..
//
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    for (int i = 0; i < strings.size(); i++) {
        sort(strings.begin(), strings.end());
    }

    return answer;
}

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
#if 1
#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[4] = { 0 };
    int j = 0;
    
    for (int i = 0; i < dartResult.size(); i++)
    {
        if (47 < dartResult[i] && dartResult[i] > 58) //스테이지의 시작
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
#endif

//3번
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