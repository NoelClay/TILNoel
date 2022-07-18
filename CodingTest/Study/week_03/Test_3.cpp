//1번
//2개의 배열이 들어오고 배열의 길이만큼 인덱스를 탐색하는 동안 
//signs를 검사해서 true면 + false명 -화 하여 answer에 누적하고 반환
#if 0
#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for (int i = 0; i < signs.size(); i++)
    {
        if (signs[i] == true) 
            answer += absolutes[i];
        else
            answer -= absolutes[i];
    }

    return answer;
}
int main()
{
    int N;
    vector<int> absolute;
    vector<bool> signs;
    char check;
    int icheck;

    cout << "N: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << "부호 입력: ";
        cin >> check;
        if (check == '-')
            signs.push_back(false);
        else
            signs.push_back(true);
        cout << "숫자 입력: ";
        cin >> icheck;
        absolute.push_back(icheck);    
    }

    cout << solution(absolute, signs);
}
#endif

//2번
//전체 학생 수 만큼
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<bool> cloth(n, false);
    int cnt = 0;

    for (int i = 0; i < reserve.size(); i++) {
        cloth[reserve[i]-1] = true;
    }
    
    for (int i = 0; i < lost.size(); i++) {
        if (cloth[lost[i] - 1] == true) {
            cloth[lost[i] - 1] = false;
            cnt++;
        }
        else if (lost[i] > 1 && cloth[lost[i] - 2] == true) {
            cloth[lost[i] - 2] = false;
            cnt++;
        }
        else if (lost[i] < n && cloth[lost[i]] == true) {
            cloth[lost[i]] = false;
            cnt++;
        }
    }
    answer = n - lost.size() + cnt;
    return answer;
}

int main()
{
    int n = 3;
    vector<int> lost = { 3 };
    vector<int> reserve = { 1};
    cout << solution(n, lost, reserve) << endl;
}

#endif

//3번
//인덱스를 하나씩 탐색할때 마다 초를 카운트 한다. cnt++
//인덱스가 증가할때마다 현재 인덱스의 값과 그 이전의 값들을 n번 탐색하며 대소비교하되 n제곱....
//작아졌다면 그때의 cnt값을 count 변수에 넣어준다.
//count 
//추가된 배열의 카운팅초를 반환한다.
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> count(prices.size());
    int cnt = 0;
    for (int i = 0; i < prices.size(); i++) {
        for (int j = 0; j < i; j++) 
        {
            if (answer[j] > answer[i] && count[j] == 0)//가격이 떨어졌다면 그리고 초가 할당된적이 없다면
            {
                count[j] = cnt;//떨어진시점의 초를 할당.
            }
        }
        cnt++;
        
    }
    //cnt가 할당되지 않은 count배열을 찾아 전부 cnt를 할당
    for (int i = 0; i < prices.size(); i++) {
        if (count[i] == 0) {
            count[i] = cnt;
        }
    }
    //각 가격별 어느시점에 카운팅 스탑이 적용되었는지가 count에 저장되어 있음.
    //각 가격별 시작 시점이 곧 인덱스 이므로 인덱스만큼 빼주면 됨.
    for (int i = 0; i < prices.size(); i++) {
        answer[i] = count[i] - i;
    }
    return answer;
}

int main()
{
    int N = 0;
    vector<int> prices;
    int icheck;
    

    cout << "N: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << "가격입력: ";
        cin >> icheck;
        prices.push_back(icheck);
    }
    vector<int> answer(N);
    answer = solution(prices);

    for (int i = 0; i < N; i++) {
        cout << answer[i];
    }

}
#endif

//3번 복습 1 미해결
// <legacy>
//인덱스를 하나씩 탐색할때 마다 초를 카운트 한다. cnt++
//인덱스가 증가할때마다 현재 인덱스의 값과 그 이전의 값들을 n번 탐색하며 대소비교하되 n제곱....
//작아졌다면 그때의 cnt값을 count 변수에 넣어준다.
//count 
//추가된 배열의 카운팅초를 반환한다.

//<new>
// 각 초마다 가격이 갱신되는데 그 당시의 가격들이 떨어지기 전까지 초를 세는 문제
// 저장되어 있는 숫자보다 더 작은 숫자가 들어올때 초 카운팅이 멈춘다.
// 프라이스 배열의 길이는 십만이므로 이중포문은 허용되지 않는다.
// 이렇게 입력이 긴 문제는 1. 규칙성 2. 자료구조 를 활용한 응용이 필요하다.
// 그리고 뭔가 연속된 입력값의 대소관계를 비교해서 이미 안에 들어있던 자료의 카운팅을 멈추는건
// 스택을 활용하면 될것같은 느낌이 든다.
// 
// 반복문을 돌리면서 카운팅은 자동으로 인덱스로 이루어진다.
// 
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;
    vector<int> count(5);
    int cnt = 0;
    
    stack<int> istack;
    cnt = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (istack.empty() || istack.top() <= prices[i]) {
            istack.push(prices[i]);
        }
        else {
            count[i] = cnt;
            istack.pop();
        }
        cnt++;
    }
    for (int i = 0; i < prices.size(); i++) {
        if (count[i] == 0) {
            count[i] = cnt;
        }
    }
    for (int i = 0; i < prices.size(); i++) {
        answer[i] = count[i] - i;
    }
    return answer;
}

int main()
{
    int N = 5;
    vector<int> prices = {1, 2, 3, 2,3};
    int icheck;


    //cout << "N: ";
    //cin >> N;

    //for (int i = 0; i < N; i++) {
    //    cout << "가격입력: ";
    //    cin >> icheck;
    //    prices.push_back(icheck);
    //}
    //
    auto answer = solution(prices);

    for (int i = 0; i < N; i++) {
        cout << answer[i];
    }

}
#endif