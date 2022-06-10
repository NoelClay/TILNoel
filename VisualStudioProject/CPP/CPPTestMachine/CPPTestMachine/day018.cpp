#if 0

//������ : ���������� Ŭ�������� ���� �÷��̾�� / �������� ������ �÷��̾��
// ��ü �������� ���� N, ����ڰ� ������ ���������� ��ȣ�� ��� stages �迭
// �������� ��ȣ �迭�� �������� ���� ������ ������������ �����Ͽ� ����
// 
// 1<=N<=500, N^2 = 250000 �鸸����
// stages�� ��Ҵ� 1�̻� n+1 ������ ����. n+1�� ����Ŭ��� �ǹ��Ѵ�.
// ���� �������̸� ���� ���������� ���ʿ� ����. ���������� ������ ������ ���ٸ� ������ 0
// 
// ù��° �õ�
// 1. �� ���������� ������ ����� ���� �����ϴ� ���� ����. (������ �����, ������ �����) ������
// 2. ������ ���͸� �����Ͽ� �������� ����ϰ� �����ϰ� ����
// 
// �ι�°
// 1. �����غ��� stages �ȿ� �ִ� ��Ҹ� ������������ �����ϰ��� ����� �ϸ� �� �������� ����.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) 
{
	//������������ ������ �ϰ� ���� ����ϱ� �������� ����.
	sort(stages.begin(), stages.end());

	//���� ���� ���������� �������� �� ���ʺ��� ������ ��� ��/��ü����
	//�� ���� ���������� �������� 
	//�̹� �������� ������ �����/ 
	//��ü����-(�̹� ���������� �������� ���� ����� == �Ʊ� ī���õ� ����� ��)

	vector<pair<double, int>> temp; //�������� ���������� �����ϴ� ����
	int total = stages.size(); //�� ���̸� �ʱ�ȭ.
	int curNum = 1;//���� Ž������ �������� �ѹ�
	int cnt = 0;
	vector<int> answer;

	for (int i = 0; i < stages.size(); i++)
	{
		//ó���� 1�ϰŴϱ� 1���� ũ�ٸ� �� �������� - curNum ���̴� ������0����
		if (curNum < stages[i])
		{
			for (curNum; curNum < stages[i]; curNum++)//�� �ݺ����� ���� �������� �ȴ�.
			{
				//��ó�� cnt=0
				temp.push_back(make_pair((double)cnt / (double)total, curNum));
				total = total - cnt;	cnt = 0;
			}
		}
		//if (curNum == stages[i])
			cnt++;
		//else if (curNum < stages[i])
		//{
		//	//������ ���Ϳ� (������ ����, �ش� ����������ȣ)�� �ְ�
		//	temp.push_back(make_pair((double)cnt / (double)total, curNum));
		//	//cnt �ʱ�ȭ, curNum �ʱ�ȭ, total�ʱ�ȭ
		//	total = total - cnt;	curNum = stages[i];		cnt = 1;
		//}
	}

	sort(temp.begin(), temp.end(), compare);

	vector<bool> boolCount(N, true);
	//������ �������� ������ ���͸� �̿��� answer ���� ����� ��ȯ
	for (int i = 0; i < N; i++) 
	{
		//���ĵ� ���������� �ֵ�. ���� �������� ��� �ȵ� ���������� �ִٸ�?
		//bool�� �迭�� �������� ������ŭ�� �ε����� ������ ������ �ڿ� 
		//pushback�� ��Ұ� �ִٸ� true �ƴ϶�� false�� �ϰ�
		//temp �迭�� ���̰� ª�ٸ� false�� �ָ� ���� �ε������� Ž���ؼ� ��ȯ.

		//if (i > temp.size())
		//{
		//	//�̷������� ó���ϸ� �ݺ����� �ʹ� ���� �����ڳ�..
		//	for(;;){}
		//	//���ʿ� temp�� N����ŭ ä���� �ִٸ�? ������� 
		//	//stages���� ī���� �ȵ� ������������ double 0�� �����ϴ°�. 
		//}
		answer.push_back(temp[i].second);

	}
}
//�������� �������� ����, �������� ���� ��쿣 �������� ����.
bool compare(pair<double, int> a, pair<double, int>b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}



#endif