//1��
// Collatz�� ����
// �ݺ�Ƚ�� 500���� �Ѿ�� -1 ����
//
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    while (num != 1) {
        if (answer > 500) {
            answer = -1;    break;
        }
        if (num % 2 == 0) num /= 2;
        else if(num %2 ==1) num = num * 3 + 1;
        answer++;
    }
    return answer;
}
int main() 
{

}
#endif

//2��
//������� �ΰ��� ���ļ� ���ڿ� �迭�� ��ȯ�Ѵ�. 
//10���� �迭�� �־����� 2������Ʈ�� �ٲ۵ڿ� 1�� # 0�� ��ĭ
//�� ���� ��ĥ�� ��¥ ������ �̷�����°� �ƴ϶� ��Ʈ or ������ �̷������.
//c++�� ��Ʈ ���� https://boycoding.tistory.com/163
//���� for���ε� �ٱ��� n�� ������ logn�� n�� 16 ���� �鸸����. ���ڿ����� �����¿��� n�� 16*16*4 = 1024
//c++ ���ڿ� �Ųٷ� reverse�Լ� https://blockdmask.tistory.com/363
// https://marobiana.tistory.com/159

#if 0
#include <string>
#include <vector>
#include<iostream>

using namespace std;

string reverse(string s, int n) { 
    string answer;
    for (int i = n-1; i >= 0; i--) {
        answer += s[i];
    }
    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    //vector<string> answer(n); 
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        int a = arr1[i] | arr2[i]; //bitset ����
        string s;
        for (int j = 0; j < n; j++) {
            //���� a�� 0�̶�� �׳� �˾Ƽ� �������� ���� 0�̶� ��ĭ �߰��Ұ�
            if (a % 2 == 1) s + '#'; 
            else s + ' ';
            a /= 2;
        }
        //���� �ݺ����� ������ ������� s�� �Ųٷ��Ͽ� answer�� ��ȯ
        answer.push_back(reverse(s, n)); //reverse ����
    }
    return answer;
}

int main(void)
{
    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = { 30, 1,21,17,28 };

    vector<string> s = solution(n, arr1, arr2);
    for (int i = 0; i < n; i++) {

    }

}
#endif

//3��
// ������ȣ�� Ű���� ���� - ������ �ð���. 
// �ð��� - �⺻�ð� = �߰��ð�
// ������� = �⺻��� + �߰��ð�/10*�������
// �ʰ��ð��� �ø��Ѵ�. 2*�������
// 
// ������ȣ�� �������� �������� ������ ������� ���� �迭 ��ȯ
// �� �ð��� 60�� 24�ô� 1440�� 05:34�� 334 ���� �ð��� ��(int)�� ȯ��
// IN�� ��쿡 inVector�� ������ȣ�� Ű����� ����ð��� ������ ȯ���Ѱ� �߰�
// Out�� ��쿡 outVector�� ������ȣ�� Ű����� inVector�� ����� �ð��� �� �ð��� �߰�
// inVector�� Ű���� ��Ҵ� �����.
// ���� record n��Ž�簡 ������ inVector�� ��Ұ� �����ִٸ� outVector�� 23:59�� ���ð��� �߰�
// ������ȣ ������ outVector�� �����ϰ� �ð���Ҹ� answer���Ϳ� ��ȯ
// 
// �ݺ�Ƚ�� n=1000, ���� records ���� 3ȸ, 
// 
// ���ڿ� ��ĭ �������� �����ϱ� substr() https://starrykss.tistory.com/1546
// <sstream> https://seoyeonkk.tistory.com/entry/C-%EA%B3%B5%EB%B0%B1-%EA%B8%B0%EC%A4%80-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%9E%90%EB%A5%B4%EA%B8%B0split
// getline() https://greenapple16.tistory.com/219
// ���� �� �ڼ��� ���� https://chbuljumeok1997.tistory.com/42
// 
// string to int https://psychoria.tistory.com/709
// https://godog.tistory.com/entry/C-string-to-int-int-to-string-%ED%98%95%EB%B3%80%ED%99%98-%ED%95%98%EA%B8%B0
//
#if 0
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

//string str = "Enter id1234 Muzi";//������ ���� string�� �ִٰ�����.
//istringstream ss(str);//istringstream ss ������ string ���� as�� �ʱ�ȭ�Ѵ�.
//string buff;
//while (getline(ss, buff, ' '))//ss stream �������� ' '(����)���� �Է����� �޾Ƶ��δ�.
//{
//    // getline���� �о���� ���� buff�� ������ ����Ѵ�.
//    cout << buff << endl;
//}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<int, int>> inVector;
    vector<pair<int, int>> outVector;

    for (int i = 0; i < records.size(); i++) {
        vector<string> temp;
        int j = 0;
        istringstream ss(records[i]);
        while (getline(ss, temp[j], ' '))//ss stream �������� ' '(����)���� �Է����� �޾Ƶ��δ�.
        {
            cout << temp[j] << endl;
            j++;
        }
        if (temp[2] == "IN") {

            inVector.push_back(make_pair((stoi(temp[1]), stoi(temp[1])));
        }
    }

    return answer;
}
#endif

