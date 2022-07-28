//1번
// 2차 시도
// 1. <문자열 자르기>
// substr() 함수를 활용하여 자른다. 레코드배열 각 원소는 문자열. 그리고 각 의미있는 성분들은
// 공백으로 구별되어있음. 공백을 기준으로 딱 3개의 단어를 추출해야함.
// string space_delimiter = " ";
// vector<string> words{};
//
// size_t pos = 0;
// 포스에 공백의 인덱스를 찾아 저장할때 그 저장이 실패하지 않았다면 반복
// while ((pos = text.find(space_delimiter)) != string::npos) {
//      //0인덱스부터 공백 인덱스개수만큼 짤라서 반환하면 공백의 인덱스 전까지 짤라셔 저장됨.
//     words.push_back(text.substr(0, pos));
//      //0인덱스부터 공백 인덱스개수만큼 지우는건데 여기서 뒤에 더하는 숫자는 1이다. 
//      //따라서 공백까지 포함되어 삭제된다. 만약 공백의 길이가 1개가 아니라 2개짜리라면 2개까지 지울거다.
//     text.erase(0, pos + space_delimiter.length());
// }
// 
// 2. <시간 환산>
// 그렇게 잘라서 저장한 문자열 배열은 총 레코드 길이만큼 생겨서 2차원 배열처럼 구조가 생길것이다.
// 첫번째 요소인 시간은 다시 ':' 을 기준으로 구별하여 분단위 시간으로 환산할 필요가 있다.
// 
// auto hour = words[i].substr(0, words[i].find(':'));
// auto htom = atoi(hour.c_str()) * 60;
// int minute = htom + atoi(words[i].substr(words[i].find(':')).c_str());
// 
// 3. <차번호 키워드>
// 두번째 차량번호는 각 차량의 사용시간을 계산할때 쓰이는 주요 키워드 역할을 할것.
// 키워드 딕셔너리의 자료형인 pair 자료형의 원소로 사용될 것이다.
// 
// 4. <IN OUT 구별>
// 세번1째 문자열인 IN OUT으로 구별하여 IN일때는 집어넣고 OUT일땐 OUT시간대와 IN시간대를 빼서
// 사용시간을 계산해야된다.
// 
// 5.<inVector outVector 만들기>
// IN일 경우에 inVector에 차량번호를 키워드로 현재시각을 분으로 환산한거 추가
// Out일 경우에 outVector에 차량번호를 키워드로 inVector에 저장된 시각을 뺀 시간을 추가
// inVector의 키워드 요소는 지운다.
// 만일 record n번탐사가 끝나도 inVector에 요소가 남아있다면 outVector에 23:59를 뺀시간을 추가
// 차량번호 순으로 outVector를 나열하고 시간요소를 answer벡터에 반환
// 
// find()함수 벡터 응용 https://9x211x2.tistory.com/17
// IN OUT 할때 필요함.
// 
// string::npos 의 의미 https://mg729.github.io/c++/2019/11/03/C++_string_npos/
// substr()으로 공백을 기준으로 단어 잘라서 배열에 저장하기
// https://www.delftstack.com/ko/howto/cpp/cpp-split-string-by-space/
//
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//vector pair find_if 참고자료 https://velog.io/@neity16/Programers-%EC%BA%90%EC%8B%9C-findif
string fstr = "";
bool findValue(pair<string, int> a) {
    if (a.first == fstr) return true;
    return false;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> inVector;
    vector<pair<string, int>> outVector;
    vector<vector<string>> totalData;
    vector<string> words;
    string space_delimiter = " ";
    size_t pos = 0;

    //<레코드 잘라서 만들어진 2차원 벡터>
    for (int i = 0; i < records.size(); i++) {

        //포스에 공백의 인덱스를 찾아 저장할때 그 저장이 실패하지 않았다면 반복
        while ((pos = records[i].find(space_delimiter)) != string::npos) {

            //0인덱스부터 공백 인덱스개수만큼 짤라서 반환하면 공백의 인덱스 전까지 짤라셔 저장됨.
            words.push_back(records[i].substr(0, pos));
            //0인덱스부터 공백 인덱스개수만큼 지우는건데 여기서 뒤에 더하는 숫자는 1이다. 
            //따라서 공백까지 포함되어 삭제된다. 만약 공백의 길이가 1개가 아니라 2개짜리라면 2개까지 지울거다.
            records[i].erase(0, pos + space_delimiter.length());
        }
        totalData.push_back(words);
    }
    //<inVector outVector 만들기>
    for (int i = 0; i < totalData.size(); i++) {
        if (totalData[i][2] == "IN") {
            //문자열로 시간계산
            auto hour = totalData[i][0].substr(0, totalData[i][0].find(':'));
            auto htom = atoi(hour.c_str()) * 60;
            int minute = htom + atoi(totalData[i][0].substr(totalData[i][0].find(':')).c_str());

            inVector.push_back(make_pair(totalData[i][1], minute));
        }
        else if (totalData[i][2] == "OUT") {
            // 인덱스값을 계산하는건 inVector에 저장된 시간값을 조회하고 계산하기위해 그리고 원소를 삭제하기위해
            fstr = totalData[i][1];
            int tempIdx = find_if(inVector.begin(), inVector.end(), findValue) - inVector.begin();
            //문자열로 시간계산
            auto hour = totalData[i][0].substr(0, totalData[i][0].find(':'));
            auto htom = atoi(hour.c_str()) * 60;
            int minute = htom + atoi(totalData[i][0].substr(totalData[i][0].find(':')).c_str());
            //아웃벡터는 단순히 언제 들어갔는지 시각값이 아니라 사용한 시간값이 들어가야한다.
            //하지만 두번 들어갔다가 나오는 경우도 고려해야함. 만약 outVector에 이미 키워드가 있다면 누적이고
            //아직 키워드가 없다면 갱신이다.
            if (find_if(outVector.begin(), outVector.end(), findValue) != outVector.end()) {
                int tempIdx2 = find_if(outVector.begin(), outVector.end(), findValue) - outVector.begin();
                outVector[tempIdx2].second += minute;
            }
            else {
                outVector.push_back(make_pair(totalData[i][1], minute - inVector[tempIdx].second));
            }
            //아웃벡터에 기록 다했으면 인벡터에서 키워드로 찾은 인덱스로 찾아가서 원소 삭제.
            inVector.erase(inVector.begin() + tempIdx);
        }
    }
    //totalData를 끝까지 돌면서 in과 out으로 정리를 다 끝냈다. 그러나 아직 inVector에 원소가 남아있다면
    //23:59까지 사용한 것으로 간주하여 out에 갱신을 하든 누적을 하든 한다.
    //<남은 inVector 처리>
    if (!inVector.empty()) {
        for (int i = 0; i < inVector.size(); i++) {
            //최대시각 - inVector에 기록된 시각
            int minute = 23 * 60 + 59 - inVector[i].second;
            fstr = inVector[i].first;
            if (find_if(outVector.begin(), outVector.end(), findValue) != outVector.end()) {
                fstr = inVector[i].first;
                int tempIdx2 = find_if(outVector.begin(), outVector.end(), findValue) - outVector.begin();
                outVector[tempIdx2].second += minute;
            }
            else {
                outVector.push_back(make_pair(totalData[i][1], minute));
            }
        }
    }
    //<outVector를 활용해서 정렬하고, 만들어놓은 사용시간을 fees 요금표에 맞게 계산하여 answer에 반환>
    sort(outVector.begin(), outVector.end());
    //기본시간 초과분에 대해서 분당 초과 요금이 계산된다.
    for (int i = 0; i < outVector.size(); i++) {
        if (outVector[i].second < fees[0]) {
            answer[i] = fees[1];
        }
        else {
            answer[i] = fees[1] + ((outVector[i].second - fees[0]) / fees[2]) * fees[3];
            if ((outVector[i].second - fees[0]) % fees[2] != 0) {
                answer[i] += fees[3];
            }
        }
    }

    return answer;
}
int main() {
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = { "05:34 5961 IN","06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT",
    "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

    auto result = solution(fees, records);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
#endif

//2번
// 스피드에따라 모든 작업들이 누적 계산되는데 100이상이면 반환한다. 
// 하지만 앞에 기능이 100이 되어야만 뒤에거도 반환된다.
// 
// 스택 자료구조를 쓰면 어떨까 순서대로를 지킬수 있을거 같다.
// 총 자료의 개수는 100개이므로 3제곱까지 가능하다.
// 
// 한 턴 두 턴 진행될때마다 스피드를 누적시키고
// 아니다 이렇게 누적시킬필요없이 필요한건 진행된날짜뿐이다. 어차피 스택에서 뽑으면서 곱하면 되자나.
// 
// <프로그래스 스택만들기> 이때 거꾸로 삽입해야되는걸 유의
// <날짜 진행시키면서 맨 위쪽 자료에 날짜*스피드 한걸 더해서 100이상이 되는지 확인>
// <100 이상이라면 pop하고 카운트 그다음 자료에도 같은걸 적용>
// <이때 100 이하라면 카운트를 중단하고 그 카운트를 정답 배열에 반환>
// <마찬가지로 100 이상이 계속 된다면 pop을 계속하며 카운트 증가>
//
#if 0
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> proStack;
    int date = 0;
    int cnt = 0;
    int idx = 0;
    bool ret = false;

    //<스택 만들기> 이때 거꾸로 삽입한다.
    for (int i = progresses.size()-1; i >= 0; i--) {
        proStack.push(progresses[i]);
    }
    //<날짜 진행>
    while (!proStack.empty()) {
        date++;
        //<스택의 맨위쪽 자료에 잘 맞는 누적값을 더해서 그게 100 이상인지 체크>
        while(proStack.top() + date * speeds[idx] >= 100) {
            idx++;
            //이렇게 만들때의 문제점이 하나 발견되었다. idx가 하나 증가하는 구조는 논리적으로 맞지만
            //종료조건 체크때 범위 오버플로우 문제가 발견됨. while문 맨끝에 만약 idx가 size()-1보다 커지면
            //검사없이 강제로 빠져나오는 구문을 하나 추가하는것으로 해결
            cnt++;
            proStack.pop();
            ret = true;
            if (idx > speeds.size() - 1) break;
        }
        if (ret) {
            answer.push_back(cnt);
            cnt = 0;
            ret = false;
        }       
    }

    return answer;
}

int main()
{
    vector<int> progresses1 = { 93, 30, 55 };
    vector<int> progresses2 = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds1 = { 1, 30, 5 };
    vector<int> speeds2 = { 1,1,1,1,1,1 };

    auto result = solution(progresses1, speeds1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    result = solution(progresses2, speeds2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
#endif
//고찰
// 항상 버그는 범위체크 문제에서 빈번하게 나는것 같다.
// 작업의 개수가 100개 정도인 만큼 이중 포문을 이용해서 체크하는것도 무리는 없었을거 같다.
// 논리는 같다. 바깥쪽에선 시간이 돌아가고 안쪽에선 인덱스가 증가하는 방식이다.
//