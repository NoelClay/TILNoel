/*<1> ���ؿ� ���� �����͸� ����
<���� �˰��� ����>
�����̶� �����͸� Ư���� ���ؿ� ���� ������� �����ϴ� ��.
������ ���� ���� ����Ǵ� �˰��� �� �ϳ�. ���� Ž���� �Ҷ��� ���� ��ó�������� �ʿ��ϴ�.
�˰����� ȿ������ ���� �����Ҽ� �־� �պκп��� ���� ù��° �˰����̱⵵ �ϴ�.

<���� ����>
���ĵ��� ���� �κ� ���ĵ� �κ� �ΰ����� ������ ���ĵ��� ���� �κп��� ���� ���� ���� ���ĵ� �κ����� �ϳ��� �����ϸ�
�ᱹ ������������ ���ĵȴ�.
1.�ּҰ� ���ϱ� 2.�� ���ε����� ������ ��ȯ 3.���ĵ��� ���� �κ��� ó�� �ε����� �ϳ� ���� 4.��ȯ�Ϸ��� �ε����� �ϳ�����
*/
//6.1 ���� ���� ����
#if 0
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> array = { 7,5,9,0,3,1,6,2,4,8 };
	int min = 999999;
	int minIdx = 0;

	for (int startidx = 0; startidx < array.size(); startidx++) { //���� ����� ������ŭ �ݺ��ϸ鼭
		min = 999999;
		for (int i = startidx; i < array.size(); i++) { //���ο��� ���� ������ 1�� ������ �ݺ� Ž���Ѵ�.
			if (min > array[i]) {
				min = array[i];		minIdx = i;
			}
		}//���� �ݺ����� ������ ���ĵ��� ���� �κ��� ���� ���� ���� min�� ����ǰ� �׶��� �ε����� ����

		array[minIdx] = array[startidx]; //�ּҰ��� ����ִ� �ε����� �� ó�� ���� �ְ�
		//�̸� �����ص� �ּҰ��� ��ó�� ���� ������ ��ȯ �Ϸ�.
		array[startidx] = min;
	}

	for (auto n : array) {
		cout << n << endl;
	}
}
#endif
/*����, å�� ���縦 ����
���� ���� ������ �ʿ���� �ε������� �����ϴ� �����ε� �����Ͽ� ���񱳰� �����ϴٴ� ���� ĳġ�߾�� �Ѵ�.
*/

