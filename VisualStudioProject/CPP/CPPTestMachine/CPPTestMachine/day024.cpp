#if 0
//n은 1~200 따라서 각 컴퓨터는 0~n-1로 표현됨. 대각행렬 대각선은 1
//computers[i][j]가 1이면 i와 j가 연결되었음을 의미한다.
//return은 연결되지 않은 간선의 개수를 반환한다.

//이중 for문으로 computer 벡터를 탐색하면서 return은 간선의 개수이므로 n에서 0까지 작아진다.
//computer[i][j] == 1인 경우 n--; 한번 -1된 ij가 다음번에 나오면 카운팅 하면 안된다.
//뭔가 스택으로 push pop?
// 
//스택으로 할려면 입출력의 연속성이 있어야 하는데 연속성이 보이질 않는다. 
//집합으로 처리하면 중복을 막을 수 있을거 같다.
//집합관련 https://blockdmask.tistory.com/79
//https://hwan-shell.tistory.com/130
//
//결국 pair값으로 저장을해야 할것 같다.. pair로 검사를 하려해도 어떻게 해야 중복 체크를 할지는 모르겠다.

#include<iostream>
#include<vector>
#include<set>
//#include<stack>

using namespace std;

int solution(int n, vector<vector<int>> computer) {
	//stack<int> stack;
	set<pair<int, int>> set;

	for (int i = 0; i < computer.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (computer[i][j] == 1 && i != j) {//i j가 다를때 1이면 연결되었다는 의미
				
				//if (set.find(make_pair(j, i)) != set.end()) {//set에 i,j값이 존재하지 않는다면
				//	set.insert(make_pair(i, j));
				//}
				//else if(set.find)
				//	
				//}


			}
		}
	}
}

#endif