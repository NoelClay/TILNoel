//�� Ǯ��
#if 0

//1. ���ڿ��� ���̴� �鸸���ϱ� n�� Ž�� �̻��� �δ㽺����. 
// ����Ž���� 2�� �����ϴ� ���� �ð��ʰ� Ȯ�� 100����
// 2. ���ĺ�¦���� �̹� ������ �ִ�. aa bb cc ��� 26���� ���ڿ��� ���� find�� ã��
// �����ϴ� ������ find�� null�� �ɶ����� �ݺ��Ѵ�. ��ü�����δ� n/2?
// 3. https://popawaw.tistory.com/52?category=903476
// 4. remove erase ���ܹ߻� ó�� �ϴ°ſ��� �ʹ� ������. ����.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) 
{
	vector<string> stringPair = { "aa", "bb", "cc", "dd", "ee", "ff", "gg", 
		"hh", "ii", "jj", "kk", "ll", "mm", "nn","oo","pp",
		"qq","rr","ss","tt", "uu", "vv", "ww", "xx", "yy", "zz" };


	for (int i = 0; i < 26; i++) 
	{
		s.erase(remove(s.begin(), s.end(), stringPair[i]), s.end());
	}
}

int main()
{
	string a = "aabbccddeeff";
	a.erase(remove(a.begin(), a.end(), "gg"), a.end());
	cout << a;
}
#endif

//���� Ǯ��
// https://mungto.tistory.com/37

#if 0
//�迭�̳� ���ڿ��� ¦���� �����ϰ� ���� ��·�� �̾���̰� �ٽ� Ž���� �ؾߵǴٺ��� �ð��� �����ɸ���
//remove�Լ��� ����ҷ��ص� remove�� �����ϸ� �ȵǴ� ���ǿ��� ������ ��쿡 ���α׷������� ���� �� ����
//����üũ�� �����ϰ� �ع����� �ٽ� �ð����⵵�� ���谡 �� ���������� ������ �־���.
//-> �̷� ������ �ذ��ϱ� ���ؼ� �����̳� ť(ȿ������ �ڷᱸ��)�� ������ Ǯ �� �ִ����� �����غ����Ѵ�.
//-> ������ ����� ��� LIFO�� Ư���� �̿��� ���� ���ڿ��� ������ �ٷ� �����ϴ� ������� �ذ�

#include <string>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s) {
    stack<char> str;
    //ó������ ������ ��ȸ (���⵵ = n)
    for (int i = 0; i < s.length(); i++) {
        //������ ����ְų� ž�ϰ� ������ڰ� �ٸ��ٸ� ���ÿ� Ǫ��
        if (str.empty() || str.top() != s[i])    str.push(s[i]);
        //ž�� ������ڰ� ���ٸ� ž���ִ� ��������
        else if (str.top() == s[i])        str.pop();
        //ž�� �ִ� ���ڰ� ���ŵǰ� ������ �־��� ���ڿ��� 
        //�ε��� i�� �ǳʶٹǷ� ¦��� ���ŵǴ� ȿ��
    }
    //������ ����ִٸ� ��������Ѱ��̹Ƿ� 1����
    if (str.empty())    return 1;
    return 0;
}

void print(string s, int answer) {
    int t = solution(s);
    if (t == answer)
        cout << "����" << endl;
    else
        cout << "Ʋ��" << endl;
}

int main() {
    print("baabaa", 1);
    print("cdcd", 0);
    return 0;
}

#endif