#if 0
//하샤드 수 = 각 자리수의 합으로 나누어 떨어지는 수.
//x는 1이상 10000이하인 정수이다 보니 만약 10000일 경우 10으로 총 5번 나눌것이다.
//재귀적으로 풀 수 있을거 같았으나 재귀구조를 만들기는 어려웠다.
// 10000 이하이기 때문에 다중 if 문을 만들어 풀수도 있었겠지만 
// 문자열로 바꾸어서 하나씩 빼는 것도 괜찮을것 같다. https://notepad96.tistory.com/67
// string 사용법 https://blockdmask.tistory.com/338
// 아스키코드표 https://stepbystep1.tistory.com/10
//
#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool solution(int arr) {
	int sum = 0;
	string num = to_string(arr);
	for (int i = 0; i < num.size(); i++) {
		sum += num.at(i) - 48;
	}
	if (arr % sum == 0) return true;
	else	return false;
}

int main()
{
	int arr = 13;
	if (solution(arr)) printf("true");
	else	printf("false");
}

#endif

// 222/10  22/10 2/10 0