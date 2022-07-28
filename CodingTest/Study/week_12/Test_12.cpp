//1��
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
#include <iostream>
#include <algorithm>

using namespace std;

//vector pair find_if �����ڷ� https://velog.io/@neity16/Programers-%EC%BA%90%EC%8B%9C-findif
string fstr = "";
bool findValue(pair<string, int> a) {
    if (a.first == fstr) return true;
    return false;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> inVector;
    vector<pair<string, int>> outVector;
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
            fstr = totalData[i][1];
            int tempIdx = find_if(inVector.begin(), inVector.end(), findValue) - inVector.begin();
            //���ڿ��� �ð����
            auto hour = totalData[i][0].substr(0, totalData[i][0].find(':'));
            auto htom = atoi(hour.c_str()) * 60;
            int minute = htom + atoi(totalData[i][0].substr(totalData[i][0].find(':')).c_str());
            //�ƿ����ʹ� �ܼ��� ���� ������ �ð����� �ƴ϶� ����� �ð����� �����Ѵ�.
            //������ �ι� ���ٰ� ������ ��쵵 ����ؾ���. ���� outVector�� �̹� Ű���尡 �ִٸ� �����̰�
            //���� Ű���尡 ���ٸ� �����̴�.
            if (find_if(outVector.begin(), outVector.end(), findValue) != outVector.end()) {
                int tempIdx2 = find_if(outVector.begin(), outVector.end(), findValue) - outVector.begin();
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
            fstr = inVector[i].first;
            if (find_if(outVector.begin(), outVector.end(), findValue) != outVector.end()) {
                fstr = inVector[i].first;
                int tempIdx2 = find_if(outVector.begin(), outVector.end(), findValue) - outVector.begin();
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

//2��
// ���ǵ忡���� ��� �۾����� ���� ���Ǵµ� 100�̻��̸� ��ȯ�Ѵ�. 
// ������ �տ� ����� 100�� �Ǿ�߸� �ڿ��ŵ� ��ȯ�ȴ�.
// 
// ���� �ڷᱸ���� ���� ��� ������θ� ��ų�� ������ ����.
// �� �ڷ��� ������ 100���̹Ƿ� 3�������� �����ϴ�.
// 
// �� �� �� �� ����ɶ����� ���ǵ带 ������Ű��
// �ƴϴ� �̷��� ������ų�ʿ���� �ʿ��Ѱ� ����ȳ�¥���̴�. ������ ���ÿ��� �����鼭 ���ϸ� ���ڳ�.
// 
// <���α׷��� ���ø����> �̶� �Ųٷ� �����ؾߵǴ°� ����
// <��¥ �����Ű�鼭 �� ���� �ڷῡ ��¥*���ǵ� �Ѱ� ���ؼ� 100�̻��� �Ǵ��� Ȯ��>
// <100 �̻��̶�� pop�ϰ� ī��Ʈ �״��� �ڷῡ�� ������ ����>
// <�̶� 100 ���϶�� ī��Ʈ�� �ߴ��ϰ� �� ī��Ʈ�� ���� �迭�� ��ȯ>
// <���������� 100 �̻��� ��� �ȴٸ� pop�� ����ϸ� ī��Ʈ ����>
//
#if 0
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> proStack;
    int date = 0;
    int cnt = 0;
    int idx = 0;
    bool ret = false;

    //<���� �����> �̶� �Ųٷ� �����Ѵ�.
    for (int i = progresses.size()-1; i >= 0; i--) {
        proStack.push(progresses[i]);
    }
    //<��¥ ����>
    while (!proStack.empty()) {
        date++;
        //<������ ������ �ڷῡ �� �´� �������� ���ؼ� �װ� 100 �̻����� üũ>
        while(proStack.top() + date * speeds[idx] >= 100) {
            idx++;
            //�̷��� ���鶧�� �������� �ϳ� �߰ߵǾ���. idx�� �ϳ� �����ϴ� ������ �������� ������
            //�������� üũ�� ���� �����÷ο� ������ �߰ߵ�. while�� �ǳ��� ���� idx�� size()-1���� Ŀ����
            //�˻���� ������ ���������� ������ �ϳ� �߰��ϴ°����� �ذ�
            cnt++;
            proStack.pop();
            ret = true;
            if (idx > speeds.size() - 1) break;
        }
        if (ret) {
            answer.push_back(cnt);
            cnt = 0;
            ret = false;
        }       
    }

    return answer;
}

int main()
{
    vector<int> progresses1 = { 93, 30, 55 };
    vector<int> progresses2 = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds1 = { 1, 30, 5 };
    vector<int> speeds2 = { 1,1,1,1,1,1 };

    auto result = solution(progresses1, speeds1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    result = solution(progresses2, speeds2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
#endif
//����
// �׻� ���״� ����üũ �������� ����ϰ� ���°� ����.
// �۾��� ������ 100�� ������ ��ŭ ���� ������ �̿��ؼ� üũ�ϴ°͵� ������ �������� ����.
// ���� ����. �ٱ��ʿ��� �ð��� ���ư��� ���ʿ��� �ε����� �����ϴ� ����̴�.
//