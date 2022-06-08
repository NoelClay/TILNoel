#if 0

//���ξ�� a���� b������ ������ a������ b���� �պκ��� �Ϻκ��� �ɰ�쿡 a�� ���ξ �Ǵ� ��
//1. ���ڿ� Ž��
//2. ����Loop 
//3. �ؽ�

//1.sort(key = len)�� ���� str�� ���̿� ���� ������ ��, phone_book�� ù��°�� ���λ�� �����Ͽ� 
//������ ��ȭ��ȣ�� ���ڸ��� ��

//2.�� ���� ���� ������� ���ڼ����� ���ڿ� ����. �� ���λ� �񱳽�, ������ ��ȭ��ȣ�� �ƴ� �ٷ� ���� ��ȭ��ȣ�� ��.
//ù���ڿ� �������ڰ� ���ڼ����� ��ġ�ϴ� �ֵ鳢�� �˾Ƽ� �پ��ִ� ���°� �Ǿ��ְ� �񱳴���� �����༮�ΰɷ� ������ �Ǿ�����
//�񱳴�� ������ ����.

//3.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

bool Solution(vector<string> phone_book)
{
	//hash map����
	unordered_map<string, int> map;
	//Ű���� �� ��ȭ��ȣ�� ������� 1
	for (int i = 0; i < phone_book.size(); i++)	map[phone_book[i]] = 1;

    // 2. ��� ��ȭ��ȣ�� substring�� HashMap�� �����ϴ��� Ȯ���Ѵ�.
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book[i].size() - 1; j++)
        {
            //�� ��ȭ��ȣ�� 0~�� ��ȭ��ȣ�� ����-1 �ε��� ���� ��� �������� ����鼭
            string phone_number = phone_book[i].substr(0, j + 1);
            //�� ������ Ű������ �ؽ��� �����ϴ��� Ž���Ѵ�. ���� �����Ѵٸ� 
            //�� �ؽ��� Ű���� �� phonebook[i]�� ���ξ �ȴ�.
            if (map[phone_number])
                return false;
        }
    }
    return true;
}

#endif