//å 6.1 ���� ���� ����
#if 0
#include<iostream>
#include<vector>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {
	for (int i = 0; i < n; i++) { //�� ���Ұ�����ŭ �ݺ��Ұ��̰�
		int min_index = i; // ���� ���� ������ �ε��� �ϴ��� ó���� ������ �ε����� i�� ����
		for (int j = i + 1; j < n; j++) {//i�ε����� �������� ���� ���
			if (arr[min_index] > arr[j]) {
				min_index = j;//���� ���� ������ �ʿ� ���� �ε��� ������ ������ ���ؼ� �ε��� ������ ����.
			}
		}
		//���� ���� ���� �ε����� ã�Ұ� ��ȯ�ؼ� ������ i�ε����� ���ؼ� ��ȯ�ؾ���.
		swap(arr[i], arr[min_index]); // ������ �迭�� �ε����� ������� �� ���� ��ȯ�ϴ� �Լ�
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
#endif

/* ��������
�����͸� �ϳ��� Ȯ���ϸ�, �� �����͸� ������ ��ġ�� �����ϸ� ���?
������ n������ ������ Ƚ���� �ݺ��ϸ� ������ �ӵ��� �����̴� �������İ� �޸�. �������� ��Ƚ���� �����ȴ�.
�̸� ���������� ����� ���� �ξ� ���� ���������� �Ϸᰡ �Ͼ��.
1.�� ������ ���ĵ� �κ����� �ݺ��� �Ͼ ���� ���ĵ� �κ��� �ϳ��� �þ �ᱹ ��� ��Ұ� ���ĵȴ�.
2. ù ��° �����ʹ� �� ��ü�� ���ĵǾ� �ִٰ� �Ǵ��ϰ�, �� ��° �����ͺ��� 
ù��° �������� ���ʿ� �������� �����ʿ� �������� �Ǵ��Ѵ�.
3. �̾ ����° �����͸� ������ �Ųٷ� �ι�° ������ ù��° �����Ͷ� ���ϸ鼭 ��� ������ �Ǵ��Ѵ�.
4. �̾ �׹�° �������̴�. �ε����� �Ųٷ� �ٿ����鼭 �ڱ⺸�� ���� ���� ���ö����� ���ϸ�ȴ�. �ֳ�
�̹� �ڱ� ���ʿ� �ִ� �� �����͵��� ���� ������������ �̹� ���ĵǾ� �ִ� �����̱� ������ �ڱ⺸�� ū �༮���� �����Ŀͼ� 
ó������ �ڱ⺸�� ���� �����͸� �����ٸ� �ٷ� ���ڸ��� �� �������� �ڱ⺸�� ������ ���ʿ� �ְ� �ڱ⺸�� ū�� �����ʿ� �ִ�
�ٷ� �ڱ��� �ڸ��̱� �����̴�.
*/
//6.3 �������� ����
//������ �����
//1. ������ �Ѵٸ� �������� �з��ߵǴµ� �װ��� ��� �����ұ�?
#if 0
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> array = { 7,5,9,0,3,1,6,2,4,8 };
	for (int i = 1; i < array.size(); i++) {
		for (int j = i-1; j >= 0; j--) {
			if (array[j] < array[i]) {
				
			}
		}//j�� 0�����ص� ���� ���� ��ã������ 
	}
}
#endif
//����(����)
// �迭�������� �ε��� �ű�� ����� ���ϰڴ�.
// å���� ���� ���������� ���� �츮�� ��������δ� �������� ã���� �� �ε����� �����ϰ�
// �������� �о�°� ��������� ����������, ���������δ� �׷��� ����� ������ ������ ��ƴ�
// ���� ����ؼ� ������ ������ �ϴ°ɷ� �����Ѵ�.
// i�� 1���� �����ϰ� j�� i���� �����ϸ� 1�� �����Ѵ�.
// ���� j-1�ε����� j�� ���Ҷ� ������ �� ũ�� �����ϸ� �ȴ�.
// �̷��� �����ϴٰ� ������ �� ������ �������� ���� �ݺ��� Ż��� �ݺ������ϸ� ���ϴ� ���������� ����.
//6-3 å ���� ����
#if 0
#include<iostream>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {
	for (int i = 1; i < n; i++) {
		// �ε��� i���� 1���� �����ϸ� �ݺ��ϴ� ����
		for (int j = i; j > 0; j--) {
			// �� ĭ�� �������� �̵�
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
			// �ڱ⺸�� ���� �����͸� ������ �� ��ġ���� ����
			else break;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
#endif

/*<�� ����>
�� ������ �պ����İ� �Բ� ���� ���� �˰��� �� �ϳ��̴�.
�ٽ��� 1. �ǹ� 2. ���� 3. ��� �̴�.
1. �ǹ��� ������ �Ǵ� ���ҷ� �Ϲ������� ù��° ���Ұ� �ǹ��̵Ǹ�, ���� �ε����� ������ �ε�����
���ÿ� �����δ�. �ǹ��� �������� �ǹ����� ū���Ҹ� ���ʿ��� ã�� �ǹ����� ���� ���Ҹ� �����ʿ��� ã�´�.
�׷��� ã���� �� ���� ��ȯ�Ѵ�. �� ���� �� �ε����� ���� �����ϰ� �Ǹ� ��ȯ �������� ù��° �����
�ǹ��� �����ʺ��� ã�ƿ� ���� ���� ��ȯ���Ѵ�. �ǹ��� ã�ư� �ڸ��� ���ʿ��� �ǹ����� ���� �������̰�
�������� �ǹ����� ���� ū���� ���� �ȴ�.
2. ���������� �ǹ��� �������� ������ �� ���̴�. ���ʿ��� ������ �����ʿ��� �������� �̷�������Ѵ�.
3. ��Ϳ��� �ݵ�� ���������� �־�� �Ѵ�. ���� �������� �����Ϸ��� �������� ������ 1�����
�����ϴ� ������� ¥�� �ϼ�.
*/
#if 0
#include<iostream>
#include<vector>
using namespace std;

vector<int> arr = { 7,5,9,0,3,1,6,2,4,8 };
void quickSort( int ln, int rn) {
	if (ln >= rn) {
		return;
	}
	int lp = ln + 1;
	int rp = rn;
	while (true) {
		while (lp<=rn&&arr[lp] <= arr[ln]){
			//arr[lp]�� �ǹ����� ū ��쿡 �ݺ� ����
			lp++;
		}
		while (rp>ln&&arr[rp] >= arr[ln]){
			 //arr[rp]�� �ǹ����� ���� ��쿡 �ݺ� ����
			rp--;
		}
		if (lp > rp) {
			swap(arr[ln], arr[rp]);
			break;
		}
		else {
			swap(arr[lp], arr[rp]);
		}
	}
	quickSort( ln, rp-1);
	quickSort( rp + 1, rn);
	return;
}
int main()
{
	
	quickSort( 0, arr.size()-1);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}
#endif
//����(����)
//�ε��� ������ ��� ���� �߰� �߰� ��ȯ���� �ʴ� ������ �߻�
//
//���� üũ �������� ������ ����. ���������� ���ؼ��� ���� ������ �ʾҴ�.
//å�� ������ ������ ���� ���� ¥�� ������ �ݺ��Ǿ���. õõ�� ������� �ϸ� ������ �� ���� ���µ�, �׳� ���α׷��� ������
//���� �ʰ� ������ ���� �����̴�.
//for���� ����ϸ� �������� ������ ���� while������ �ٲپ ������ ���� �ʰ� ������ ����.
//
//���������� �ǹ��� ��ȯ�ϴ� �ε����� right �ε����̴�. �� right �ε����� �׷��� start �ε������� ���� �۾������� �ȵȴ�.
//������ left�ε����� �ٸ���. left�� ������ �ε������� Ŀ���� �� ���� �ִ°�? �׷���. �ݵ�� Ŀ���� �Ѵ�. �������
// 6 7 ¥���� ����. start=0 end=1 left=1 right=1 �̴�. �̶� left�� right�� �Ѿ�� �ʴ´ٸ� ������� �ʴ´�. �׷��⿡ 
//left�� ������ �Ѿ �ǰ� right�� ������ ���� ���� �����ؾ��Ѵ�.

/*å 6.4 ������*/
#if 0
#include<vector>
#include<iostream>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

void quickSort(int* arr, int start, int end) { //������ �Ű������� ���� �� �̸��� �ּҸ� ã�ư��� ����� �Ŷ�� ��
	if (start >= end) return; // ���Ұ� 1���� ��� ����
	//start�� end���� Ŀ���� ��찡 ������?
	//������ start == end �ϰ� �Ǹ� ���� ��͸� Ż�� �� �� ����. �ֳ��ϸ�
	//���� ���� ��͸� ��ȯ�ϴ°� right-1�� right +1 �� �ϱ� ����.
	//������� 2��¥�� �迭���� �ǹ��� 1�ε����� ���ԵǾ� �����Ͽ� ������ ȣ���ϰ� �ɰ��
	//quickSort(arr, 0, 1-1); quickSort(arr, 1+1, 1); �� �Ǵµ� �̶� �����ʺκ� ȣ�⿡�� Ŀ���� �ȴ�.

	int pivot = start; // �ǹ��� ù ��° ����
	int left = start + 1;
	int right = end;
	//��������� ���� �� �Ͱ� ����.

	while (left <= right) {
		//�ݺ����� ���ǵ� ���� ������. left�� right�� ������ �Ѿ�� ����.

		// �ǹ����� ū �����͸� ã�� ������ �ݺ�
		while (left <= end && arr[left] <= arr[pivot]) left++;
		//������� �������ϰ� �ٸ���. ���� left < end ������ �ݺ��߰�, arr[left] > arr[pivot]�̸� �����ϴ� ������ ����.
		//�� end�� ���� �ε������� �ݺ��� ����������? ������ ���ҵ� ���� ����̱� �����̴�. ���� ������ ���Ҹ� ������ ������
		//���� �����÷θ� �ν��� ��ó������ �������� �����̾���. ���� left�� end �̻��� �Ѿ �������� �ʰ� �ȴ�.

		// �ǹ����� ���� �����͸� ã�� ������ �ݺ�
		while (right > start && arr[right] >= arr[pivot]) right--;

		// �����ȴٸ� ���� �����Ϳ� �ǹ��� ��ü
		if (left > right) swap(arr[pivot], arr[right]);
		// �������� �ʾҴٸ� ���� �����Ϳ� ū �����͸� ��ü
		else swap(arr[left], arr[right]);
		//��������� ������ ����.
	}
	// ���� ���� ���� �κа� ������ �κп��� ���� ���� ����
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);
	//���⼭ ���� right�� �ƴ� left�� �ǹ��� ���´ٰ� �����ؼ� ������ �Ǽ��� �־���.

	//������� ���� �� ������ �̻��ϰ� ���� �����÷ο� ������ �߻��Ѵ�.
}

int main(void) {
	quickSort(arr, 0, n - 1); //�����ϰ����ϴ� �迭, ù��° �ε���, ������ �ε���
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
#endif

/*��� ����
������ �����ϴ�. ������������ �迭�� ������ 0~ �ִ밪���� ������ ������ �ִٸ�, �ִ밪+1���� ��Ҹ� ���� �˻縮��Ʈ�� �����ϰ�
�־��� �迭�� 0�ε������� ���̱��� Ž���ϸ鼭 ���� ����ִ� ���� �˻縮��Ʈ�� �ε����� ����Ͽ� ī��Ʈ�� '���'�Ѵ�.
�׷��� ī��Ʈ ���� ��� ���� �̴�.
�־��� �迭�� ����Ž���ϴ� N, ������ŭ ����� ������ �ִ� �������Ʈ ����Ž�� K�� Ž���ϸ鼭 �� �ε����� ��Ұ��� �ε��� ������ �Ǿ� ���

������ �������⵵������ŭ�� �����ο�� ���� ���� �������Ʈ ��ü�� �ʿ��ϱ� �����̴�.
�׸���, ���� �ڷ������� ������ �����ϸ�, �ִ밪�� �ּҰ��� ������ Ŭ ���� �׷��� ����� ������ ���� ���� ��ȿ�������� ����ȴ�.
�ֳ��ϸ� n+k ��ŭ�� �ð����⵵�� ���µ�, n�������� ������ �� Ŀ�� �� �� �ֱ� �����̴�.
*/
#if 0
#include<vector>
#include<iostream>
using namespace std;
auto countSort(vector<int> arr) {
	cout << "0~�ִ밪�� �迭�� �����ϴ� ��� ����" << endl;
	cout << "�ִ밪�� �Է��ϼ���." << endl;
	int k = 0;
	cin >> k;
	vector<int> array(k + 1);
	vector<int> result;
	for (auto n : arr) {
		array[n]++;
	}
	for (int i = 0; i < k + 1; i++) {
		if (array[i] != 0) {
			for (int j = 0; j < array[i]; j++) {
				result.push_back(i);
			}
		}
	}
	return result;
}

int main() {
	vector<int> arr = { 7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2 };
	auto arr2 = countSort(arr);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < arr2.size(); i++) {
		cout << arr2[i] << ' ';
	}
}
#endif
/*C++�� sort�� �˰��� ���̺귯���� �ִ�.
*/
#if 0
#include<iostream>
#include<algorithm>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main(void) {
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
#endif
/*�ڵ� �׽�Ʈ���� ���� �˰����� ���Ǵ� ���
1. ���� ���̺귯���� ����ؼ� Ǫ�� ����
2. ���� �˰����� ������ ���� ����� ����
3. �� ���� ������ �ʿ��� ����*/

/*<2> ������ �Ʒ���
�ϳ��� �������� �پ��� ���� �����Ѵ�. �̷��� ���� ũ�⿡ ������� �����Ǿ� �ִ�. �� ���� ū �� ���� ���� ���� ������
�����ؾ� �Ѵ�. ������ ������������ �����ϴ� ���α׷��� ����ÿ�.
�Է�����: ù°�ٿ� ������ ���� �ִ� ���� ���� N�� �־�����. 500����
��° �ٿ� N+1��° �ٱ��� N���� ���� �Էµȴ�. ���� ������ �ʸ������� �ڿ����̴�.
�������: ������ ������������ ���ĵ� ����� �������� ���. ������ ���� ������ �����Ӱ� ���
�Է¿���
3
15
27
12
��¿���
27 15 12

<���ٹ��>
���������� ��� �������� �ݴ�� �Ѵ�. 1.�������� 2.�������� 3.������ 4.�˰��� ���̺귯��
*/

//1.��������
// ������ �ӵ��� �ݺ�, ���ĵ��� ���� �κа� ���ĵ� �κ����� �����ǰ� ���� �ϳ��� �������� 
// �ִ밪�� ã�Ƽ� �ϳ��� ��ȯ�� ������ �ذ�
#if 0
#include<iostream>
#include<vector>
using namespace std;

auto selectSort(vector<int> arr) {
	vector<int> answer = arr;
	int maxIdx;
	for (int i = 0; i < arr.size(); i++) { //������ �ε��� �ϳ��� ����
		maxIdx = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (answer[j] > answer[maxIdx]) {
				maxIdx = j;
			}
		}//���� �ݺ����� ������ i�ε����� ������ maxidx�� ��ȯ�Ѵ�.
		swap(answer[i], answer[maxIdx]);
	}
	return answer;
}

