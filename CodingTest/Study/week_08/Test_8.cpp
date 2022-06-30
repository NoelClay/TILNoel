//1번
// Collatz의 추측
// 반복횟수 500번이 넘어가면 -1 리턴
//
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    while (num != 1) {
        if (answer > 500) {
            answer = -1;    break;
        }
        if (num % 2 == 0) num /= 2;
        else if(num %2 ==1) num = num * 3 + 1;
        answer++;
    }
    return answer;
}
int main() 
{

}
#endif

//2번
//비밀지도 두개를 합쳐서 문자열 배열로 반환한다. 
//10진수 배열이 주어지고 2진수비트로 바꾼뒤에 1은 # 0은 빈칸
//두 수를 합칠때 진짜 덧셈이 이루어지는게 아니라 비트 or 연산이 이루어진다.
//c++의 비트 연산 https://boycoding.tistory.com/163
//이중 for문인데 바깥은 n번 안쪽은 logn번 n은 16 따라서 백만이하. 문자열마다 뒤집는연산 n개 16*16*4 = 1024
//c++ 문자열 거꾸로 reverse함수 https://blockdmask.tistory.com/363
// https://marobiana.tistory.com/159

#if 0
#include <string>
#include <vector>
#include<iostream>

using namespace std;

string reverse(string s, int n) { 
    string answer;
    for (int i = n-1; i >= 0; i--) {
        answer += s[i];
    }
    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    //vector<string> answer(n); 
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        int a = arr1[i] | arr2[i]; //bitset 수정
        string s;
        for (int j = 0; j < n; j++) {
            //만약 a가 0이라면 그냥 알아서 나머지는 전부 0이라 빈칸 추가할것
            if (a % 2 == 1) s + '#'; 
            else s + ' ';
            a /= 2;
        }
        //내부 반복문이 끝나면 만들어진 s를 거꾸로하여 answer에 반환
        answer.push_back(reverse(s, n)); //reverse 수정
    }
    return answer;
}

int main(void)
{
    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = { 30, 1,21,17,28 };

    vector<string> s = solution(n, arr1, arr2);
    for (int i = 0; i < n; i++) {

    }

}
#endif

//3번
// 차량번호가 키워드 출차 - 입차는 시간값. 
// 시간값 - 기본시간 = 추가시간
// 주차요금 = 기본요금 + 추가시간/10*단위요금
// 초과시간은 올림한다. 2*단위요금
// 
// 차량번호를 기준으로 오름차순 정렬한 주차요금 정수 배열 반환
// 한 시간은 60분 24시는 1440분 05:34는 334 현재 시각을 분(int)로 환산
// IN일 경우에 inVector에 차량번호를 키워드로 현재시각을 분으로 환산한거 추가
// Out일 경우에 outVector에 차량번호를 키워드로 inVector에 저장된 시각을 뺀 시간을 추가
// inVector의 키워드 요소는 지운다.
// 만일 record n번탐사가 끝나도 inVector에 요소가 남아있다면 outVector에 23:59를 뺀시간을 추가
// 차량번호 순으로 outVector를 나열하고 시간요소를 answer벡터에 반환
// 
// 반복횟수 n=1000, 내부 records 정리 3회, 
// 
// 문자열 빈칸 기준으로 구별하기 substr() https://starrykss.tistory.com/1546
// <sstream> https://seoyeonkk.tistory.com/entry/C-%EA%B3%B5%EB%B0%B1-%EA%B8%B0%EC%A4%80-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%9E%90%EB%A5%B4%EA%B8%B0split
// getline() https://greenapple16.tistory.com/219
// 조금 더 자세한 설명 https://chbuljumeok1997.tistory.com/42
// 
// string to int https://psychoria.tistory.com/709
// https://godog.tistory.com/entry/C-string-to-int-int-to-string-%ED%98%95%EB%B3%80%ED%99%98-%ED%95%98%EA%B8%B0
//
#if 0
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

//string str = "Enter id1234 Muzi";//다음과 같은 string이 있다고하자.
//istringstream ss(str);//istringstream ss 변수에 string 변수 as로 초기화한다.
//string buff;
//while (getline(ss, buff, ' '))//ss stream 변수에서 ' '(공백)까지 입력으로 받아들인다.
//{
//    // getline으로 읽어들인 값을 buff에 저장해 출력한다.
//    cout << buff << endl;
//}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<int, int>> inVector;
    vector<pair<int, int>> outVector;

    for (int i = 0; i < records.size(); i++) {
        vector<string> temp;
        int j = 0;
        istringstream ss(records[i]);
        while (getline(ss, temp[j], ' '))//ss stream 변수에서 ' '(공백)까지 입력으로 받아들인다.
        {
            cout << temp[j] << endl;
            j++;
        }
        if (temp[2] == "IN") {

            inVector.push_back(make_pair((stoi(temp[1]), stoi(temp[1])));
        }
    }

    return answer;
}
#endif

