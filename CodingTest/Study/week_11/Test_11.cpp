//1��
// Ÿ�ٳѹ� �����
// �ѹ��迭�� �Է±��̴� 20�� �̹Ƿ� �ݺ�Ƚ���� ��� ������� ��� ����� ���� �� ���ϴ� �ݺ����� ������.
// �� ���ڸ��� ����� ���� 2���� + �� - �� ����� ���� 2�� n�� ���� 2�� 20���� 2�� 10���� �����̴ϱ� ���� �� �鸸
// 
// ����ؾ� �������� ��� ����� ���� ���� �� �������� �� �𸣰ڴ�.
// 
// -��õ�-
// ���ϰ� ������ ��Ģ�� �������� �ʾҴ�. �׳� ����⸸ �ϸ� �ȴ�. �ѹ��� ������ ���Ѵ����� 
// Ÿ���� ��������� �󸶸� ���ߵǴ����� ���ϰ� ���⸦ ����� ����� ���� ���ϴ� ������� �Ѵٸ�? �����Ѱ� ����Ұ� ������
// ���� ����� Ȯ���Ұ� ����. ������� 4�� ����� ���� ���տ��� ���� ������ �ϸ� �Ǵ� ������ �����
// ù��° �ε����� ���ٽÿ� �� ù��° ���� ������ ������ � �ε������� ������ �������� ����� 
// �ι�° �ε����� �����ؼ� ���������� �ذ� �� �� �ִٸ�....
// -������-
// �� �������� Ʋ�� ������ �ִ�. ���ϴ°Ͱ� ���� ���� ������ �ƴϴ�. ���� ���ÿ� �� ���ڴ� �������� ���ڿ��� ������ �ȴ�.
// ��� ���Ұ� ���� ����� ������ �ִٸ� �̰� ������� ��Ģ�� ��������� ������ �� �ٸ� �����̹Ƿ� �� ���ڸ��� ���ܸ� �����ϱ� �ʹ� �����.
// 
// -��õ�-
// �����ΰ�?
// 
// <�ͺ�HINT>
// ��ͷ� Ǫ�°Ŵ�. ��ʹ� 1. Ż������ 2. �ݺ��ϰ��� �ϴµ� ���ϴ� ��� �� �ʼ�.
//
#if 0
#include <string>
#include <vector>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sTarget = 0;
    int temp = 0;
    sort(numbers.begin(), numbers.end());
    //vector<int> tempNum(numbers);

    //for (int i = 0; i < numbers.size(); i++) {//20ȸ
    //    sTarget += numbers[i];
    //}
    //sTarget -= target; //�̾Ƽ� ������ �ϴ� ���� ������.

    //for (int i = 0; i < numbers.size(); i++) {
    //    if(numbers[i] == sTarget)
    //}
    for (int j = 1; j <= numbers.size(); j++) {// ���̳ʽ��� ���� ��ȣ�� ������ ����� �ݺ���
        vector<int> tempNum(numbers);
        // �ѹ� �迭�� �༮�� �߿� ��� ������ �����ϴ� �Լ��� �ʿ���. ���� ������� ���°� ���� ������� ���°� ����
        // ���⼭�� ������ �ٲ��� �ʴ´ٰ� ������ �� ���� �� ���� ���� ����� ������ ������ �ڸ��� ����Ͽ� �� �ڸ��� �߿��ϴٴ� ���� �����ϱ� ����?
        // ����... https://mjmjmj98.tistory.com/38
        //

        vector<int> tempVector;

        for (int i = 0; i < j; i++) //j�� �����ϸ鼭 -�� �� �༮���� ���� �����ϰ� �ɰ�
        {
            tempVector.push_back(1);
        }

        for (int i = 0; i < numbers.size() - j; i++)
        {
            tempVector.push_back(0);
        }

        sort(tempVector.begin(), tempVector.end());

        do
        {
            for (int i = 0; i < tempVector.size(); i++)
            {
                if (tempVector[i] == 1)
                { // ������ ���
                    cout << numbers[i] << " ";
                }
            }

            cout << endl;

        } while (next_permutation(tempVector.begin(), tempVector.end()));

        for (int i = 0; i < numbers.size(); i++) {//���ϴ� �ݺ���
            temp += tempNum[i];
        }
        if (temp == target) {//���ؼ� ī��Ʈ
            answer++;
            temp = 0;
        }
    }



    return answer;
}
#endif

