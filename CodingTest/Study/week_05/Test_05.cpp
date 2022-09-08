//1번

//1. 약수구하는 알고리즘
//2. 약수의 개수 체크 (짝수면 result에 더하고 홀수면 뺌)
//3. s부터 시작해서 n까지 증가.

// 소수이면 약수는 짝수개.
// 임의의 합성수는 소수들의 곱으로 나타낼수 있음.
// 임의의 합성수의 제곱근보다 작은 소수들로 나눠떨어지지 않으면 그 수는 소수임.

#if 0
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int start = left;
    bool primeCheck = true;
    //3. 선형탐색
    for (int i = 0; i <= (right - left); i++)
    {
        bool primeCheck = true;
        //int cnt = 0;//2.개수 체크
        
        //소수판별
        for (int j = 2; j * j <= start; j++)
        {
            if (start % j == 0) { primeCheck = false; break; }
        }

        //소수라면 약수는 짝수개니까
        if (primeCheck) {
            answer += start;
        }
        //소수가 아니라면 약수의 개수를 체크해야될 것 같다.
        //약수란 합성수를 나머지 없이 나눌수 있는 수의 집합이다. 나누기는 이항연산자이므로, 
        // 나누어 떨어진다는 소리는 a = bq 를 만족하는 b와 q가 약수라는 소리이다. 
        // b와 q가 같은 경우가 아니라면 약수의 집합은 짝수일 것이다. 
        // 따라서 약수의 개수는 짝수개여야 한다.
        // 약수집합의 원소가 홀수개라는 소리는 a= b^2인 경우가 있다는 뜻. 
        //따라서 어떤 합성수의 제곱근이 정수인지를 체크하면된다.
        else if (((double)sqrt(start) - (int)sqrt(start)) == 0) answer -= start;
        else answer += start;

        start++;
    }

    return answer;
}
int main() {
    int s = 13, n = 17;
    cout << solution(s, n);
}


#endif

//2번

//1. 거리계산을 해야되는 경우는 2, 5, 8, 0
//2. 현재 손가락의 위치를 저장하고 담고 있어야한다.
//3. 키패드는 4*3 행렬의 모습과 유사하다. 각 인덱스의 값을 이용해 거리 계산이 가능할 거 같다.
//예를들어 0,0 과 3,1 은 총 4번만큼 떨어져 있다. 1,1과 2,2는 2만큼 떨어져 있다.

//첫번째 시도 문제점
//2차원 배열을 선언해놓고 보니까 각 요소와 일치하는지 검색하는 단계에서 막히고, 
//인덱스를 어떻게 반환해야할지도 막막했다.
//해결책
//1차원 배열의 개념을 활용하고 인덱스가 아닌 안에 요소값으로 순서쌍 자료형을 저장하자.

//두번째 시도 문제점
//거리계산을 위해 왼손위치 오른손위치를 각각의 인덱스를 표현하는 튜플 페어 값으로 저장을 해보려 했으나 
//페어를 환산하는 개념이 아직 부족하여 검사할때마다 make_pair를 할려면 일일히 경우의 수마다 
//if문을 붙여야되서 너무 길어질거 같았다.
// 해결책
// 순서쌍의 개념이 n진법으로 변환해서 생각해보았다. 
// 유사3진법 만들기 -1하고 각각 자리수끼리의 차를 더한다.
//00 01 02 / 10 11 21 / 20 21 22 / 30 31 32 (0은 자동으로 31 변환 초기위치는 왼30 오32)


#if 0
#include <string>
#include <vector>
#include <algorithm> //sort, find
#include <unordered_map>//해시를 만드는
 // pair : (a,b)순서쌍 자료구조

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> keyPad;
    vector<pair<int, int>> hPosition;
    hPosition.push_back(make_pair(3, 0));
    hPosition.push_back(make_pair(3, 2));

    //int position[2] = { 22, 33 };   //22와 33을 각각 *과 #이라 생각해본다.

    //keypad 위치값 순서쌍 생성 {0,0 0,1 0,2 ..... 3,2}
    for (int i = 0, j=0; i < 4; )
    {
        keyPad.push_back(make_pair(i, j));
        j++;
        if (j / 3 == 1) {
            i++;    j = 0;
        }
    }

    //매개변수로 받은 숫자배열의 값을 이용해 터치문자열을 반환하고 위치값 계산하는 반복문
    for (int i = 0; i < numbers.size(); i++)
    {
        //무조건 왼쪽일때
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            hPosition[0] = make_pair()
        }
        //무조건 오른쪽일때
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {

        }
        else
        {

        }
    }


    return answer;
}
#endif

//3번

//
//
//


#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    return answer;
}
#endif