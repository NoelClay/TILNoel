/* <1> ������ �ݾ� �ڸ��� ���ư��� Ž��

���� �ٸ� Ž������ �˱� ���� ���� ���� �˾ƾߵǴ� ���ʴ� ����Ž���̴�.
����Ž���� �ʹ� ���� �ڷῡ�� �������� ������ �ؾ߸� �ϴ� ��쿡�� �ؾ��Ѵ�.
����Ʈ �ڷ������� Ư�� ���Ұ� ������� ã�� ������ count()�� �����Ҷ� �̷� ����Ž����
���ȴ�. �������� ������ �ڷ�鿡�� Ư�� �ڷḦ ���� Ư���� ��Ģ�� ���� �� �� ����� ������ �Ϲ����̴�.

���� ����Ž���� �˾ƺ���. �⺻������ ���ĵǾ��ִٴ� ������ �Ǿ� �־�� �ǹ̰� �ִ� Ž�����̴�.
�ٽ� ��ġ �ε����� ������ �߰��� �����̴�. �߰����� ���Ҹ� ���Ͽ� Ÿ�ٺ��� ������ �߰��� �������� ���������� �ϰ�
Ÿ�ٺ��� ũ�� ������ �߰������� ���������� �Ͽ� �ٽ� �߰����� �������� ã�´�. �׷��ٰ� ���Ҹ� �߰��ϸ� ��ȯ�ϰ�
�ᱹ �߰����� ���� �� ���� ������ �������� ã�� �� ���ٰ� ��ȯ�Ѵ�.
����Ž���� �����ϴ� ��� 2����. ��Ϳ� �ݺ����� �ִ�. ��ʹ� ���⿡�� �������� ������ ���� �����ϰ� ȣ���ڸ� ����ϱ⿡
�������� ������ �ְ�, �ݺ����� �������� ������ ������ ���� ���� ������� ���ɼ��� �����ϴ�.
*/
//1-1 ��� ����Ž�� (�õ� ����)
#if 0
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int midIdx;

int binarySearch(vector<int> arr, int start, int end, int target) {
	if (start > end) {
		return -1;
	}

	if (arr[midIdx] == target) {
		return midIdx;
	}
	else if (arr[midIdx] > target) {
		midIdx = (start + midIdx - 1) / 2;
		binarySearch(arr, start, (start + end - 2) / 2, target);
	}
	else if (arr[midIdx] < target) {
		midIdx = (midIdx + 1 + end) / 2;
		binarySearch(arr, (start + end + 2) / 2, end, target);
	}
}

int main()
{
	vector<int> array = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int target;
	cout << "ã������ ���� �Է��ϼ��� : ";
	cin >> target;

	midIdx = (0 + 15 - 1) / 2;
	auto result = binarySearch(array, 0, 15 - 1, target);
	cout << result;

}

#endif
/*����(���� ����)
��������� ȣ���ϴ°� ������ �¾Ұ� ���� ������ �̻��� ������ 
�ᱹ ��ȯ�ϴ� �� ���� ������ �Լ��� �Ǿ������.
else if���� ���� ��� ��Ͱ� �Ͼ���� �׷��� �ᱹ ���� �ٱ��ʿ� �ִ� �Լ��� ������ ��ȯ�ϴ°�?
��ȯ�ϴ°� ���� �׳� ��������� �ߵ��ϸ� ����Ǵ°Ŵ�.
��͹��� �׳� ȣ���ϴ°� �ƴ϶� return���� ȣ���ؾ��Ѵ�. �׷��� �� ����� ��ȯ�� �ٱ��� ���ȣ���Լ���
��ȯ���� �Ǵ� ���̴�.
*/

//1-1 ��� ����Ž�� (å���� ��������)
#if 0
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int midIdx;

int binarySearch(vector<int> arr, int start, int end, int target) {
	if (start > end) {
		return -1;
	}

	if (arr[midIdx] == target) {
		return midIdx;
	}
	else if (arr[midIdx] > target) {
		midIdx = (start + midIdx - 1) / 2;
		return binarySearch(arr, start, (start + end - 2) / 2, target);
	}
	else if (arr[midIdx] < target) {
		midIdx = (midIdx + 1 + end) / 2;
		return binarySearch(arr, (start + end + 2) / 2, end, target);
	}
}

