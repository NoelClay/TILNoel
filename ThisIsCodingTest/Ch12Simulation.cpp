/*	Q07 ��Ű ��Ʈ����Ʈ
�ſ� ������ ��ų�� ��Ű ��Ʈ����Ʈ Ư�� ���ǿ����� ��밡��
���� ĳ������ ������ N�̶�� �Ҷ� �ڸ����� �������� ���� N�� ������
������ ���� �κ��� �� �ڸ����� �հ� ������ �κ��� �� �ڸ����� ���� ���� ���� ������ ��Ȳ�� �ǹ��Ѵ�.
���� ��� ���� ������ 123,402��� ���� �κ��� ���� 6 ������ �κ��� ���� 6 ���� ��밡��

�Է� ����
ù° �ٿ� ���� N�� ������ �־�����.(10 <= N <= 99,999,999) ��, ���� N�� �ڸ����� �׻�
¦�� ���·θ� �־�����. ���� ��� �ڸ����� 5�� ���´� ������ �ʴ´�.
�������
ù° �ٿ� ��Ű ��밡���ϸ� LUCKY ��� �ȵǸ�� READY���

<���ٹ��>
���ڷ� �������� ���ڿ��� �޾Ƽ� ¥���°� ������ ����.

*/
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	cout << "�÷��̾��� ������ �Է��϶�(���̴� ¦����)" << endl;
	string N;
	cin >> N;
	int forword = 0, behind = 0;
	for (int i = 0; i < (N.size() / 2); i++) {
		forword += (N[i]-48);
	}
	for (int i = N.size() / 2; i < N.size(); i++) {
		behind += (N[i] - 48);
	}
	if (forword == behind) {
		cout << "LUCKY";
	}
	else {
		cout << "READY";
	}
}
#endif // 1
/*Q08 ���ڿ� ������
���ĺ� �빮�ڿ� ����(0~9)�θ� ������ ���ڿ��� �Է����� �־����ϴ�. �̶� ��� ���ĺ���
������������ �����Ͽ� �̾ ����� �ڿ�, �� �ڿ� ��� ���ڸ� ���� ���� �̾ ����մϴ�.
���� ��� K1KA5CB7 �̶�� ���� ������ ABCKK13�� ���

<���� ���>
���ڿ����� ���ڸ� ���� ������ ���ڿ��� ��������� ���ڿ��� ���������� �����Ѵ�.
�ƴϸ� ���ڿ��� �ϳ��� ��ȸ�ϸ� (�ѱ��̴� 10000�̴ϱ� 1����) ���ڸ� ���ڴ�� string�� Ǫ�����ϰ�
���ڸ� ���ڴ�� Ǫ������ �ѵڿ� ���ڿ��� ������ �����Ѵ�.

*/
#if 0
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cout << "���ڿ� �빮�ڷ� �̷���� ���ڿ��� �Է��ϼ���" << endl;
	string s;
	cin >> s;
	int sum=0;
	string newS;
	for (auto n : s) {
		if ('0' <= n && n <= '9') {
			sum += n-48;
		}
		else if ('A' <= n && n <= 'Z') {
			newS.push_back(n);
		}
		else {
			cout << "�Է°��� �߸��Ǿ����ϴ�." << endl;
			return 0;
		}
	}
	sort(newS.begin(), newS.end());
	cout << newS << sum;
}
#endif // 1

/* Q09 ���ڿ� ����
���ڿ����� ���� ���� �����ؼ� ��Ÿ���� ���� �� ������ ������ �ݺ��Ǵ� ������ ǥ���Ͽ�
�� ª�� ���ڿ��� �ٿ��� ǥ���ϴ� �˰����� �����ϰ� �ִ�.
������ ���� aabbaccc�� ��� 2a2ba3c �̷��� ����� ���ӵ� ���ڰ� ���� ��� 
����ȿ���� ���ζ�� ������ �ִ�.
ababcdcdababcdcd�� ��쿡 1������ �ƴ϶� 2���� ���ӵ� ���ڸ� üũ�Ѵٸ�
2ab2cd2ab2cd�� ������ �����ϰ� 8���� �ڸ��� 2ababcdcd�̴�.
������ ���ڿ� s�� �Ű������� �־�����, ���� ������ ������� 1�� �̻� ������ ���ڿ��� �߶�
�����Ͽ� ǥ���� ���ڿ� �� ���� ª�� ���� ���̸� return�ϵ��� solution�Լ��� �ϼ��϶�.

aabbaccc					2a2ba3c				7
ababcdcdababcdcd			2ababcdcd			9
abcabcdede					2abcdede			8
abcabcabcabcdededededede	2abcabc2dedede		14
xababcdcdababcdcd			xababcdcdababcdcd	17

<���ٹ��>
���ڿ��� ���̴� 1000�������̰� ���� �ҹ����̴�.
�ᱹ �ٽ��� ���ӵ� ���°� ��� �Ǿ��ִ��� �ľ��� ��� �ұ�
1000���� ���ڸ� 1000�� �ݺ��ؼ� ��� ����� ���� �����Ѵ����� ���� ª�� ���̸�
��ȯ�ϴ°��� �ᱹ ���� �ƴұ�?
���̻����ŭ �ݺ��ϴ°� �ǹ̰� ���� �� ������ �ݸ�ŭ�� �����غ��� �ɵ�
�� 100��ȸ �̻� �Ѿ ���� ����.


*/
#if 0
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int solution(string s) {
	stack<string>stackstring;

	vector<int>answer;
	//i�� ���ӵɶ� 2�� �̻���� �տ� ���� ���̰�, 1�� �̻��̸� �տ� �ƹ��͵� �Ⱥ���. 
	for (int i = 1; i <= s.size() / 2; i++) {
		vector<string>tempString;
		int j = 0;
		while (1) {
			
		}
	}
}

int main() {
	vector<string> arr = { "aabbaccc","ababcdcdababcdcd",
	"abcabcdede", "abcabcabcabcdededededede", "xababcdcdababcdcd" };
	for (auto n : arr) {
		solution(n);
	}
}

#endif // 1
