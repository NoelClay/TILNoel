#if 0
// 아 한마디로 길이가 같은 두 배열에서 하나씩 숫자를 뽑아 곱한다음 누적합한 결과가
// 가장 최소가 되는 값을 반환한다.
// 
// 3 * 4 > 2* 5 > 1*6 이다. 5*5> 4*6> 3*7 > 2*8 > 1*9 
// 10*10>11*9>12*8>13*7>14*6>15*5>16*4>17*3 등등 두 숫자의 차이가 작을 수록 커진다.
// a의 최소값과 b의 최대값을 곱해서 누적하거나 그 반대를 하면 될것.
// nlogn * 2번 + n번반복*2번(한번 곱하고 한번 더해) 1000*10*2 + 1000*2 = 2만2천번
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