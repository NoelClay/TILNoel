#if 0 //���ذ�
// ���ڰ� ���� ����� �����¿� �پ��ִٸ� ���� �迭�ȿ� �߰��ϴ� ����?
// m,n�� ���� 100���� ���� ������ ������ 10000������
// 
// pair�� �� ����, ī��Ʈ
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