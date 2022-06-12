//내 풀이
#if 0

//1. 문자열의 길이는 백만개니까 n번 탐색 이상은 부담스럽다.
// 2. 알파벳짝지는 이미 정해져 있다. aa bb cc 등등 26쌍의 문자열을 전부 find로 찾아
// 제거하는 과정을 find가 null이 될때까지 반복한다. 전체적으로는 n/2?
// 3. https://popawaw.tistory.com/52?category=903476
// 4. remove erase 예외발생 처리 하는거에서 너무 막힌다. 포기.
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

//답지 풀이