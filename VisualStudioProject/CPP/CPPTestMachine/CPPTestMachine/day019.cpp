//내 풀이
#if 0
//1. 가장 큰 숫자는 9 8 7...1 순 내림차순으로 정렬한다음에 
// k만큼 뒤에서 제거하고 반환하면 된다.
//2. 입출력예시를 보아하니 문자열에서 문자를 제거만하지 
//문자들의 순서를 뒤바꿀 순 없는거 같다.
//3. 규칙성 찾기 or 만들 수 있는 리스트를 전부구하고 대소비교
//
//4. 자력으로는 규칙성을 못찾겠으니 전부 리스트를 구하고 대소비교한다.
// n개 중에 k개를 제거하고 순서를 고려한 리스트 뽑기
// (k개 제거의 경우의 수) x (정렬의 경우의 수)
// 4개중에 2개 제거의 경우의 수 =  4C2 순서 고려 안하는 제거할 숫자 2개뽑기
// 그렇게 제거한 숫자를 정렬하는 경우의 수 = 1	(새롭게 조합해서 숫자를 만들지는 않는다.)
// 따라서 nCk = n!/(n-k)!k! <- 총 리스트의 개수

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(string number, int k)
{
	vector<string> list;
	int lp = 0;
	int nLength = number.length();
	int recnt = 1;
	//n!/(n-k)!
	for (int i = nLength; i > nLength - k; i--)
		recnt *= i;
	for (int j = k; k > 1; j--)
		recnt /= j;

	for (int i = 0; i < recnt; i++)
	{
		//k를 이용해서 패딩을 설정해가며 리스트에 recnt번 문자열을 
		//리소싱해서 추가해야되는데..이것도 규칙성이 필요한데 잘 모르겠다.
		//이 규칙성이나 저 규칙성이나 둘 중 하나는 알아야한다.
	}
}

#endif


//답지
#if 0
//
//

#include <vector>
#include <algorithm>

#endif