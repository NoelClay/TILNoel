#if 0

//실패율 : 스테이지를 클리어하지 못한 플레이어수 / 스테이지 도달한 플레이어수
// 전체 스테이지 개수 N, 사용자가 도달한 스테이지의 번호가 담긴 stages 배열
// 스테이지 번호 배열을 실패율이 높은 순서로 내림차순으로 정렬하여 리턴
// 
// 1<=N<=500, N^2 = 250000 백만이하
// stages의 요소는 1이상 n+1 이하의 숫자. n+1은 최종클리어를 의미한다.
// 같은 실패율이면 작은 스테이지가 앞쪽에 정렬. 스테이지에 도달한 유저가 없다면 실패율 0
// 
// 첫번째 시도
// 1. 각 스테이지별 도달한 사람의 수를 저장하는 벡터 생성. (실패한 사람수, 도달한 사람수) 순서쌍
// 2. 생성된 벡터를 참고하여 실패율을 계산하고 저장하고 정렬
// 
// 두번째
// 1. 생각해보니 stages 안에 있는 요소를 오름차순으로 정렬하고나서 계산을 하면 더 쉬워질거 같다.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) 
{
	//오름차순으로 정렬을 하고 나면 계산하기 쉬워질거 같다.
	sort(stages.begin(), stages.end());

	//가장 낮은 스테이지의 실패율은 맨 왼쪽부터 실패한 사람 수/전체길이
	//그 다음 스테이지의 실패율은 
	//이번 스테이지 실패한 사람수/ 
	//전체길이-(이번 스테이지에 도달하지 못한 사람수 == 아까 카운팅된 사람의 수)

	vector<pair<double, int>> temp; //실패율과 스테이지를 저장하는 벡터
	int total = stages.size(); //총 길이를 초기화.
	int curNum = 1;//현재 탐색중인 스테이지 넘버
	int cnt = 0;
	vector<int> answer;

	for (int i = 0; i < stages.size(); i++)
	{
		//처음엔 1일거니까 1보다 크다면 그 스테이지 - curNum 사이는 실패율0프로
		if (curNum < stages[i])
		{
			for (curNum; curNum < stages[i]; curNum++)//이 반복문을 통해 같아지게 된다.
			{
				//맨처음 cnt=0
				temp.push_back(make_pair((double)cnt / (double)total, curNum));
				total = total - cnt;	cnt = 0;
			}
		}
		//if (curNum == stages[i])
			cnt++;
		//else if (curNum < stages[i])
		//{
		//	//순서쌍 벡터에 (실패율 계산식, 해당 스테이지번호)를 넣고
		//	temp.push_back(make_pair((double)cnt / (double)total, curNum));
		//	//cnt 초기화, curNum 초기화, total초기화
		//	total = total - cnt;	curNum = stages[i];		cnt = 1;
		//}
	}

	sort(temp.begin(), temp.end(), compare);

	vector<bool> boolCount(N, true);
	//실패율 기준으로 정렬한 벡터를 이용해 answer 벡터 만들고 반환
	for (int i = 0; i < N; i++) 
	{
		//정렬된 스테이지를 넣되. 만약 실패율이 계산 안된 스테이지가 있다면?
		//bool형 배열을 스테이지 개수만큼의 인덱스를 갖도록 선언한 뒤에 
		//pushback한 요소가 있다면 true 아니라면 false를 하고
		//temp 배열의 길이가 짧다면 false인 애를 낮은 인덱스부터 탐색해서 반환.

		//if (i > temp.size())
		//{
		//	//이런식으로 처리하면 반복문을 너무 많이 돌리자나..
		//	for(;;){}
		//	//애초에 temp가 N개만큼 채워져 있다면? 예를들어 
		//	//stages에서 카운팅 안된 스테이지들은 double 0을 저장하는것. 
		//}
		answer.push_back(temp[i].second);

	}
}
//실패율은 내림차순 정렬, 실패율이 같을 경우엔 오름차순 정렬.
bool compare(pair<double, int> a, pair<double, int>b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}



#endif