/*1번 프로그래밍
고객의 약관 동의를 얻어서 수집된 1~n번으로 분류되는 개인정보 n개가 있다. 약관 종류는 여러가지
각 약관마다 개인정보 보관 유효기간이 따로 정해져 있다. 당신은 각 개인정보가 어떤 약관으로 수집되었는지
알고 있다. 수집된 개인정보는 유효기간 전까지만 보관되며, 지난다면 반드시 파기해야한다.
예를들어, A라는 약관의 유효기간이 12달이고, 2021년 1월 5일에 수집된 개인정보가 A약관으로 수집되었다면
해당 개인 정보는 2022년 1월 4일까지 보관가능하며 2022년 1월 5일에는 파기해야한다.
당신은 오늘 날짜로 파기해야 할 개인정보 번호들을 구하려 한다.

모든 달은 28일까지만 있다고 가정한다.

오늘 날짜가 2022.05.19라고 가정한다면
A: 6달, B: 12달, C:3달 이라는 약관이 있다.
1번 2021.05.02, A, 2021.11.02에 파기
2번 2021.07.01, B, 2022.07.01에 파기
3번 2022.02.19, C, 2022.05.19에 파기
4번 2022.02.20, C, 2022.05.20에 파기

답은 2022.05.19 날짜에 파기해야할 정보는 1번, 3번이다.

오늘 날짜 즉 확인 날짜 문자열 today, 약관의 유효기관을 담은 문자열배열 terms,
수집된 개인정보들을 담은 1차원 문자열 배열 privacies가 매개변수

제한사항
today는 "yyyy.mm.dd"
terms의 길이는 20이하. "C 7"과 같이 약관 알파벳과 유효기간을 공백으로 구분한 문자열. 유효기간은 100이하
privacies의 길이는 100이하. privacies[i]는 i+1번 개인정보의 수집 일자와 약관 종류를 나타냄.
privacies의 원소는 "날짜 약관종류"의 형태로 공백으로 구분한 문자열
2000 <= yyyy <= 2022
1 <= mm <= 12
mm이 한 자리수인 경우 앞에 0이 붙는다.
1 <= dd <= 28
dd가 한자리수라면 앞에 0이 붙는다.

<접근방법>
일단 주어진 정보를 써먹을 수 있게 바꾸는게 가장 중요하겠지 어차피 달 단위로 커지기에
mm이 12보다 커지면 yyyy+=(mm/12) mm%=12
하고나서 today보다 작은 애들은 전부 반환 answer에 추가 아닌 애들은 추가 안함.
privacies를 조회하며 알파벳정보와 가입날짜 정보를 분리하고
알파벳 정보를 바탕으로 terms에 기록된 정보를 확인한다.(이 과정은 terms를 다른 방식으로 포팅하는 것도 방법이겠다.)
    terms를 정렬하게 되면 사전정렬이 된다. 이때 20번을 추가로 돌면서 map 해쉬테이블을 사용하는것도 방법이겠다.)
아무튼 terms의 숫자를 조회하여 가입날짜에 추가한 뒤에 가입날짜의 mm이 12보다 크다면 위의 식을 활용하여
만든다. 그 만들어진 값이 today보다 작다면 answer에 추가. today보다 작은지는 먼저 yyyy부터 확인하고
today의 yyyy보다 작다면 추가 같다면 mm조회 mm도 같다면 dd조회 만약 같거나 작다면 이제는 반환.

*/
#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int toyy = stoi(today.substr(0, 4));
    int tomm = stoi(today.substr(5, 2));
    int todd = stoi(today.substr(8, 2));

    map<char, int> termstable;
    for (auto n : terms) {
        char temp1 = n[0];
        string temp2 = n.substr(2, n.size() - 2);
        int temp3 = stoi(temp2);
        termstable.insert({temp1, temp3});
    }
    for (int i = 0; i < privacies.size();i++) {
        auto n = privacies[i];
        char ptemp1 = n[11];
        int pryy = stoi(n.substr(0, 4));
        int prmm = stoi(n.substr(5, 2));
        int prdd = stoi(n.substr(8, 2));
        int plusmon = termstable[ptemp1];
        prmm += plusmon;
        if (prmm > 12) {
            pryy += (prmm / 12);
            prmm %= 12;
        }

        if (pryy < toyy)    answer.push_back(i + 1);        
        else if (pryy == toyy) {
            if (prmm < tomm) answer.push_back(i + 1);
            else if (prmm == tomm) {
                if (prdd <= todd) answer.push_back(i + 1);
            }
        }
    }

    return answer;
}

#endif // 1
//고찰 테스트케이스 한개가 실패 뜨던데 무슨 경우인지 모르겠다.