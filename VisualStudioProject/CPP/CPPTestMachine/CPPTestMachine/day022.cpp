#if 0 //미해결
//피로도 시스템 최소 필요 필도, 소모 피로도
// 하루에 한번씩 탐험할 수 있는 던전들이 있음. 유저가 최대한 많은 던전을 돌려함
// 현재 피로도 k, 각 던전별 "최소 필요 피로도", 소모 피로도가 담긴 2차원 배열
// k = 5000이하의 자연수, 던전의 개수는 8개이하. 피로도는 1000이하 자연수 
// 항상 최소 필요 피로도는 소모 피로도보다 작지 않다.
// 
// 직관적으로 생각해보면 최소 피로도가 가장 크다고 해서 앞으로 와야되는 것도 아니고 
// 소모 필요도가 가장 작다고해서 먼저 하면 되는 것도 아니다. 
// 최소필요도 - 소모필요도 가 가장 큰 녀석들이 앞으로 오면? 
// 먼저해야되는 최소필요도도 만족하고 소모필요도도 적으니 다음에 영향을 적게 준다.
// 반례가 분명 생길거 같은데 어떤 조건에서 반례가 생기는지는 잘 모르겠다.
//
#include<vector>
#include<iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {

}

int main() {
	int k = 80;
	vector<vector<int>> dungeons = { {80, 20}, {50, 40}, {30, 10} };
	cout << solution(k, dungeons);
}

#endif