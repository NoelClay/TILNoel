//1��
// ���ľ˰��� ���� �ε��� ���ĺ���
// sort�� ���ڿ� ������ �����Ѵ�. https://www.delftstack.com/ko/howto/cpp/sort-string-in-cpp/
// ���� �ε��� ���ĺ��� �����ϰ��� �װ� �������� ���輺�� ���..
// 
// <2���õ�>
// ������ �ε����� �����ϴ� ��ųʸ� Ʃ�� ��� ���� �ڷᱸ���� �̿��Ҽ� ������ ����.
// strings�� �Է��� �� 50���̰�
// �� ������ ���̴� 100 ����.
// �� ���ڴ� �ƽ�Ű �ڵ�� �̷���� �ְ� ��� �񱳰� �����ϴ�. ������ �����̶� �������� ���İ��� ���������̴�.
// �������� ���� ��� �߿� ȿ������ ����� �պ�����, ������, 
// - �߰� ���� - ���ڿ��� ��Һ� https://dojang.io/mod/page/view.php?id=346
// ���ڿ��� ������ ������ �ܼ��ϴ�. ���ڿ��� ��Һ񱳸� �ϸ� ���ڿ��� ���������� ���ϸ鼭 ���������� �ڿ������� ���ڴ�
// �� ū ���ڿ��� �������ش�. ������ �� ��Һ񱳸� � �ε������� �������� �̴�. �׷���.. �ƿ� �� �ε����� �������� �ڸ�
// ���ڿ��� ����°͵� ����ϰ� ����.
// ���ڿ� �ڸ��� ��� https://velog.io/@qoehdcjswp/C-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%A0%95%EB%A6%AC
//
#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    //for (int i = 0; i < strings.size(); i++) {
    //    sort(strings.begin(), strings.end());
    //}
    vector<pair<string, int>> temp;

    for (int i = 0; i < strings.size(); i++) {
        temp.push_back(make_pair(strings[i].substr(n), i));
    }

    sort(temp.begin(), temp.end());

    for (int i = 0; i < strings.size(); i++) {//�� 50�� �ݺ��ϸ鼭
    //���ĵ� ������ �ι�° ������ ���� ����Ǿ��ִ� �ε��� ������ ������ �� ��Ʈ���� �����Ͽ� pushback
        answer.push_back(strings[temp[i].second]);
    }

    return answer;
}

int main() {
    vector <vector<string>> s = { { "sun", "bed", "car" }, {"abcd", "abce", "cdx"}};
    int n[] = { 1,2 };
    auto result = solution(s[1], n[1]);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}

//����
//�⺻������ ��ųʸ��� ���� �������� �����ϸ� �ʹ� ��������� ����. ���ڿ� ��Һ񱳰� �̷������ ������ �˻��غ�������
//��� ���������� �̷�������� �˼� �־���.
#endif

//2��
// ��Ʈ ������ 3�� ����ǰ� �� ���� x=0~10 �� �������� ���������� ���� sdt
// ���� ��Ÿ�� ������ ��Ÿ�� ��÷�� �ش� ������ �ٷ� ���� ������ �� 2���
// �������� �ش������� ���̳ʽ��� ��Ÿ���� ó������ ���� �� �ְ� �̶��� ó�������� 2���
// ���Ҵ� ������ �����°� �����ϸ� ��ø�Ǽ� ��� ����. ���̳ʽ��� ���� �Ȱ��� -2���
// sdt�� �������� �ϳ��� �ְ� ���Ҵ� �� �� �ϳ��� ���� �����ϰ� ���� ���� ���� ����.
// 
// ���ڿ� dartResult�� ���̰� �߱������̴�. �⺻������ ���� ���� ���̴� 6�� ���� �� ���ڿ��� 12������(10�� ���) ����
// ���ڸ� �������� �� �������� ���� ������ �� �� ���������� ù ������ ����.
// �ƽ�Ű�ڵ�ǥ https://stepbystep1.tistory.com/10
//
#if 0
#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[4] = { 0 };
    int j = 0;
    
    for (int i = 0; i < dartResult.size(); i++)
    {
        if (47 < dartResult[i] && dartResult[i] < 58) //���������� ���� �� ���ڶ��
        {
            j++;    //score[0] �� ������ 0�̴�.
            if (dartResult[i + 1] == '0') {//10�� ���
                score[j] == 10;
                i++;
            }
            else {
                score[j] += dartResult[i] -'0';
            }
        }
        else if (dartResult[i] == 'S')  score[j] = score[j];
        else if (dartResult[i] == 'D')  score[j] *= score[j];
        else if (dartResult[i] == 'T')  score[j] = score[j] * score[j] * score[j];
        else if (dartResult[i] == '#')  score[j] *= -1;
        else if (dartResult[i] == '*') {
            score[j - 1] *= 2;  score[j] *= 2;
        }
    }
    answer = score[1] + score[2] + score[3];
    return answer;
}

int main() {
    cout << solution("1S2D*3T");
}
//����
// �ܼ� ���� �Ǽ�. ���������� ��� �񱳸� �Ҷ� �ε�ȣ�� ������ �߸��Ǿ� �׻� �������� �� �̻��� ����� �߾���.
//
#endif

//3�� -���ذ�-
//�ִܰŸ� ��ã�� 
// 1. ������ ���� �ٽ� ���ư� �ʿ� ����. 
// 2. �������� ���� ��ġ�� ���ؼ� �� ���� �������� ����?
// 3. ĳ���Ϳ� �������� ���ÿ� ����
// dfs bfs
#if 0
#include<vector>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int curpos[2] = { 0 };
    int n = maps.size(), m = maps[0].size();
    for (int i = 0, j = 0; i < n;) 
    {
        if (n-i>m-j) {//���η� ������ ���� �� ���� ����
            if (maps[i + 1][j] == 1) curpos[0]++;
            else if (maps[i][j + 1] == 1) curpos[1]++;
        }
        else {//���η� ������ ���� �� ���� ����

        }
        maps[i][j];
        if (curpos[0] == n && curpos[1] == m) break;
        answer++;

    }

    return answer;
}
#endif