int main() {
	int N;
	cout << "��� ����" << endl;
	cin >> N;
	cout << "���ʴ�� ���� �Է�" << endl;
	vector<int> arr(N);
	for (auto &n : arr) {
		cin >> n;
	}
	auto result = selectSort(arr);

	for (auto n : result) {
		cout << n << ' ';
	}

}
#endif
//����
//�����Լ����� ������ �迭�� �Լ��� ���ڷ� ������ �������� �ƴ� ���������� �������⶧���� ����� ������ ��� ����������
//�ٲ�������� ���� �߰��� ����Ʈ�� ���� ��ȯ�ϰ� ����.
//���� �ڷ����� �Ⱦ��� �������� �迭�� �����ϴ� ����� ���� �� �𸣰���.

//2. ��������
//�������İ� ��������� ���ĵ� �κа� ���ĵ��� ���� �κ��� �����ٴ� ��.
//ó�� �����Ҷ� �� ���� �ε����� ���ĵǾ� �ִ°����� ���� ���� 1���� �����Ѵ�. 1�� ����� 0�� ������� ������ ū���� ���Ͽ�
//�۴ٸ� swap ���� �ʴٸ� �ű⼭ ���� ��? ���ĵǾ��ִ� �κп��� �̹� ���ĵǾ� ���ϰ� �Ǿ���.
//�� ������� ������������ �ٲ�.
#if 0
#include<iostream>
#include<vector>
using namespace std;

