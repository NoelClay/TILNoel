//�� Ǯ��
#if 0

//1. ���ڿ��� ���̴� �鸸���ϱ� n�� Ž�� �̻��� �δ㽺����.
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