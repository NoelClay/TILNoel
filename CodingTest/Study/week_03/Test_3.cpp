//1��
//2���� �迭�� ������ �迭�� ���̸�ŭ �ε����� Ž���ϴ� ���� 
//signs�� �˻��ؼ� true�� + false�� -ȭ �Ͽ� answer�� �����ϰ� ��ȯ
#if 0
#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for (int i = 0; i < signs.size(); i++)
    {
        if (signs[i] == true) 
            answer += absolutes[i];
        else
            answer -= absolutes[i];
    }

    return answer;
}
int main()
{
    int N;
    vector<int> absolute;
    vector<bool> signs;
    char check;
    int icheck;

    cout << "N: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << "��ȣ �Է�: ";
        cin >> check;
        if (check == '-')
            signs.push_back(false);
        else
            signs.push_back(true);
        cout << "���� �Է�: ";
        cin >> icheck;
        absolute.push_back(icheck);    
    }

    cout << solution(absolute, signs);
}
#endif

//2��
//��ü �л� �� ��ŭ
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<bool> cloth(n, false);
    int cnt = 0;

    for (int i = 0; i < reserve.size(); i++) {
        cloth[reserve[i]-1] = true;
    }
    
    for (int i = 0; i < lost.size(); i++) {
        if (cloth[lost[i] - 1] == true) {
            cloth[lost[i] - 1] = false;
            cnt++;
        }
        else if (lost[i] > 1 && cloth[lost[i] - 2] == true) {
            cloth[lost[i] - 2] = false;
            cnt++;
        }
        else if (lost[i] < n && cloth[lost[i]] == true) {
            cloth[lost[i]] = false;
            cnt++;
        }
    }
    answer = n - lost.size() + cnt;
    return answer;
}

int main()
{
    int n = 3;
    vector<int> lost = { 3 };
    vector<int> reserve = { 1};
    cout << solution(n, lost, reserve) << endl;
}

#endif

//3��
//�ε����� �ϳ��� Ž���Ҷ� ���� �ʸ� ī��Ʈ �Ѵ�. cnt++
//�ε����� �����Ҷ����� ���� �ε����� ���� �� ������ ������ n�� Ž���ϸ� ��Һ��ϵ� n����....
//�۾����ٸ� �׶��� cnt���� count ������ �־��ش�.
//count 
//�߰��� �迭�� ī�����ʸ� ��ȯ�Ѵ�.
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> count(prices.size());
    int cnt = 0;
    for (int i = 0; i < prices.size(); i++) {
        for (int j = 0; j < i; j++) 
        {
            if (answer[j] > answer[i] && count[j] == 0)//������ �������ٸ� �׸��� �ʰ� �Ҵ������ ���ٸ�
            {
                count[j] = cnt;//������������ �ʸ� �Ҵ�.
            }
        }
        cnt++;
        
    }
    //cnt�� �Ҵ���� ���� count�迭�� ã�� ���� cnt�� �Ҵ�
    for (int i = 0; i < prices.size(); i++) {
        if (count[i] == 0) {
            count[i] = cnt;
        }
    }
    //�� ���ݺ� ��������� ī���� ��ž�� ����Ǿ������� count�� ����Ǿ� ����.
    //�� ���ݺ� ���� ������ �� �ε��� �̹Ƿ� �ε�����ŭ ���ָ� ��.
    for (int i = 0; i < prices.size(); i++) {
        answer[i] = count[i] - i;
    }
    return answer;
}

int main()
{
    int N = 0;
    vector<int> prices;
    int icheck;
    

    cout << "N: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << "�����Է�: ";
        cin >> icheck;
        prices.push_back(icheck);
    }
    vector<int> answer(N);
    answer = solution(prices);

    for (int i = 0; i < N; i++) {
        cout << answer[i];
    }

}
#endif

//3�� ���� 1 ���ذ�
// <legacy>
//�ε����� �ϳ��� Ž���Ҷ� ���� �ʸ� ī��Ʈ �Ѵ�. cnt++
//�ε����� �����Ҷ����� ���� �ε����� ���� �� ������ ������ n�� Ž���ϸ� ��Һ��ϵ� n����....
//�۾����ٸ� �׶��� cnt���� count ������ �־��ش�.
//count 
//�߰��� �迭�� ī�����ʸ� ��ȯ�Ѵ�.

//<new>
// �� �ʸ��� ������ ���ŵǴµ� �� ����� ���ݵ��� �������� ������ �ʸ� ���� ����
// ����Ǿ� �ִ� ���ں��� �� ���� ���ڰ� ���ö� �� ī������ �����.
// �����̽� �迭�� ���̴� �ʸ��̹Ƿ� ���������� ������ �ʴ´�.
// �̷��� �Է��� �� ������ 1. ��Ģ�� 2. �ڷᱸ�� �� Ȱ���� ������ �ʿ��ϴ�.
// �׸��� ���� ���ӵ� �Է°��� ��Ұ��踦 ���ؼ� �̹� �ȿ� ����ִ� �ڷ��� ī������ ���ߴ°�
// ������ Ȱ���ϸ� �ɰͰ��� ������ ���.
// 
// �ݺ����� �����鼭 ī������ �ڵ����� �ε����� �̷������.
// 
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;
    vector<int> count(5);
    int cnt = 0;
    
    stack<int> istack;
    cnt = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (istack.empty() || istack.top() <= prices[i]) {
            istack.push(prices[i]);
        }
        else {
            count[i] = cnt;
            istack.pop();
        }
        cnt++;
    }
    for (int i = 0; i < prices.size(); i++) {
        if (count[i] == 0) {
            count[i] = cnt;
        }
    }
    for (int i = 0; i < prices.size(); i++) {
        answer[i] = count[i] - i;
    }
    return answer;
}

int main()
{
    int N = 5;
    vector<int> prices = {1, 2, 3, 2,3};
    int icheck;


    //cout << "N: ";
    //cin >> N;

    //for (int i = 0; i < N; i++) {
    //    cout << "�����Է�: ";
    //    cin >> icheck;
    //    prices.push_back(icheck);
    //}
    //
    auto answer = solution(prices);

    for (int i = 0; i < N; i++) {
        cout << answer[i];
    }

}
#endif