auto insertSort(vector<int> arr) {
	vector<int> answer =arr;
	for (int i = 1; i < arr.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (answer[j] > answer[j - 1]) {
				swap(answer[j], answer[j - 1]);
			}
			else {
				break;
			}
		}
	}
	return answer;
}

int main() {
	int N;
	cout << "��� ����" << endl;
	cin >> N;
	cout << "���ʴ�� ���� �Է�" << endl;
	vector<int> arr(N);
	for (auto& n : arr) {
		cin >> n;
	}
	auto result = insertSort(arr);

	for (auto n : result) {
		cout << n << ' ';
	}
}
#endif

//3. ������
//ù��° ��Ҹ� �ǹ����� ���ϰ� �����ε����� �ǹ������� ū ��Ҹ� ã�������� �����ϰ� �������ε����� �ǹ������� ���� ��Ҹ� 
//ã�������� �����ϸ鼭 �׷��� �ݺ��� ������ ���� �ε����� �������ε����� ��. �̶� ������ �����ʺ��� Ŀ������ �ǹ����� ���� �����
//�����ʰ��� �ǹ����� ��ȯ�ϰ�, ������ �ε����� �������� ���� ������ ��͸� ȣ���Ѵ�.
//�̶� ��ȯ�ϴ� �����ʰ��� �ε��� �ʰ��� �Ͼ�� �ȵǰ�, ���� �ε����� �����ʺ��� Ŀ���ߵǴ°� ���� �����̹Ƿ� �ε��������ʰ����
//�̰� ������������
#if 0
#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> answer;
vector<int> arr;

