//1��

//���̵� ����Ʈ�� �ۼ��ϰ�(�ߺ� ��� x)
//�� ���̵� �������� ������ ������ ���ڿ��� �ۼ��Ҷ�
//������ �������� ������ �Ű��� �������� �ǽŰ���
//�Ű����� �̸����� ���ٰ����� �迭�� ����� �� �迭�� �ǽŰ����� �̸��� �����ϵ� �ߺ��� ������� �ʴ´�.
//��ȯ�ÿ� �� ���̵� ������ �°� �迭�� ���̸� ��ȯ�Ѵ�.

#if 1
#include <string>
#include <vector>
#include <iostream>
//c++ map //�� ���������� 2���� ���ͺ��� ȿ�������� �ڷḦ ������ �� �ִ�.
//c++ sstream //���ڿ��� ������ �������� �����⿡ �����ϴ�.
//c++ set	//�ߺ�üũ�� �ڵ������ϴ� �ڷᱸ���� set�� Ȱ���ϸ� ������ ����ȴ�.
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	//vector<int> answer;
	//return answer;

	//������ ���� �����
	vector<id_list>
}

int main()
{
	//cout << solution();
}
#endif

//2��

//m*n ���� ���·� ���ڴ� �׷�����.
//������ ����� ���ڸ� ���δ� �����̴�.
//���� >= ����

//� ���� �־������� �װ��� m*n���� ��Ÿ���� ����� ���� ����� �����̴�. ������� ����� ���� ���س���
//����� ����� ���� ���� (m+2)*(n+2) - m*n�� �������� ���� ���� ������ ���� ��찡 ���� �� ���̴�.

#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> divisor(int N) {

	vector<int> answer;
	int index = 0;

	for (int i = 0; i <= sqrt(N); i++) {
		if (N % i == 0) {
			answer.push_back(i);
			index++;
			if (N / i != i) {
				answer.push_back(N / i);
				index++;
			}		
		}	
	}
	sort(answer, answer + index);

	return answer;
}
vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	//return answer;
	vector<int> yellowdiv = divisor(yellow);
	int rightIndex;
	vector<vector<int>> yellowMN;
	vector<int> MN;

	//m X N ������ ������ �迭 �����
	rightIndex = yellowdiv.size();
	for (int i = 0; i <= rightIndex; i++, rightIndex--) {
		MN.push_back(yellowdiv[i]);
		MN.push_back(yellowdiv[rightIndex]);
		yellowMN.push_back(MN);
		MN.clear();

		//yellowMN[]
		//push_back�� ���� ����...
	}

	//(m+2)*(n+2) - m*n = brown �� ����� ���� ã��
	int check = 0;
	int BM, BN;
	while (1) {
		BM = yellowMN[check][0] + 2;
		BN = yellowMN[check][1] + 2;

		if ((BM * BN - yellowMN[check][0] * yellowMN[check][1]) == brown) {
			break;
		}
	}
	//divisor �迭�� ���������̾��� ������m ū��n�� ���������ϱ� ���α��̴� ���κ��� ���ų� Ŀ���ϴϱ� ���θ��� ����ؾߵǴϱ�

	answer.push_back(BN);
	answer.push_back(BM);

	return answer;

}

int main()
{
	
	//cout << solution();
}
#endif