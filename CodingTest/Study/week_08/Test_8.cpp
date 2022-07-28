//1��
// Collatz�� ����
// �ݺ�Ƚ�� 500���� �Ѿ�� -1 ����
//
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;
    while (num != 1) {
        if (answer > 500) {
            answer = -1;    break;
        }
        if (num % 2 == 0) num /= 2;
        else if(num %2 ==1) num = num * 3 + 1;
        answer++;
    }
    return answer;
}
int main() 
{
    vector<int> n = { 6, 16, 626331 };
    for (int i = 0; i < n.size(); i++) {
        cout << solution(n[i]) << endl;
    }
}
#endif

//2��
//������� �ΰ��� ���ļ� ���ڿ� �迭�� ��ȯ�Ѵ�. 
//10���� �迭�� �־����� 2������Ʈ�� �ٲ۵ڿ� 1�� # 0�� ��ĭ
//�� ���� ��ĥ�� ��¥ ������ �̷�����°� �ƴ϶� ��Ʈ or ������ �̷������.
//c++�� ��Ʈ ���� https://boycoding.tistory.com/163
//���� for���ε� �ٱ��� n�� ������ logn�� n�� 16 ���� �鸸����. ���ڿ����� �����¿��� n�� 16*16*4 = 1024
//c++ ���ڿ� �Ųٷ� reverse�Լ� https://blockdmask.tistory.com/363
// https://marobiana.tistory.com/159

//2��°�õ�
// int�� �ڷ� �ΰ��� ��Ʈ�� ������ �����ϸ� ���� �� �� �˾Ҵµ� �ȵǳ�?
// test�� �غ��� �Ǵ� ���� Ȯ��
//

#if 0
#include <string>
#include <vector>
#include<iostream>

using namespace std;

string reverse(string s) { 
    string answer ="";
    for (int i = s.size()-1; i >= 0; i--) {
        answer += s[i];
    }
    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    //vector<string> answer(n); 
    vector<string> answer;
    string s = "";

    for (int i = 0; i < n; i++) {
        auto a = arr1[i] | arr2[i]; //bitset ���� 
        //string s=""; 
        //���� ���� �ݺ��� ������ ��� s�� �ʱ�ȭ �ɰŴϱ� �̷��� �ȵ�
        for (int j = 0; j < n; j++) {
            //���� a�� 0�̶�� �׳� �˾Ƽ� �������� ���� 0�̶� ��ĭ �߰��Ұ�
            if (a % 2 == 1) s.push_back('#');
            else s.push_back(' ');
            a /= 2;
        }
        //���� �ݺ����� ������ ������� s�� �Ųٷ��Ͽ� answer�� ��ȯ
        answer.push_back(reverse(s)); //reverse ����
        s = "";
    }
    return answer;

}

int main(void)
{
    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = { 30, 1,21,17,28 };

    auto s = solution(n, arr1, arr2);
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }

}
//����
// �������� ũ�� ������ �����µ� �ڲ� ���������� ��������� �ذ�
// ������ ���ڿ��� ���ϴ� ���ڵ��� �߰��� �ȵǴ� ������ �߻�
// �÷��� �����ڷ� ���ڸ� �߰��ϸ� ���� �Ǵµ� �� �ȵǴ��� �ǹ�������, push_back���� �ذ�
#endif

#if 0   //test
#include <iostream>
using namespace std;
int main() {
    int n = 18, m = 17;
    auto s = n | m;
    cout << s;
}
#endif




//3��
// ������ȣ�� Ű���� ���� - ������ �ð���. 
// �ð��� - �⺻�ð� = �߰��ð�
// ������� = �⺻��� + �߰��ð�/10*�������
// �ʰ��ð��� �ø��Ѵ�. 2*�������
// 
// ������ȣ�� �������� �������� ������ ������� ���� �迭 ��ȯ
// �� �ð��� 60�� 24�ô� 1440�� 05:34�� 334 ���� �ð��� ��(int)�� ȯ��
// IN�� ��쿡 inVector�� ������ȣ�� Ű����� ����ð��� ������ ȯ���Ѱ� �߰�
// Out�� ��쿡 outVector�� ������ȣ�� Ű����� inVector�� ����� �ð��� �� �ð��� �߰�
// inVector�� Ű���� ��Ҵ� �����.
// ���� record n��Ž�簡 ������ inVector�� ��Ұ� �����ִٸ� outVector�� 23:59�� ���ð��� �߰�
// ������ȣ ������ outVector�� �����ϰ� �ð���Ҹ� answer���Ϳ� ��ȯ
// 
// �ݺ�Ƚ�� n=1000, ���� records ���� 3ȸ, 
// 
// ���ڿ� ��ĭ �������� �����ϱ� substr() https://starrykss.tistory.com/1546
// <sstream> https://seoyeonkk.tistory.com/entry/C-%EA%B3%B5%EB%B0%B1-%EA%B8%B0%EC%A4%80-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%9E%90%EB%A5%B4%EA%B8%B0split
// getline() https://greenapple16.tistory.com/219
// ���� �� �ڼ��� ���� https://chbuljumeok1997.tistory.com/42
// 
// string to int https://psychoria.tistory.com/709
// https://godog.tistory.com/entry/C-string-to-int-int-to-string-%ED%98%95%EB%B3%80%ED%99%98-%ED%95%98%EA%B8%B0

