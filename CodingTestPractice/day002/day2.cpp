//인덱스를 하나씩 탐색할때 마다 초를 카운트 한다. cnt++
//인덱스가 증가할때마다 현재 인덱스의 값과 그 이전의 값들을 n번 탐색하며 대소비교하되 n제곱....
//작아졌다면 그때의 cnt값을 count 변수에 넣어준다.
//count 
//추가된 배열의 카운팅초를 반환한다.
#if 0
# include <string>
# include <vector>
# include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> count(prices.size());
    int cnt = 0;
    for (int i = 0; i < prices.size(); i++) {
        for (int j = 0; j < i; j++) 
        {
            if (answer[j] > answer[i] && count[j] == 0)//가격이 떨어졌다면 그리고 초가 할당된적이 없다면
            {
                count[j] = cnt;//떨어진시점의 초를 할당.
            }
        }
        cnt++;
        
    }
    //cnt가 할당되지 않은 count배열을 찾아 전부 cnt를 할당
    for (int i = 0; i < prices.size(); i++) {
        if (count[i] == 0) {
            count[i] = cnt;
        }
    }
    //각 가격별 어느시점에 카운팅 스탑이 적용되었는지가 count에 저장되어 있음.
    //각 가격별 시작 시점이 곧 인덱스 이므로 인덱스만큼 빼주면 됨.
    for (int i = 0; i < prices.size(); i++) {
        answer[i] = count[i] - i;
    }
    return answer;
}

int main()
{
    int N = 0;
    vector<int> prices;
    int icheck;
    

    cout << "N: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << "가격입력: ";
        cin >> icheck;
        prices.push_back(icheck);
    }
    vector<int> answer(N);
    answer = solution(prices);

    for (int i = 0; i < N; i++) {
        cout << answer[i];
    }

}
#endif