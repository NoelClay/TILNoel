#if 0
//�ϻ��� �� = �� �ڸ����� ������ ������ �������� ��.
//x�� 1�̻� 10000������ �����̴� ���� ���� 10000�� ��� 10���� �� 5�� �������̴�.
//��������� Ǯ �� ������ �������� ��ͱ����� ������ �������.
// 10000 �����̱� ������ ���� if ���� ����� Ǯ���� �־������� 
// ���ڿ��� �ٲپ �ϳ��� ���� �͵� �������� ����. https://notepad96.tistory.com/67
// string ���� https://blockdmask.tistory.com/338
// �ƽ�Ű�ڵ�ǥ https://stepbystep1.tistory.com/10
//
#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool solution(int arr) {
	int sum = 0;
	string num = to_string(arr);
	for (int i = 0; i < num.size(); i++) {
		sum += num.at(i) - 48;
	}
	if (arr % sum == 0) return true;
	else	return false;
}

int main()
{
	int arr = 13;
	if (solution(arr)) printf("true");
	else	printf("false");
}

#endif

// 222/10  22/10 2/10 0