/*1��
īī���� ���� �����ڷ� �Ի��� �����̴� ���� �����ڷκ��� ������ ����.
������ �ҽ� �ڵ峻 �ۼ��� ��ȣ�� ������ ������ ¦�� ���� ���� ���·� �ۼ��Ǿ�
������ ���� ���� �˾Ҵ�.
�ҽ� �ڵ� ���� ��� ��ȣ�� �̾Ƽ� �ùٸ� ������� ��ġ�� ��ȣ ���ڿ��� �˷��ִ� ���α׷�
�����ϸ� �ȴ�.
����� ����
'('��')' �θ� �̷���� ���ڿ��� �ִ� ���, '('�� ������ ')'�� ������ ���ٸ� �̸� ��������
��ȣ ���ڿ��̶�� �θ���.
�׸��� ���⿡ '('��')'�� ��ȣ�� ¦�� ��� ���� ��� �̸� �ùٸ� ��ȣ ���ڿ��̶�� �θ���.
�������, "(()))("�� ���� ���ڿ��� �������� ���ڿ������� �ùٸ� ��ȣ ���ڿ��� �ƴϴ�.
'('��')'�θ� �̷���� ���ڿ� w�� "�������� ��ȣ ���ڿ��̶��" ������ ���� ������ ����
�ùٸ� ��ȣ ���ڿ��� ��ȯ�����ϴ�.
1. �Է��� �� ���ڿ��� ��� ���ڿ� ��ȯ
2. ���ڿ� w�� �� �������� ��ȣ ���ڿ� u, v�� �и��Ѵ�. 
�� u�� �������� ���ڿ��� ���̻� �и��� �� ������ϰ� v�� ���ڿ����°� �����ϴ�.
3. ���ڿ� u�� �ùٸ��ٸ� ���ڿ� v�� ������ �ٽ� 1�ܰ���� ����
3-1. ������ ��� ���ڿ��� u�� �̾����.
4. ���ڿ� u�� �ùٸ��� �ʴٸ� �Ʒ� ������ ����
4-1. �� ���ڿ��� ù ���ڷ� '('�� ���δ�.
4-2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾���δ�.
4-3. ')'�� �ٽ� ���δ�.
4-4. u�� ù��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� 
�ڿ� ����.
4-5. ������ ���ڿ��� ��ȯ�Ѵ�.

w�� ���̴� 1000������ ¦��. �׻� �������� ���ڿ��� �־���. �ùٸ� ���ڿ��̸� �״�� return

*/
#if 0
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool firstcheck(string p) {
    if (p == "") return true;
}
//�������� ����, �ε����� �и�
pair<string, string> secondcheck(string p) {
    bool isend = false;
    int lcnt = 0, rcnt = 0;
    string u, v;
    for (auto n:p) {
        if (isend) v += n;
        else {
            if (n == '(') lcnt++;
            else rcnt++;
            u += n;
            if (lcnt == rcnt) isend = true;
        }
    }
    return { u, v };
}
void finalcheck(pair<string, string> spair) {
    string u = spair.first, v = spair.second;
    int lcnt = 0, rcnt = 0;
    bool isRight = false;
    for (auto n : u) {
        if (n == '(') lcnt++;
        else rcnt++;
        if (lcnt == rcnt) break;
    }

    if (lcnt + rcnt == u.size()) isRight = true;
    //3��
    if (isRight) {
        bool isblank = firstcheck(v);
    }
    //4��
    else
    {

    }
}


string solution(string p) {
    
    string answer = "";
    return answer;
}

int main()
{
    cout << solution("(()())()");
    cout << solution(")(");
    cout << solution("()))((()");
}
#endif
/*����

*/

// 2��
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int n = survey.size();
    map<char, int> dp = { {'R',0},{'T',0},{"CF",0},{"FC",0},
        {"JM",0},{"MJ",0},{"AN",0},{"NA",0}};
    for (int i = 0; i < n; i++) {
        if (choices[i] == 4) { continue; }
        else if (choices[i] > 4) { //�����Ѵٴ� �� 5�� 1�� 6�� 2�� 7�� 3��
            dp[survey[i][1]] += (choices[i] - 4);
        }
        else {
            dp[survey[i]] += (4 - choices[i]);
        }
    }
    if (dp["RT"] >= dp["TR"]) answer += 'T';
    else answer += 'R';
    if (dp["CF"] >= dp["FC"]) answer += 'F';
    else answer += 'C';    
    if (dp["JM"] >= dp["MJ"]) answer += 'M';
    else answer += 'J';    
    if (dp["AN"] >= dp["NA"]) answer += 'N';
    else answer += 'A';
    return answer;
}

int main()
{
    cout << solution({ "AN", "CF", "MJ", "RT", "NA" }, { 5,3,2,7,5 }) << endl;
    cout << solution({ "TR", "RT", "TR" }, { 7,1,3 })<<endl;
}
#endif