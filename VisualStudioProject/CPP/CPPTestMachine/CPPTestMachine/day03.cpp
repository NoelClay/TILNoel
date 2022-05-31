#if 0 //map�� �̿��Ͽ� �غ����� ������ ���� �𸣴� ������ �������� key���� �������� ���ĵ� �ڷḦ Ȱ���ϱⰡ �������.

//�帣�� ���� ���� ����� �뷡 2���� ��Ƽ� �ٹ� ���. �뷡�� ������ȣ[�迭�� �ε���]�� ����, 
//�뷡 ���� ������ ���� ���� ����� �뷡�� ���� ����. 
//�̶� ���� �帣 2���� �� á�ٸ� �� �帣�� �ش��ϴ� ����� ���� ������ 
//�� �帣�� ������ ��� �߿��� ���Ƚ���� �� ���� �Ÿ� ã�Ƽ� �ִ´�.
#include <string>
#include <vector>
#include<iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    multimap<int, int> playsmap;//key�ߺ��� ����ϴ� ��
    map<string, int> genresmap;//string�� ���� cnt�� ��� �˻��ϰ� ó���ؾߵ��� �𸣰ھ �ᱹ �ʵΰ� �����..
    vector<int> answer;

    //���Ƚ���� ������ȣ�� Ȱ���Ͽ� ���ڷḦ ����. n��
    for (int i = 0; i < plays.size(); i++)
    {
        //playsmap[i] = plays[i];
        playsmap.insert(pair<int, int>(plays[i], i));
        //���Ƚ�������� �ڵ� �������� ���ĵǰ� ���߿� �߰��Ǵ� �� ������ȣ�� ���� �뷡���� �ڷ� ���� �ȴ�.(�̰��� �����ؾߵȴ�.)

        genresmap[genres[i]] = 0;    
    }

    //n�� �ݺ��ϸ� ���� ���Ƚ��(key��)�� �����ͺ��� ���ʴ�� answer�� ������ȣ�� ��ȯ�ϵ�
    //��ȯ�Ҷ����� �� ������ȣ�� �帣üũ�� �Ͽ� �帣�� 2�� üũ�Ǿ������� ��������.

    for (int i = 0; i < plays.size(); i++) 
    {
        playsmap.end()
    }

    return answer;
}
int main()
{

}
#endif

#if 1
#include <string>
#include <vector>
#include<iostream>
#include <map>
#include<algorithm>

using namespace std;

struct playidx {
    int idx;
    int playcnt;
    string genre;
};

bool compare(playidx &a, playidx &b) {
    if (a.playcnt > b.playcnt) return true;
    else if (a.playcnt == b.playcnt)
        if (a.idx < b.idx) return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    vector<playidx> infos;
    vector<int> answer;
    //���Ƚ���� ������ȣ�� Ȱ���Ͽ� ��Ʈ��Ʈ �ڷ����� ��ҷΰ����� ���͸� ����. n��
    for (int i = 0; i < plays.size(); i++)
    {
        playidx temp;
        temp.idx = i;
        temp.playcnt = plays[i];
        temp.genre = genres[i];
        infos.push_back(temp);
    }

    //�ϴ� ���� ����.
    sort(infos.begin(), infos.end(), compare);

    //n�� �ݺ��ϸ� ���� ���Ƚ��(key��)�� �����ͺ��� ���ʴ�� answer�� ������ȣ�� ��ȯ�ϵ�
    //��ȯ�Ҷ����� �� ������ȣ�� �帣üũ�� �Ͽ� �帣�� 2�� üũ�Ǿ������� ��������.
    //�帣�� üũȸ���� �ʱ�ȭ�ϱ� ���ؼ� Ű���� �帣������ ������ ���� �����ϴ� ���� ������ ����.

    //�ߺ��� ����ϴ� ��. �� �ߺ��� 2�������� ����� ��.
    multimap<string, int> genremap;

    for (int i = 0, int j=0; i < plays.size(); i++)
    {
        if (genremap.count(infos[i].genre) == 2) { ; }
        else if (genremap.count(infos[i].genre) < 2) {
            genremap.insert(pair<string, int>(infos[i].genre, 1));
            answer[j++] = infos[i].idx;
        }
    }

    return answer;
}
int main()
{

}
#endif