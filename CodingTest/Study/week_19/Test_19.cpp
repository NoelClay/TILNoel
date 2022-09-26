// 1��
/*��ī�� ���絵

<���� ���>
���⵵ ���������� �ϴ� �������� ������
1. ������ ��ҹ��� �������� ���� �����ϰ� ���������� �����
�ƽ�Ű�ڵ� ������ �빮�ڴ� 65~90 �ҹ��ڴ� 97~122 
���� �빮�ڿ� �ҹ��ڰ� ���̴� 32

2. ������ ������ �׸��� �� ������ ���� ���̷� ���� ���� ��ī�� ���絵
������: https://unluckyjung.github.io/cpp/2020/04/24/Set_Func/

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
        //ù���� ���ĺ��� ���� ã�´�.
        if ((str1[i] >= 65 && str1[i] <= 90) || (str1[i] >= 97 && str1[i] <= 122)) {
            //���ĺ��� �༮�� ã�Ҵ�? �׷��� ���� i���� ũ�鼭 ������ ���� ���ĺ��� ã�ƾ߰���.
            for (int j = i + 1; j < str1.size(); j++) {
                if ((str1[j] >= 65 && str1[j] <= 90) || (str1[j] >= 97 && str1[j] <= 122)) {
                //���� ������ �������� �ᱹ i�� �༮�� j�� �༮�� �ᱹ ã�Ҵٴ� ��� �̶����� �Ҵ��Ѵ�.
                    //�׷��� ������ �빮�ڷ� ������ ���̴�.
                    if (str1[i] >= 97) str1[i] -= 32;
                    if (str1[j] >= 97) str1[j] -= 32;
                    vec1.push_back({ str1[i], str1[j] });
                    //�׷��� ������� �κ������� �ְ� ���� �κ������� i�� �ε��� �ʱ�ȭ�� ���۵Ǵµ�
                    //�̶� i�� ����� �ѱ�ٸ� �ݺ��� ���� ���� ���̰�, ���ʿ� �߰��� j�� ����� �ѱ�ٸ�
                    //�̰� ���� ���ư��� ���� ���̴�. �׷� ���ܸ� �����ؾߵǴµ�... �ϴ� ���߿�..
                    i = j - 1;//���߿� ++�� ��
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
        //ù���� ���ĺ��� ���� ã�´�.
        if ((str2[i] >= 65 && str2[i] <= 90) || (str2[i] >= 97 && str2[i] <= 122)) {
            //���ĺ��� �༮�� ã�Ҵ�? �׷��� ���� i���� ũ�鼭 ������ ���� ���ĺ��� ã�ƾ߰���.
            for (int j = i + 1; j < str2.size(); j++) {
                if ((str2[j] >= 65 && str2[j] <= 90) || (str2[j] >= 97 && str2[j] <= 122)) {
                    //���� ������ �������� �ᱹ i�� �༮�� j�� �༮�� �ᱹ ã�Ҵٴ� ��� �̶����� �Ҵ��Ѵ�.
                    if (str2[i] >= 97) str2[i] -= 32;
                    if (str2[j] >= 97) str2[j] -= 32;
                    vec2.push_back({ str2[i], str2[j] });
                    //�׷��� ������� �κ������� �ְ� ���� �κ������� i�� �ε��� �ʱ�ȭ�� ���۵Ǵµ�
                    //�̶� i�� ����� �ѱ�ٸ� �ݺ��� ���� ���� ���̰�, ���ʿ� �߰��� j�� ����� �ѱ�ٸ�
                    //�̰� ���� ���ư��� ���� ���̴�. �׷� ���ܸ� �����ؾߵǴµ�... �ϴ� ���߿�..
                    i = j - 1;//���߿� ++�� ��
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
    cout << solution("FRANCE", "french") << endl; // ���� : 16384
    cout << solution("handshake", "shake hands") << endl; // ���� : 65536
    cout << solution("aa1+aa2", "AAAA12") << endl; // ���� : 43690
    cout << solution("E=M*C^2", "e=m*c^2") << endl; // ���� : 65536
}
#endif

// 2��
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
        cout << iter << " "; // ���� : 2 1 3 4
    }
    cout << endl;

    for (auto iter : solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))
    {
        cout << iter << " "; // ���� : 2 1 3 4
    }
    cout << endl;

    for (auto iter : solution("{{20,111},{111}}"))
    {
        cout << iter << " "; // ���� : 111 20
    }
    cout << endl;

    for (auto iter : solution("{{123}}"))
    {
        cout << iter << " "; // ���� : 123
    }
    cout << endl;

    for (auto iter : solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))
    {
        cout << iter << " "; // ���� : 3 2 4 1
    }
    cout << endl;
}
#endif