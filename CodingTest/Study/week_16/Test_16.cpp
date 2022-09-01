// 1번
/*<접근방법>
각 큐의 대소관계 비교를 통해 가능할까? 예를들어 큰쪽은 계속 팝하고 작은 쪽은 푸쉬하고 그게 반복을 하다가
어느순간 일치점이 나오지 않을까? 만약 더이상 하나밖에 안남았는데도 크다면 방법은 없으니까 -1인거고
근데 제일 중요한건 최소 횟수를 반환해야한다는 것. 이 방법이 최소 횟수를 보장하는가? 예시만 봤을땐 가능
queue1                  queue2
1 3 5 7 9               2 4 5 8 10
1 3 5 7 9 2             4 5 8 10 

9 3 2 3 3               16 4 3 2 1
9 3 2 3 3 16            4 3 2 1
3 2 3 3 16              4 3 2 1 9
2 3 3 16                4 3 2 1 9 3
3 3 16                  4 3 2 1 9 3 2
3 3 16 4                3 2 1 9 3 2
3 16 4                  3 2 1 9 3 2 3
하.. 그런데 이게 최적해라는걸 어떻게 알지?
가장 완벽한건 모든 경우의 수를 다 구하는건데 그게 가능한가?

벡터를 큐처럼 활용해보자. -> pop_front 기능을 지원하지 않기 때문에 불가능하다. 
왜냐하면 연산마다 원소 개수만큼 계속 시간이 필요한데 이러면 시간복잡도가 너무 커짐.

그냥 큐를 사용하자.
*/
#if 0
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1=0, sum2=0, ttime;
    queue<int> q1, q2;
    for (auto n : queue1) {
        sum1 += n;  q1.push(n);
    }
    for (auto n : queue2) {
        sum2 += n;  q2.push(n);
    }
    ttime = sum1 + sum2;
    if (ttime % 2 == 1) return -1;
    
    ttime = queue1.size() + queue2.size(); //총 원소의 개수보다 푸쉬팝이 일어나는 경우는 ..
    //백만번?..
    //여기까지 초기화.

    while (!q1.empty() && !q2.empty() && answer<=ttime) {
        if (sum1 == sum2) return answer;
        else if (sum1 < sum2) { //queue2에서 pop queue1에서 push
            sum1 += q2.front(); sum2 -= q2.front();
            q1.push(q2.front());    q2.pop();           
        }
        else if (sum1 > sum2) { //q1 -> q2
            sum2 += q1.front(); sum1 -= q1.front();
            q2.push(q1.front());    q1.pop();
        }
        answer++;
    }
    if (q1.empty() || q2.empty() || answer > ttime) return -1;
    else
    {
        return answer;
    }
}

int main()
{
    cout << solution({ 3,2,7,2 }, { 4,6,5,1 }) << endl; // 정답 : 2
    cout <<solution({ 1,2,1,2 }, { 1,10,1,2 })<<endl; // 정답 : 7
    cout <<solution({ 1,1 }, { 1,5 })<<endl; // 정답 : -1
}
#endif

/*2번
XYZ 마트는 일정한 금액을 지불하면 10일 동안 회원 자격을 부여합니다. XYZ 마트에서는 회원을 대상으로
매일 한 가지 제품을 할인하는 행사를 합니다. 할인하는 제품은 하루에 하나씩만 구매할 수 있습니다.
알딸한 남영이는 자신이 원하는 제품과 수량이 할인하는 날짜와 10일 연속으로 일치할 경우에 맞춰서
회원가입을 할려합니다.
예를 들어, 남영이가 원하는 제품이 바나나3 사과2 쌀2 돼지고기2 냄비1 이며, XYZ마트에서 14일간 회원을
대상으로 할인하는 제품이 날짜 순서대로 치킨, 사과, 사과, 바나나, 쌀, 사과, 돼지고기, 바나나, 돼지고기,
쌀, 냄비, 바나나, 사과, 바나나인 경우에 대해 알아봅시다.
첫째 날부터 열흘 간에는 냄비가 할인하지 않기 때문에 첫째 날에는 회원가입을 하지 않습니다.
둘째 날부터 열흘 간에는 바나나를 원하는 만큼 할인 구매 할 수 없기 때문에 둘째 날에도 회원가입을 하지 않슨다.
셋째, 넷째, 다섯째 부터는 원하는 제품이 수량과 일치하기에 셋 중에 하루에 회원가입을 하려함.
원하는 제품 배열 want, 제품 수량 배열 number, 할인 품목 배열 discount
원하는 제품을 모두 할인 받을 수 있는 날짜의 총 일수를 return 없으면 0

<접근방법>
무조건 10개 이하이다. discount는 10만. 이건 정렬을 해서 어찌 할수 있는 방법이 아니다. 또 정렬을 하면 안된다.
discount를 선형탐색하면서 내부적으로는 계속 시작 인덱스마다 want를 만족하는지를 10번 돌아가니까 100만번!
*/
#if 0
#include <string>
#include <vector>
#include <map>
#include<iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    int totalcnt = 0;
    bool success = false;
    map<string, int> check; //{want number}
    for (int i = 0; i < want.size(); i++) {
        check.insert({ want[i], number[i] });
        totalcnt += number[i];
    }
    //+1을 해야 마지막 요소까지 탐색 가능 11개의 데이터중 10개를 탐색하는 방법은 11-10+1인 2가지이다.
    for (int start = 0; start < discount.size() - totalcnt+1; start++) {
        for (int i = 0; i < totalcnt; i++) {
            if (check.find(discount[start+i]) != check.end() && check[discount[start+i]]>0) { //디스카운트로 찾은 데이터가 있다면
                check[discount[start+i]]--;
                success = true;
            }
            else {
                success = false;//반복문이 다 돌기 이전에 else로 한번이라도 빠지면 그냥 실패다.
                break;
            }
        }//내부 반복문 끝
        if (success) answer++;
        //다시 checkmap초기화
        for (int i = 0; i < want.size(); i++) {
            check[want[i]]= number[i];
        }
    }

    return answer;
}

int main()
{
    cout << solution({ "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 },
        {"chicken", "apple", "apple", "banana", "rice",
        "apple", "pork", "banana", "pork", "rice",
        "pot", "banana", "apple", "banana"}); // 정답 : 3

    cout << endl;
    
    cout << solution({ "apple" }, { 10 },
        { "banana","banana", "banana", "banana", "banana",
        "banana", "banana", "banana", "banana", "banana" }); // 정답 : 0
}
#endif
/*고찰

*/