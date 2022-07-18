#if 0
#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(string s, int n) {
    string answer(s);

    //Uppercase Lowercase ���� ������ ������ +n�ϰ� �ɰ�� ����
    for (int i = 0; i < s.length(); i++)
    {
        //Upper A:65 Z:90 91-26 = 65 ���� Upper+n-26 �������� n�� 1�̻� 25���� �ڿ����̴�. 
        // ���� n�� 26���� ū ����� n�� ���� 26���� ���� �������� ���ϰ� -26�� �߾�� �ɰ� ����.
        if (64 < s[i] && s[i] < 91) {
            if (s[i] + n > 90) { answer[i] = answer[i] + n - 26; }
            else { answer[i] += n; }
        }

        //Lower a:97 z:122
        else if (96 < s[i] && s[i] < 123) {
            if (s[i] + n > 122) { answer[i] = answer[i] + n - 26; }
            else { answer[i] += n; }
        }
        else {  }
    }
    return answer;
}
int main() {
    string s = "a b z";
    int n = 4;
    cout << solution(s, n);
}

#endif

//1. x���� 1ū���� �������� Ž���ϸ鼭 ��Ʈ �ٸ� ������ ���� 1~2�� ���� ���� ��ȯ
// 
//2. x�� ��Ʈ ���¸� �ٷ� �� �� �ִٸ� �ֿ����� ��Ʈ�� ����ִٸ� ä��� ������ ��
//2-1 �ǿ����� ��Ʈ�� ä���� �ִٸ� ���� ������ ��Ʈ�� ����ִ� ������ �ϴ� ä��� 
//������ �����ʿ� �ִ� ��Ʈ ���� 0���� �ٲ۴�. �׸��� ó�� ���º��� 1�� 2�����̳������� �� �����ʺ��� 1�� ä���.
//2-2 x�� �����ʿ� ����ִ� ��Ʈ�� �ϳ��� ���ٸ� ���ʿ� ��Ʈ �ϳ� �߰��ϰ� ������ 0���� �� �ٲ۵ڿ� 
//1�� ������ 2�� ���̳������� �����ʺ��� 1�� �ٲ۴�.

//3_1 �׸��� �� 1������ ���� ���� �ǿ����ʿ� 1�� �߰��ϴ� ����̰� 2�����̳��� ���� �� ���� �����̴�.
//3_2 .... �ʹ� ���������� �ϴ� 1������ �ذ��Ѵ�.

//��Ʈ 1�� ���� ���ϱ�: 10������ 2�� ���鶧 �������� 1�� ��찡 1�̾���. ������ 1�� ��츦 ī��Ʈ�Ѵ�. 
//�̶� 2���� 1�� �ڸ����� 0�� ��츸 üũ�ؼ� +1�� �ٷ� ��ȯ�Ѵ�. ó�� �ٷ� ������ �������°� 1���ڸ����� 0�ΰ�.
//���� 1�� �ɶ����� ������.
#if 0
#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int cntx = 0; int cnty = 0;

    for (int i = 0; i < numbers.size(); i++)    //n��
    {
        long long tempx = numbers[i];
        long long tempy = tempx;
        //����ó�� 2�� �ǿ����ʺ�Ʈ�� ä���� �ִµ� �����Ÿ��� ���� 1�� ��쿣 11�� ���� ����
        if (tempx == 1) answer.push_back(static_cast < long long>(3));
        //2���� 0���ڸ��� 0�� ��쿣 �׳� +1�� ��
        else if (tempx % 2 == 0) answer.push_back(static_cast<long long>(tempx) + 1);
        else 
        {
            //temp�� ��� ������ ���鼭 üũ�ϴ� 1�� ������ üũ�ϴ� �ݺ���
            while (tempx != 1)        //logn�� Ƚ���� ������ �ɰ����ϱ�
            {
                cntx += tempx % 2;    tempx /= 2;
            }
            do{
                cnty = 0;
                tempy++;
                //temp�� +1 ������Ų ���� ������ ���鼭 1�� ���� üũ
                while (tempy != 1)
                {
                    cnty += tempy % 2;    tempy /= 2;
                }
            } while (!(abs(cntx - cnty) == 2 || abs(cntx - cnty) == 1));
            answer.push_back(tempy);
        }
    }
    return answer;
}
int main() {
    vector<long long> numbers = { 2, 7 };
    auto answer = solution(numbers);
    cout << answer[0] << endl;
    cout << answer[1];
}
#endif
// 1  2  3   4    5   6                         10    11  12                       16     17    18                      22         24       29     30                              36                                    42 
// A AA AAA AAAA AAAAA AAAAE AAAAI AAAAO AAAAU AAAE AAAEA AAAEE AAAEI AAAEO AAAEU AAAI AAAIA AAAIE AAAII AAAIO AAAIU AAAO AAAOA AAAOE ... AAAUA AAAUE AAAUI AAAUO AAAUU AAI AAIA AAIAA AAIAE AAIAI AAIAO AAIAU AAIE AAIEA .... EUUUU I IA IAA 
//1. 5�ڰ� �ɶ����� ���� �߰� ��ĭ�� �� ä���������� �ϴ� A�� �߰��Ѵ�. ��ĭ-A
//2. 5�ڰ� �� ä������(���ڿ��� ���̰� 5�̸�)�ǿ����� ���ں��� üũ �ڸ��ø� �ϵ��� A-E-I-O-U
//3. �����ø� �ϵ��� �ǿ����� ���ڸ� ��޾� �ϴٰ� U���� ���� U�� ����� 4��° �ڸ����� �ø�.

// 6N = �ڿ��� E�� ������ �ټ��ڸ�
// ������ A�� ������ �༮ ó���� 1���� , 5�ڸ� ä������ �������ʹ� 6���� 3��° A�� �����ɶ�����, 3��° �ø��� �����ϰ��� 7���� 
// �ٺ������δ� 6���̷� �ڸ��ø��� �߻��ϴ°� �´µ� U �ܰ迡�� �ø��� �ι��̷������ ������ +1�� �� �����ؾߵǰ� ���� �ø��� �̷������ ������ +2�� �����ؾ��ϴ� ���ΰ� ����.
// ���� �����̶�� ���ĺ��� ���� ��� PUSH POP�� �Ͼ������ üũ�ϴ���

//�ϴ� ���ĺ��� 5���ϱ� 5�������ٵ� 5�����ε� �ڸ��ٲܶ����� �ϳ��� ������ �߰��ȴٰ� �����ؾߵǴ°ǰ�
//5^4=625 5^3=125 5^2=25 5^1=5 5^0=1
//A�� �����̸� 0 E =1 01234 I=2*625=1250..
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    return answer;
}
#endif