void quickSort(int start, int end) {
	if (start >= end) {
		return;
	}

	int left = start + 1;
	int right = end;
	int pivot = start;

	while (left <= right) {
		while (left <= end &&arr[left] >= arr[pivot]) { 
			//������������ �����ؾ��ϱ⿡ ���ʿ� ū���� �;ߵ�. ���� ���������� �ݺ�
			//�׷��� ���ʰ��� �ǹ����� ���ؼ� ���ʰ��� �� ũ�ٸ� �׳� �����İ���. �ֳ��ϸ� �������� ���������� �ѰܾߵǼ�
			left++;
		}
		while (right > start &&arr[right] <= arr[pivot]) {
			//�׷��� �ݺ������� ���� ���񱳸� �ϸ� �Ǵ°� �ƴϴ�. ���ѹݺ��� �����÷ο츦
			//�����ϱ� ���� �߰� ���������� �־���ߵȴ�. �ٷ� �ε��� ���� üũ�̴�. �׷��� ��ȯ�ϴ°� �ǹ����� ū����
			//����Ű�� right�� �ٲܰ��̱⶧���� right �ε����� ������ 1�� �� ���̴°ɷ� ����.
			right--;
		}
		if (left > right) {
			swap(arr[pivot], arr[right]);
		}
		else {
			swap(arr[left], arr[right]);
		}
	}
	quickSort( start, right - 1);
	quickSort( right + 1, end);

	return;
}

