#if 0
//scovile�� ���̴� �鸸 k�� �ݺ�Ƚ���� ���������� �ȵɰ� ����. ����� ������ -1 return
// ��� ���� ���� ���� ���� �ι�°�� ���� ���� ���� ��� 
// ���峷�����Ľ��ں� + 2*�ι�°�γ������Ľ��ں�
// 
// �ϴ� �������� ������ �Ǿ��ִٴ� �����Ͽ� �����Ѵ�. �׷��� �������� ���Ŀ��� �̹� nlogn ���� �ð��ʰ�...
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