//2��
// ���� ���ĺ�(A)�� Ÿ�� ���ĺ� ���� �Ÿ� ����� ������ ����������. ������ ����� ����ť ������ �̿��� �� ������ ����.
// Ȥ�� ������ ��� ������ A�� ������ �ϱ� ������ A~Z������ �Ÿ��� ���߶� ����� �ϰ� �� �Ÿ����� Ŀ���� �Ʒ��� ������ �ϰ�
// �� �Ÿ����� �۴ٸ� ���� ������ �Ͽ� �Ÿ� ��� �ϴ� ��ĵ� �ִ�.
// 
// ���������� ���� �������� ������ �������� �����Ѱ� ������ ù��° ��ġ���� ������ �ϱ� ������ ù��°�� �������� �˻��ؼ� 
// �������� �� �ʿ䰡 ���ٴ� �Ǵ��� ��� �������� ����.
// BABAZ ���� ��쿣 �޿޿��� �������� ���� ª��.
// BAABAZAAA ���� ��쿣 ������������ �޿޿޿޿޿޺��� ª�� ù��° ���� �������� �翷�� A�� ������ ����ؾߵǴ� ������ �˷��ش�.
// A�� ������ ���� �������� �̵��ϰ� �ѹ� ������ ������ �ٲ��� �ʴ´�.
// 
// �Է��� ���̴� 20���̱� ������ ���ڿ� ��ü�� �ѹ� ���ȴ°��� ������ ���� �ʴ´�.(�� �־��� ���ڿ��� A�϶��� �׳� �ƹ��͵� ���ϰ� �ε����� ����)
// �׷��� ���� ���ڿ��� �ѹ� �Ⱦ ����� ������ ī��Ʈ�� ��ȯ
// 
// <�ƽ�Ű ���>
// �ƽ�Ű �ڵ� A�� 65 Z�� 90 �̴�. ���߾��� N�� �� �Ʒ� ������� 13�� �̵��̰�, M�� ���� 12�� O�� �Ʒ��� 12���̴�.
// ������ N���� ������ Ÿ��-65�� �ϸ� �ɰ��̰� N���� ũ�� 91-Ÿ�� �ϸ� �ȴ�.
// <���� ���ϱ�>
// �ƽ�Ű ���� ���� ����� ���ÿ� �̷����� �������� ��� ���� �ص� ����� ���°� ����. 
// ������ �� ���ڸ��� ���� ����� �ؾߵǰ� ���� ����ī��Ʈ�� ��ü 20�̸��� ���̰� �߻�
// �ּ��̵� Ƚ���� ī��Ʈ�ؾ��ϴµ� ���������� ��� �ε������� ���� Ȥ�� �������� ��� �ε������� ������ ����ϴ� ������ �ʿ��ϴ�.
// name�� ù��° ���ڸ� �������� ���ʿ� �ִ�(�ǳ����� �� �Ųٷ�) A���ڿ��� ���ε����� �����ʿ� ������ A���ڿ��� ���ε����� ����Ž������ ����ϰ�
// �ε����� �̿��� ����� �ҷ��� �ߴµ� 
// -�߰��� �� ����-
// ��ü ���ڿ��� �������� ù��° ���� �������� A�� �� ���� ���� A������ ���� -1 �ϸ� �����̵� ������ ī��Ʈ �ȴ�. ���� �ε����� �̿��� �������� �ʿ� ������.
// �ε����� �� �� ������ ����� 1���� �����ϴ� ����� size()-1 ���� �����ϴ� ������� ������
// A�� �ƴ� ���ڸ� �߰��Ҷ������� ������ ī��Ʈ �� ���� �� ������ �� ū���� ���� �ȴ�.
// 
// 2�� �׽�Ʈ ���̽�
//input:LABLPAJM / answer : 61
//input : BMOABA / answer : 30
//input : LAABAA / answer : 15
//input : AAAAAAAAJAAAA / answer : 14
//input : SAAAAAARRM / answer : 41
//input : RABAMATAWADLAFAVAAE / answer : 78
//input : XAAAAAABA / answer : 6
//input : AYOZAAVADAY / answer : 35
//input : AAFEASAAVA / answer : 30
//input : UAGAAASAAFAFXZA / answer : 47
//input : AAAAZAATAEA / answer : 19
//input : AACALATLAHABAA / answer : 50
//input : FAWJAAAFV / answer : 35
//input : AACAVAAPSAAOAA / answer : 49
//input : AKAAWAKX / answer : 33
//input : LOAAAHAJAAFAEBAWO / answer : 79
//input : AWAWVAQVAAA / answer : 35
//input : RCETAAAAVUEAETZAAAK / answer : 75
//input : GTAASKKAE / answer : 52
//input : AAAABAAAAAAKSAIQ / answer : 49
//input : ADASAAAUAAAPAA / answer : 39
//input : AAAAADBAAELSPUAAAOA / answer : 70
//input : VJAAIAFNAAAAA / answer : 47
//input : AARUAUAAHTBJAAYS / answer : 69
//input : IASAGITUPHE / answer : 74
//input : AAALAAAAAA / answer : 14
//input : AAAEASAHQAYTAAAJ / answer : 60
//input : BAALEAAAPMAAAHSRAV / answer : 83
//input : ASWAAATDAJAXA / answer : 45
//input : DYAOAAAARQANAWA / answer : 66
//input : AAIAPB / answer : 24
// 
//
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int cntRA = 0, cntLA = 0;

    for (int i = 0; i < name.size(); i++) {
        if (name[i] > 'N') answer += (91 - name[i]);
        else answer += (name[i] - 65);
    }

    for (int i = 1; i < name.size(); i++) {//ù��° ���ڰ� A�ΰŴ� �ƿ� üũ�� ���� ���� ���̴�. ī������ ���װ� �ɰ� ����.
        if (name[i] == 'A') cntRA++;
        else break;
    }
    for (int i = 1; i < name.size(); i++) {
        if (name[name.size() - i] == 'A') cntLA++;
        else break;
    }

    if (cntLA > cntRA)
        answer += (name.size() - cntLA - 1);
    else
        answer += (name.size() - cntRA - 1);

    return answer;
}
int main() {
    vector<string> name = { "JEROEN" ,"JAN", "J"};
    
    for (int i = 0; i < name.size(); i++) {
        cout << solution(name[i])<<endl;
    }
    
}
//����
// �̵������� �� ���������� �Էµ� ������ Ž���� �� �ִ� ť���� �ڷ����� ��ߵɰ� ������ �ϴ� �ٸ� �ڷᱸ���� �Ⱦ��� ��Ģ������ �ذ� �� �� �־���.
//
// <�ͺ�HINT>
// 2�� 20���̴�. ��� ����� ���� ���� ���ؾ��Ѵ�.
//
#endif