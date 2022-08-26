// 1번 짝짓기 문제
/* 정수로 이루어진 2개의 문자열이 주어진다.이때 각 문자열을 탐색하며 서로 일치하는 짝지어질 수 있는 짝꿍 수를
찾아내어 뽑아낸 뒤에 그 짝궁수로 만들 수 있는 가장 큰 수를 문자열로 반환한다.
입력조건
각 문자열의 자리수는 3~3백만
0으로 시작하는 숫자는 주어지지 않는다.

<접근방법>
예외처리100과 200345 는 짝궁수가 0,0이다 이걸로 만들 수 있는 가장 큰 수는 0. 0밖에 존재않하는 경우의 수를 생각하라.

어차피 순서는 중요하지 않다. 그렇다면 정렬을 해놓고 풀이하는것도 방법이 될 수는 있으나 결국 3백만의 탐색을 해야하는가?
정렬을 해놓고 이분탐색 하는 방법? 아니면 아..어차피 각 수는 0~9까지니까 계수 정렬마냥 계수배열을 만들으면 일치하는만큼은 할건데...
결국 3백만을 2번 탐색해야되는데....
일단 시간초과만 고려하지 않는다면 계수배열이 가장 좋아보이긴한다..
*/
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int arrX[10] = { 0 };
    int arrY[10] = { 0 };

    for (auto n : X) {
        arrX[n - 48]++;
    }
    for (auto n : Y) {
        arrY[n - 48]++;
    }

    for (int i = 0; i < 10; i++) {
        if (arrX[i] > arrY[i]) {//둘중 더 작은 값이 항상 arrX에 저장되게
            arrX[i] = arrY[i];
        }
    }
    for (int i = 9; i >= 0; i--) {
        while(arrX[i] != 0) { //카운팅이 하나 이상 들어가있다면 0이 될때까지 반복한다.
            answer += (i + 48); //아스키 아스키 숫자를 계수만큼 반복해서 추가할 것이다.
            arrX[i]--;
        }
    }
    if (answer == "") {//아무것도 추가되지 않았다면
        answer = "-1";
    }
    else if (answer[0] == '0') { //최대값이 0이라면
        answer = "0";
    }

    return answer;
}

int main()
{
    cout << solution("100", "2345") << endl; // 정답 : -1
    cout << solution("100", "203045") << endl; // 정답 : 0
    cout << solution("100", "123450") << endl; // 정답 : 10
    cout << solution("12321", "42531") << endl; // 정답 : 321
    cout << solution("5525", "1255") << endl; // 정답 : 552
}
#endif

/*2번 택배상자 트럭에 싣기
실어야 하는 택배상자 크기가 모두 같으며 1번 상자부터 n번 상자까지 번호가 증가하는 순서대로
컨테이너 벨트에 일렬로 놓여 전달된다. 컨테이너 벨트는 한 방향으로만 진행이 가능해서 벨트에 놓인 순서대로
(1번 상자부터)상자를 내릴 수 있다. 하지만 벨트에 놓인 순서대로 상자를 내려 바로 트럭에 싣게 되면 트럭기사가
배달하는 순서와 상자가 실린 순서가 맞지 않아 배달에 차질이 생긴다. 따라서 순서대로 내리긴 내리되 
또 배달 순서에 맞게 실어야한다.

만약 벨트의 맨 앞에 놓인 상자가 현재 트럭에 실어야 되는 순서가 아니라면 그 상자를 잠시 다른 곳에 보관해 놓을 필요가 있다.
땅바닥에 놓을 순 없어 보조 컨테이너벨트에 내려놓는다. 보조 컨테이너 벨트는 앞 뒤로 이동시킬 수 있지만 입구외에는 막혀있어 
맨 앞 상자만 뺄 수 있다.즉, 가장 마지막에 보조 컨테이너 벨트에 보관한 상자부터 꺼내게 된다. 
보조 컨테이너 벨트를 활용해도 싣는 순서대로 실을수 없다면 상자 싣기를 중단한다.

예를들어 5개의 상자를 실어야하고 싣는 순서는 43125 순서인경우 우선 1번 2번 3번을 차례대로 보조에 넣고 
4번을 트럭에 싣고 3번을 보조에서 꺼내 실으면메인 벨트에는 5가 있고 보조 벨트에는 2가 있어서 1을 실을수 없다. 
따라서 중단. 택배기사가 원하는 order가 주어지면 총 몇개의 상자를 실을 수 있는지 return 하는 함수 완성

입력조건
order는 1~백만까지
order는 1~길이이하의 수가 한번씩만 등장
order[i] 의 수는 메인 벨트의 i+1번째 상자를 트럭에 실으라는 의미.

<접근방법>
스택 2개를 만들어 푸는 구현의 문제로가면 시간 초과 문제가 있다. 선형탐색에서 이미 백만개이기때문에



*/
//구현으로 풀이
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
int mainBelt = 1;

int solution(vector<int> order) {
    int answer = 0;
    stack<int>supBelt;

    for (auto n : order) {
        while (mainBelt < n) {
            supBelt.push(mainBelt);
            mainBelt++;
        }
        if (mainBelt == n) {
            answer++;
            mainBelt++;
        }
        else if (supBelt.top() == n) {
            answer++;
            supBelt.pop();
        }
        else { break; }
    }
    mainBelt = 1;
    return answer;
}

int main()
{
    cout << solution({ 4, 3, 1, 2, 5 })<<endl; // 정답 : 2
    cout << solution({ 5, 4, 3, 2, 1 })<<endl; // 정답 : 5
}
#endif