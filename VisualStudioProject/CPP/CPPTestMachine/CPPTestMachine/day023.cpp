#if 0 //미해결
// 숫자가 같은 멤버가 상하좌우 붙어있다면 같은 배열안에 추가하는 형태?
// m,n은 각각 100개씩 따라서 가능한 조합은 10000개까지
// 
// pair는 각 원소, 카운트
//
#include<vector>
#include<iostream>
#include<stack>
using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<pair<int, int>> pvector;

	for (int i = 0; i < m ; i++) {
		for (int j = 0; j < n; j++) {
			if(pvector.)
			pstack.push(make_pair(picture[i][j], 1));
		}
	}

}
int main() {
	int m = 6, n = 4;
	vector<vector<int>> picture =
	{ {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} };

	cout << solution(m, n, picture)[0] << endl;
	cout << solution(m, n, picture)[1] << endl;
}

#endif