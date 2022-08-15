// 1��
/*
ũ�Ⱑ NxN���� ���ð� �ִ�. �� ĭ�� ��ĭ 0, �� 1, ġŲ�� 2 �� ä���� �ִ�. ������ ��ĭ�� (r,c) ��,�ķ� ǥ���ϰ�
�ǿ��� ���� 1,1 �� ������ �Ʒ��� r,c�� ǥ���Ѵ�.
���� ġŲ�� ������ ���� ����� �Ÿ��� ġŲ�Ÿ���. ġŲ �Ÿ��� .������ + ������ �� ���Ѵ�.
���ÿ��� �ִ� ġŲ���� ���� M�� �־����� �־��� �迭���� M���� ������ ������ ġŲ���� �����Ѵ�.
������ ��ġŲ�Ÿ��� ���� �۰ԵǴ� �Լ��� ������.
�Է�����
2 <= N <= 50, 1 <= M <=13
���ù迭 city�� �־���. ���� ������ 2N���� ���� �ʰ�, ��� 1���̻� ����.  M <= ġŲ���� ���� <= 13
�������
ġŲ�Ÿ��� ������ ��µ�.

<���ٹ��>
Ž���� �ؾ��Ѵ�.
�ᱹ 1�� �����ְ� 2�� �����ȴ�. �� 1�� �������� 2���� �Ÿ��� ����Ͽ� �����صд�.
m���� ���� 2�� �����ϴ� ����� ���� ���� ã�� �׶����� �� 1�� ���� �� �ִ� ���� �ּҰ��� ��ȯ�ϸ� ���� ������?
(����)������� �����ؼ� � ������ ã�Ƽ� ��� �ؾߵ��� ���� ����

<���ٹ��2>
city���� 2�� ����� ��ǥ�� �����صΰ� M����ŭ �̴� ����� ���� 2���� ���͸� ���� �����. 
�� ������ 1�� �ε����� 2�� �ε��������� �Ÿ��� ���� ����ϰ� �ּҰ��� ��ȯ�ؼ� answer�� ī��Ʈ�Ѵ�.
�׷����ϸ� �ᱹ �ּ� ġŲ�Ÿ����� ������ ��.
���� ���� �ּ� ġŲ�Ÿ��� ���� ������������ �� ���� �ּҰ�.
<����� ��><����>
https://ansohxxn.github.io/algorithm/combination/

*/
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//���� �����
vector<vector<pair<int, int>>> combTank;

void Combination(vector<pair<int, int>> arr, vector<pair<int,int>> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        combTank.push_back(comb);
    }
    else if (depth == arr.size())  // depth == n // ��� �Ȼ̴ٰ� r ���� ä���� ���� ���� �� ���� �ɷ��� �Ѵ�.
    {
        return;
    }
    else
    {
        // arr[depth] �� ���� ���
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);
        //�ѹ� �� combination�� ��������� ��� ����Ǹ� ȣ���ϰ� ����ȴ�.

        // arr[depth] �� ���� ���� ���
        Combination(arr, comb, r, index, depth + 1);
    }
}


int solution(int N, int M, vector<vector<int>> city_map) {
    vector<pair<int, int>> comb(M);
    vector<pair<int, int>> twoVector;
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (city_map[i][j] == 2) {
                twoVector.push_back({ i, j });
            }
        }
    }
    Combination(twoVector, comb, M, 0, 0);

    return answer;
}

int main()
{
    vector<vector<int>> city_1 = { {0, 0, 1, 0, 0},
                                   {0, 0, 2, 0, 1},
                                   {0, 1, 2, 0, 0},
                                   {0, 0, 1, 0, 0},
                                   {0, 0, 0, 0, 2}, };

    vector<vector<int>> city_2 = { {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0}, };

    vector<vector<int>> city_3 = { {0, 2, 0, 1, 0},
                                   {1, 0, 1, 0, 0},
                                   {0, 0, 0, 0, 0},
                                   {2, 0, 0, 1, 1},
                                   {2, 2, 0, 1, 2}, };

    cout << solution(5, 3, city_1) << endl; // ���� : 5
    cout << solution(5, 1, city_2) << endl; // ���� : 11
    cout << solution(5, 2, city_3) << endl; // ���� : 10
}
#endif

// 2��
/*
������ũ�� �� �������� �߶� �� ������ ���� �������� ��. ���� ���ε��� �Ϸķ� �÷��� �ִ�. ������ũ�� �����ϰ� �����������µ�
������ũ�� ũ�⺸�� ������ ������ �� ������ ����. ��� �߷ȴ��� ������� ������ �� ������ ������ ������(����)�� 
�����ϰ� �ö� �ִ����� ������ �ִ�.
������� 12131412 �� ������ 1213 / 1412 or 12131/ 412 �ΰ� �� ���� 3������ �����ϴ� ������ ����̰� ������ ����Ǽ��� 
2���� �̴�. ������ ����� ���� �����ϴ� �ַ�� �Լ�

�Է�����
1<=topping.size() <= �鸸 ,   1<=topping�� �� ���� ũ�� <= 10000

�Է¿���    ��¿���
12131412        2
12314           0

<���ٹ��>
�ߺ��� �����ϱ� ���� map�� ����ϰ� (left, int) (right, int)�� ���� ���ʿ��� �����ʿ��� ���鼭 �����ϰ�
left >= right ���ǿ� �ش��ϸ� �ε����� ���� �����ٴ� ��. �̶� ���ϴ°� ���߰� �� �κ� ������ ���ؼ�..
(����)
*/
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = -1;

    return answer;
}

int main()
{
    cout << solution({ 1, 2, 1, 3, 1, 4, 1, 2 }); // ���� : 2
    cout << solution({ 1, 2, 3, 1, 4 }); // ���� : 0
}
#endif

// 3��
/* �ʴ����� ��ϵ� �ֽ� ������ ��� �迭 prices, ������ �������� ���� �Ⱓ�� �� ���ΰ��� return
<���ٹ��>

�����̽��� ���ÿ� �߰��Ǿ��ִ� �ͺ��� ũ�� �߰��ϰ� ������ ī������ �����鼭 ���ÿ� ���� �Ͼ��. �̶� �ݺ������� ����������
�ݺ����� �����鼭 ī������ �ڵ����� �ε����� �̷������.

*/
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> count(5);
    int cnt = 0;

    stack<int> istack;
    //22311
    for (int i = 0; i < prices.size(); i++) {
        if (istack.empty() || istack.top() <= prices[i]) {
            istack.push(prices[i]);
        }
        else {
            while (!(istack.top() > prices[i])) {
                
            }
            count[i] = cnt;
            istack.pop();
        }
        cnt++;
    }

    return answer;
}

int main()
{
    // ���� : 4 3 1 1 0
    for (auto iter : solution({ 1, 2, 3, 2, 3 }))
    {
        cout << iter << " ";
    }
}
#endif