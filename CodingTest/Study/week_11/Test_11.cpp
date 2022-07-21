//1번
// 타겟넘버 만들기
// 넘버배열의 입력길이는 20개 이므로 반복횟수는 사실 상관없이 모든 경우의 수를 다 구하는 반복문을 만들어도됨.
// 각 숫자마다 경우의 수는 2가지 + 와 - 총 경우의 수는 2의 n개 따라서 2의 20승은 2의 10승의 제곱이니까 거의 딱 백만
// 
// 어떻게해야 동적으로 모든 경우의 수를 구할 수 있을지는 잘 모르겠다.
// 
// -재시도-
// 더하고 빼고의 규칙은 정해지지 않았다. 그냥 만들기만 하면 된다. 넘버의 총합을 구한다음에 
// 타겟을 만들기위해 얼마를 빼야되는지를 구하고 빼기를 만드는 경우의 수를 구하는 방식으로 한다면? 복잡한건 비슷할거 같은데
// 조금 쉬운건 확실할것 같다. 예를들어 4를 만들기 위해 조합에서 수를 선별만 하면 되는 구조로 만들면
// 첫번째 인덱스로 접근시에 그 첫번째 수를 무조건 포함한 어떤 인덱스들의 조합이 나올지를 만들고 
// 두번째 인덱스로 접근해서 순차적으로 해결 할 수 있다면....
// -재점검-
// 위 가정에서 틀린 접근이 있다. 더하는것과 빼는 것은 별개가 아니다. 빼는 동시에 그 숫자는 더해지는 숫자에서 빠지게 된다.
// 모든 원소가 같은 수라고 정해져 있다면 이것 나름대로 규칙이 만들어질거 같은데 다 다른 숫자이므로 각 숫자마다 예외를 구성하기 너무 힘들다.
// 
// -재시도-
// 순열인가?
// 
// <와보HINT>
// 재귀로 푸는거다. 재귀는 1. 탈출조건 2. 반복하고자 하는데 변하는 요소 가 필수.
//
#if 0
#include <string>
#include <vector>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sTarget = 0;
    int temp = 0;
    sort(numbers.begin(), numbers.end());
    //vector<int> tempNum(numbers);

    //for (int i = 0; i < numbers.size(); i++) {//20회
    //    sTarget += numbers[i];
    //}
    //sTarget -= target; //뽑아서 만들어야 하는 수가 구해짐.

    //for (int i = 0; i < numbers.size(); i++) {
    //    if(numbers[i] == sTarget)
    //}
    for (int j = 1; j <= numbers.size(); j++) {// 마이너스가 붙을 번호의 개수를 만드는 반복문
        vector<int> tempNum(numbers);
        // 넘버 배열의 녀석들 중에 몇개를 고를지를 선택하는 함수가 필요함. 순서 상관있지 고를는건 순열 상관없이 고르는건 조합
        // 여기서는 순서를 바뀌지 않는다고 했으니 이 말은 즉 덧셈 뺄샘 경우의 수에서 각자의 자리를 고려하여 즉 자리가 중요하다는 얘기와 같으니까 순열?
        // 순열... https://mjmjmj98.tistory.com/38
        //

        vector<int> tempVector;

        for (int i = 0; i < j; i++) //j가 증가하면서 -가 될 녀석들의 수도 증가하게 될것
        {
            tempVector.push_back(1);
        }

        for (int i = 0; i < numbers.size() - j; i++)
        {
            tempVector.push_back(0);
        }

        sort(tempVector.begin(), tempVector.end());

        do
        {
            for (int i = 0; i < tempVector.size(); i++)
            {
                if (tempVector[i] == 1)
                { // 실제값 출력
                    cout << numbers[i] << " ";
                }
            }

            cout << endl;

        } while (next_permutation(tempVector.begin(), tempVector.end()));

        for (int i = 0; i < numbers.size(); i++) {//더하는 반복문
            temp += tempNum[i];
        }
        if (temp == target) {//비교해서 카운트
            answer++;
            temp = 0;
        }
    }



    return answer;
}
#endif

