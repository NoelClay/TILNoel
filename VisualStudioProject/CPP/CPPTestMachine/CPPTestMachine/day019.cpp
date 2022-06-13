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


//답지풀이
// https://ongveloper.tistory.com/98

#if 0
//답지에서 말하는 규칙성
//1. k개의 숫자를 뺄경우 몇자리(n) 숫자를 만들어야 하는지를 생각해야한다.
// 2. 최소n자리 숫자를 만들어야 하므로 버릴 수 있는 집합(앞쪽)과 
// 버리면 안되는 집합(뒤쪽)으로 나뉜다.
// 3. 버릴 수 있는 집합안에서 가장 큰 숫자 하나를 제외하고 그 앞쪽까지 버리고 나면 
// 다시 버릴 수 있는 집합(선택된 숫자 바로뒤부터 시작)과 
// 버릴 수 없는 집합(뒤쪽부터 n-(선택된 횟수))으로 나뉘고 다시 위 과정을 반복
//
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	//총 몇번을 탐색할지 == 총 몇개의 숫자를 고를지. 
	//즉 문자열에서 빼야하는 개수를 제거하고 나면 결국 최종적인 문자열 자리수가 나온다.
	int n = number.length() - k;

	//idx는 다음번에 탐색할때 다음 인덱스로 가야되니 1커져야 하는 로직을 가지므로
	//idx = -1로 초기화
	for (int i = 0, idx = -1; i < n; i++) {
		char max = '0'; //버릴 수 있는 집합 중 최대값을 비교하기 위해.
		for (int j = idx + 1; j <= k + i; j++) {
			if (max < number[j]) {
				max = number[j];
				idx = j;
				//최종적으로 내부 루프가 돌고 나면 앞쪽 집합 중에 앞에서부터 
				// 가장큰 원소가 저장되고 그 인덱스도 저장된다.
			}
			//j <= k + i의 의미는 전체 10중에 k=4라면 총 6자리의 숫자가 필요하고 
			//1.이때 버려야될 숫자중 어디는 살려둘지를 체크할때 총 k+1번 까지 탐색하고나서 
			//그중 앞쪽에서부터 가장 큰 값을 살려두려는 의도 만약 앞쪽부터 k+1번까지 탐색했는데
			//가장 큰수가 k+1번이라면 그대로 j= K+1이 되고 앞에 k개의 숫자들이 탈락되고나서
			//다음 루프가 돌때 j<=k+i을 한번씩만 만족하고 차례대로 answer += max가 총 6번반복되며 끝난다.
			//
			//2. 만약 j=2가 최대값이라면 다음 루프는 j=3에서 돌고 j<=4+1 만족할때까지 돌아간다. 
			//k+i까지만 탐색하는 이유는 뒤쪽에 n-i개의 자리까지 확보해줘야하기 때문.
			//(4+0,6-0) (4+1,6-1) (4+2, 6-2)...(제거가능한 집합 범위, 살려둬야하는 최소집합 범위)
		}
		answer += max;
	}


	return answer;
}
#endif