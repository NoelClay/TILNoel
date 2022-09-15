/*현재 상황에서 가장 좋아보이는 것만 택하는 그리디 알고리즘

정확한 최적해 공식을 짜는게 중요한 문제이다. 그럴 싸한 답을 도출해내기 만만하지만, 창의적인 다양한
방법을 요구하기에 난이도를 다양하게 내는게 가능한 문제이다.

항상 정당성을 따져가며 최적화를 하는 방식으로 문제를 해결한다.

*/

/* Q1 모험가 길드
한 마을에 모험가각 N명 있다. 모험가 길드에서는 N명의 모험가를 대상으로 '공포드'를 측정했다.
'공포도'가 높은 모험가는 쉽게 공포를 느껴 위험 상황에서 제대로 대처할 능력이 떨어진다.
모험가 길드장인 동빈이는 모험가 그룹을 안전하게 구성하고자 공포도가 X인 모험가는 반드시
X명 이상으로 구성한 모험가 그룹에 참여해야 여행을 떠날 수 있도록 규정했습니다. 동빈이는 리더이다.
최대 몇개의 모험가 그룹을 만들 수 있는지 구하는 문제
N명의 모험가에 대한 정보가 주어졌을 때, 여행을 떠날 수 있는 그룹 수의 최댓갑을 구하는 프로그램

예를 들어  2 3 1 2 2 라는 공포도 정보가 있다면
3은 3명 이상인 그룹을 구성해야만 구성원으로 들어갈 수 있기에
1 혼자
3 2 2 세명
2 마을 
이런식으로 구성하여 2팀이 나가는 경우도 가능하고
1 혼자
2 2 두명
2 3 마을 이런식으로 두팀도 가능하고 상당히 많은 방법이 있겠지만 결국 두 팀이 최대 가능 팀이므로
2가 출력되어야 한다.

N은 10만이하 자연수들은 둘째 줄 부터 공백으로 구분하여 입력됨.

입력 예시			출력예시	2
5					
2 3 1 2 2

<접근방법>
내가 생각하기에 최소의 인원으로 구성된 팀이 많아질 수록 팀의 숫자가 가장 많을거 같다.
따라서 정렬을 한 번한 뒤에 최소공포도로 구성 가능한 애들끼리 구성을 하고 공포도가
큰 녀석들은 마을에 재껴 두는게 가장 효과적이지 않나? 결국 이 공식은 평균 공포값은 의미 없이
공포도가 큰 녀석이 끼는 순간 그만큼 숫자를 구성해야되는 문제이기 때문에
2 2 2 2 2 2 3 이라면 그냥 2끼리 2명 고용하는게 베스트이다. 평균값을 위해 여러 조합을 고려할 필요가 없다.
최대값의 영향력이 지대적이기 때문이다.
*/
#if 0
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N, answer=0;
	cout << "모험가는 총 몇명인가? : ";
	cin >> N;
	cout << "각 모험가의 공포도를 띄어쓰기로 전부 적어라." << endl;
	vector<int> feers(N);
	vector<int> checkstack;
	for (auto& n : feers) cin >> n;

	//1.먼저 정렬을하자.
	sort(feers.begin(), feers.end());
	//2. 탐색을 하면서 최대 인원수가 조정된다. 1일땐 추가 없이 끝 2일땐 하나 더 추가하고 다시 탐색할때
	//2라서 종료조건을 만족하면 끝
	for (int i = 0; i < feers.size(); i++) {
		int now = feers[i];
		checkstack.push_back(now);
		if (checkstack.size() == now) {
			answer++; checkstack.clear();
		}
	}
	
	cout << endl << answer;
}

#endif // 1
/*Q.02. 곱하기 혹은 더하기
각 자리가 숫자로만 이루어진 문자열 S가 주어졌을때 왼쪽부터 오른쪽으로 하나씩 모든
숫자를 확인하며 숫자 사이에 'X'혹은 '+' 연산을 넣어 결과적으로 가장 큰 수를 구하는
프로그램을 작성하라. 단, +보다 X를 먼저 계산하는 일반적인 사칙연산과 달리 순서대로
이루어진다. 예를들어 02984가 주어지면 0+2x9x8x4 로 576이고 567이면 5x6x7 로 210

<접근방법>
곱하기가 더하기보다 무조건 크다. 1과 0사이만 아니라면 어떤 숫자를 상대로도 마찬가지
두개의 문자열을 꺼내서 0 혹은 1이 있는지 확인하고 케이스 2가지 중에 하나를 선택함
그 다음부터는 하나씩 꺼내면서 계속 반복*/
#if 0
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	cout << "숫자로만 이루어진 문자열을 입력하세요." << endl;
	string numbers;
	cin >> numbers;
	vector<int>temp;
	int answer = 0, tempi;
	
	if (numbers.size() <= 1) {
		cout << "문자열의 길이는 1입니다. 따라서" << endl;
		cout << numbers[0];
		return -1;
	}
	else {
		temp.push_back(numbers[0] - '0');
		temp.push_back(numbers[1] - '0');
		if (temp[0] <= 1 || temp[1] <= 1) { //둘 중에 하나라도 0이나 1이면 더하기
			answer = temp[0] + temp[1];
		}
		else	answer = temp[0] * temp[1];
		for (int i = 2; i < numbers.size(); i++) {//만약에 넘버의 사이즈가 2이하라면 실행도 안되겠지.
			tempi = numbers[i] - '0';
			if (answer <= 1 || tempi <= 1) {
				answer += tempi;
			}
			else	answer *= tempi;
		}
		cout << endl << answer;
	}
}


