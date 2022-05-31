#if 0 //map을 이용하여 해볼려고 했지만 내가 모르는 개념들과 생각보다 key값을 기준으로 정렬된 자료를 활용하기가 어려웠다.

//장르별 가장 많이 재생된 노래 2개씩 모아서 앨범 출시. 노래는 고유번호[배열의 인덱스]로 구분, 
//노래 정렬 기준은 가장 많이 재생된 노래가 먼저 들어간다. 
//이때 같은 장르 2곡이 다 찼다면 그 장르에 해당하는 곡들은 이제 못들어가고 
//그 장르를 제외한 곡들 중에서 재생횟수가 더 많은 거를 찾아서 넣는다.
#include <string>
#include <vector>
#include<iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    multimap<int, int> playsmap;//key중복을 허용하는 맵
    map<string, int> genresmap;//string에 따른 cnt를 어떻게 검사하고 처리해야될지 모르겠어서 결국 맵두개 만들기..
    vector<int> answer;

    //재생횟수와 고유번호를 활용하여 맵자료를 만듬. n번
    for (int i = 0; i < plays.size(); i++)
    {
        //playsmap[i] = plays[i];
        playsmap.insert(pair<int, int>(plays[i], i));
        //재생횟수값으로 자동 오름차순 정렬되고 나중에 추가되는 즉 고유번호가 높은 노래들이 뒤로 가게 된다.(이것을 주의해야된다.)

        genresmap[genres[i]] = 0;    
    }

    //n번 반복하며 가장 재생횟수(key값)가 높은것부터 차례대로 answer에 고유번호를 반환하되
    //반환할때마다 그 고유번호로 장르체크를 하여 장르가 2번 체크되었는지를 따져야함.

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
    //재생횟수와 고유번호를 활용하여 스트럭트 자료형을 요소로가지는 벡터를 만듬. n번
    for (int i = 0; i < plays.size(); i++)
    {
        playidx temp;
        temp.idx = i;
        temp.playcnt = plays[i];
        temp.genre = genres[i];
        infos.push_back(temp);
    }

    //일단 정렬 먼저.
    sort(infos.begin(), infos.end(), compare);

    //n번 반복하며 가장 재생횟수(key값)가 높은것부터 차례대로 answer에 고유번호를 반환하되
    //반환할때마다 그 고유번호로 장르체크를 하여 장르가 2번 체크되었는지를 따져야함.
    //장르별 체크회수를 초기화하기 위해선 키값을 장르값으로 가지는 맵을 생성하는 편이 나을거 같다.

    //중복을 허용하는 맵. 딱 중복은 2개까지만 허용할 것.
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