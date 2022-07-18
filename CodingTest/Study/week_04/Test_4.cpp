#if 0
#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(string s, int n) {
    string answer(s);

    //Uppercase Lowercase 구분 각각의 끝에서 +n하게 될경우 보정
    for (int i = 0; i < s.length(); i++)
    {
        //Upper A:65 Z:90 91-26 = 65 따라서 Upper+n-26 다행히도 n은 1이상 25이하 자연수이다. 
        // 만약 n이 26보다 큰 수라면 n을 먼저 26으로 나눈 나머지로 더하고 -26을 했어야 될거 같다.
        if (64 < s[i] && s[i] < 91) {
            if (s[i] + n > 90) { answer[i] = answer[i] + n - 26; }
            else { answer[i] += n; }
        }

        //Lower a:97 z:122
        else if (96 < s[i] && s[i] < 123) {
            if (s[i] + n > 122) { answer[i] = answer[i] + n - 26; }
            else { answer[i] += n; }
        }
        else {  }
    }
    return answer;
}
int main() {
    string s = "a b z";
    int n = 4;
    cout << solution(s, n);
}

#endif

//1. x보다 1큰수를 선형으로 탐색하면서 비트 다른 지점의 수가 1~2개 차이 날때 반환
// 
//2. x의 비트 상태를 바로 알 수 있다면 최오른쪽 비트가 비어있다면 채우면 무조건 끝
//2-1 맨오른쪽 비트가 채워져 있다면 다음 오른쪽 비트가 비어있는 공간을 일단 채우고 
//나머지 오른쪽에 있는 비트 전부 0으로 바꾼다. 그리고 처음 상태보다 1이 2개차이날때까지 맨 오른쪽붙터 1을 채운다.
//2-2 x의 오른쪽에 비어있는 비트가 하나도 없다면 왼쪽에 비트 하나 추가하고 나머지 0으로 싹 바꾼뒤에 
//1의 개수가 2개 차이날때까지 오른쪽부터 1로 바꾼다.

//3_1 그말은 즉 1개차이 나는 경우는 맨오른쪽에 1을 추가하는 경우이고 2개차이나는 경우는 그 외의 경우들이다.
//3_2 .... 너무 복잡해지니 일단 1번으로 해결한다.

//비트 1의 개수 구하기: 10진수를 2로 만들때 나머지가 1인 경우가 1이었다. 나머지 1인 경우를 카운트한다. 
//이때 2진법 1의 자리수가 0인 경우만 체크해서 +1로 바로 반환한다. 처음 바로 나누어 떨어지는게 1의자리수가 0인것.
//몫이 1이 될때까지 나눈다.
#if 0
#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int cntx = 0; int cnty = 0;

    for (int i = 0; i < numbers.size(); i++)    //n번
    {
        long long tempx = numbers[i];
        long long tempy = tempx;
        //예외처리 2개 맨오른쪽비트가 채워져 있는데 나눌거리는 없는 1인 경우엔 11이 가장 작음
        if (tempx == 1) answer.push_back(static_cast < long long>(3));
        //2진수 0승자리가 0인 경우엔 그냥 +1이 답
        else if (tempx % 2 == 0) answer.push_back(static_cast<long long>(tempx) + 1);
        else 
        {
            //temp를 계속 나누어 들어가면서 체크하는 1의 개수를 체크하는 반복문
            while (tempx != 1)        //logn번 횟수가 반으로 쪼개지니까
            {
                cntx += tempx % 2;    tempx /= 2;
            }
            do{
                cnty = 0;
                tempy++;
                //temp에 +1 누적시킨 놈을 나누어 들어가면서 1의 개수 체크
                while (tempy != 1)
                {
                    cnty += tempy % 2;    tempy /= 2;
                }
            } while (!(abs(cntx - cnty) == 2 || abs(cntx - cnty) == 1));
            answer.push_back(tempy);
        }
    }
    return answer;
}
int main() {
    vector<long long> numbers = { 2, 7 };
    auto answer = solution(numbers);
    cout << answer[0] << endl;
    cout << answer[1];
}
#endif
// 1  2  3   4    5   6                         10    11  12                       16     17    18                      22         24       29     30                              36                                    42 
// A AA AAA AAAA AAAAA AAAAE AAAAI AAAAO AAAAU AAAE AAAEA AAAEE AAAEI AAAEO AAAEU AAAI AAAIA AAAIE AAAII AAAIO AAAIU AAAO AAAOA AAAOE ... AAAUA AAAUE AAAUI AAAUO AAAUU AAI AAIA AAIAA AAIAE AAIAI AAIAO AAIAU AAIE AAIEA .... EUUUU I IA IAA 
//1. 5자가 될때까지 글자 추가 빈칸이 다 채워질때까지 일단 A를 추가한다. 빈칸-A
//2. 5자가 다 채워지면(문자열의 길이가 5이면)맨오른쪽 글자부터 체크 자리올림 하듯이 A-E-I-O-U
//3. 지리올림 하듯이 맨오른쪽 글자를 등급업 하다가 U까지 오면 U를 지우고 4번째 자리숫자 올림.

// 6N = 뒤에가 E로 끝나는 다섯자리
// 마지막 A로 끝나는 녀석 처음엔 1차이 , 5자리 채워지고 나서부터는 6차이 3번째 A가 유지될때까지, 3번째 올림이 등장하고나서 7차이 
// 근본적으로는 6차이로 자리올림이 발생하는게 맞는데 U 단계에서 올림이 두번이루어지는 구간은 +1을 더 생각해야되고 세번 올림이 이루어지느 구간은 +2를 생각해야하는 식인거 같다.
// 만약 스택이라면 알파벳만 보고서 어떻게 PUSH POP이 일어났는지를 체크하는지

//일단 알파벳이 5개니까 5진법일텐데 5진법인데 자리바꿀때마다 하나씩 연산이 추가된다고 생각해야되는건가
//5^4=625 5^3=125 5^2=25 5^1=5 5^0=1
//A가 바탕이면 0 E =1 01234 I=2*625=1250..
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    return answer;
}
#endif