int main() {
	cout << "��� ����" << endl;
	cin >> N;
	cout << "���ʴ�� ���� �Է�" << endl;
	vector<int>temp(N);
	arr = temp;
	for (auto& n : arr) {
		cin >> n;
	}
    quickSort( 0, N-1);

	for (auto n : arr) {
		cout << n << ' ';
	}
}
#endif
/*����
left++ right--���� �ް���
*/

//4. �˰��� ���̺귯��
// �˰��� ���̺귯���� sort�Լ� ���, ���⿡ ���о� �Լ��� �����ؼ� Ŀ���͸���¡ �� �� �ִ�.
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> answer;
vector<int> arr;

//���������� ���� ���о� �Լ�
bool comp(int a, int b) {
	return a > b;
}

int main() {
	cout << "��� ����" << endl;
	cin >> N;
	cout << "���ʴ�� ���� �Է�" << endl;
	vector<int>temp(N);
	arr = temp;
	for (auto& n : arr) {
		cin >> n;
	}
	sort(arr.begin(), arr.end(), comp);

	for (auto n : arr) {
		cout << n << ' ';
	}
}
#endif

/*<3> ������ ���� ������ �л� ����ϱ�
N���� �л� ������ �ִ�. �л� ������ �л��� �̸��� �л��� �������� ���еȴ�. 
�� �л��� �̸��� ���� ������ �־����� �� ������ ���� ������� �л��� �̸��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�����
ù° �ٿ� �л��� �� N�� �Էµȴ�. �ʸ�����
��³ N+1° �ٱ��� �л��� �̸��� ��Ÿ���� ���ڿ� A�� �л��� ������ ��Ÿ���� ���� B�� �������� ���еǾ� �Էµȴ�.
���ڿ� A�� ���̿� �л��� ������ 100������ �ڿ����̴�.
�������
������ ���� ������� ����Ѵ�. ������ ������ �л����� ������ �����Ӱ� ���

<���ٹ��>
�̸��� ������ ���輺�� ������� ���°� �ʿ��ϴ�. pair �ڷ��� map �ڷ��� ���� �ִµ� ���⼭�� pair�� ����ҵ�
�׷����ؼ� 1.�������� 2.�������� 3.������ 4.sort���̺귯��
*/
//1.��������
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;

