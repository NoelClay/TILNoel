//1��
// ���̵�� 3~15, �ҹ���, ����, ����, �����, ��ħǥ ���� �ƽ�Ű�ڵ�ǥ https://stepbystep1.tistory.com/10
// �ҹ��� 97~122 �빮�� 65~90 �빮��->�ҹ��� +32 ���� 48~57 ���� 45 ����� 95 ��ħǥ 46
// 
// 1�ܰ�: �ҹ���ġȯ   2�ܰ�: ���� ���ڵ� �����ϰ� ���ڿ� ����     3�ܰ�: ���Ӹ�ħǥ�� 1����     4�ܰ�:ó���� �� ��ħǥ�� ����
// 5�ܰ�: ó���ϰ� ���� ���ڿ��� �ȴٸ� a�߰�   
// 6�ܰ�: 15�� �Ѿ�� ���ڵ��� ���� ���� ������ �ڿ� ��ħǥ�� ���� ��ġ�ϰ� �Ǹ� �� ��ħǥ�� ���� 14~15 �ɰ�
// 7�ܰ�: �ᱹ 2�� ���϶��(a�߰��ؼ� 1���� ������ ����) ������ ���ڸ� ���̰� 3�ɶ����� �ݺ��ؼ� �߰�
// 
// �Է� ���̴� 1000�� ���� n^2�� �ȵȴ�. nlogn�� 10 * 1000
// 
// �ܰ踶�� ��� Ž���� �ϴ� �ͺ��� ��ĥ �� �ִ°� ���� �ܰ迡�� ó���ϴ°� �ð����⵵ ����
// 
// 1�ܰ� 2�ܰ� ��ġ�°� �����ҵ� n��Ž���� �ϸ鼭 ���ܴ� �����ϸ鼭 �̾���̰� �빮�ڶ�� �ҹ��ڷ� ��ȯ
// �����ϰ� �̾���̴°� ������ �迭 �ڷ������δ� �ʹ� �����ɸ��� ������ ������ Ȱ�� 
// ���ÿ� �߰��Ҷ� ���ڿ� ������ �߰��ϸ� �ٽ� ������ �Ǿպ��� ��������.
// 
// 3�ܰ� 4�ܰ� ��ġ�°� ����. ��ħǥ�� ã�µ� �װ� ó�� �ε������ �̾��� ��ħǥ�鵵 ���� ����
// ��ħǥ�� ã���� �̾ ������ ��ħǥ���� �ִٸ� �³׵��� �� ����. 
// ���� �׷��� �����ϴٰ� ������ ���� �����ߴٸ� �������ִ� ��ħǥ�� ����
// 
// 5�ܰ� ������ �� ���ڿ�. 5�ܰ� ���ǿ� �ɸ� ���� 6 7�ܰ� �Ұ͵� ���� �ٷ� aaa
// 
// 6 7�ܰ赵 ���ÿ� �����Ұ� ���ڿ� ���̿� ���� �бⰡ ����. ���ڿ� ���� 2�� ���ϴ� ������ ���ڸ� �߰��ؼ� ��ü���� 3�ɶ�����
// ���� ���ڿ� ���̰� 15���� ũ�� �ڿ� �α׸� �����Ѵ�. �̶� ������ ���ڿ��� ��ħǥ��� �� ��ħǥ���� �����ϸ鼭 ��
// 
// c++ switch case https://docs.microsoft.com/ko-kr/cpp/cpp/switch-statement-cpp?view=msvc-170
//
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int level = 0;
    char padding;
    stack<char> cstack;
    stack<char> cstack2;


    //while (true) {
    //    switch (level)
    //    {
    //    case 0: //1~2�ܰ� ��ģ ���·�
    //        for (int i = 0; i < (int)new_id.size(); i++) {
    //            if (65<=new_id[i]&& new_id[i]<=90) {//�빮�ڶ�� �ҹ��ڷ�
    //                cstack.push(new_id[i] + 32);
    //            }
    //            else if ((48 <= new_id[i] && new_id[i] <= 57) || (97 <= new_id[i] && new_id[i] <= 122)) {
    //                 ���ڶ�� �ҹ��ڶ�� �״�� �߰�
    //                cstack.push(new_id[i]);
    //            }
    //            else if (new_id[i] == 45 || new_id[i] == 95 || new_id[i] == 46) {
    //                ������, ����ٶ��, ��ħǥ��� �״�� �߰�
    //                cstack.push(new_id[i]);
    //            }
    //        �� �ܿ� ���� ó�� �ݺ��� ������ ���� cstack�� ���ڿ��� ó������ ������ ���� �ٽ� pop�Ҷ� ������ pop��
    //        �ݺ� Ƚ���� 1000�� * ��+���=�� 10ȸ �ð����⵵ 1����
    //        }
    //        level++;
    //        break;

    //    case 1://3~4�ܰ� ��ģ ����
    //        while (!cstack.empty()) 
    //        {
    //            if (cstack.top() == 46 ) {//��ħǥ�� ���Դٸ�
    //                if (cstack2.top() != 46 && !cstack2.empty()) {//���ӵ� ��ħǥ�� �ƴ϶��
    //                    cstack2.push(cstack.top());//��ħǥ�� ���°� �´�. �糡 Ȥ�� ���ӵǴ� �ֵ��� ��ŵ�ϴ°�
    //                    cstack.pop();
    //                }
    //                else { //���⿡�� ����ؾߵǴ� ���� ���� �߰��ؾߵ� ���ڰ� ��ħǥ�ε� ���� ������ ����ִٴ���
    //                    ���� 46 ��ħǥ�� ����̴�.
    //                    cstack.pop();
    //                }
    //            }
    //            else {//cstack.top�� ��ħǥ�� �ƴ� ��쿡�� �̹� ���� ó�� �����Ƿ� �� �߰�
    //                cstack2.push(cstack.top());
    //                cstack.pop();
    //            }
    //        }//cstack�� ��� �Ǹ鼭 �ݺ��� ������. �ݺ��� �������� stack2�� top�� �ָ��Ѵ�. �̰��� ù��° ������ ����̴�. �̰� ��ħǥ�� ����
    //        if (cstack2.top() == 46) {
    //            cstack2.pop();
    //        }
    //        ���� �Ǵ��� ���� ���ڿ��� ���̸� ���.
    //        if (cstack2.empty()) { return "aaa"; }
    //        else if (cstack2.size() < 3) { level = 3; }
    //        else { level = 4; }
    //        break;
    //    case 3:
    //        while (!cstack2.empty()) {
    //            answer += cstack2.top(); //�ᱹ ù��° ���ں��� ���ԵǴ� ��.
    //            cstack2.pop();
    //        }
    //        padding = answer[answer.size() - 1];
    //        for (int i = answer.size() - 1; i < 3; i++) {
    //            answer += padding;
    //        }
    //        return answer;
    //        break;
    //    case 4:
    //        int cnt = 0;
    //        while (!cstack2.empty()) {
    //            cnt++;
    //            if (cnt == 15) { //15��° �߰��̰� ��ħǥ�� �ƴ϶�� �߰��ϰ� ��
    //                if (cstack2.top() != 46) {
    //                    answer += cstack2.top();
    //                    
    //                }
    //                else { return answer; }
    //            }
    //            answer += cstack2.top();
    //            cstack2.pop();
    //        }           
    //        break;
    //    }
    //}

    while (level != 10) {
        if (level == 0) {//1~2�ܰ� ��ģ ���·�
            for (int i = 0; i < (int)new_id.size(); i++) {
                if (65 <= new_id[i] && new_id[i] <= 90) {//�빮�ڶ�� �ҹ��ڷ�
                    cstack.push(new_id[i] + 32);
                }
                else if ((48 <= new_id[i] && new_id[i] <= 57) || (97 <= new_id[i] && new_id[i] <= 122)) {
                    // ���ڶ�� �ҹ��ڶ�� �״�� �߰�
                    cstack.push(new_id[i]);
                }
                else if (new_id[i] == 45 || new_id[i] == 95 || new_id[i] == 46) {
                    //������, ����ٶ��, ��ħǥ��� �״�� �߰�
                    cstack.push(new_id[i]);
                }
                //�� �ܿ� ���� ó�� �ݺ��� ������ ���� cstack�� ���ڿ��� ó������ ������ ���� �ٽ� pop�Ҷ� ������ pop��
                //�ݺ� Ƚ���� 1000�� * ��+���=�� 10ȸ �ð����⵵ 1����
            }
            level = 1;
        }
        else if (level == 1) {
            while (!cstack.empty())
            {
                if (cstack.top() == 46) {//��ħǥ�� ���Դٸ�
                    if (cstack2.top() != 46 && !cstack2.empty()) {//���ӵ� ��ħǥ�� �ƴ϶��
                        cstack2.push(cstack.top());//��ħǥ�� ���°� �´�. �糡 Ȥ�� ���ӵǴ� �ֵ��� ��ŵ�ϴ°�
                        cstack.pop();
                    }
                    else { //���⿡�� ����ؾߵǴ� ���� ���� �߰��ؾߵ� ���ڰ� ��ħǥ�ε� ���� ������ ����ִٴ���
                        //���� 46 ��ħǥ�� ����̴�.
                        cstack.pop();
                    }
                }
                else {//cstack.top�� ��ħǥ�� �ƴ� ��쿡�� �̹� ���� ó�� �����Ƿ� �� �߰�
                    cstack2.push(cstack.top());
                    cstack.pop();
                }
            }//cstack�� ��� �Ǹ鼭 �ݺ��� ������. �ݺ��� �������� stack2�� top�� �ָ��Ѵ�. �̰��� ù��° ������ ����̴�. �̰� ��ħǥ�� ����
            if (cstack2.top() == 46) {
                cstack2.pop();
            }
            //���� �Ǵ��� ���� ���ڿ��� ���̸� ���.
            if (cstack2.empty()) { return "aaa"; }
            else if (cstack2.size() < 3) { level = 3; }
            else { level = 4; }
        }
        else if (level == 3) {
            while (!cstack2.empty()) {
                answer += cstack2.top(); //�ᱹ ù��° ���ں��� ���ԵǴ� ��.
                cstack2.pop();
            }
            padding = answer[answer.size() - 1];
            for (int i = answer.size() - 1; i < 3; i++) {
                answer += padding;
            }
            return answer;
        }
        else if(level==4){
            int cnt = 0;
            while (!cstack2.empty()) {
                cnt++;
                if (cnt == 15) { //15��° �߰��̰� ��ħǥ�� �ƴ϶�� �߰��ϰ� ��
                    if (cstack2.top() != 46) {
                        answer += cstack2.top();
                        return answer;
                    }
                    else { return answer; }
                }
                answer += cstack2.top();
                cstack2.pop();
            }
            level = 10;
        }
    }
    return answer;
}
int main() {
    vector<string> new_id{ "...!@BaT#*..y.abcdefghijklm", "z-+.^.","=.=", "123_.def", "abcdefghijklmn.p"};
    //for (int i = 0; i < 5; i++) {
        cout << solution(new_id[1]) << endl;
    //}
    //cout << solution("...!@BaT#*..y.abcdefghijklm");
}
#endif

//2��
// head num tail �ε��� ������ �����ϰ� ��� �������� ���� �����ϰ�
// 
// https://blockdmask.tistory.com/362
//
#if 0
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    return answer;
}
#endif