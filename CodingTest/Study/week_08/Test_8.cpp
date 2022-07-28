//1번
// Collatz의 추측
// 반복횟수 500번이 넘어가면 -1 리턴
//
#if 0
#include <string>
#include <vector>
#include <iostream>

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
    vector<int> n = { 6, 16, 626331 };
    for (int i = 0; i < n.size(); i++) {
        cout << solution(n[i]) << endl;
    }
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

//2번째시도
// int형 자료 두개에 비트셋 연산을 적용하면 적용 될 줄 알았는데 안되나?
// test로 해보니 되는 것을 확인
//

#if 0
#include <string>
#include <vector>
#include<iostream>

using namespace std;

string reverse(string s) { 
    string answer ="";
    for (int i = s.size()-1; i >= 0; i--) {
        answer += s[i];
    }
    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    //vector<string> answer(n); 
    vector<string> answer;
    string s = "";

    for (int i = 0; i < n; i++) {
        auto a = arr1[i] | arr2[i]; //bitset 수정 
        //string s=""; 
        //위와 같이 반복문 내에서 계속 s가 초기화 될거니까 이러면 안됨
        for (int j = 0; j < n; j++) {
            //만약 a가 0이라면 그냥 알아서 나머지는 전부 0이라 빈칸 추가할것
            if (a % 2 == 1) s.push_back('#');
            else s.push_back(' ');
            a /= 2;
        }
        //내부 반복문이 끝나면 만들어진 s를 거꾸로하여 answer에 반환
        answer.push_back(reverse(s)); //reverse 수정
        s = "";
    }
    return answer;

}

int main(void)
{
    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = { 30, 1,21,17,28 };

    auto s = solution(n, arr1, arr2);
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }

}
//고찰
// 로직상은 크게 문제가 없었는데 자꾸 에러가떠서 디버깅으로 해결
// 원인은 문자열에 원하는 문자들이 추가가 안되는 문제가 발생
// 플러스 연산자로 문자를 추가하면 원래 되는데 왜 안되는지 의문이지만, push_back으로 해결
#endif

#if 0   //test
#include <iostream>
using namespace std;
int main() {
    int n = 18, m = 17;
    auto s = n | m;
    cout << s;
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
#include <sstream>
#include <iostream>
#include <algorithm>

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
    vector<pair<string, int>> inVector;
    vector<pair<string, int>> outVector;

    //for (int i = 0; i < records.size(); i++) {
    //    vector<string> temp;
    //    int j = 0;
    //    istringstream ss(records[i]);
    //    while (getline(ss, temp[j], ' '))//ss stream 변수에서 ' '(공백)까지 입력으로 받아들인다.
    //    {
    //        cout << temp[j] << endl;
    //        j++;
    //    }
    //    if (temp[2] == "IN") {

    //        inVector.push_back(make_pair((stoi(temp[1]), stoi(temp[1])));
    //    }
    //}

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
            int tempIdx = find_if(inVector.begin(), inVector.end(), totalData[i][1]) - inVector.begin();
            //문자열로 시간계산
            auto hour = totalData[i][0].substr(0, totalData[i][0].find(':'));
            auto htom = atoi(hour.c_str()) * 60;
            int minute = htom + atoi(totalData[i][0].substr(totalData[i][0].find(':')).c_str());
            //아웃벡터는 단순히 언제 들어갔는지 시각값이 아니라 사용한 시간값이 들어가야한다.
            //하지만 두번 들어갔다가 나오는 경우도 고려해야함. 만약 outVector에 이미 키워드가 있다면 누적이고
            //아직 키워드가 없다면 갱신이다.
            if (find_if(outVector.begin(), outVector.end(), totalData[i][1]) != outVector.end()) {
                int tempIdx2 = find_if(outVector.begin(), outVector.end(), totalData[i][1]) - outVector.begin();
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
            if (find_if(outVector.begin(), outVector.end(), inVector[i]) != outVector.end()) {
                int tempIdx2 = find_if(outVector.begin(), outVector.end(), inVector[i]) - outVector.begin();
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

