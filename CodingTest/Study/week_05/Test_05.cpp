//1��

//1. ������ϴ� �˰���
//2. ����� ���� üũ (¦���� result�� ���ϰ� Ȧ���� ��)
//3. s���� �����ؼ� n���� ����.

// �Ҽ��̸� ����� ¦����.
// ������ �ռ����� �Ҽ����� ������ ��Ÿ���� ����.
// ������ �ռ����� �����ٺ��� ���� �Ҽ���� ������������ ������ �� ���� �Ҽ���.

#if 0
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int start = left;
    bool primeCheck = true;
    //3. ����Ž��
    for (int i = 0; i <= (right - left); i++)
    {
        bool primeCheck = true;
        //int cnt = 0;//2.���� üũ
        
        //�Ҽ��Ǻ�
        for (int j = 2; j * j <= start; j++)
        {
            if (start % j == 0) { primeCheck = false; break; }
        }

        //�Ҽ���� ����� ¦�����ϱ�
        if (primeCheck) {
            answer += start;
        }
        //�Ҽ��� �ƴ϶�� ����� ������ üũ�ؾߵ� �� ����.
        //����� �ռ����� ������ ���� ������ �ִ� ���� �����̴�. ������� ���׿������̹Ƿ�, 
        // ������ �������ٴ� �Ҹ��� a = bq �� �����ϴ� b�� q�� ������ �Ҹ��̴�. 
        // b�� q�� ���� ��찡 �ƴ϶�� ����� ������ ¦���� ���̴�. 
        // ���� ����� ������ ¦�������� �Ѵ�.
        // ��������� ���Ұ� Ȧ������� �Ҹ��� a= b^2�� ��찡 �ִٴ� ��. 
        //���� � �ռ����� �������� ���������� üũ�ϸ�ȴ�.
        else if (((double)sqrt(start) - (int)sqrt(start)) == 0) answer -= start;
        else answer += start;

        start++;
    }

    return answer;
}
int main() {
    int s = 13, n = 17;
    cout << solution(s, n);
}


#endif

//2��

//1. �Ÿ������ �ؾߵǴ� ���� 2, 5, 8, 0
//2. ���� �հ����� ��ġ�� �����ϰ� ��� �־���Ѵ�.
//3. Ű�е�� 4*3 ����� ����� �����ϴ�. �� �ε����� ���� �̿��� �Ÿ� ����� ������ �� ����.
//������� 0,0 �� 3,1 �� �� 4����ŭ ������ �ִ�. 1,1�� 2,2�� 2��ŭ ������ �ִ�.

//ù��° �õ� ������
//2���� �迭�� �����س��� ���ϱ� �� ��ҿ� ��ġ�ϴ��� �˻��ϴ� �ܰ迡�� ������, 
//�ε����� ��� ��ȯ�ؾ������� �����ߴ�.
//�ذ�å
//1���� �迭�� ������ Ȱ���ϰ� �ε����� �ƴ� �ȿ� ��Ұ����� ������ �ڷ����� ��������.

//�ι�° �õ� ������
//�Ÿ������ ���� �޼���ġ ��������ġ�� ������ �ε����� ǥ���ϴ� Ʃ�� ��� ������ ������ �غ��� ������ 
//�� ȯ���ϴ� ������ ���� �����Ͽ� �˻��Ҷ����� make_pair�� �ҷ��� ������ ����� ������ 
//if���� �ٿ��ߵǼ� �ʹ� ������� ���Ҵ�.
// �ذ�å
// �������� ������ n�������� ��ȯ�ؼ� �����غ��Ҵ�. 
// ����3���� ����� -1�ϰ� ���� �ڸ��������� ���� ���Ѵ�.
//00 01 02 / 10 11 21 / 20 21 22 / 30 31 32 (0�� �ڵ����� 31 ��ȯ �ʱ���ġ�� ��30 ��32)


#if 0
#include <string>
#include <vector>
#include <algorithm> //sort, find
#include <unordered_map>//�ؽø� �����
 // pair : (a,b)������ �ڷᱸ��

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> keyPad;
    vector<pair<int, int>> hPosition;
    hPosition.push_back(make_pair(3, 0));
    hPosition.push_back(make_pair(3, 2));

    //int position[2] = { 22, 33 };   //22�� 33�� ���� *�� #�̶� �����غ���.

    //keypad ��ġ�� ������ ���� {0,0 0,1 0,2 ..... 3,2}
    for (int i = 0, j=0; i < 4; )
    {
        keyPad.push_back(make_pair(i, j));
        j++;
        if (j / 3 == 1) {
            i++;    j = 0;
        }
    }

    //�Ű������� ���� ���ڹ迭�� ���� �̿��� ��ġ���ڿ��� ��ȯ�ϰ� ��ġ�� ����ϴ� �ݺ���
    for (int i = 0; i < numbers.size(); i++)
    {
        //������ �����϶�
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            hPosition[0] = make_pair()
        }
        //������ �������϶�
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {

        }
        else
        {

        }
    }


    return answer;
}
#endif

//3��

//
//
//


#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    return answer;
}
#endif