/*<1> �پ��� �׷��� �˰���

<�̹� ��� ������ �Ⱦ��>

10�忡�� ��� ������� �׸���� ���� �˰��� �� �ռ� ������� Ȱ���� �׷��� �̷�

�׷����� ���� �������� �̷���� �ڷᱸ���̴�. �������� ���� �ٸ� ��ü�� ����Ǿ� �ִٴ�
�����̳����� �ٷ� �׷��� ������ ���ø��� ��.

�׷����� Ʈ���� ����
					�׷���							Ʈ��
���⼺			����׷����ϼ��� �ƴҼ���			����׷���
��ȯ��			��ȯ�ϼ��� �ƴҼ���				���ȯ
��Ʈ��� ����		��Ʈ ���� ����					��Ʈ ��� ����
��尣 ���輺		�θ� �ڽİ��� �ƴ�				�θ� �ڽ� ����
���� ����		��Ʈ��ũ ��						���� ��

�׷������� ������ ��ǻ�� ������ȭ �ϴ� ���
1. ������� : ������ ���� , �������⵵�� ����� ���� ����, �˻��ӵ� ���
2. ��������Ʈ : ��ũ�� ����Ʈ�� ����ϴ� ���, �������⵵�� ������ ������ŭ, �˻� �ӵ� ����

<���μ� ����>
���� ���Ұ� ���� �� ������ �ǹ��Ѵ�. ���μ� ���� �ڷᱸ���� �˱����ؼ� ���μ� ���� ������ �ʿ�

���μ� ���� �ڷᱸ���� ���μ� �κ� ���յ�� �������� ���� �����͵��� ó���ϱ� ���� �ڷᱸ��
���μ� ���� �ڷᱸ������ �ٽ� ��� 2���� �ʿ��ѵ� �ٷ� union�� find�̴�.
union�� ������ �������� ���μ� ������ ������ä�� �����͵��� ��ġ�� �����̴�.
find�� Ư�� ���Ұ� � ���տ� �ִ����� �˷��ִ� �����̴�.
���μ� ������ union-find �����̶�� �Ѵ�. 2���� �ٽɱ����
�ᱹ �� ������ ���μ� �������� �ƴ����� �ľ��� �� �ִٴ� ���� �������� � ���Ҹ� �������� ��������
�Ȱ��������� ���� �� �� ������ �ǹ��Ѵ�.

���μ� ���� �ڷᱸ���� Ʈ���� ǥ���Ѵ�.
union A B �� ������
1. A�� ��Ʈ��� B�� ��Ʈ��带 ��������� ���� ��Ʈ��带 ã�´�.
2. �� ������Ʈ ��尡  �� ū ��Ʈ����� ��Ʈ��尡 �ǵ��� �Ѵ�.

*/
//���� �����غ� ���μ� ����
/*�Է¿���			��¿���
6 4					�� ���Ұ� ���� ����: 1 1 1 1 5 5
1 4					�θ� ���̺�: 1 1 2 1 5 5
2 3
2 4
5 6*/
#if 0
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int V, E;

void myUnion(vector<pair<int, int>>(&dp), int a, int b) {
	//�������� ����ؾ��ϴ°�? ��Ʈ��尡 ���̻� ���������� �� �ڱ� �ڽŰ� ��Ʈ��尡 ���������� ��Ʈ��带 ã��.
	int i, j;
	while (dp[a].first != dp[a].second) {
		a = dp[a].second;//��Ʈ ��带 ã�ư�
	}
	while (dp[b].first != dp[b].second) {
		b = dp[b].second;//��Ʈ ��带 ã�ư�
	}
	if (a < b) {
		dp[b].second = a;
	}
	else {
		dp[a].second = b;
	}
}
int myFind(vector<pair<int, int>> dp, int a) {
	//���� ��Ʈ ��� ��ȯ�ϴ� ����
	while (dp[a].first != dp[a].second) {
		a = dp[a].second;
	}
	return a;
}
void solution(vector<pair<int, int>>(&dp)) {
	//�ʱ�ȭ ���� �� ������ ��Ʈ ���� �ڱ� �ڽ��̴�.
	int cnt = 0;
	for (auto& n : dp) {
		n.first = cnt;
		n.second = cnt;
		cnt++;
	}
	cout << "������ ���踦 ������ ������ŭ �Է��϶�." << endl;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		myUnion(dp, a, b);
	}
}
int main() {
	cout << "����� ���� V �� ������ ���� E�� �Է��϶�" << endl;
	cin >> V >> E;
	vector<pair<int, int>> dp(V + 1); //���, ��Ʈ��� ���踦 ������ ���̺� 
	solution(dp);
	cout << "�� ���Ұ� ���� ����: ";
	for (int i = 1; i < V + 1; i++) {
		cout << myFind(dp, i) << ' ';
	}
	cout << endl;
	cout << "�θ����̺�: ";
	for (int i = 1; i < V + 1; i++)	cout << dp[i].second << ' ';
}

