//1번
// 아이디는 3~15, 소문자, 숫자, 빼기, 언더바, 마침표 가능 아스키코드표 https://stepbystep1.tistory.com/10
// 소문자 97~122 대문자 65~90 대문자->소문자 +32 숫자 48~57 빼기 45 언더바 95 마침표 46
// 
// 1단계: 소문자치환   2단계: 예외 문자들 제거하고 문자열 연결     3단계: 연속마침표는 1개로     4단계:처음과 끝 마침표는 제거
// 5단계: 처리하고 나니 빈문자열이 된다면 a추가   
// 6단계: 15개 넘어가는 문자들은 전부 제거 제거한 뒤에 마침표가 끝에 위치하게 되면 그 마침표도 제거 14~15 될것
// 7단계: 결국 2개 이하라면(a추가해서 1개는 무조건 되지) 마지막 문자를 길이가 3될때까지 반복해서 추가
// 
// 입력 길이는 1000개 따라서 n^2은 안된다. nlogn은 10 * 1000
// 
// 단계마다 계속 탐색을 하는 것보다 합칠 수 있는건 같은 단계에서 처리하는게 시간복잡도 유리
// 
// 1단계 2단계 합치는거 가능할듯 n번탐색을 하면서 예외는 삭제하면서 이어붙이고 대문자라면 소문자로 변환
// 삭제하고 이어붙이는건 기존의 배열 자료형으로는 너무 오래걸릴거 같으니 스택을 활용 
// 스택에 추가할때 문자열 끝부터 추가하면 다시 꺼낼때 맨앞부터 꺼내진다.
// 
// 3단계 4단계 합치는거 가능. 마침표를 찾는데 그게 처음 인덱스라면 이어진 마침표들도 전부 삭제
// 마침표를 찾으면 이어서 나오는 마침표들이 있다면 걔네들은 다 삭제. 
// 만일 그렇게 삭제하다가 스택의 끝에 도달했다면 가지고있던 마침표도 버림
// 
// 5단계 조건은 빈 문자열. 5단계 조건에 걸린 순간 6 7단계 할것도 없이 바로 aaa
// 
// 6 7단계도 동시에 가능할것 문자열 길이에 따라 분기가 갈림. 문자열 길이 2개 이하는 마지막 문자를 추가해서 전체길이 3될때까지
// 만약 문자열 길이가 15보다 크면 뒤에 싸그리 제거한다. 이때 마지막 문자열이 마침표라면 그 마침표까지 제거하면서 끝
// 
// c++ switch case https://docs.microsoft.com/ko-kr/cpp/cpp/switch-statement-cpp?view=msvc-170
//
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int level = 0;
    char padding;
    stack<char> cstack;
    stack<char> cstack2;


    //while (true) {
    //    switch (level)
    //    {
    //    case 0: //1~2단계 합친 형태로
    //        for (int i = 0; i < (int)new_id.size(); i++) {
    //            if (65<=new_id[i]&& new_id[i]<=90) {//대문자라면 소문자로
    //                cstack.push(new_id[i] + 32);
    //            }
    //            else if ((48 <= new_id[i] && new_id[i] <= 57) || (97 <= new_id[i] && new_id[i] <= 122)) {
    //                 숫자라면 소문자라면 그대로 추가
    //                cstack.push(new_id[i]);
    //            }
    //            else if (new_id[i] == 45 || new_id[i] == 95 || new_id[i] == 46) {
    //                빼기라면, 언더바라면, 마침표라면 그대로 추가
    //                cstack.push(new_id[i]);
    //            }
    //        그 외엔 버림 처리 반복이 끝나고 나면 cstack엔 문자열이 처음부터 끝까지 들어가며 다시 pop할때 끝부터 pop됨
    //        반복 횟수는 1000번 * 비교+계산=약 10회 시간복잡도 1만번
    //        }
    //        level++;
    //        break;

    //    case 1://3~4단계 합친 형태
    //        while (!cstack.empty()) 
    //        {
    //            if (cstack.top() == 46 ) {//마침표가 나왔다면
    //                if (cstack2.top() != 46 && !cstack2.empty()) {//연속된 마침표만 아니라면
    //                    cstack2.push(cstack.top());//마침표도 들어가는거 맞다. 양끝 혹은 연속되는 애들을 스킵하는거
    //                    cstack.pop();
    //                }
    //                else { //여기에서 고려해야되는 것은 지금 추가해야될 문자가 마침표인데 담을 스택이 비어있다던가
    //                    같은 46 마침표일 경우이다.
    //                    cstack.pop();
    //                }
    //            }
    //            else {//cstack.top이 마침표가 아닌 경우에는 이미 예외 처리 했으므로 걍 추가
    //                cstack2.push(cstack.top());
    //                cstack.pop();
    //            }
    //        }//cstack이 비게 되면서 반복이 끝난다. 반복이 끝났을때 stack2의 top에 주목한다. 이곳은 첫번째 문자의 요소이다. 이게 마침표면 제거
    //        if (cstack2.top() == 46) {
    //            cstack2.pop();
    //        }
    //        레벨 판단을 위해 문자열의 길이를 잰다.
    //        if (cstack2.empty()) { return "aaa"; }
    //        else if (cstack2.size() < 3) { level = 3; }
    //        else { level = 4; }
    //        break;
    //    case 3:
    //        while (!cstack2.empty()) {
    //            answer += cstack2.top(); //결국 첫번째 문자부터 들어가게되는 셈.
    //            cstack2.pop();
    //        }
    //        padding = answer[answer.size() - 1];
    //        for (int i = answer.size() - 1; i < 3; i++) {
    //            answer += padding;
    //        }
    //        return answer;
    //        break;
    //    case 4:
    //        int cnt = 0;
    //        while (!cstack2.empty()) {
    //            cnt++;
    //            if (cnt == 15) { //15번째 추가이고 마침표가 아니라면 추가하고서 끝
    //                if (cstack2.top() != 46) {
    //                    answer += cstack2.top();
    //                    
    //                }
    //                else { return answer; }
    //            }
    //            answer += cstack2.top();
    //            cstack2.pop();
    //        }           
    //        break;
    //    }
    //}

    while (level != 10) {
        if (level == 0) {//1~2단계 합친 형태로
            for (int i = 0; i < (int)new_id.size(); i++) {
                if (65 <= new_id[i] && new_id[i] <= 90) {//대문자라면 소문자로
                    cstack.push(new_id[i] + 32);
                }
                else if ((48 <= new_id[i] && new_id[i] <= 57) || (97 <= new_id[i] && new_id[i] <= 122)) {
                    // 숫자라면 소문자라면 그대로 추가
                    cstack.push(new_id[i]);
                }
                else if (new_id[i] == 45 || new_id[i] == 95 || new_id[i] == 46) {
                    //빼기라면, 언더바라면, 마침표라면 그대로 추가
                    cstack.push(new_id[i]);
                }
                //그 외엔 버림 처리 반복이 끝나고 나면 cstack엔 문자열이 처음부터 끝까지 들어가며 다시 pop할때 끝부터 pop됨
                //반복 횟수는 1000번 * 비교+계산=약 10회 시간복잡도 1만번
            }
            level = 1;
        }
        else if (level == 1) {
            while (!cstack.empty())
            {
                if (cstack.top() == 46) {//마침표가 나왔다면
                    if (cstack2.top() != 46 && !cstack2.empty()) {//연속된 마침표만 아니라면
                        cstack2.push(cstack.top());//마침표도 들어가는거 맞다. 양끝 혹은 연속되는 애들을 스킵하는거
                        cstack.pop();
                    }
                    else { //여기에서 고려해야되는 것은 지금 추가해야될 문자가 마침표인데 담을 스택이 비어있다던가
                        //같은 46 마침표일 경우이다.
                        cstack.pop();
                    }
                }
                else {//cstack.top이 마침표가 아닌 경우에는 이미 예외 처리 했으므로 걍 추가
                    cstack2.push(cstack.top());
                    cstack.pop();
                }
            }//cstack이 비게 되면서 반복이 끝난다. 반복이 끝났을때 stack2의 top에 주목한다. 이곳은 첫번째 문자의 요소이다. 이게 마침표면 제거
            if (cstack2.top() == 46) {
                cstack2.pop();
            }
            //레벨 판단을 위해 문자열의 길이를 잰다.
            if (cstack2.empty()) { return "aaa"; }
            else if (cstack2.size() < 3) { level = 3; }
            else { level = 4; }
        }
        else if (level == 3) {
            while (!cstack2.empty()) {
                answer += cstack2.top(); //결국 첫번째 문자부터 들어가게되는 셈.
                cstack2.pop();
            }
            padding = answer[answer.size() - 1];
            for (int i = answer.size() - 1; i < 3; i++) {
                answer += padding;
            }
            return answer;
        }
        else if(level==4){
            int cnt = 0;
            while (!cstack2.empty()) {
                cnt++;
                if (cnt == 15) { //15번째 추가이고 마침표가 아니라면 추가하고서 끝
                    if (cstack2.top() != 46) {
                        answer += cstack2.top();
                        return answer;
                    }
                    else { return answer; }
                }
                answer += cstack2.top();
                cstack2.pop();
            }
            level = 10;
        }
    }
    return answer;
}
int main() {
    vector<string> new_id{ "...!@BaT#*..y.abcdefghijklm", "z-+.^.","=.=", "123_.def", "abcdefghijklmn.p"};
    //for (int i = 0; i < 5; i++) {
        cout << solution(new_id[1]) << endl;
    //}
    //cout << solution("...!@BaT#*..y.abcdefghijklm");
}
#endif

//2번
// head num tail 인덱스 값들을 저장하고 헤드 기준으로 파일 정렬하고
// 
// https://blockdmask.tistory.com/362
//
#if 0
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    return answer;
}
#endif