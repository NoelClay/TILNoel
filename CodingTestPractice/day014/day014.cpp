#if 0
// 브릿지 랭스가 헷갈리는데 이 다리는 일차선 다리이고 트럭은 모두가 일정한 속력으로 달리고
// 1초에 한칸씩 이동하고 한칸에 한 트럭씩 서있을 수 있으며 최대 무게를 초과하지 말아야 하는 상태
// 
// 무게 7짜리가 길이 2짜리 다리를 다 지나는데 경과된 시간은 3초가 되어야 결국 다 지난 상태가 된다. 
// 1초 경과 10 2초 경과 10 10 3초경과 10 10 10 4초경과 10101010 5초1010101010 6초101010101010
// 10초 경과 10짜리 10개 전부 올라감. 이후 마지막짜리가 통과하기까지 +100칸 따라서 110초
// 
// 마지막 녀석이 올라간 초과시간 시점에서 다리길이만큼 더해주면 최종시간이 나오는 셈.
// 
// 먼저 들어간 녀석이 먼저 나가는 형태 큐가 적당
// 큐 사용법 https://life-with-coding.tistory.com/408
// 
// 반복횟수는 입력값이 10000이므로 n제곱은 안된다.
// 
// 올라간 초과시간 시점에서 다리길이만큼 더해주면 그 녀석이 더이상 다리위에 없는 셈이 되니까. 
// 큐에 올라갈때  pair의 형태로 자기무게, 초과시간 시점 의 값을 큐에 푸쉬한다.
// 
// 어찌저찌 해결했네. 많이 막혔던 이유는 초를 계산하는 if문 구조가 
// 내 생각대로 돌아가지 않고 cnt를 계산하던 문제가 제일 컸다. if문 안에 반복문까지 넣으면서 해결했다.
//
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck) {
	queue<pair<int, int>> bridge;
	int totalwei = 0;
	int answer = 0;
	int cnt = 0;
	//for (int i = 0; i < truck.size(); i++) {
	//	totalwei += truck[i];
	//	if (i == truck.size()-1) {// 즉 i가 마지막 인덱스라면 바로 계산이 끝난다.
	//		//마지막 인덱스가 올라간 카운팅 시점 + 다리길이 는 누적시간
	//		cnt++;
	//		cnt += bridge_length;
	//	}
	//	else if (totalwei + truck[i + 1] > weight) { //앞에 있는 트럭이 다 지나갈때까지 초를 세야함.
	//		cnt++; //초를 증가시켜놓고
	//		bridge.push(make_pair(truck[i], cnt)); //추가한뒤에
	//		cnt = (bridge.front().second) + (bridge_length);
	//		//현재 초과시간을 초기화하면 맨앞 녀석이 다 지나간 뒤의 시간으로 초기화가 되는데 그 공식은
	//		//다리위에 올라가있는 맨앞 녀석의 올라간시점 + 다리길이 다 지날때까지의 시간
	//		totalwei -= bridge.front().first; //시간을 초기화한만큼 다리 무게도 초기화하고
	//		bridge.pop();	//맨앞에 녀석도 팝
	//		
	//	}
	//	else { //그렇지 않다면 빨리 다음 트럭도 다리 위에 올려야지.
	//		
	//	}
	//}
	for (int i = 0; i < truck.size(); i++) {
		totalwei += truck[i];
		if (totalwei > weight) { //트럭을 지금 추가 할 수 없는 상태라면
			do {
				cnt = bridge.front().second + bridge_length; //앞에 트럭이 빠져나가는 시간으로 초기화하고
				totalwei -= bridge.front().first; //앞에 트럭이 빠져나간 무게로 초기화하고
				bridge.pop(); //실제 맨앞 트럭을 뺀다음에
			} while (totalwei > weight);
			bridge.push(make_pair(truck[i], cnt)); //다리 위에 그 시점에 지금 추가할 트럭을 올린다.
		}
		else
		{
			cnt++;
			bridge.push(make_pair(truck[i], cnt));
		}
	}
	//마지막 트럭이 다리위에 올라간채로 끝난다. 그 트럭이 마지막까지 통과할려면 길이만큼 더해져야함.
	cnt += bridge_length;
	return cnt;
}
int main()
{
	int length = 100;
	int weight = 100;
	vector<int> truck = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	cout << solution(length, weight, truck);
}
#endif