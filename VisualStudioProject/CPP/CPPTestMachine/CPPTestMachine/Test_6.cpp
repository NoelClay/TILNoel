//1��
// ù��° Ǯ��
// ���� �������� ������ ¦�� �ε����� Upper Ȧ�� �ε����� Lower
// ���ڿ��� ����������� ������ �Լ� https://notepad96.tistory.com/22
// 
// �ǹ��ذ�: ��� �������� ��ū�� �����ұ�? https://repilria.tistory.com/197
// 
// �߰��ڷ�: �ƽ�Ű�ڵ� https://maincodes.tistory.com/68
//          ���ڿ� ������ ���� https://www.delftstack.com/ko/howto/cpp/remove-last-character-from-a-string-in-cpp/
// 
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    vector<string> v;
    string answer = "";
    char* c = strtok((char*)s.c_str(), " ");
    //����������� ���ڿ� ������ �ݺ�Ƚ�� : ������ �� �ִ� n
    while (c) {
        v.push_back(c);
        c = strtok(NULL, " ");
    }
    //�� ���ڿ��� ��Ҹ����
    for (int i = 0; i < v.size(); i++) { //�ٱ� for�� : ������ �� m
        for (int j = 0; j < v[i].size(); j++) {//���� for���� �����δٰ� ����
            if (v[i][j] < 91 && j % 2 == 1)//�빮���̰�, Ȧ���ε������
                v[i][j] += 32;
            if (j % 2 == 0 && v[i][j] > 96)//¦�� �ε����� �ҹ��ڶ��
                v[i][j] -= 32;
        }
        //i�� �����ϱ����� answer�� �����̶� �Բ� ���ؼ� ��ȯ
        answer += v[i];
    }
    //���� �������� ���� �ϳ� ����
    answer.pop_back();
    
    return answer;
}
#endif

//2��
// ���� ������ �̿��ؼ� ������ �۾��� �ؾߵɰ� ����.
// ����:
// mov [15351214]
// box [431132 4]
// ���û���ϱ�: https://life-with-coding.tistory.com/406
// 
// moves�� ���� Ƚ����� �񱳿� �̵� ������ �̷���� ���̹Ƿ� moves�� ũ��� 1000 
// �� n������ ���
// 
// �߰������� �� ����: board�� stack���¸� ���? Ȥ�� top�ε����� ����ϴ� ���?
// moves�� ��Ҵ� �������� �������� �࿡���� ���¸� ��� ������ ���Ѵ�.
#if 0
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stack;
    //vector<stack<int>> sboard;    //���� ���ʹ� ��������� �ʴ±���.
    //�� ������ top�ε��� ������ ����Ѵٸ�

    

    for (int i = 0; i < moves.size(); i++) {
        if (stack.empty())   stack.push(board[i][moves[i]]);
        else if (stack.top() == moves[i]) {
        stack.pop();
}
    }

    return answer;
}
#endif

//3��
// �밢���� �׷����� ���ε� ���ΰ� �Ǿ��� ��·�� �Ѵ� 1cm �̻����� �����ϴ� ��쿡 
// �� �밢���� ����� ���簢������ ������ �ȴ�.
// ���ΰ� ��� �밢���� ���ΰ� ��� ���ΰ� ��� �밢���� ���ΰ� ���. 
// 12/8 = 1.5 ���ΰ� 1cm�϶� ���δ� 1.5cm���� ���� ���簢�� 2���� �����.
// 16/8 = 2   ���ΰ� 1cm�϶� ���δ� 2cm���� ���� ���簢�� 2���� �����.
// 20/8 = 2.5 ���ΰ� 1cm�϶� ���δ� 2.5cm���� ���� ���簢�� 3���� �����.
// ���/ª���� �� �ݿø��� �Ѱ� ���ϱ� ª���� �ϸ� 
// �밢���� ª���� 1cm �̵��ϴ� ���� ����� ���簢���� ���� ���ϱ� ª���� ���� �̵��ϴ°Ÿ�
// 
//
#if 0

#include<iostream>

using namespace std;

long long solution(int w, int h) {
    long long answer = 1;
    int cnt = 0;

    if (w > h)//���ΰ� �� ����
    {
        if (w % h == 0)//������ �������� ���
        {
            cnt = w / h;
        }
        else
        {
            cnt = w / h + 1;
        }
        answer = w * h - cnt * h;
    }
    else//���ΰ� �� ���� Ȥ�� ���� ���
    {
        if (h % w == 0)//������ �������� ���, ���ٸ� ������ �����������
        {
            cnt = h / w;
        }
        else
        {
            cnt = h / w + 1;
        }
        answer = w * h - cnt * h;
    }
    return answer;
}
#endif