#endif // 1
/*���� (å ������ ����)
���� ���� �ٸ� ������� �ߴ�. �����غ��� �θ��� ���̺����� �ε����� �� �ڱ� �ڽ� ����̹Ƿ�
pair�ڷ����� �ʿ� ��������, ��������ε� ¥�� �ڵ尡 �� ���������.*/

//å���� �ٽ� ���� Union-find �ڷᱸ��(�����)
#if 0
#include<iostream>
#include<vector>
using namespace std;
int V, E;
vector<int> dp(10001);

int find_Parent(int i) {
	if (i != dp[i]) return find_Parent(dp[i]);
	else return i;
}

void union_Parent(int a, int b) {
	//�������� ����ؾ��ϴ°�? ��Ʈ��尡 ���̻� ���������� �� �ڱ� �ڽŰ� ��Ʈ��尡 ���������� ��Ʈ��带 ã��.
	int i, j;
	i = find_Parent(a);
	j = find_Parent(b);
	if (i < j)	dp[j] = i;
	else		dp[i] = j;
}

void Union_Find_Tree() {
	//�ʱ�ȭ ���� �� ������ ��Ʈ ���� �ڱ� �ڽ��̴�.
	int cnt = 0;
	for (auto& n : dp) {
		n = cnt;
		cnt++;
	}
	cout << "������ ���踦 ������ ������ŭ �Է��϶�." << endl;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		union_Parent(a, b);
	}
}
int main() {
	cout << "����� ���� V �� ������ ���� E�� �Է��϶�" << endl;
	cin >> V >> E;
	Union_Find_Tree();
	cout << "�� ���Ұ� ���� ����: ";
	for (int i = 1; i < V + 1; i++) {
		cout << find_Parent(i) << ' ';
	}
	cout << endl;
	cout << "�θ����̺�: ";
	for (int i = 1; i < V + 1; i++)	cout << dp[i] << ' ';
}

#endif // 1

/* ���� �Ϲ����� ���μ� ������ ������ : find() �Լ��� ��ȿ����
find()�Լ��� �θ��� �迭�� ���� ���� �ڱ��ڽ��� �θ����� �� ���� ����� ��Ʈ��带 �߰��Ҷ�����
��������� �ݺ��ϴµ� �̴� �־��� ��� ����� ������ŭ �ݺ��ϰ� �Ǿ� ��ȿ�������� �þ ���ɼ��� ũ��.
�׷��� �������� �������� �ǿ����� ������ �θ��带 �����ϴ°� �ƴ϶� ��ũ�迭�� ��Ʈ��带 �׳� �����ϴ�
������� ���������ϴ�. �װ� �ٷ� ��� ���� path compression ����̴�. find()�Լ��� ���������
ȣ���Ҷ� ������ ���� �ʴ� �ڵ忡 ��ȯ���� �����ϴ� ���·� �ϸ� ������ �Ǵٰ� ���� ��Ʈ ��尡 ����ɰ�.
*/
#if 0
int new_find_Parent(int i) {
	if (i != dp[i]) return dp[i] = find_Parent(dp[i]);
	else return dp[i];
}
#endif // 1
/* ���μ� ������ ���� : ������ �׷������� ����Ŭ �Ǻ�
���� �׷��������� DFS�� �̿��Ͽ� ��� ����� ���� Ž���ϸ� ����Ŭ �������� Ȯ�� ����������
������ �׷������ ���μ� ������ union-find������ Ȯ�� �� �� �ִ�.
1. ���� �������� �־��� ������ �׷��� ������ �ִ�.
2. ��� �������� ���迡 ���ؼ� ������ ������ �����غ���.
3. ������ ������ ���� ��Ʈ��尡 ���ŵǰ� �Ǵµ� �׶� ���� � �˻縦 �ϳ� �Ѵ�.
�� �˻� ������ ���� ��Ʈ��带 ������ �ִ��� �̴�. �� �̹� ���������� ������� ������ �����Ͽ� �ִ�
���� ��� ���̿� �����̶�� �װ� ����Ŭ ���¶�� �Ǻ��ϴ� ��.

���� ��� 1. 1 2 3�� �ְ� (1,2) (2,3)�� ���� ������ �ִٸ� dp = {1, 2, 3}�̴�.
2. (1,2)�� ������ �ϸ� {1, 1, 3} (2,3)�� ������ �ϸ� {1, 1, 1}
3. ��Ʈ��尡 ���� 1�� ���� �Ǿ����� ���� ��Ʈ��带 ������ �ִ� ���¸� ������ �ϴ� ������ ������.
���� ����Ŭ ���°� �ƴϴ�.

��2 1. 1 2 3�� �ְ� (1,2) (2,3) (1,3)�� ���� ������ �ִٸ� dp = {1 2 3}
2. (1,2) (2,3) ���� union�ϸ� dp= {1 1 1}
3. �� ���¿��� (1,3)�� union�ҷ����� ��Ʈ��尡 ���� ���� ���� 1 2 3�� ����Ŭ ����
*/
//���� �����غ��� ������ �׷������� ����Ŭ�� �Ǻ��ϱ����� union-find�� Ȱ���ϴ� ����
#if 0
#include<iostream>
#include<vector>
using namespace std;