int main()
{
	vector<int> array = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int target;
	cout << "ã������ ���� �Է��ϼ��� : ";
	cin >> target;

	midIdx = (0 + 15 - 1) / 2;
	auto result = binarySearch(array, 0, 15 - 1, target);
	cout << "�迭�� �ε��� ���� : " << result;

}

#endif

//1-2 �ݺ������� ����Ž�� ����
#if 0
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int binarySearch(vector<int> arr, int target) {
	int start = 0;
	int end = arr.size() - 1;
	int midIdx = 0;

	while (start <= end) {
		midIdx = (start + end) / 2;
		if (arr[midIdx] == target) {
			break;
		}
		else if(target > arr[midIdx]) {
			start = midIdx + 1;
		}
		else if (target < arr[midIdx]) {
			end = midIdx - 1;
		}
	}
	return midIdx;
}

int main()
{
	vector<int> array = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int target;
	cout << "ã������ ���� �Է��ϼ��� : ";
	cin >> target;

	auto result = binarySearch(array, target);
	cout << "�迭�� �ε��� ���� : " << result;
}
#endif

/*�ڵ��׽�Ʈ���� ����Ž��
����Ž���� ������ �������̰� ����������, ���� �ڵ��׽�Ʈ���� �����϶�� �ϸ� �������̵��� ���� ��
�ܼ��� ������Ž�� ������ �����°� �Ӹ� �ƴ϶� �ڷ����� ���������� �׸��� �˰��� �� ���� ������ ���̱�
�����ϸ� ����Ž���� �󸶳� �� �����ϰ� �ֳĿ� ���� �ð����෮�� �޶�����. ����Ž���� �׳� ���� ����
���� ������ ������ ���¸� �ܿ�� �ִ°� �����ϴ�.*/

/*<Ʈ�� �ڷᱸ��>
�����ͺ��̽��� �⺻������ Ʈ���ڷᱸ���� �������� �����͸� �����Ѵ�. ���� �˻����� ����� �ӵ��� ������
������ �ȴ�. Ʈ�� �ڷᱸ���� ���� ��尣�� �θ��� �ڽĳ���� ���踦 ���ϸ� �� ���̿� ���ǹ��� ��Ģ����
���������μ� �ڷ������ ȿ���� ���δ�.

<���� Ž�� Ʈ��>
Ʈ�� �ڷᱸ���߿� ���� ������ Ʈ���̴�. �����ڽĳ�� < �θ��� < �������ڽĳ�� �� ��Ģ���� ������ä��
�����ϴ� Ʈ�������̴�. �� Ʈ�������� Ž���ϴ� ����� �ϴ� Ÿ���� �θ���� ���ϰ� ��Ұ��迡 ����
����� �ڽĳ�忡 ���������� �����ϴ� Ž������ ������.
��Ʈ ������ �����ؼ� Ÿ�ٰ� ��ġ�ϴ� ��带 ã�������� �ݺ��ϴµ� �ᱹ �ڽĳ�尡 ���� ������� ����
���Ұ� ���� ���̹Ƿ� Ž���� �����Ѵ�.
*/

/*<2> ��ǰ ã��
�����̳� ���ڸ��忡�� ��ǰ�� N���ִ�. �� ��ǰ�� ���� ������ ������ ��ȣ�� �ִ�.
��� �� �մ��� M�� ������ ��ǰ�� �뷮���� �����ϰڴٸ� ���� �� �������� ��û�ߴ�. �����̴� ���� ��ġ�� �ʰ�
�մ��� ������ ��ǰ M�� ������ ��� Ȯ���ؼ� �������� �ۼ��ؾ� �Ѵ�. �̶� ���� �ȿ� ��ǰ�� ��� �ִ���
Ȯ���ϴ� ���α׷��� �ۼ��غ���. 
���� ��� ������ ��ǰ�� �� 5���϶� ��ǰ ��ȣ�� ������ ����.
N=5
8, 3, 7, 9, 2
�մ��� �� 3���� ��ǰ�� �ִ��� Ȯ�� ��û�ߴ�.
M=3
5, 7, 9
�̶� �մ��� ��û�� ��ǰ�� ������� Ȯ���� ��ǰ�� ������ yes ������ no ����Ѵ�.

�Է�����
ù° �ٿ� ���� N�� �־�����. �鸸 ����
��° �ٿ� �������� �����Ͽ� N���� ������ �־��� �鸸 ����
��° �ٿ� ���� M�� �־�����. �ʸ� ����
��° �ٿ� �������� �����Ͽ� M���� ������ �־�����. �鸸 ����
��� ����
ù° �ٿ� �������� �����Ͽ� �� ��ǰ�� ���翩�ΰ� yes or no�� ����

<���ٹ��>
�ϴ� �̺�Ž�� �����ΰ� ��°ġ�� �׻� �Է��ڷ���� ���� ���� ����Ž���� �����ص� �ȴ�.
������ �ð��ʰ��� �����̱� �����̴�.
���� ���� Ž���� ������ �ݺ� �� ���̱� ������ ����Ž���� ���ؼ� ������ ������ �Ǿ� �־����
*/
#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void solution(vector<int> store, vector<int> findList) {
	sort(store.begin(), store.end());

	for (auto n : findList) {
		int start = 0;
		int end = store.size() - 1;
		int mid = 0;
		while (1) {
			if (start > end) {
				cout << "no ";
					break;
			}
			mid = (start + end) / 2;
			if (n == store[mid]) {
				cout << "yes ";
				break;
			}
			else if (n < store[mid]) {
				end = mid - 1;
			}
			else if (n > store[mid]) {
				start = mid + 1;
			}
		}
	}
}

