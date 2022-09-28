// 1��
/* �Ǻ���ġ ���� ���� 0�� 1�� �����Ѵ�. 0��°�� 0 1��°�� 1 �� �������ʹ� �ٷξտ� �ִ�
�� ���� ���� ���Ұ� �˴ϴ�. ��ȭ���� An = An-2 + An-1 �̷���.

<���ٹ��>
�̴� ��ͷ� ��� ȣ���ϴ� ����� �̿��ؼ� Ǫ�°� ���� ������ �ܼ��ϰ� �����ü�� �ӵ���
����Ű�� ���ؼ��� ���Ҿ� ����� �ݺ����� ���� �� ȿ������ ���̴�.
*/
#if 0 //ž�ٿ� - ���
#include <string>
#include <iostream>

using namespace std;

int solution(int number) {
    if (number == 0) return 0;
    if (number == 1 || number == 2) return 1; //��� ���Ṯ
    return solution(number - 2) + solution(number - 1);
}

int main()
{
    cout << solution(10) << endl;
    cout << solution(5) << endl;
    cout << solution(15) << endl;
}
#endif
#if 0 //���Ҿ� �ݺ���
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int solution(int number) {
    dp.clear();
    int answer = 0;
    int idx = 2;
    dp.push_back(0);
    dp.push_back(1);
    while (idx <= number) {
        dp.push_back(dp[idx - 2] + dp[idx - 1]);
        idx++;
    }
    return answer = dp[number];
}

int main()
{
    cout << solution(10) << endl;
    cout << solution(5) << endl;
    cout << solution(15) << endl;
}

#endif // 1 //���Ҿ� �ݺ���



// 2��
/* ������� �������� ���� ��� ����. N�� 3�� �ŵ����� �̶�� �Ҷ�, ũ�� N�� ������ N x N
���簢�� ����Դϴ�. ũ�� 3�� ������ ����� ������ �ְ�, ����� ������ ��� ĭ��
���� �ϳ��� �ִ� �����̴�.
N�� 3���� ū ���, ũ�� N�� ������ �������� ä���� ����� N/3x N/3 ���谡���� ũ�� N/3��
�������� �ѷ��� �����̴�. N�� ������ 3�� �ŵ����� ���·� �־�����.

<���ٹ��>
3�� �ŵ����� ������� 1���� 1�� 2���� �� 2���� 3���� �� 3������ ������ ������ �ȴ�.
3���� ��� �����鼭 ����� �Ѵ�. ���Ҿ� ����̶�� �� �ʱⰪ ���� �Ű��������� ��ȭ���� �����ϸ�
ž�ٿ� ����� �⺻���� ��ȭ�� ������ ���� ������ �����ϴ�.
��ȭ���� ���� 3�� ��� 2�� �ؿ� 3�� ����ϴ� �Ŵ�. 

9�϶� �� ���Ұ� 3x3 3�϶� 1x1 27�϶� 9x9

<���� ��� 2>
�ƿ� �� ���� �����ִ� �༮���ٰ� ��ĭ���� �ٲ�ߵ� �κи� ��ĭ���� �ٲٴ� ����� ������ ����
�װ� ������ ��������...
��������� ȣ���ϴ°� ������ ��°� �ƴ϶� ����°�. �� �Ʒ��� 1���� ����� �״����� 9���� ����� 
�� ������ 27���� ����� ���
���ʹ� ��� ����? 3x3���� 2x2�� ���� 9x9���� 4~6x4~6�� ���� 27x27���� 9~17x9~17�� ����
�̰� ��� ����ΰ���? ��� ������ ��������̴µ�...

<���� ��� 3>
�ٽ� ���. �̰� �׳� �迭�� �ִ°� �������� ��� ������ ��µǴ����� �����̴�.
�ᱹ �ٹٲ��� �ѹ� �ϰ� �� ��� �ٽ� ���� �ö󰡴°� �Ұ����ϴ�. �ᱹ ��������δ� 3x3��
������ ����Ѵٰ� ���������� �����δ� �׷� ����� �Ұ����Ѱ� ����.

-> �׷��ٸ� 27�̸� 27�� �� ����� �ٳѱ�� * ** * �ݺ��ؼ� 27�� ��� �̷���?
�̷��ٰ� �߰��� 4��° �ݺ����� ***   ******   *** �̰��� 27������ �ݺ�?
�� ��ĭ �ε����� ���ϴ� �Ϲݽ��� �ʿ��ϴٸ� �� �Ϲݽ��� 3�϶� 1,1
9�϶� 3,3 ~ 5,5 ���� ��ĭ ũ�� �׸��� 1,1 1,4 1,7 4,1 4,4 4,7 7,1 7,4 7,7
27�϶�

(i/3)%3 == 1 && (j/3)%3 == 1

*/
#if 0 //���Ҿ�
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> dp;

vector<string> solution(int number) {
    dp.clear();
    vector<string> temp = { "***", "* *", "***" };
    dp.push_back(temp);
    int idx = 3;
    while (idx <= number)
    {
        int i = cbrt(idx) - 1;
        vector<string> temp1;
        temp1.push_back(dp[i][0] + dp[i][0] + dp[i][0]);
        temp1.push_back(dp[i][1] + dp[i][1] + dp[i][1]);
        temp1.push_back(dp[i][2] + dp[i][2] + dp[i][2]);
        dp.push_back(temp1);
    }

    return answer;
}

int main()
{
    
}
#endif

#if 0//ž�ٿ�
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> solution(int number) {
    if (number == 3) {

    }
    vector<string> answer;
}

int main()
{

}
#endif

//������ 
#if 0
#include<iostream>
using namespace std;

void star(int i, int j, int num)
{
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        cout << ' ';
    }
    else
    {
        if (num / 3 == 0)
            cout << '*';
        else
            star(i, j, num / 3);
    }
}
int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            star(i, j, num);
        cout << '\n';
    }
}
#endif // 1