#endif
/*Q03 문자열 뒤집기
다솜이는 0과 1로만 이루어진 문자열 S를 가지고 있다. 다솜이는 문자열 S에 있는 모든 숫자를 전부 같게 만드려고한다.
다솜이가 할 수 있는 행동은 S에서 연속된 하나 이상의 숫자를 잡고 모두 뒤집는 것.
뒤집는 것은 1을 0으로 0을 1로 바꾸는 것을 의미한다. 예를들어 00011000 일때
전체를 뒤집는 거 1번 11100111
중간에 0 뒤집으면 111111로 조건을 만족하여 2번이다
하지만 처음부터 마지막까지 뒤집고 중간부터 중간까지 뒤집을 필요 없이 처음부터 중간에 11을 뒤집으면 00이되어
00000000이 되어버린다.그러면 최소 횟수 1만으로 만족하는 것이다.
어디서부터 뒤집을지는 자유다 단 한번 뒤집기 시작하면 끊었다가 다시 어디부터 뒤집는건 안된다. 연속적으로 뒤집어야함.
그걸 1회로 친다.

<접근방법>
애초에 다 뒤집을 이유가 있나? 이 문제는 결국 연속되어있는 애들을 뒤집어야 되는 문제이다. 그런데 정답은 
꼭 1어야 하는것도 꼭 0이어야 하는 것도 아니다. 0으로 만드는게 유리한지 1로 만드는게 유리한지를 체크한다음에
그냥 연속적인 애들의 구간 만큼이 최소 반복횟수 아닐까? 0이 더 많은지 1이 더 많은지가 아니라 
연속된 구간의 개수가 중요하다. 어차피 연속된 구간은 인덱스로 접근할 것이다. 나는 pair배열로 인덱스 구간을 집계하여
저장하는 방식이 적절할거라고 본다. 그리고 배열의 길이를 비교하면 그게 바로 연속된 구간의 개수가 된다.
<스택>
연속된 녀석들을 비교할때 가장 유용한건 아마 스택 자료형이 아닐까 한다.
*/
#if 1
#include <iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main() {
	string s;
	cout << "0과 1로만 이루어진 문자열 입력하시오" << endl;
	cin >> s;
	int answer = 0, startidx = 0;
	vector<pair<int, int>> oneIdxs;
	vector<pair<int, int>> zeroIdxs;
	stack<int>check;
	int i = 0;
	/*연속된 숫자를 체크하는건 결국 이전 인덱스와 지금인덱스 혹은 지금인덱스와
	이후 인덱스가 같은 요소를 저장하고 있는지만 체크하면 된다. 그 변곡점을
	저장하면 구간을 저장하는 것이 될터이고 그 구간의 개수가 더 적은쪽이 답이다.*/
	for (int i = 1; i < s.size(); i++) {
		int j = i - 1; //항상 이전 인덱스를 가르킬 것이다.
		if (s[j] == s[i]) {
			continue;
		}
		else if (s[j] == '0') { //원래 0이 연속적이었는데 지금 1을 발견한거니까.
			zeroIdxs.push_back({ startidx, j });
			startidx = i;
		}
		else if (s[j] == '1') {
			oneIdxs.push_back({ startidx, j });
			startidx = i;
		}
	}
	//다 돌았으면 한번 체크를 해줘야된다. 변곡점이 마지막에 있었는지 없었는지에
	//따라 달라진다. 만약 변곡점이 없었다면 하나 추가하면되고, 변곡점이 있었다면
	//마지막 변곡점에 해당하는 요소를 추가한다.
	if (s[s.size() - 2] == s[s.size() - 1]) { //같다면
		if (s[s.size() - 1] == '0') {
			zeroIdxs.push_back({ startidx, s.size()-1 });
		}
		else{
			oneIdxs.push_back({ startidx, s.size() - 1 });
		}
	}
	else//같지 않다면 이미 변곡점이 하나 생성되어 추가되어 있고 마지막인덱스에
	{//대한 요소값만 추가해주면 끝
		if (s[s.size() - 1] == '0') {
			zeroIdxs.push_back({ s.size() - 1, s.size() - 1 });
		}
		else {
			oneIdxs.push_back({ s.size() - 1, s.size() - 1 });
		}
	}
	int zerogroupcnt = zeroIdxs.size();
	int onegroupcnt = oneIdxs.size();
}

#endif // 1
