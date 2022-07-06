#if 0
// ���ڿ��� �Ű������� �־�����. ����� ���ڰ� �����ִ� �����̴�.
// ���ڿ��� �ǹ��ϴ� ���� ���ڸ� return
// 
// s�� ���̴� 50�����̹Ƿ� ���ڿ��� ����Ž���ص� �̻� ����.
// return�� 20�������� ������ ���´�. int�� ���� https://www.crocus.co.kr/1167
// 
// ���ڿ��߿� �� ���ڴ� 48~57, ���ĺ��� 97~122
// [one] [two, three] [four, five] [six, seven] [eight] [nine] ���ĺ� ù���ڰ� ���� ���� 6����
// ���ڷ� �ѹ� �Ÿ��� ���ĺ� 6���� ������ �Ÿ��� �� �߿��� 2��° ���ڵ� �˾ƾߵǴ� ��쿣 �б� �ϳ� �� �߰�
// o:111 t:116 f:102 s:115 e:101 n:110
//       w:119 o:111 i:105 
// ������ �ѹ� Ȱ���غ��ڴ�. char�������� ���ڸ� �����ϸ� ��Ʈ�ڷ������� �������⵵�� �ξ� �پ�� ���̰�,
// ���� �ڷᱸ�� �̱� ������ ���� ���굵 ������ ���̴�.
// 
// ����: if���� ��� �þ����� �ּ����� �̸� ������ ���� �ʴ� �̻� �ٷ� �б� ������ ����. 
// 1. ���׿����ڸ� ����ؼ� ���̸� �����Ű�� ���
// 2. �������⵵�� �ð����⵵�� �ö󰡰����� pairset�̳� ���Ḯ��Ʈ �� ������ �ִ� �ڷᱸ���� ����� 
// �� �ڷᱸ���� key�� ��ġ�ϸ� ����Ǿ� �ִ� value�� ���ÿ� �����ϴ� ���
// 
// ���� ���� ������� ������ ����.
//
//
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int solution(string s) {
	int answer = 0;
	int digit = 1;
	stack<char> cstack;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > 47 && s[i] < 58) {
			cstack.push(s[i]);
		}
		else if (s[i] == 111) { //one
			cstack.push(49);	i += 2;
		}
		else if (s[i] == 116) {	//t�ΰ��
			if (s[i + 1] == 119) {//two�ΰ��
				cstack.push(50);	i += 2;
			}
			else{//three �� ���
				cstack.push(51);	i += 4;
			}
		}
		else if (s[i] == 102) {//f case
			if (s[i + 1] == 111) { //four case
				cstack.push(52);	i += 3;
			}
			else {//five case
				cstack.push(53);	i += 3;
			}
		}
		else if (s[i] == 115) {//s case
			if (s[i + 1] == 105) {//six case
				cstack.push(54);	i += 2;
			}
			else {//seven case
				cstack.push(55);	i += 4;
			}
		}
		else if (s[i] == 101) {//eight case
			cstack.push(56);	i += 4;
		}
		else if (s[i] == 110) {//nine case
			cstack.push(57);	i += 3;
		}
		else{
			break;
		}
	}
	while (!cstack.empty()) {
		answer += (cstack.top() - 48) * digit;
		digit *= 10;
		cstack.pop();
	}
	return answer;
}

int main()
{
	vector<string> s = { "one4seveneight","23four5six7", "2three45sixseven", "123" };
	cout << solution(s[3]);
}
#endif