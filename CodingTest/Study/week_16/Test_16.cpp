// 1��
/*<���ٹ��>
�� ť�� ��Ұ��� �񱳸� ���� �����ұ�? ������� ū���� ��� ���ϰ� ���� ���� Ǫ���ϰ� �װ� �ݺ��� �ϴٰ�
������� ��ġ���� ������ ������? ���� ���̻� �ϳ��ۿ� �ȳ��Ҵµ��� ũ�ٸ� ����� �����ϱ� -1�ΰŰ�
�ٵ� ���� �߿��Ѱ� �ּ� Ƚ���� ��ȯ�ؾ��Ѵٴ� ��. �� ����� �ּ� Ƚ���� �����ϴ°�? ���ø� ������ ����
queue1                  queue2
1 3 5 7 9               2 4 5 8 10
1 3 5 7 9 2             4 5 8 10 

9 3 2 3 3               16 4 3 2 1
9 3 2 3 3 16            4 3 2 1
3 2 3 3 16              4 3 2 1 9
2 3 3 16                4 3 2 1 9 3
3 3 16                  4 3 2 1 9 3 2
3 3 16 4                3 2 1 9 3 2
3 16 4                  3 2 1 9 3 2 3
��.. �׷��� �̰� �����ض�°� ��� ����?
���� �Ϻ��Ѱ� ��� ����� ���� �� ���ϴ°ǵ� �װ� �����Ѱ�?

���͸� ťó�� Ȱ���غ���. -> pop_front ����� �������� �ʱ� ������ �Ұ����ϴ�. 
�ֳ��ϸ� ���긶�� ���� ������ŭ ��� �ð��� �ʿ��ѵ� �̷��� �ð����⵵�� �ʹ� Ŀ��.

�׳� ť�� �������.
*/
#if 0
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1=0, sum2=0, ttime;
    queue<int> q1, q2;
    for (auto n : queue1) {
        sum1 += n;  q1.push(n);
    }
    for (auto n : queue2) {
        sum2 += n;  q2.push(n);
    }
    ttime = sum1 + sum2;
    if (ttime % 2 == 1) return -1;
    
    ttime = queue1.size() + queue2.size(); //�� ������ �������� Ǫ������ �Ͼ�� ���� ..
    //�鸸��?..
    //������� �ʱ�ȭ.

    while (!q1.empty() && !q2.empty() && answer<=ttime) {
        if (sum1 == sum2) return answer;
        else if (sum1 < sum2) { //queue2���� pop queue1���� push
            sum1 += q2.front(); sum2 -= q2.front();
            q1.push(q2.front());    q2.pop();           
        }
        else if (sum1 > sum2) { //q1 -> q2
            sum2 += q1.front(); sum1 -= q1.front();
            q2.push(q1.front());    q1.pop();
        }
        answer++;
    }
    if (q1.empty() || q2.empty() || answer > ttime) return -1;
    else
    {
        return answer;
    }
}

int main()
{
    cout << solution({ 3,2,7,2 }, { 4,6,5,1 }) << endl; // ���� : 2
    cout <<solution({ 1,2,1,2 }, { 1,10,1,2 })<<endl; // ���� : 7
    cout <<solution({ 1,1 }, { 1,5 })<<endl; // ���� : -1
}
#endif

/*2��
XYZ ��Ʈ�� ������ �ݾ��� �����ϸ� 10�� ���� ȸ�� �ڰ��� �ο��մϴ�. XYZ ��Ʈ������ ȸ���� �������
���� �� ���� ��ǰ�� �����ϴ� ��縦 �մϴ�. �����ϴ� ��ǰ�� �Ϸ翡 �ϳ����� ������ �� �ֽ��ϴ�.
�˵��� �����̴� �ڽ��� ���ϴ� ��ǰ�� ������ �����ϴ� ��¥�� 10�� �������� ��ġ�� ��쿡 ���缭
ȸ�������� �ҷ��մϴ�.
���� ���, �����̰� ���ϴ� ��ǰ�� �ٳ���3 ���2 ��2 �������2 ����1 �̸�, XYZ��Ʈ���� 14�ϰ� ȸ����
������� �����ϴ� ��ǰ�� ��¥ ������� ġŲ, ���, ���, �ٳ���, ��, ���, �������, �ٳ���, �������,
��, ����, �ٳ���, ���, �ٳ����� ��쿡 ���� �˾ƺ��ô�.
ù° ������ ���� ������ ���� �������� �ʱ� ������ ù° ������ ȸ�������� ���� �ʽ��ϴ�.
��° ������ ���� ������ �ٳ����� ���ϴ� ��ŭ ���� ���� �� �� ���� ������ ��° ������ ȸ�������� ���� �ʽ���.
��°, ��°, �ټ�° ���ʹ� ���ϴ� ��ǰ�� ������ ��ġ�ϱ⿡ �� �߿� �Ϸ翡 ȸ�������� �Ϸ���.
���ϴ� ��ǰ �迭 want, ��ǰ ���� �迭 number, ���� ǰ�� �迭 discount
���ϴ� ��ǰ�� ��� ���� ���� �� �ִ� ��¥�� �� �ϼ��� return ������ 0

<���ٹ��>
������ 10�� �����̴�. discount�� 10��. �̰� ������ �ؼ� ���� �Ҽ� �ִ� ����� �ƴϴ�. �� ������ �ϸ� �ȵȴ�.
discount�� ����Ž���ϸ鼭 ���������δ� ��� ���� �ε������� want�� �����ϴ����� 10�� ���ư��ϱ� 100����!
*/
#if 0
#include <string>
#include <vector>
#include <map>
#include<iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    int totalcnt = 0;
    bool success = false;
    map<string, int> check; //{want number}
    for (int i = 0; i < want.size(); i++) {
        check.insert({ want[i], number[i] });
        totalcnt += number[i];
    }
    //+1�� �ؾ� ������ ��ұ��� Ž�� ���� 11���� �������� 10���� Ž���ϴ� ����� 11-10+1�� 2�����̴�.
    for (int start = 0; start < discount.size() - totalcnt+1; start++) {
        for (int i = 0; i < totalcnt; i++) {
            if (check.find(discount[start+i]) != check.end() && check[discount[start+i]]>0) { //��ī��Ʈ�� ã�� �����Ͱ� �ִٸ�
                check[discount[start+i]]--;
                success = true;
            }
            else {
                success = false;//�ݺ����� �� ���� ������ else�� �ѹ��̶� ������ �׳� ���д�.
                break;
            }
        }//���� �ݺ��� ��
        if (success) answer++;
        //�ٽ� checkmap�ʱ�ȭ
        for (int i = 0; i < want.size(); i++) {
            check[want[i]]= number[i];
        }
    }

    return answer;
}

int main()
{
    cout << solution({ "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 },
        {"chicken", "apple", "apple", "banana", "rice",
        "apple", "pork", "banana", "pork", "rice",
        "pot", "banana", "apple", "banana"}); // ���� : 3

    cout << endl;
    
    cout << solution({ "apple" }, { 10 },
        { "banana","banana", "banana", "banana", "banana",
        "banana", "banana", "banana", "banana", "banana" }); // ���� : 0
}
#endif
/*����

*/