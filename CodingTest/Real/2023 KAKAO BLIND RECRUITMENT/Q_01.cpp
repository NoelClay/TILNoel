/*1�� ���α׷���
���� ��� ���Ǹ� �� ������ 1~n������ �з��Ǵ� �������� n���� �ִ�. ��� ������ ��������
�� ������� �������� ���� ��ȿ�Ⱓ�� ���� ������ �ִ�. ����� �� ���������� � ������� �����Ǿ�����
�˰� �ִ�. ������ ���������� ��ȿ�Ⱓ �������� �����Ǹ�, �����ٸ� �ݵ�� �ı��ؾ��Ѵ�.
�������, A��� ����� ��ȿ�Ⱓ�� 12���̰�, 2021�� 1�� 5�Ͽ� ������ ���������� A������� �����Ǿ��ٸ�
�ش� ���� ������ 2022�� 1�� 4�ϱ��� ���������ϸ� 2022�� 1�� 5�Ͽ��� �ı��ؾ��Ѵ�.
����� ���� ��¥�� �ı��ؾ� �� �������� ��ȣ���� ���Ϸ� �Ѵ�.

��� ���� 28�ϱ����� �ִٰ� �����Ѵ�.

���� ��¥�� 2022.05.19��� �����Ѵٸ�
A: 6��, B: 12��, C:3�� �̶�� ����� �ִ�.
1�� 2021.05.02, A, 2021.11.02�� �ı�
2�� 2021.07.01, B, 2022.07.01�� �ı�
3�� 2022.02.19, C, 2022.05.19�� �ı�
4�� 2022.02.20, C, 2022.05.20�� �ı�

���� 2022.05.19 ��¥�� �ı��ؾ��� ������ 1��, 3���̴�.

���� ��¥ �� Ȯ�� ��¥ ���ڿ� today, ����� ��ȿ����� ���� ���ڿ��迭 terms,
������ ������������ ���� 1���� ���ڿ� �迭 privacies�� �Ű�����

���ѻ���
today�� "yyyy.mm.dd"
terms�� ���̴� 20����. "C 7"�� ���� ��� ���ĺ��� ��ȿ�Ⱓ�� �������� ������ ���ڿ�. ��ȿ�Ⱓ�� 100����
privacies�� ���̴� 100����. privacies[i]�� i+1�� ���������� ���� ���ڿ� ��� ������ ��Ÿ��.
privacies�� ���Ҵ� "��¥ �������"�� ���·� �������� ������ ���ڿ�
2000 <= yyyy <= 2022
1 <= mm <= 12
mm�� �� �ڸ����� ��� �տ� 0�� �ٴ´�.
1 <= dd <= 28
dd�� ���ڸ������ �տ� 0�� �ٴ´�.

<���ٹ��>
�ϴ� �־��� ������ ����� �� �ְ� �ٲٴ°� ���� �߿��ϰ��� ������ �� ������ Ŀ���⿡
mm�� 12���� Ŀ���� yyyy+=(mm/12) mm%=12
�ϰ��� today���� ���� �ֵ��� ���� ��ȯ answer�� �߰� �ƴ� �ֵ��� �߰� ����.
privacies�� ��ȸ�ϸ� ���ĺ������� ���Գ�¥ ������ �и��ϰ�
���ĺ� ������ �������� terms�� ��ϵ� ������ Ȯ���Ѵ�.(�� ������ terms�� �ٸ� ������� �����ϴ� �͵� ����̰ڴ�.)
    terms�� �����ϰ� �Ǹ� ���������� �ȴ�. �̶� 20���� �߰��� ���鼭 map �ؽ����̺��� ����ϴ°͵� ����̰ڴ�.)
�ƹ�ư terms�� ���ڸ� ��ȸ�Ͽ� ���Գ�¥�� �߰��� �ڿ� ���Գ�¥�� mm�� 12���� ũ�ٸ� ���� ���� Ȱ���Ͽ�
�����. �� ������� ���� today���� �۴ٸ� answer�� �߰�. today���� �������� ���� yyyy���� Ȯ���ϰ�
today�� yyyy���� �۴ٸ� �߰� ���ٸ� mm��ȸ mm�� ���ٸ� dd��ȸ ���� ���ų� �۴ٸ� ������ ��ȯ.

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
//���� �׽�Ʈ���̽� �Ѱ��� ���� �ߴ��� ���� ������� �𸣰ڴ�.