// 2�� �õ�
// 1. <���ڿ� �ڸ���>
// substr() �Լ��� Ȱ���Ͽ� �ڸ���. ���ڵ�迭 �� ���Ҵ� ���ڿ�. �׸��� �� �ǹ��ִ� ���е���
// �������� �����Ǿ�����. ������ �������� �� 3���� �ܾ �����ؾ���.
// string space_delimiter = " ";
// vector<string> words{};
//
// size_t pos = 0;
// ������ ������ �ε����� ã�� �����Ҷ� �� ������ �������� �ʾҴٸ� �ݺ�
// while ((pos = text.find(space_delimiter)) != string::npos) {
//      //0�ε������� ���� �ε���������ŭ ©�� ��ȯ�ϸ� ������ �ε��� ������ ©��� �����.
//     words.push_back(text.substr(0, pos));
//      //0�ε������� ���� �ε���������ŭ ����°ǵ� ���⼭ �ڿ� ���ϴ� ���ڴ� 1�̴�. 
//      //���� ������� ���ԵǾ� �����ȴ�. ���� ������ ���̰� 1���� �ƴ϶� 2��¥����� 2������ ����Ŵ�.
//     text.erase(0, pos + space_delimiter.length());
// }
// 
// 2. <�ð� ȯ��>
// �׷��� �߶� ������ ���ڿ� �迭�� �� ���ڵ� ���̸�ŭ ���ܼ� 2���� �迭ó�� ������ ������̴�.
// ù��° ����� �ð��� �ٽ� ':' �� �������� �����Ͽ� �д��� �ð����� ȯ���� �ʿ䰡 �ִ�.
// 
// auto hour = words[i].substr(0, words[i].find(':'));
// auto htom = atoi(hour.c_str()) * 60;
// int minute = htom + atoi(words[i].substr(words[i].find(':')).c_str());
// 
// 3. <����ȣ Ű����>
// �ι�° ������ȣ�� �� ������ ���ð��� ����Ҷ� ���̴� �ֿ� Ű���� ������ �Ұ�.
// Ű���� ��ųʸ��� �ڷ����� pair �ڷ����� ���ҷ� ���� ���̴�.
// 
// 4. <IN OUT ����>
// ����1° ���ڿ��� IN OUT���� �����Ͽ� IN�϶��� ����ְ� OUT�϶� OUT�ð���� IN�ð��븦 ����
// ���ð��� ����ؾߵȴ�.
// 
// 5.<inVector outVector �����>
// IN�� ��쿡 inVector�� ������ȣ�� Ű����� ����ð��� ������ ȯ���Ѱ� �߰�
// Out�� ��쿡 outVector�� ������ȣ�� Ű����� inVector�� ����� �ð��� �� �ð��� �߰�
// inVector�� Ű���� ��Ҵ� �����.
// ���� record n��Ž�簡 ������ inVector�� ��Ұ� �����ִٸ� outVector�� 23:59�� ���ð��� �߰�
// ������ȣ ������ outVector�� �����ϰ� �ð���Ҹ� answer���Ϳ� ��ȯ
// 
// find()�Լ� ���� ���� https://9x211x2.tistory.com/17
// IN OUT �Ҷ� �ʿ���.
// 
// string::npos �� �ǹ� https://mg729.github.io/c++/2019/11/03/C++_string_npos/
// substr()���� ������ �������� �ܾ� �߶� �迭�� �����ϱ�
// https://www.delftstack.com/ko/howto/cpp/cpp-split-string-by-space/
//
#if 0
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

