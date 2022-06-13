//내 풀이
#if 0

//1. 문자열의 길이는 백만개니까 n번 탐색 이상은 부담스럽다. 
// 선형탐색을 2번 제곱하는 순간 시간초과 확률 100프로
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
// https://mungto.tistory.com/37

#if 0
//배열이나 문자열은 짝지를 삭제하고 나면 어쨌든 이어붙이고 다시 탐색을 해야되다보니 시간이 오래걸리고
//remove함수를 사용할려해도 remove가 실행하면 안되는 조건에서 실행할 경우에 프로그램에러를 피할 수 없고
//에러체크를 복잡하게 해버리면 다시 시간복잡도가 설계가 더 복잡해지는 문제가 있었다.
//-> 이런 문제를 해결하기 위해서 스택이나 큐(효율적인 자료구조)로 문제를 풀 수 있는지를 생각해봐야한다.
//-> 스택을 사용할 경우 LIFO의 특성을 이용해 같은 문자열이 있으면 바로 제거하는 방식으로 해결

#include <string>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s) {
    stack<char> str;
    //처음부터 끝까지 순회 (복잡도 = n)
    for (int i = 0; i < s.length(); i++) {
        //스택이 비어있거나 탑하고 현재글자가 다르다면 스택에 푸쉬
        if (str.empty() || str.top() != s[i])    str.push(s[i]);
        //탑과 현재글자가 같다면 탑에있는 글자제거
        else if (str.top() == s[i])        str.pop();
        //탑에 있는 글자가 제거되고 기존에 주어진 문자열의 
        //인덱스 i도 건너뛰므로 짝지어서 제거되는 효과
    }
    //스택이 비어있다면 모두제거한것이므로 1리턴
    if (str.empty())    return 1;
    return 0;
}

void print(string s, int answer) {
    int t = solution(s);
    if (t == answer)
        cout << "정답" << endl;
    else
        cout << "틀림" << endl;
}

int main() {
    print("baabaa", 1);
    print("cdcd", 0);
    return 0;
}

#endif