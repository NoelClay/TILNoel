#if 0
//n�� 1~200 ���� �� ��ǻ�ʹ� 0~n-1�� ǥ����. �밢��� �밢���� 1
//computers[i][j]�� 1�̸� i�� j�� ����Ǿ����� �ǹ��Ѵ�.
//return�� ������� ���� ������ ������ ��ȯ�Ѵ�.

//���� for������ computer ���͸� Ž���ϸ鼭 return�� ������ �����̹Ƿ� n���� 0���� �۾�����.
//computer[i][j] == 1�� ��� n--; �ѹ� -1�� ij�� �������� ������ ī���� �ϸ� �ȵȴ�.
//���� �������� push pop?
// 
//�������� �ҷ��� ������� ���Ӽ��� �־�� �ϴµ� ���Ӽ��� ������ �ʴ´�. 
//�������� ó���ϸ� �ߺ��� ���� �� ������ ����.
//���հ��� https://blockdmask.tistory.com/79
//https://hwan-shell.tistory.com/130
//
//�ᱹ pair������ �������ؾ� �Ұ� ����.. pair�� �˻縦 �Ϸ��ص� ��� �ؾ� �ߺ� üũ�� ������ �𸣰ڴ�.

#include<iostream>
#include<vector>
#include<set>
//#include<stack>

using namespace std;

int solution(int n, vector<vector<int>> computer) {
	//stack<int> stack;
	set<pair<int, int>> set;

	for (int i = 0; i < computer.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (computer[i][j] == 1 && i != j) {//i j�� �ٸ��� 1�̸� ����Ǿ��ٴ� �ǹ�
				
				//if (set.find(make_pair(j, i)) != set.end()) {//set�� i,j���� �������� �ʴ´ٸ�
				//	set.insert(make_pair(i, j));
				//}
				//else if(set.find)
				//	
				//}


			}
		}
	}
}

#endif