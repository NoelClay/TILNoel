#if 0
// �����̰� �����ϰ� �;��ϴ� �ڽ��� �迭��� �ڽ��� ¥�µ�
// �� �������� ���帹�� ���յ� ������ ���õȴ�.
// 
// orders�� ���̴� 20, �� ������ ���̴� 10 = �� ������ ������ 200
// �ڽ��迭�� ���̴� 10 �����Ҵ� 2~10 ������ �ڿ����� ������������ ���� 
// ����迭�� ���ҵ��� ���ڿ��̰�, ���������� ���ĵȴ�. 
// ���ڽ��� ������ �ִ� ������ �����ϵ� ���� �ִ� ������ �ߺ��ȴٸ� ��� ����迭�� ����.
// 
// ��¥ �������� ���ϰڴ�. �𸣰ڴ�.
//
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> Solution(vector<string>orders, vector<int>course) {

}

int main()
{
	vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	vector<int> course = { 2, 3, 4 };
	vector<string> result = Solution(orders, course);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}
#endif