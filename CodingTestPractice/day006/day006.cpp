#if 0

//접두어란 a문장 b문장이 있을때 a문장이 b문장 앞부분의 일부분이 될경우에 a가 접두어가 되는 것
//1. 문자열 탐색
//2. 이중Loop 
//3. 해시

//1.sort(key = len)을 통해 str의 길이에 따라 정렬한 뒤, phone_book의 첫번째를 접두사로 지정하여 
//나머지 전화번호의 앞자리와 비교

//2.① 문자 길이 상관없이 숫자순으로 문자열 정열. ② 접두사 비교시, 나머지 전화번호가 아닌 바로 다음 전화번호와 비교.
//첫글자와 다음글자가 숫자순으로 일치하는 애들끼리 알아서 붙어있는 상태가 되어있고 비교대상이 다음녀석인걸로 나열이 되었으니
//비교대상도 문제가 없다.

//3.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

bool Solution(vector<string> phone_book)
{
	//hash map생성
	unordered_map<string, int> map;
	//키값은 각 전화번호들 밸류값은 1
	for (int i = 0; i < phone_book.size(); i++)	map[phone_book[i]] = 1;

    // 2. 모든 전화번호의 substring이 HashMap에 존재하는지 확인한다.
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book[i].size() - 1; j++)
        {
            //한 전화번호를 0~그 전화번호의 길이-1 인덱스 까지 계속 조각조각 떼어내면서
            string phone_number = phone_book[i].substr(0, j + 1);
            //그 조각을 키값으로 해쉬가 존재하는지 탐색한다. 만약 존재한다면 
            //그 해쉬의 키값이 곧 phonebook[i]의 접두어가 된다.
            if (map[phone_number])
                return false;
        }
    }
    return true;
}

#endif
