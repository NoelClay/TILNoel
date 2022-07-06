#if 0
// 자연수 n이 있을때 어떤 숫자를 반환해라.
// 2진수변환시 1비트의 숫자가 같은 숫자이면서, n보다 큰수들 중에 가장 작은 수
// 
// 일단 n보다 클려면 1이 n보다 왼쪽에 하나 더 많으면되고, 나머지 1들은 맨오른쪽부터 차례로 쌓는다.
// 이렇게되면 맨 오른쪽 1의자리 비트는 항상 채워져 있다고 봐야된다.
// n의 입력은 이미 백만개이기 때문에 n번 탐색도 허용되지 않는다. 수학적으로 해결되어야 할것
// 2진수 변환은 logn번 탐색이다.
// 1001110 1000111  1111  1110 110011
// 1010011 1001011 10111 10011 110101
// 
// 2진수로 변환하는 과정에서 문자열에 1혹은 0으로 나오는 나머지를 추가하게 될 경우 그것은 1의자리부터 2^n자리로
// 거꾸로 연산되기때문에 바로 문자열에 추가하게 되면 다시 뒤집어야 되는 상황이 나온다.
// 따라서 스택에다가 차례로 푸쉬한다음에 나중에 문자열에 다시 팝해서 추가하는 방식을 하면 쉽게 뒤집을 수 있다.
// https://life-with-coding.tistory.com/406
// 
// 비트를 문자열로 계산할려고 했는데 생각보다 쉽지 않을것 같아서 비트셋stl을 공부해보려한다. 
// https://www.crocus.co.kr/549
// 
// 1. 맨오른쪽으로 부터 시작해서 처음 나오는 1이 있을때 그 1보다 왼쪽에 0이 나오는 그 자리에 1을 추가하고 
// 그 1보다 왼쪽은 건드리지 말고 나머지 오른쪽에 있는 1들을 전부 맨 오른쪽으로 밀어버린다.
// 2. 만약 처음 나오는 1 이후에 왼쪽으로 전부 1이라면 즉 0이 없다면 자리 올림을 해야되는 경우이다. 1자리 올림을 하고
// 나머지 1들은 전부 맨 오른쪽부터 채운다.
// 
// absort()에러에서 빠져나오지 못하고 있다.
// 아... string 스택에서 구현을 내가 실수를 했다. 내가 저장하고자하는건 문자 1이 아니라 숫자 1이고 
// 이것을 고대로 문자열로 가져와야 하는 것이었다. 기존 stack<char>  를 stack<int>로 바꿔본다.
// 그리고 스택을 문자열로 바꾸는 과정을 없애고 그냥 스택 자체로 비교하면서 문자열을 만드는 방식으로 바꿔본다.
// 아니다.. 그냥 스택쓰지말자. 스택은 맨 나중에 쓰는걸로 형태를 바꾸는게 차라리 나을 것같다. 문자열로 추가하되 
// 그것은 거꾸로 들어가 있다는걸 논리적으로 고려한채로 계산을 한다.
// 2022_07_04 결국 해결 못했다. 최종적으로는 stoi() 함수가 왜 작동 안하는지 모르겠다.
// 
//
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int solution(int n) {
	if (n == 0) { return -1; }

	int cnt = 0, AFcnt = 0; //1의 개수 셀려고
	int m = n;
	stack<int> cstack;
	string s;
	int startidx, flagidx;
	bool start = false, flag = false;

	while (m > 0) {
		//cstack.push((m % 2));
		//m /= 2;
		s += (char)(m % 2); //1의자리가 맨 왼쪽에 붙은 형태
		m /= 2;
	}

	//while (!cstack.empty()) {
	//	s.push_back((char)cstack.top());
	//	cstack.pop();
	//}

	//for (int i = (s.size() - 1); i >= 0; i--) {
	//	if (!start && s[i] == '1') { //start가 트루가 되기 전까지 반복 //왜 \x1로 해야 인식을 하는지는 모르겠음
	//		startidx = i;
	//		start = true;
	//		cnt++;
	//	}
	//	else if (start && !flag && s[i] == '0') {//start 비트가 1인 구간을 찾았으면 0찾기 시작
	//		flagidx = i;
	//		flag = true;
	//	}
	//	else if (s[i] == '1') { //1인 구간은 cnt++ 이것은 flag true가 된 이후로 0을 제외한 1들을 카운트함.
	//		cnt++;
	//		if (flag) {
	//			AFcnt++; //플래그가 참이 된 순간부터는 플래그 인덱스 왼쪽에 있는 1들은 건들지 않을 것이므로
	//			//왼쪽의 1개수를 체크한다.
	//		}
	//	}
	//}
	//int i = cstack.size();
	//while (!cstack.empty()) {
	//	i--;
	//	if (!start && cstack.top() == 1) { //start가 트루가 되기 전까지 반복 //왜 \x1로 해야 인식을 하는지는 모르겠음
	//		startidx = i;
	//		start = true;
	//		cnt++;
	//	}
	//	else if (start && !flag && s[i] == '0') {//start 비트가 1인 구간을 찾았으면 0찾기 시작
	//		flagidx = i;
	//		flag = true;
	//	}
	//	else if (s[i] == '1') { //1인 구간은 cnt++ 이것은 flag true가 된 이후로 0을 제외한 1들을 카운트함.
	//		cnt++;
	//		if (flag) {
	//			AFcnt++; //플래그가 참이 된 순간부터는 플래그 인덱스 왼쪽에 있는 1들은 건들지 않을 것이므로
	//			//왼쪽의 1개수를 체크한다.
	//		}
	//	}
	//}
	for (int i = (s.size() - 1); i >= 0; i--) {
		if (!start && s[i] == '1') { //start가 트루가 되기 전까지 반복 //왜 \x1로 해야 인식을 하는지는 모르겠음
			startidx = i;
			start = true;
			cnt++;
		}
		else if (start && !flag && s[i] == '0') {//start 비트가 1인 구간을 찾았으면 0찾기 시작
			flagidx = i;
			flag = true;
		}
		else if (s[i] == '1') { //1인 구간은 cnt++ 이것은 flag true가 된 이후로 0을 제외한 1들을 카운트함.
			cnt++;
			if (flag) {
				AFcnt++; //플래그가 참이 된 순간부터는 플래그 인덱스 왼쪽에 있는 1들은 건들지 않을 것이므로
				//왼쪽의 1개수를 체크한다.
			}
		}
	}

	string answer = s;
	//start와 flag탐사가 끝났다면 1조건의 경우과 2조건의 경우로 나뉘어질 것이다.
	if (flag) {
		answer[flagidx] = '1';
		for (int i = flagidx + 1; i < (int)answer.size(); i++) {
			answer[i] = '0';
		}
		for (int i = answer.size() - 1; cnt-AFcnt-1 > 0; i--) {
			answer[i] = '1';	
			cnt--;
		}
		int nums = stoi(answer);
		return nums;
	}
	else
	{
		int nums = stoi(answer);
		return nums;
	}
}
int main() {
	int n = 78;
	cout << solution(n);

	/*int m = 15;
	cout << solution(m);*/
}
//
//
#endif