#if 0
// n���� �߿� n/2�� ��������. ���ϸ��� �������� ��ȣ�� ����. ���� ������ ���� ��ȣ
// �ִ��� ���� ������ ���ϸ��� �����ؼ� n/2���� �ݵ�� ��������. nums�� �׻� ¦����
// ������ �� �ִ� ���ϸ� ������ ������ �ִ밪�� �����Ѵ�. �⺻������ n/2���� �ִ밪�̴�. 
// 
// � ���������� ��ȯ�� �ʿ�� ����. ���� �ߺ����� �ʴ� ���ڸ� �̵� n/2���� �ִ밪���� ������ ����.
// nums�� ���̴� 10000�� �� n^2�� �ƴϸ� �ȴ�.
// nlogn = 13*10000, n�� Ž�� �� 14���� �ݺ�
// 
// �� �̷���? ��°��� �̻��ϴ�. -> solution�� �Ű������� �������� �ʾҴ� �ܼ� �Ǽ�
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
	int answer = 0;
	int compNum = 0;
	int max = nums.size();
	
	sort(nums.begin(), nums.end());
	
	for (int i = 0; i < max; i++) {
		if (compNum < nums[i]) {
			compNum = nums[i];
			answer++;
		}
	}
	if (answer > (max / 2)) 
		return (max / 2);
	else	
		return answer;	
}

int main() {
	vector<int> nums = { 3, 4,3 ,2, 2, 3 };
	cout << solution(nums) <<endl;
	cout << nums.size();
}

#endif