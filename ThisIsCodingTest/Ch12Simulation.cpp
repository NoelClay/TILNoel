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

*/