int main() {
	int N = 0;
	cout << "��ü ��ǰ�� ���� N �Է�. N : ";
	cin >> N;
	vector<int> store(N);
	cout << "��ǰ�� �������� �����Ͽ� N���� ��ǰ�� �Է��϶�." << endl;
	for (auto& n : store) {
		cin >> n;
	}
	int M = 0;
	cout << "ã���� �ϴ� ��ǰ�� ���� M �Է�. M : ";
	cin >> M;
	vector<int> findList(M);
	cout << "M���� ã�����ϴ� ��ǰ�� �������� �����Ͽ� �Է��϶�." << endl;
	for (auto& n : findList) {
		cin >> n;
	}

	solution(store, findList);
}
#endif
/*����(å ����)
�������� �پ��� ������� Ǯ �� �ִ�. å�� ��� ���İ� ���� �ڷ����� Ȱ���� ���õ� �ִ�.
���� �����غ���.*/

//������� Ǯ��
//�Ƹ� ��� ������ ���� ��� ����Ʈ�� ����� ã���� �ϴ� ������ ������� �ִ����� ���� �븦 ����ϴ� ����ϰ�.
#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void countSolution(vector<int> store, vector<int> findList) {
	vector<int> countList(100001);

	for (auto n : store) {
		countList[n]++;
	}
	for (auto n : findList) {
		if (countList[n] != 0) {
			cout << "yes ";
		}
		else {
			cout << "no ";
		}
	}
}

int main() {
	int N = 0;
	cout << "��ü ��ǰ�� ���� N �Է�. N : ";
	cin >> N;
	vector<int> store(N);
	cout << "��ǰ�� �������� �����Ͽ� N���� ��ǰ�� �Է��϶�." << endl;
	for (auto& n : store) {
		cin >> n;
	}
	int M = 0;
	cout << "ã���� �ϴ� ��ǰ�� ���� M �Է�. M : ";
	cin >> M;
	vector<int> findList(M);
	cout << "M���� ã�����ϴ� ��ǰ�� �������� �����Ͽ� �Է��϶�." << endl;
	for (auto& n : findList) {
		cin >> n;
	}

	countSolution(store, findList);
}
#endif

//���� �ڷ���
//���� �ڷ��� Ǯ�̴� ������ �ߺ��� ������� �ʴ´ٴ� ����� �̿��� ���̴�. �̰��� ���տ� ���� ���� ���� ȿ����
//�븱 �� ������, ������ �����ϴ����� ��ȯ�ϱ⿡ �����ϴٰ� �� �� �ִ�.
#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

void setSolution(set<int> store, vector<int> findList) {
	for (auto n : findList) {
		if(store.find(n))
	}
}

int main() {
	int temp;
	int N = 0;
	cout << "��ü ��ǰ�� ���� N �Է�. N : ";
	cin >> N;
	set<int> store;
	cout << "��ǰ�� �������� �����Ͽ� N���� ��ǰ�� �Է��϶�." << endl;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		store.insert(temp);
	}
	int M = 0;
	cout << "ã���� �ϴ� ��ǰ�� ���� M �Է�. M : ";
	cin >> M;
	vector<int> findList;
	cout << "M���� ã�����ϴ� ��ǰ�� �������� �����Ͽ� �Է��϶�." << endl;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		findList.push_back(temp);
	}

	setSolution(store, findList);
}
#endif