using namespace std;
int V, E;
vector<int> dp(10001);

int find_Parent(int i) {
	if (i != dp[i]) return dp[i] = find_Parent(dp[i]);
	else return i;
}

void union_Parent(int a, int b) {
	//�������� ����ؾ��ϴ°�? ��Ʈ��尡 ���̻� ���������� �� �ڱ� �ڽŰ� ��Ʈ��尡 ���������� ��Ʈ��带 ã��.
	int i, j;
	i = find_Parent(a);
	j = find_Parent(b);
	if (i < j)	dp[j] = i;
	else		dp[i] = j;
}
void checkCycle(int a, int b) {
	if (dp[a] == dp[b]) cout << "����Ŭ ����" << endl;
	union_Parent(a, b);
}

void Union_Find_Tree() {
	//�ʱ�ȭ ���� �� ������ ��Ʈ ���� �ڱ� �ڽ��̴�.
	int cnt = 0;
	for (auto& n : dp) {
		n = cnt;
		cnt++;
	}
	cout << "������ ���踦 ������ ������ŭ �Է��϶�." << endl;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		checkCycle(a, b);
	}
}
int main() {
	cout << "����� ���� V �� ������ ���� E�� �Է��϶�" << endl;
	cin >> V >> E;
	Union_Find_Tree();
	cout << "�� ���Ұ� ���� ����: ";
	for (int i = 1; i < V + 1; i++) {
		cout << find_Parent(i) << ' ';
	}
	cout << endl;
	cout << "�θ����̺�: ";
	for (int i = 1; i < V + 1; i++)	cout << dp[i] << ' ';
}
#endif // 1
//���� : å���뵵 ���� ����.

/*<����Ʈ��>
����Ʈ���� : ��� ��尡 �������� ���� ����Ǿ� �ְ� ����Ŭ�� �߻����� �ʴ� ����

<ũ�罺Į �˰���>: ��ǥ���� ����Ʈ�� �˰���
���� ������ ����ġ����� �־������� �ּ��� ����ġ ������� ����Ʈ���� ����� �˰���
�׸��� �˰����� Ž����� ���̰�, ��Ʈ��� ���̺��� ��� �����ϸ� ������ �ֹǷ�
���̳��� ���α׷��� ����� Ȱ��ȴ�. ���������δ� ����� ����-1���� ������ ������
��� ��带 �����ϸ鼭 ����Ŭ�� ���� Ʈ���� ������� �� �ִ�.

1. Ž����� ���� ���� ����ġ ����� ���� ���� �ͺ��� ������������ �����Ѵ�.
2. ���� ���� ����� ������ �켱������ �Ͽ� �׷��� union-find ������ ���� ��Ʈ��尪��
Ȯ���ϰ� ���� ��Ʈ��尡 �ƴ϶�� ����Ʈ�� �������� �����ϰ�, ���� ��Ʈ��尪�� �̹�
������ �ִٸ� �̹� ������ ����Ŭ�� ����� �����̹Ƿ� �����ϰ� ���� �׸���� �Ѿ��.
3. �׷��� �Ͽ� ����Ʈ�� ������ ���-1�� ��ŭ ä������ �װ� �ٷ� ����Ʈ���̴�.

�Է¿���			��� ����
7 9				159
1 2 29
1 5 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25

*/
//���������� ũ�罺Į �˰���
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using namespace std;
int V, E, K, totalWeight = 0;
vector<pair<int, int>> graph[10001]; //graph������ ������ ����
vector<int> dp(10001, 10001); //��Ʈ��尡 ����Ǵ� dp���̺�
vector<int> weight;//����ġ�� ������ ���̺�
vector<pair<int, int>> SpaningTree;

