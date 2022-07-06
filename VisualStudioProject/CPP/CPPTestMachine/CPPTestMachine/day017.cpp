#if 0
// 문자열이 매개변수로 주어진다. 영어와 숫자가 섞여있는 형태이다.
// 문자열이 의미하는 원래 숫자를 return
// 
// s의 길이는 50이하이므로 문자열을 순차탐색해도 이상 없음.
// return은 20억이하의 정수가 나온다. int의 범위 https://www.crocus.co.kr/1167
// 
// 문자열중에 찐 숫자는 48~57, 알파벳은 97~122
// [one] [two, three] [four, five] [six, seven] [eight] [nine] 알파벳 첫글자가 같은 경우는 6가지
// 숫자로 한번 거르고 알파벳 6가지 갈래로 거르고 그 중에서 2번째 글자도 알아야되는 경우엔 분기 하나 더 추가
// o:111 t:116 f:102 s:115 e:101 n:110
//       w:119 o:111 i:105 
// 스택을 한번 활용해보겠다. char스택으로 숫자를 저장하면 인트자료형보다 공간복잡도가 훨씬 줄어들 것이고,
// 비선형 자료구조 이기 때문에 삽입 연산도 간단할 것이다.
// 
// 고찰: if문이 길게 늘어져서 주석으로 미리 설명을 읽지 않는 이상 바로 읽기 어려울거 같다. 
// 1. 삼항연산자를 사용해서 길이를 단축시키는 방법
// 2. 공간복잡도와 시간복잡도가 올라가겠지만 pairset이나 연결리스트 등 정답이 있는 자료구조를 만들고 
// 그 자료구조의 key와 일치하면 저장되어 있는 value를 스택에 전달하는 방식
// 
// 위와 같은 방법들이 있을거 같다.
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
		else if (s[i] == 116) {	//t인경우
			if (s[i + 1] == 119) {//two인경우
				cstack.push(50);	i += 2;
			}
			else{//three 인 경우
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