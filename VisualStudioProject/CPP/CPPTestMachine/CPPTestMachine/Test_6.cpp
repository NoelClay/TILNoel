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
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            temp.push_back(s[i]);
        }
        else {
            temp.push_back(' ');
            v.push_back(temp);
            temp = "";
        }
    }
    temp.push_back(' ');
    v.push_back(temp);
    temp = "";
    //�� ���ڿ��� ��Ҹ����
    for (int i = 0; i < v.size(); i++) { //�ٱ� for�� : ������ �� m
        for (int j = 0; j < v[i].size(); j++) {//���� for���� �����δٰ� ����
            if (v[i][j] == ' ')
                continue;
            else if (v[i][j] < 91 && j % 2 == 1)//�빮���̰�, Ȧ���ε������
                v[i][j] += 32;
            else if (j % 2 == 0 && v[i][j] > 96)//¦�� �ε����� �ҹ��ڶ��
                v[i][j] -= 32;
        }
        //i�� �����ϱ����� answer�� �����̶� �Բ� ���ؼ� ��ȯ
        answer += v[i];
    }
    //���� �������� ���� �ϳ� ����
    answer.pop_back();
    
    return answer;
}
int main() {
    string s = "try hello world";
    cout << solution(s);
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

//2�� �ι�° �õ�
// ������� Ƚ��*2 �� ��ȯ �׻� ¦���� �����ϱ�
// �迭�� ���� ������ �ʿ�� ����̰� ���̴� �ٱ��ϴ� ������ �����̾���Ұ�
// ������ �Ǵ� �迭�� �� ������ ���Ұ� �ִ��� �������� �� �� �ִ� ����������.
// ���带 ���� Ž���Ѵٰ� ġ�� 30*30 = 900 �̴�. ������ Ž���ϸ� �̹� �鸸�� �ٻ�
// ����迭 �Է�Ƚ����ŭ �ݺ��� �Ұ� 1000��
// ������ �������̱��� Ž���� ���� ������ �� �ȿ��� �� 30������ �ݺ��Ұ� 3����
// �׷��鼭 ���ÿ� �����Ҷ� top�˻縸 �ϰ� pop�Ұ��̴ϱ� �߰� �ݺ��� ����.
//
#if 0
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stack;
    //vector<stack<int>> sboard;    //���� ���ʹ� ��������� �ʴ±���.
    //�� ������ top�ε��� ������ ����Ѵٸ�

    //Legacy
    //for (int i = 0; i < moves.size(); i++) {
    //    if (stack.empty())   stack.push(board[i][moves[i]]);
    //    else if (stack.top() == moves[i]) {
    //    stack.pop();
    //    }
    //}

    //new
    for (int i = 0; i < moves.size(); i++) { //����迭 �Է����� ���Ұ� �����Ҷ����� Ž���Ұ��̰�
        for (int j = 0; j < board.size(); j++) { 
            //���� �� ���� �����ŭ �ݺ� Ž���� ���ε� ���Ұ� �߰ߵǸ� �� ��� �� ���Ҹ� ���ÿ� �߰��ϰ�
            //0���� �ʱ�ȭ�Ͽ� 2���� board ���͸� ������Ʈ�Ѵ�.
            if (board[j][moves[i]-1] != 0)//j�� ������ ����ؼ� �ϳ��� Ŀ���� ������ ���� moves[i]�� Ž���� ������
            {
                if (stack.empty() || stack.top() != board[j][moves[i]-1]) {
                    stack.push(board[j][moves[i]-1]);
                    board[j][moves[i] - 1] = 0;
                }
                else if (stack.top() == board[j][moves[i]-1]) {
                    stack.pop();
                    answer += 2;
                    board[j][moves[i] - 1] = 0;
                }
                break;
            }
        }  
    }
    return answer;
}
int main() {
    vector<vector<int>> board = { {0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };

    cout << solution(board, moves);
}

//����
// ó���� ���� ������ ������ �ڷᱸ���� ��ߵȴٴ� ������ ��ư� ­����, �ᱹ �� ���߾���.
// �ι�° �õ������� ���� ������ �ڷᱸ���� ����ؼ� �ص� �־��� ��쿡�� �鸸���� �ѱ��� �ʱ⿡ 
// 2�����迭�� ������ Ž���ϴ� ������� ¥�� �ذ��ߴ�.
// ������ ������������ �����ɷȴµ� Ž���ϰ����ϴ� �ε����� �����ϴ°��� -1����ߵȴٴ°� ���ݰ� �ذ��ߴ�.
//

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
// �ι�°�õ�
// 
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

int main() {
    int w = 8, h = 12;
    cout << solution(8, 12);
}

#endif