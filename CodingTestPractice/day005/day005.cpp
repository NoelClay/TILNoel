#if 1

//�� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̴�. ������ ���� h�� ���� �ο�Ǿ����� 
//�� h�� �ִ밪�� Hindex. �� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű�����
//hindex�� ��ȯ�ϴ� solution�Լ� �ۼ�

//�Ѹ���� ������ n�� �߿� �����̻��� n/2 �̻���� �߶����� �ּҰ��� ���ΰ�.
//1. ������ �ʿ䰡 ����. 2. �߰����� ����(�� �����̸� ū ��)

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int Solution(vector<int> citations)
{
	int answer;
	//1. ����(��������)
	sort(citations.begin(), citations.end());
	//2. �߰��� ���ϱ�: �߰����� �ε����� �ִ����/2 ��1. 5/2=2 01 '2' 34 ��2. 6/2=3 012 '3'45
	answer = citations[citations.size() / 2];
	return answer;
}


#endif