#if 1

//논문 n편 중, h번 이상 인용된 논문이 h편 이상이다. 나머지 논문이 h번 이하 인용되었으면 
//그 h의 최대값이 Hindex. 각 논문의 인용 횟수를 담은 배열 citations가 매개변수
//hindex를 반환하는 solution함수 작성

//한마디로 눈문들 n편 중에 과반이상인 n/2 이상까지 잘랐을때 최소값이 얼마인가.
//1. 정렬할 필요가 있음. 2. 중간값을 구함(딱 절반이면 큰 쪽)

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int Solution(vector<int> citations)
{
	int answer;
	//1. 정렬(오름차순)
	sort(citations.begin(), citations.end());
	//2. 중간값 구하기: 중간값의 인덱스는 최대길이/2 예1. 5/2=2 01 '2' 34 예2. 6/2=3 012 '3'45
	answer = citations[citations.size() / 2];
	return answer;
}


#endif