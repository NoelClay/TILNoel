#if 0
// �� �Ѹ���� ���̰� ���� �� �迭���� �ϳ��� ���ڸ� �̾� ���Ѵ��� �������� �����
// ���� �ּҰ� �Ǵ� ���� ��ȯ�Ѵ�.
// 
// 3 * 4 > 2* 5 > 1*6 �̴�. 5*5> 4*6> 3*7 > 2*8 > 1*9 
// 10*10>11*9>12*8>13*7>14*6>15*5>16*4>17*3 ��� �� ������ ���̰� ���� ���� Ŀ����.
// a�� �ּҰ��� b�� �ִ밪�� ���ؼ� �����ϰų� �� �ݴ븦 �ϸ� �ɰ�.
// nlogn * 2�� + n���ݺ�*2��(�ѹ� ���ϰ� �ѹ� ����) 1000*10*2 + 1000*2 = 2��2õ��
//
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	sort(A.begin(), A.end());	sort(B.begin(), B.end());
	int length = A.size();
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += A[i] * B[length - i - 1];
	}
	return sum;
}

int main() {
	vector<int> A = { 1, 2 };
	vector<int> B = { 3, 4 };

	cout << solution(A, B);
}

#endif