int find_Parent(int i) {
	if (i != dp[i]) return dp[i] = find_Parent(dp[i]);
	else return i;
}

void union_Parent(int a, int b) {
	//�������� ����ؾ��ϴ°�? ��Ʈ��尡 ���̻� ���������� �� �ڱ� �ڽŰ� ��Ʈ��尡 ���������� ��Ʈ��带 ã��.
	int i, j;
	i = find_Parent(a);
	j = find_Parent(b);
	if (i < j)	dp[j] = i;
	else		dp[i] = j;
}
bool checkCycle(int a, int b) {
	if (dp[a] == dp[b]) return false; //�� ������ ����Ŭ�̹Ƿ� �޽�
	union_Parent(a, b);//�� ������ ����Ǿ ����Ŭ�� �ƴϹǷ� ������
	return true; //������ ���������Ƿ� Ʈ��
}
void kruskal() {
	int cnt = V - 1;//�����ϴٰ� 0�� �Ǹ� �� �̻� ���ʿ䰡 ��������.
	//�ʱ�ȭ ���� �� ����� ��Ʈ��尪�� �ڱ� �ڽ�
	for (int i = 1; i < V + 1; i++) dp[i] = i;
	//graph�� ���� ����ġ�� ������� graph �� ���̺��� ����.
	//����ġ���� ������� �������� �����ϴ°� �´µ� ���? graph�� ���� �ϱ����� 
	//�ε��� ������ �����ϳ�?
	sort(weight.begin(), weight.end()); //�׸��� ���� �������� ����ġ

	for (auto n : weight) { //����ġ ���̺��� �̿��� �ε��� Ž��
		for (auto m : graph[n]) { //m�� pair {����, ����}
			bool isCycle = checkCycle(m.first, m.second);
			if (isCycle) {
				totalWeight += n; cnt--;
				SpaningTree.push_back(m);
			}
			else	continue;
		}
		if (cnt <= 0) break;
	}
	cout << endl;
	if (cnt > 0) cout << "�� �׷����� ����Ʈ���� �� �� �����ϴ�." << endl;
	else
	{
		cout << "�� �׷����� ����Ʈ���� �����մϴ�." << endl;
		cout << "����ġ ����� : " << totalWeight << endl;
	}
}
int main() {
	cout << "����� ���� V �� ������ ���� E�� �Է��϶�" << endl;
	cin >> V >> E;
	cout << "������ ���踦 ������ ������ŭ �Է��϶�." << endl;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[c].push_back({ a, b }); //����ġ�� �ε����� �ϴ� 2���� ���� 
		//�� ��Ұ��� pair ���ͷ� ���س��� ������带 ������ ���̴�.
		weight.push_back(c); //����ġ�� ������ ���̺�
	}
	kruskal();

	cout << "�� ���Ұ� ���� ����: ";
	for (int i = 1; i < V + 1; i++) {
		cout << find_Parent(i) << ' ';
	}
	cout << endl;
	cout << "�θ����̺�: ";
	for (int i = 1; i < V + 1; i++)	cout << dp[i] << ' ';
	cout << endl;
	sort(SpaningTree.begin(), SpaningTree.end());
	cout << "����Ʈ���� ����" << endl;
	for (auto n : SpaningTree)
	{
		cout << n.first << ' ' << n.second << endl;
	}
}
#endif // 1
/*����
<������ �κ�>
1. graph ������ �ޱ� �޾Ҵµ� ���� ����ġ�� ��� �������� ��ġ�� ������ ���
2. ��ġ�� �ߴٸ� �װ� �̿��ؼ� ��� ��忡 �������� ���
-> �׷����� ���� ������ �ƿ� �ٲ���. ���� ����ġ ���� �̿��� �����ؾ� �Ǵϱ�
graph�� �ε��� ������ ����ġ������ �ٲٸ� �ȴ�.
�ذ�
<å ������ ����>
å������ �迭�� 2�� 3�� �̿��ؼ� ���� �ٸ� ������ �����ϰ� �ε����� �����ϰ�
�̷� ����� �ƴ϶� ���ʿ� vector<pair<int, pair<int, int>>> �̷� ������
�ε����� �����ϸ� ��Ʈ�� ������ �������� ���� 3�� �ڷᱸ���� ����Ͽ���.

*/
//å������ ���� ����ȭ�� ũ�罺Į �˰���
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using namespace std;
int V, E, K, totalWeight = 0;
vector<pair<int, pair<int, int>>> graph; //graph������ ������ ����
vector<int> dp(10001, 10001); //��Ʈ��尡 ����Ǵ� dp���̺�
vector<int> weight;//����ġ�� ������ ���̺�
vector<pair<int, int>> SpaningTree;

