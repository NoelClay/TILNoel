#if 0
//scovile의 길이는 백만 k는 반복횟수랑 관련있으면 안될거 같다. 만들수 없으면 -1 return
// 계산 식은 가장 낮은 음식 두번째로 낮은 음식 섞을 경우 
// 가장낮은음식스코빌 + 2*두번째로낮은음식스코빌
// 
// 일단 오름차순 정렬이 되어있다는 가정하에 실행한다. 그런데 오른차순 정렬에서 이미 nlogn 으로 시간초과...
//
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(vector<int>scovile, int k) 
{
	sort(scovile.begin(), scovile.end());
	int temp=0, cnt=0;

	for (int i = 0; i < scovile.size(); ) {
		if (scovile[i] < k) {
			temp = scovile[i] + 2 * scovile[i + 1];
			cnt++;
			if (temp >= k) {
				i = i + 2;
			}
			else {
				scovile[++i] = temp;
				temp = 0;
			}
		}
		else {
			if (scovile[i + 1] >= k) break;
		}
	}
	return cnt;
}
int main()
{
	vector<int> scovile = { 1, 2, 3, 9, 10, 12 };
	cout << solution(scovile, 7);
}

#endif