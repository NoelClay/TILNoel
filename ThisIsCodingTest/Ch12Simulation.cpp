/*	Q07 럭키 스트레이트
매우 강력한 스킬인 럭키 스트레이트 특정 조건에서만 사용가능
현재 캐릭터의 점수를 N이라고 할때 자릿수를 기준으로 점수 N을 반으로
나누어 왼쪽 부분의 각 자릿수의 합과 오른쪽 부분의 각 자릿수의 합을 더한 값이 동일한 상황을 의미한다.
예를 들어 현재 점수가 123,402라면 왼쪽 부분의 합은 6 오른쪽 부분의 합은 6 따라서 사용가능

입력 조건
첫째 줄에 점수 N이 정수로 주어진다.(10 <= N <= 99,999,999) 단, 점수 N의 자릿수는 항상
짝수 형태로만 주어진다. 예를 들어 자리수가 5인 형태는 들어오진 않는다.
출력조건
첫째 줄에 럭키 사용가능하면 LUCKY 출력 안되며느 READY출력

<접근방법>
숫자로 받지말고 문자열로 받아서 짜르는게 나을것 같다.

*/
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	cout << "플레이어의 점수를 입력하라(길이는 짝수개)" << endl;
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
/*Q08 문자열 재정렬
알파벳 대문자와 숫자(0~9)로만 구성된 문자열이 입력으로 주어집니다. 이띠 모든 알파벳을
오름차순으로 정렬하여 이어서 출력한 뒤에, 그 뒤에 모든 숫자를 더한 값을 이어서 출력합니다.
예를 들어 K1KA5CB7 이라는 값이 들어오면 ABCKK13을 출력

<접근 방법>
문자열에서 숫자를 따로 추출한 문자열을 만든다음에 문자열을 사전식으로 정렬한다.
아니면 문자열을 하나씩 조회하면 (총길이는 10000이니까 1만번) 문자면 문자대로 string에 푸쉬업하고
숫자면 숫자대로 푸쉬업을 한뒤에 문자열을 사전식 정렬한다.

*/
#if 0
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cout << "숫자와 대문자로 이루어진 문자열을 입력하세요" << endl;
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
			cout << "입력값이 잘못되었습니다." << endl;
			return 0;
		}
	}
	sort(newS.begin(), newS.end());
	cout << newS << sum;
}
#endif // 1

/* Q09 문자열 압축
문자열에서 같은 값이 연속해서 나타나는 것을 그 문자의 개수와 반복되는 값으로 표현하여
더 짧은 문자열로 줄여서 표현하는 알고리즘을 공부하고 있다.
간단한 예로 aabbaccc의 경우 2a2ba3c 이러한 방식은 연속된 문자가 없을 경우 
압축효율이 제로라는 단점이 있다.
ababcdcdababcdcd의 경우에 1개씩이 아니라 2개씩 연속된 문자를 체크한다면
2ab2cd2ab2cd로 압축이 가능하고 8개씩 자르면 2ababcdcd이다.
압축할 문자열 s가 매개변수로 주어질때, 위에 설명한 방법으로 1개 이상 단위로 문자열을 잘라
압축하여 표현한 문자열 중 가장 짧은 것의 길이를 return하도록 solution함수를 완성하라.

aabbaccc					2a2ba3c				7
ababcdcdababcdcd			2ababcdcd			9
abcabcdede					2abcdede			8
abcabcabcabcdededededede	2abcabc2dedede		14
xababcdcdababcdcd			xababcdcdababcdcd	17

<접근방법>
문자열의 길이는 1000개까지이고 전부 소문자이다.
결국 핵심은 연속된 상태가 어떻게 되어있는지 파악을 어떻게 할까
1000개의 문자를 1000번 반복해서 모든 경우의 수를 조사한다음에 가장 짧은 길이를
반환하는것이 결국 답이 아닐까?
길이사이즈만큼 반복하는건 의미가 없을 듯 길이의 반만큼만 조사해보면 될듯
즉 100만회 이상 넘어갈 일이 없네.


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
	//i개 연속될때 2개 이상부터 앞에 숫자 붙이고, 1개 이상이면 앞에 아무것도 안붙음. 
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