int find_Parent(int i) {
	if (i != dp[i]) return dp[i] = find_Parent(dp[i]);
	else return i;
}

void union_Parent(int a, int b) {
	//�������� ����ؾ��ϴ°�? ��Ʈ��尡 ���̻� ���������� �� �ڱ� �ڽŰ� ��Ʈ��尡 ���������� ��Ʈ��带 ã��.
	int i, j;
	i = find_Parent(a);
	j = find_Parent(b);
	if (i < j)	dp[j] = i;
	else		dp[i] = j;
}
bool checkCycle(int a, int b) {
	if (dp[a] == dp[b]) return false; //�� ������ ����Ŭ�̹Ƿ� �޽�
	union_Parent(a, b);//�� ������ ����Ǿ ����Ŭ�� �ƴϹǷ� ������
	return true; //������ ���������Ƿ� Ʈ��
}
void kruskal() {
	int cnt = V - 1;//�����ϴٰ� 0�� �Ǹ� �� �̻� ���ʿ䰡 ��������.
	//�ʱ�ȭ ���� �� ����� ��Ʈ��尪�� �ڱ� �ڽ�
	for (int i = 1; i < V + 1; i++) dp[i] = i;
	//graph�� ���� ����ġ�� ������� graph �� ���̺��� ����.
	//����ġ���� ������� �������� �����ϴ°� �´µ� ���? graph�� ���� �ϱ����� 
	//�ε��� ������ �����ϳ�?
	sort(graph.begin(), graph.end()); //�׸��� ���� �������� ����ġ

	for (auto n : graph) { //����ġ ���̺��� �̿��� �ε��� Ž��
		bool isCycle = checkCycle(n.second.first, n.second.second);
		if (isCycle) {
			totalWeight += n.first;		cnt--;
			SpaningTree.push_back(n.second);
		}
		else	continue;

		if (cnt <= 0) break;
	}
	cout << endl;
	if (cnt > 0) cout << "�� �׷����� ����Ʈ���� �� �� �����ϴ�." << endl;
	else
	{
		cout << "�� �׷����� ����Ʈ���� �����մϴ�." << endl;
		cout << "����ġ ����� : " << totalWeight << endl;
	}
}
int main() {
	cout << "����� ���� V �� ������ ���� E�� �Է��϶�" << endl;
	cin >> V >> E;
	cout << "������ ���踦 ������ ������ŭ �Է��϶�." << endl;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ c, { a, b } }); //����ġ�� �ε����� �ϴ� 2���� ���� 
		//�� ��Ұ��� pair ���ͷ� ���س��� ������带 ������ ���̴�.
		//weight.push_back(c); //����ġ�� ������ ���̺�
	}
	kruskal();

	cout << "�� ���Ұ� ���� ����: ";
	for (int i = 1; i < V + 1; i++) {
		cout << find_Parent(i) << ' ';
	}
	cout << endl;
	cout << "�θ����̺�: ";
	for (int i = 1; i < V + 1; i++)	cout << dp[i] << ' ';
	cout << endl;
	sort(SpaningTree.begin(), SpaningTree.end());
	cout << "����Ʈ���� ����" << endl;
	for (auto n : SpaningTree)
	{
		cout << n.first << ' ' << n.second << endl;
	}
}
#endif // 1