//2번
// 현재 알파벳(A)과 타겟 알파벳 간의 거리 계산이 가능한 구조여야함. 옛날에 배웠던 원형큐 구조를 이용할 수 있을거 같다.
// 혹은 어차피 모든 시작은 A로 시작을 하기 때문에 A~Z까지의 거리를 반잘라서 계산을 하고 그 거리보다 커지면 아래로 조작을 하고
// 그 거리보다 작다면 위로 조작을 하여 거리 계산 하는 방식도 있다.
// 
// 오른쪽으로 갈지 왼쪽으로 갈지도 생각보다 간단한건 무조건 첫번째 위치에서 시작을 하기 때문에 첫번째의 오른쪽을 검사해서 
// 오른쪽은 갈 필요가 없다는 판단이 들면 왼쪽으로 간다.
// BABAZ 같은 경우엔 왼왼왼이 오오오오 보다 짧다.
// BAABAZAAA 같은 경우엔 오오오오오가 왼왼왼왼왼왼보다 짧다 첫번째 문자 기준으로 양옆의 A의 개수가 출발해야되는 방향을 알려준다.
// A의 개수가 적은 방향으로 이동하고 한번 정해진 방향은 바뀌지 않는다.
// 
// 입력의 길이는 20개이기 때문에 문자열 전체를 한번 쑥훑는것은 문제가 되지 않는다.(단 주어진 문자열이 A일때는 그냥 아무것도 안하고 인덱스만 증가)
// 그렇게 전부 문자열을 한번 훑어서 계산이 끝나면 카운트를 반환
// 
// <아스키 계산>
// 아스키 코드 A는 65 Z는 90 이다. 정중앙인 N은 위 아래 상관없이 13번 이동이고, M은 위로 12번 O는 아래로 12번이다.
// 계산법은 N보다 작으면 타겟-65를 하면 될것이고 N보다 크면 91-타겟 하면 된다.
// <방향 정하기>
// 아스키 계산과 방향 계산이 동시에 이뤄질거 같았지만 사실 따로 해도 상관이 없는거 같다. 
// 어차피 각 문자마다 전부 계산을 해야되고 그저 방향카운트로 전체 20미만의 차이가 발생
// 최소이동 횟수를 카운트해야하는데 오른쪽으로 어느 인덱스까지 갈지 혹은 왼쪽으로 어느 인덱스까지 갈지를 계산하는 구조가 필요하다.
// name의 첫번째 문자를 기준으로 왼쪽에 있는(맨끝부터 즉 거꾸로) A문자열의 끝인덱스와 오른쪽에 나열된 A문자열의 끝인덱스를 순차탐색으로 계산하고
// 인덱스를 이용한 계산을 할려고 했는데 
// -추가로 든 생각-
// 전체 문자열의 개수에서 첫번째 문자 기준으로 A가 더 많은 쪽의 A개수를 빼고 -1 하면 방향이동 개수가 카운트 된다. 굳이 인덱스를 이용한 계산까지는 필요 없었다.
// 인덱스를 딱 두 갈래로 나누어서 1부터 증가하는 방법과 size()-1 부터 감소하는 방법으로 나누고
// A가 아닌 문자를 발견할때까지의 개수를 카운트 한 다음 그 개수가 더 큰쪽을 빼면 된다.
// 
// 2번 테스트 케이스
//input:LABLPAJM / answer : 61
//input : BMOABA / answer : 30
//input : LAABAA / answer : 15
//input : AAAAAAAAJAAAA / answer : 14
//input : SAAAAAARRM / answer : 41
//input : RABAMATAWADLAFAVAAE / answer : 78
//input : XAAAAAABA / answer : 6
//input : AYOZAAVADAY / answer : 35
//input : AAFEASAAVA / answer : 30
//input : UAGAAASAAFAFXZA / answer : 47
//input : AAAAZAATAEA / answer : 19
//input : AACALATLAHABAA / answer : 50
//input : FAWJAAAFV / answer : 35
//input : AACAVAAPSAAOAA / answer : 49
//input : AKAAWAKX / answer : 33
//input : LOAAAHAJAAFAEBAWO / answer : 79
//input : AWAWVAQVAAA / answer : 35
//input : RCETAAAAVUEAETZAAAK / answer : 75
//input : GTAASKKAE / answer : 52
//input : AAAABAAAAAAKSAIQ / answer : 49
//input : ADASAAAUAAAPAA / answer : 39
//input : AAAAADBAAELSPUAAAOA / answer : 70
//input : VJAAIAFNAAAAA / answer : 47
//input : AARUAUAAHTBJAAYS / answer : 69
//input : IASAGITUPHE / answer : 74
//input : AAALAAAAAA / answer : 14
//input : AAAEASAHQAYTAAAJ / answer : 60
//input : BAALEAAAPMAAAHSRAV / answer : 83
//input : ASWAAATDAJAXA / answer : 45
//input : DYAOAAAARQANAWA / answer : 66
//input : AAIAPB / answer : 24
// 
//
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int cntRA = 0, cntLA = 0;

    for (int i = 0; i < name.size(); i++) {
        if (name[i] > 'N') answer += (91 - name[i]);
        else answer += (name[i] - 65);
    }

    for (int i = 1; i < name.size(); i++) {//첫번째 문자가 A인거는 아예 체크도 하지 않을 것이다. 카운팅의 버그가 될거 같다.
        if (name[i] == 'A') cntRA++;
        else break;
    }
    for (int i = 1; i < name.size(); i++) {
        if (name[name.size() - i] == 'A') cntLA++;
        else break;
    }

    if (cntLA > cntRA)
        answer += (name.size() - cntLA - 1);
    else
        answer += (name.size() - cntRA - 1);

    return answer;
}
int main() {
    vector<string> name = { "JEROEN" ,"JAN", "J"};
    
    for (int i = 0; i < name.size(); i++) {
        cout << solution(name[i])<<endl;
    }
    
}
//고찰
// 이동공식이 더 복잡해지면 입력된 순서를 탐색할 수 있는 큐같은 자료형을 써야될거 같은데 일단 다른 자료구조를 안쓰고 규칙만으로 해결 할 수 있었다.
//
// <와보HINT>
// 2의 20승이다. 모든 경우의 수를 전부 구해야한다.
//
#endif