//string str = "Enter id1234 Muzi";//������ ���� string�� �ִٰ�����.
//istringstream ss(str);//istringstream ss ������ string ���� as�� �ʱ�ȭ�Ѵ�.
//string buff;
//while (getline(ss, buff, ' '))//ss stream �������� ' '(����)���� �Է����� �޾Ƶ��δ�.
//{
//    // getline���� �о���� ���� buff�� ������ ����Ѵ�.
//    cout << buff << endl;
//}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> inVector;
    vector<pair<string, int>> outVector;

    //for (int i = 0; i < records.size(); i++) {
    //    vector<string> temp;
    //    int j = 0;
    //    istringstream ss(records[i]);
    //    while (getline(ss, temp[j], ' '))//ss stream �������� ' '(����)���� �Է����� �޾Ƶ��δ�.
    //    {
    //        cout << temp[j] << endl;
    //        j++;
    //    }
    //    if (temp[2] == "IN") {

    //        inVector.push_back(make_pair((stoi(temp[1]), stoi(temp[1])));
    //    }
    //}

    vector<vector<string>> totalData;
    vector<string> words;
    string space_delimiter = " ";
    size_t pos = 0;

    //<���ڵ� �߶� ������� 2���� ����>
    for (int i = 0; i < records.size(); i++) {
        //������ ������ �ε����� ã�� �����Ҷ� �� ������ �������� �ʾҴٸ� �ݺ�
        while ((pos = records[i].find(space_delimiter)) != string::npos) {
        //0�ε������� ���� �ε���������ŭ ©�� ��ȯ�ϸ� ������ �ε��� ������ ©��� �����.
            words.push_back(records[i].substr(0, pos));
      //0�ε������� ���� �ε���������ŭ ����°ǵ� ���⼭ �ڿ� ���ϴ� ���ڴ� 1�̴�. 
      //���� ������� ���ԵǾ� �����ȴ�. ���� ������ ���̰� 1���� �ƴ϶� 2��¥����� 2������ ����Ŵ�.
            records[i].erase(0, pos + space_delimiter.length());
        }
        totalData.push_back(words);
    }
    //<inVector outVector �����>
    for (int i = 0; i < totalData.size(); i++) {
        if (totalData[i][2] == "IN") {
            //���ڿ��� �ð����
            auto hour = totalData[i][0].substr(0, totalData[i][0].find(':'));
            auto htom = atoi(hour.c_str()) * 60;
            int minute = htom + atoi(totalData[i][0].substr(totalData[i][0].find(':')).c_str());

            inVector.push_back(make_pair(totalData[i][1], minute));
        }
        else if (totalData[i][2] == "OUT") {
            // �ε������� ����ϴ°� inVector�� ����� �ð����� ��ȸ�ϰ� ����ϱ����� �׸��� ���Ҹ� �����ϱ�����
            int tempIdx = find_if(inVector.begin(), inVector.end(), totalData[i][1]) - inVector.begin();
            //���ڿ��� �ð����
            auto hour = totalData[i][0].substr(0, totalData[i][0].find(':'));
            auto htom = atoi(hour.c_str()) * 60;
            int minute = htom + atoi(totalData[i][0].substr(totalData[i][0].find(':')).c_str());
            //�ƿ����ʹ� �ܼ��� ���� ������ �ð����� �ƴ϶� ����� �ð����� �����Ѵ�.
            //������ �ι� ���ٰ� ������ ��쵵 ����ؾ���. ���� outVector�� �̹� Ű���尡 �ִٸ� �����̰�
            //���� Ű���尡 ���ٸ� �����̴�.
            if (find_if(outVector.begin(), outVector.end(), totalData[i][1]) != outVector.end()) {
                int tempIdx2 = find_if(outVector.begin(), outVector.end(), totalData[i][1]) - outVector.begin();
                outVector[tempIdx2].second += minute;
            }
            else {
                outVector.push_back(make_pair(totalData[i][1], minute - inVector[tempIdx].second));
            }
            //�ƿ����Ϳ� ��� �������� �κ��Ϳ��� Ű����� ã�� �ε����� ã�ư��� ���� ����.
            inVector.erase(inVector.begin() + tempIdx);
        }
    }
    //totalData�� ������ ���鼭 in�� out���� ������ �� ���´�. �׷��� ���� inVector�� ���Ұ� �����ִٸ�
    //23:59���� ����� ������ �����Ͽ� out�� ������ �ϵ� ������ �ϵ� �Ѵ�.
    //<���� inVector ó��>
    if (!inVector.empty()) {
        for (int i = 0; i < inVector.size(); i++) {
            //�ִ�ð� - inVector�� ��ϵ� �ð�
            int minute = 23 * 60 + 59 - inVector[i].second;
            if (find_if(outVector.begin(), outVector.end(), inVector[i]) != outVector.end()) {
                int tempIdx2 = find_if(outVector.begin(), outVector.end(), inVector[i]) - outVector.begin();
                outVector[tempIdx2].second += minute;
            }
            else {
                outVector.push_back(make_pair(totalData[i][1], minute));
            }
        }
    }
    //<outVector�� Ȱ���ؼ� �����ϰ�, �������� ���ð��� fees ���ǥ�� �°� ����Ͽ� answer�� ��ȯ>
    sort(outVector.begin(), outVector.end());
    //�⺻�ð� �ʰ��п� ���ؼ� �д� �ʰ� ����� ���ȴ�.
    for (int i = 0; i < outVector.size(); i++) {
        if (outVector[i].second < fees[0]) {
            answer[i] = fees[1];
        }
        else {
            answer[i] = fees[1] + ((outVector[i].second - fees[0]) / fees[2]) * fees[3];
            if ((outVector[i].second - fees[0]) % fees[2] != 0) {
                answer[i] += fees[3];
            }
        }        
    }

    return answer;
}
int main() {
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = { "05:34 5961 IN","06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT",
    "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

    auto result = solution(fees, records);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

}

#endif

