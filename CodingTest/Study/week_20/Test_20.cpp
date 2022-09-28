// 1번
/* 피보나치 수열 구현 0과 1로 시작한다. 0번째는 0 1번째는 1 그 다음부터는 바로앞에 있는
두 수의 합이 원소가 됩니다. 점화식은 An = An-2 + An-1 이런식.

<접근방법>
이는 재귀로 계속 호출하는 방식을 이용해서 푸는게 가장 구현이 단순하고 재귀자체의 속도를
향상시키기 위해서는 바텀업 방식인 반복문이 조금 더 효율적일 것이다.
*/
#if 0 //탑다운 - 재귀
#include <string>
#include <iostream>

using namespace std;

int solution(int number) {
    if (number == 0) return 0;
    if (number == 1 || number == 2) return 1; //재귀 종료문
    return solution(number - 2) + solution(number - 1);
}

int main()
{
    cout << solution(10) << endl;
    cout << solution(5) << endl;
    cout << solution(15) << endl;
}
#endif
#if 0 //바텀업 반복문
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int solution(int number) {
    dp.clear();
    int answer = 0;
    int idx = 2;
    dp.push_back(0);
    dp.push_back(1);
    while (idx <= number) {
        dp.push_back(dp[idx - 2] + dp[idx - 1]);
        idx++;
    }
    return answer = dp[number];
}

int main()
{
    cout << solution(10) << endl;
    cout << solution(5) << endl;
    cout << solution(15) << endl;
}

#endif // 1 //바텀업 반복문



// 2번
/* 재귀적인 패턴으로 별을 찍어 본다. N이 3의 거듭제곱 이라고 할때, 크기 N의 패턴은 N x N
정사각형 모양입니다. 크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에
별이 하나씩 있는 패턴이다.
N이 3보다 큰 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 N/3x N/3 정삭가형을 크기 N/3의
패턴으로 둘러싼 형태이다. N은 무조건 3의 거듭제곱 형태로 주어진다.

<접근방법>
3의 거듭제곱 순서대로 1승은 1번 2승은 총 2종류 3승은 총 3종류의 패턴이 나오게 된다.
3으로 계속 나누면서 출력을 한다. 바텀업 방식이라면 맨 초기값 부터 매개변수까지 점화식을 전개하면
탑다운 방식은 기본적인 점화식 구현을 통해 도출이 가능하다.
점화식은 위에 3개 가운데 2개 밑에 3개 출력하는 거다. 

9일땐 한 원소가 3x3 3일땐 1x1 27일땐 9x9

<접근 방법 2>
아예 싹 별이 찍혀있는 녀석에다가 빈칸으로 바꿔야될 부분만 빈칸으로 바꾸는 방법도 있을거 같네
그게 오히려 쉬울지도...
재귀적으로 호출하는건 오히려 찍는게 아니라 지우는거. 맨 아래는 1개를 지우고 그다음엔 9개를 지우고 
그 다음엔 27개를 지우는 방식
센터는 어떻게 선정? 3x3에선 2x2가 센터 9x9에선 4~6x4~6가 센터 27x27에선 9~17x9~17가 센터
이게 어떻게 재귀인거지? 재귀 구현이 어려워보이는데...

<접근 방법 3>
다시 재귀. 이게 그냥 배열에 넣는건 괜찮은데 어떻게 저렇게 출력되느냐의 문제이다.
결국 줄바꿈을 한번 하게 될 경우 다시 위로 올라가는건 불가능하다. 결국 개념상으로는 3x3을
여러번 출력한다고 느껴지지만 실제로는 그런 방법은 불가능한거 같다.

-> 그렇다면 27이면 27번 쫙 별찍고 줄넘기고 * ** * 반복해서 27번 찍고 이런식?
이러다가 중간에 4번째 반복에서 ***   ******   *** 이것을 27번까지 반복?
그 빈칸 인덱스를 구하는 일반식이 필요하다면 그 일반식은 3일땐 1,1
9일땐 3,3 ~ 5,5 까지 빈칸 크게 그리고 1,1 1,4 1,7 4,1 4,4 4,7 7,1 7,4 7,7
27일땐

(i/3)%3 == 1 && (j/3)%3 == 1

*/
#if 0 //바텀업
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> dp;

vector<string> solution(int number) {
    dp.clear();
    vector<string> temp = { "***", "* *", "***" };
    dp.push_back(temp);
    int idx = 3;
    while (idx <= number)
    {
        int i = cbrt(idx) - 1;
        vector<string> temp1;
        temp1.push_back(dp[i][0] + dp[i][0] + dp[i][0]);
        temp1.push_back(dp[i][1] + dp[i][1] + dp[i][1]);
        temp1.push_back(dp[i][2] + dp[i][2] + dp[i][2]);
        dp.push_back(temp1);
    }

    return answer;
}

int main()
{
    
}
#endif

#if 0//탑다운
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> solution(int number) {
    if (number == 3) {

    }
    vector<string> answer;
}

int main()
{

}
#endif

//동현님 
#if 0
#include<iostream>
using namespace std;

void star(int i, int j, int num)
{
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        cout << ' ';
    }
    else
    {
        if (num / 3 == 0)
            cout << '*';
        else
            star(i, j, num / 3);
    }
}
int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            star(i, j, num);
        cout << '\n';
    }
}
#endif // 1