auto selectSort(vector<pair<string, int>> &(stScore)) { //������ �Ű������� ������
	for (int i = 0; i < stScore.size(); i++) {
		int min = INT_MAX;
		int minIdx = 0;
		for (int j = i; j < stScore.size(); j++) {
			if (stScore[j].second < min) {
				min = stScore[j].second;
				minIdx = j;
			}
		}
		swap(stScore[i], stScore[minIdx]);
	}

	return;
}

int main() {
	int N;
	cout << "������ ���� N�� �Է��϶�: ";
	cin >> N;
	vector<pair<string, int>> stScore(N);
	cout << "�л� �̸��� ������ �������� �����Ͽ� �Է��ϰ� �� ���Ҵ� ���ͷ� �����Ѵ�." << endl;
	string tString;
	int tScore;
	for (int i = 0; i < stScore.size(); i++) {
		cin >> tString;		cin >> tScore;
		stScore[i].first = tString;
		stScore[i].second = tScore;
	}
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;
	selectSort(stScore);
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;

}
#endif

//2. ��������
#if 0
#include<iostream>
#include<vector>
using namespace std;

void insertSort(vector<pair<string, int>>(&stScore)) {
	int left = 0;
	int right = stScore.size() - 1;
	for (int i = 1; i < stScore.size(); i++) {
		for (int j = i; j > 0; j--) {//������ Ž���ε����� j�� --�Ұ��̴�.
			if (stScore[j].second > stScore[j - 1].second) { 
				//���� ���ĵȺκ��� Ž���ϴ� �ڱ⺸�� ���� �༮�� ������ ����
				break;
			}
			else {
				swap(stScore[j], stScore[j - 1]);
			}
		}
	}
}

int main() {
	int N;
	cout << "������ ���� N�� �Է��϶�: ";
	cin >> N;
	vector<pair<string, int>> stScore(N);
	cout << "�л� �̸��� ������ �������� �����Ͽ� �Է��ϰ� �� ���Ҵ� ���ͷ� �����Ѵ�." << endl;
	string tString;
	int tScore;
	for (int i = 0; i < stScore.size(); i++) {
		cin >> tString;		cin >> tScore;
		stScore[i].first = tString;
		stScore[i].second = tScore;
}
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;
	insertSort(stScore);
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;
}
#endif
//3. ������
#if 0
#include<iostream>
#include<vector>
using namespace std;
void quickSort(vector<pair<string, int>> (&stScore), int start, int end) {
	//���� left�� �� Ŀ��ä�� �����°� �ִٸ� �ɷ��߰���
	if (start >= end) {
		return;
	}
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right) {
		while (left <= end && stScore[pivot].second >= stScore[left].second) {
			left++;
		}
		while (right > start && stScore[pivot].second <= stScore[right].second) {
			right--;
		}
		if (left > right) {
			swap(stScore[pivot], stScore[right]);
			break;
		}
		else {
			swap(stScore[left], stScore[right]);
		}
	}
	quickSort(stScore, start, right - 1);
	quickSort(stScore, right + 1, end);
}

int main() {
	int N;
	cout << "������ ���� N�� �Է��϶�: ";
	cin >> N;
	vector<pair<string, int>> stScore(N);
	cout << "�л� �̸��� ������ �������� �����Ͽ� �Է��ϰ� �� ���Ҵ� ���ͷ� �����Ѵ�." << endl;
	string tString;
	int tScore;
	for (int i = 0; i < stScore.size(); i++) {
		cin >> tString;		cin >> tScore;
		stScore[i].first = tString;
		stScore[i].second = tScore;
}
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;
	quickSort(stScore, 0 , N-1);
	for (int i = 0; i < stScore.size(); i++) {
		cout << stScore[i].first << ' ';
	}
	cout << endl;
}
#endif
//4. sort���̺귯��
#if 0
#include<iostream>
#include<vector>
using namespace std;
int main() {

}
#endif