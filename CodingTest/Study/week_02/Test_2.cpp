//1번

//아이디 리스트를 작성하고(중복 허용 x)
//그 아이디를 바탕으로 공백을 포함한 문자열을 작성할때
//공백을 기준으로 왼쪽은 신고자 오른쪽은 피신고자
//신고자의 이름으로 접근가능한 배열을 만들고 그 배열엔 피신고자의 이름을 저장하되 중복을 허용하지 않는다.
//반환시에 각 아이디 순서에 맞게 배열의 길이를 반환한다.

#if 1
#include <string>
#include <vector>
#include <iostream>
//c++ map //이 문제에서는 2차원 벡터보다 효과적으로 자료를 정리할 수 있다.
//c++ sstream //문자열을 공백을 기준으로 나누기에 적당하다.
//c++ set	//중복체크를 자동으로하는 자료구조인 set을 활용하면 연산이 압축된다.
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	//vector<int> answer;
	//return answer;

	//벡터의 벡터 만들기
	vector<id_list>
}

int main()
{
	//cout << solution();
}
#endif

//2번

//m*n 개의 형태로 격자는 그려진다.
//갈색은 노란색 격자를 감싸는 격자이다.
//가로 >= 세로

//어떤 수가 주어졌을때 그것을 m*n으로 나타내는 경우의 수는 약수의 조합이다. 노란색의 경우의 수를 구해놓고
//노란색 경우의 수에 각각 (m+2)*(n+2) - m*n을 했을때의 값이 갈색 격자의 수인 경우가 답이 될 것이다.

#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> divisor(int N) {

	vector<int> answer;
	int index = 0;

	for (int i = 0; i <= sqrt(N); i++) {
		if (N % i == 0) {
			answer.push_back(i);
			index++;
			if (N / i != i) {
				answer.push_back(N / i);
				index++;
			}		
		}	
	}
	sort(answer, answer + index);

	return answer;
}
vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	//return answer;
	vector<int> yellowdiv = divisor(yellow);
	int rightIndex;
	vector<vector<int>> yellowMN;
	vector<int> MN;

	//m X N 조합을 저장한 배열 만들기
	rightIndex = yellowdiv.size();
	for (int i = 0; i <= rightIndex; i++, rightIndex--) {
		MN.push_back(yellowdiv[i]);
		MN.push_back(yellowdiv[rightIndex]);
		yellowMN.push_back(MN);
		MN.clear();

		//yellowMN[]
		//push_back은 깊은 복사...
	}

	//(m+2)*(n+2) - m*n = brown 인 경우의 수를 찾기
	int check = 0;
	int BM, BN;
	while (1) {
		BM = yellowMN[check][0] + 2;
		BN = yellowMN[check][1] + 2;

		if ((BM * BN - yellowMN[check][0] * yellowMN[check][1]) == brown) {
			break;
		}
	}
	//divisor 배열은 오름차순이었고 작은거m 큰거n에 저장했으니까 가로길이는 세로보다 같거나 커야하니까 가로먼저 출력해야되니까

	answer.push_back(BN);
	answer.push_back(BM);

	return answer;

}

int main()
{
	
	//cout << solution();
}
#endif