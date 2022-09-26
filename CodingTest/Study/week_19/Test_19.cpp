// 1번
/*자카드 유사도

<접근 방법>
복잡도 따지지말고 일단 구현으로 가보자
1. 영문자 대소문자 구별하지 말고 동일하게 다중집합을 만들기
아스키코드 영문자 대문자는 65~90 소문자는 97~122 
동일 대문자와 소문자간 차이는 32

2. 교집합 합집합 그리고 둘 사이의 길이 차이로 나눈 값이 자카드 유사도
교합차: https://unluckyjung.github.io/cpp/2020/04/24/Set_Func/

*/
#if 1
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> vec1;
vector<string> vec2;

void Print_Vec(const vector<string>& vec) {
    for (auto& it : vec) {
        cout << it << " ";
    }
    cout << "\n";
}

vector<string> Union_Func() {
    cout << "Union_Func\n";
    vector<string> buff(vec1.size() + vec2.size());
    auto iter = set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buff.begin());
    buff.erase(iter, buff.end());

    //Print_Vec(buff);
    return buff;
}

vector<string> Intersection_Func() {
    cout << "Intersection_Func\n";
    vector<string> buff(vec1.size() + vec2.size());
    auto iter = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buff.begin());
    buff.erase(iter, buff.end());

    //Print_Vec(buff);
    return buff;
}

vector<string> CreateVec1(string str1 ) {
    vec1.clear();
    for (int i = 0; i < str1.size(); i++) {
        //첫글자 알파벳을 먼저 찾는다.
        if ((str1[i] >= 65 && str1[i] <= 90) || (str1[i] >= 97 && str1[i] <= 122)) {
            //알파벳인 녀석을 찾았다? 그러면 이제 i보다 크면서 인접한 다음 알파벳을 찾아야겠지.
            for (int j = i + 1; j < str1.size(); j++) {
                if ((str1[j] >= 65 && str1[j] <= 90) || (str1[j] >= 97 && str1[j] <= 122)) {
                //여기 안으로 들어왔으면 결국 i인 녀석과 j인 녀석을 결국 찾았다는 얘기 이때부터 할당한다.
                    //그런데 무조건 대문자로 통일할 것이다.
                    if (str1[i] >= 97) str1[i] -= 32;
                    if (str1[j] >= 97) str1[j] -= 32;
                    vec1.push_back({ str1[i], str1[j] });
                    //그렇게 만들어진 부분집합이 있고 다음 부분집합은 i의 인덱스 초기화로 시작되는데
                    //이때 i가 사이즈를 넘긴다면 반복이 돌지 않을 것이고, 애초에 중간에 j가 사이즈를 넘긴다면
                    //이것 또한 돌아가지 않을 것이다. 그런 예외를 적용해야되는데... 일단 나중에..
                    i = j - 1;//나중에 ++될 것
                    break;
                }
            }
        }
    }
    sort(vec1.begin(), vec1.end());
    return vec1;
}
vector<string> CreateVec2(string str2) {
    vec2.clear();
    for (int i = 0; i < str2.size(); i++) {
        //첫글자 알파벳을 먼저 찾는다.
        if ((str2[i] >= 65 && str2[i] <= 90) || (str2[i] >= 97 && str2[i] <= 122)) {
            //알파벳인 녀석을 찾았다? 그러면 이제 i보다 크면서 인접한 다음 알파벳을 찾아야겠지.
            for (int j = i + 1; j < str2.size(); j++) {
                if ((str2[j] >= 65 && str2[j] <= 90) || (str2[j] >= 97 && str2[j] <= 122)) {
                    //여기 안으로 들어왔으면 결국 i인 녀석과 j인 녀석을 결국 찾았다는 얘기 이때부터 할당한다.
                    if (str2[i] >= 97) str2[i] -= 32;
                    if (str2[j] >= 97) str2[j] -= 32;
                    vec2.push_back({ str2[i], str2[j] });
                    //그렇게 만들어진 부분집합이 있고 다음 부분집합은 i의 인덱스 초기화로 시작되는데
                    //이때 i가 사이즈를 넘긴다면 반복이 돌지 않을 것이고, 애초에 중간에 j가 사이즈를 넘긴다면
                    //이것 또한 돌아가지 않을 것이다. 그런 예외를 적용해야되는데... 일단 나중에..
                    i = j - 1;//나중에 ++될 것
                    break;
                }
            }
        }
    }
    sort(vec2.begin(), vec2.end());
    return vec2;
}

int solution(string str1, string str2) {
    int answer = 0;
    CreateVec1(str1);
    CreateVec2(str2);
    auto interSet = Intersection_Func();
    auto unionSet = Union_Func();
    cout << interSet.size()<<endl;
    cout << unionSet.size() << endl;
    answer = (((double)interSet.size() / (double)unionSet.size()) * 65536);

    return answer;
}

int main()
{
    cout << solution("FRANCE", "french") << endl; // 정답 : 16384
    cout << solution("handshake", "shake hands") << endl; // 정답 : 65536
    cout << solution("aa1+aa2", "AAAA12") << endl; // 정답 : 43690
    cout << solution("E=M*C^2", "e=m*c^2") << endl; // 정답 : 65536
}
#endif

// 2번
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    return answer;
}

int main()
{
    for (auto iter : solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
    {
        cout << iter << " "; // 정답 : 2 1 3 4
    }
    cout << endl;

    for (auto iter : solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))
    {
        cout << iter << " "; // 정답 : 2 1 3 4
    }
    cout << endl;

    for (auto iter : solution("{{20,111},{111}}"))
    {
        cout << iter << " "; // 정답 : 111 20
    }
    cout << endl;

    for (auto iter : solution("{{123}}"))
    {
        cout << iter << " "; // 정답 : 123
    }
    cout << endl;

    for (auto iter : solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))
    {
        cout << iter << " "; // 정답 : 3 2 4 1
    }
    cout << endl;
}
#endif