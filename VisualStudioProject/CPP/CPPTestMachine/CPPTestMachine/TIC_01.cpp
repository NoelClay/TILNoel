#if 0
//1번
// 자신의 이름과 나이를 입력받고 "나의 이름은 홍길동이고, 20살 입니다."라고 출력하는 
// 프로그램을 작성하세요. 단, 반드시 std::cout, std::cin을 이용해 작성합니다.
//
#include <iostream>
#include <tchar.h>	//_TCHAR 형을 쓰기위한 헤더파일

int _tmain(int argc, _TCHAR* argv[]) { 
	//유니코드일때는 그에 맞게 혹은 아스키일땐 아스키에 맞게 포팅하는 메인함수
	std::cout << "이름을 입력하세요 : " << std::endl;
	char name[15];
	std::cin >> name;
	std::cout << "나이를 입력하세요 : " << std::endl;
	int age;
	std::cin >> age;
	std::cout << "나의 이름은 " << name << "이고, " << age << "살 입니다.";
}
//고찰
// std cout cin 문법에 익숙해지기 위한 연습문제
//
#endif

#if 0
// 2번 문제
// C++11에서 auto 예약어는 어떤 의미인지 쓰고 코드로 예를 보이세요.
// 
// <안보고 쓴 답> 
// auto 예약어는 컴파일러 수준에서 문법에 맞게 자료형을 자동으로 지정하는 예약어이다.
// 할당하는 값이 무엇인지, 임시결과를 어떤걸 저장하는지에 따라 auto라고만 써두면 알아서
// 그 자료형에 맞는 자료형으로 변수를 지정해준다.
// 
// <41p 1.4.2 auto 예약어에 대한 설명>
// 과거 C에도 있던 auto 예약어는 지역변수 선언에 해당하는 기억 분류 지정자였다고 한다.
// 하지만 아무도 안썼다. 왜냐하면 지역변수 선언할때 디폴트로 알아서 스택영역을 사용하는 변수로
// 사용할 수 있었기 때문이다.
// C+11에서는 강력한 기능으로 변경되었는데 초깃값의 형식에 맞춰 선언하는 
// 인스턴스의 형식이 자동으로 결정되게 하는 기능으로 바뀐것.
//
#include <iostream>
#include <tchar.h>	//_TCHAR 형을 쓰기위한 헤더파일
using namespace std;
int _tmain(int argc, _TCHAR* argv[]) {
	//유니코드일때는 그에 맞게 혹은 아스키일땐 아스키에 맞게 포팅하는 메인함수
	int n = 7;
	int m[7] = { 1,2,3,4,5,6,7 };
	char a = 'a';
	char b[10] = "Noel";

	//char c[4] = { '1','2','3','4' };

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			auto z = n;
			cout << z << endl;
		}
		else if (i == 1) {
			auto z = m;
			for (int j = 0; j < (sizeof(m) / sizeof(1)); j++) {
				cout << z[j] << endl;
			}
		}
		else if (i == 2) {
			auto z = a;
			cout << z << endl;
		}
		else if (i == 3) {
			auto z = b;
			cout << z << endl;
		}
	}
}
//고찰
// auto 예약어를 복습하고 사용해보는 예제
//
#endif

#if 0
//3번 문제
// char[12] 배열 메모리를 new 연산자로 동적 할당하고 해제하는 코드 예를 작성하세요.
// 
// <책 안찾아보고 쓰는 new 동적할당>
// new 연산자는 새로운 객체(인스턴스)를 생성하는 연산자이다.
// 
// <책 43p 동적할당을 보고 쓰는 정리>
// new 연산자는 새로운 포인터를 할당하는 방법이다. malloc을 떠올리면 된다.
// 하지만 malloc보다 편리하고 강력한 기능은 초기 메모리 공간을 적을 필요가 없이 메모리 공간확보를
// 자동으로 수행한다는 점이다.
// 
// 포인터형식 포인터이름 = new 자료형;
// delete 포인터이름;
// 
// 포인터형식 포인터이름 = new 배열형식[배열크기];
// delete[] 포인터이름;
//
#include <iostream>
#include <tchar.h>	//_TCHAR 형을 쓰기위한 헤더파일
using namespace std;
int _tmain(int argc, _TCHAR* argv[]) {
	//유니코드일때는 그에 맞게 혹은 아스키일땐 아스키에 맞게 포팅하는 메인함수
	int c[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int *d = new int[12];
	d = c; //얕은복사. 배열의 주소를 가져다가 참조한다.
	d[0] = 0;
	cout << c[0] << endl;
	cout << d[0] << endl;

//	delete[] d;//delete 호출은 프로그램이 끝날때 스택을 더이상 쓰지 않을때에만 한다.
	// 사실상 사용하지 않아야 한다. 알아서 종료될때 호출되는 호출자인거 같다.
	int *e = new int;
	*e = c[0]; //깊은 복사 e의 주소로 가서 c[0] 상수값을 저장한다.
	c[0] = 1;
	cout << c[0] << endl;
	cout << e[0] << endl;
}
#endif

//4번
// int에 대한 참조 형식을 매개변수로 받고 두 변수의 값을 교환하는 함수를 작성하세요. 
// 함수 원형은 void Swap(int &a, int &b)입니다.
// 
// c++에서 주소값을 받아서 사용하는 함수를 짜보라는 문제인거 같다.
// 45 page 1.6 참조자 형식의 내용에서 핵심을 가져오면
// 
// 형식 &이름 = 원본;
// 의 형태로 참조자 형식을 정의할 수 있다. 포인터와 상당히 유사하며
// 이름 = 할당할 내용;
// 하면 원본에도 영향을 주는 형태이다.
// 
// 위처럼 선언과 동시에 반드시 초기화로 할당이 이루어져야지 의미가 있는 형식이다. 
// 언젠가는 int 자료형 원본을 받겠지 생각하고 빈공간을 선언하는 형태를 
// 컴파일러는 가만 나두지 않는다.
// 
// 앞서 포인터를 생각했을때 변수를 포인터형으로 만드는건 가능하지만 상수를 포인터형으로 만드는건 불가능했다.
// 왜냐하면 공간의 느낌이 아니라 상수는 값의 느낌이기에 참조해서 변형자체가 의미가 없어서 
// 포인터의 기능을 수행 불가하기 때문이다. 참조형도 마찬가지로 상수에 선언하는건 불가능하다.
// <불가능한 예시들> 
// int *p = &3; 주소값이라 해석하는 포인터 형에도 상수참조형은 말이 안됨		
// int &a = 3; 참조형 변수에 할당 가능한 데이터는 상수가 될 수 없음.		
// int &a;	할당할 원본 없는 참조형은 컴파일러가 허락하지 않음.
// 
// 매개변수가 참조형인 함수에서의 햇갈리는 문제점은 바로 호출할때에 있다.
// int test(int &a); 라고 선언된 참조형 매개변수를 가진 함수를 호출할때 '실인수' 혹은 '인자'로 전달하는
// 호출자의 형태는 기본형과 달리 특별할까? 아니다. 참조형을 선언할때만 &를 붙이고 나중에 사용할때는 자연스럽게
// 할당하는 것 처럼. 매개변수로 할당하려는 인수를 전달할때에도 그냥 이름만 적는다.
// int &num = temp;		test(num); 과 같이 그냥 이름으로 호출을 하는것으로 기본형 매개변수와 호출의 형태는 동일하다.
// 호출자의 형태만 보고서는 매개변수의 형식을 속단할 수 없다는 것.
//
#if 0
#include<iostream>
using namespace std;

//void Swap(int &a, int &b) { //실행결과 2222 따라서 실패
// //실패 원인은 참조형 데이터에 참조형 데이터를 할당하면 참조를 하고
// //참조형 데이터에 상수형 데이터를 할당하면 수정을 하기 때문이다.
//	int temp;
//	temp = a;
//	a = b;
//	b = a;
//
//	cout << a << endl;
//	cout << b << endl;
//}

void Swap(int& a, int& b) {
	int tempA = a, tempB = b;	
	a = tempB;
	b = tempA;

	cout << a << endl;
	cout << b << endl;
}

int main()
{
	int nums[] = { 0, 1, 2, 3, 4, 5 };
	int& a = nums[1];
	int& b = nums[2];

	Swap(a, b);

	cout << a << endl;
	cout << b << endl;
}

#endif

// 5번
// 상수형 참조가 기존의 참조형식과 크게 다른 점이 무엇일까?
// 
// <50page 1.6.2 r-value 참조>
// 형식 &&이름 = 상수
// 위와 같은 형식으로 상수형 참조는 서언과 동시에 초기화를 해줘야한다.
// 앞서 공간을 할당하고 값을 변화시킬 수 있는 변수니까 참조형이 가능하다고 했고
// 상수는 이미 정해진 값이기에 참조의 의미가 없다고 했다. 하지만 c++는 상수형을 저장할 수 있는 참조형변수를 만들었다.
// 아직 설명하기엔 이르지만 일단 알고 넘어가야되는건 r-value는 저장하지 않으면 사라지는 임시결과라는 것이고
// 그 임시결과를 저장하기에 좋은 형식이 바로 상수참조형이라는 것이라는 점이다.
// 
#if 0
#endif

//6번
// 다음과 같은 int배열을 오름차순으로 정렬한 후 화면에 결과를 출력하는 프로그램을 작성하세요. 정렬방법은 상관없지만
// 출력할때는 반드시 범위 기반 for문을 활용하시오.
// <52page 1.7 범위 기반 for문>
// 
// for문은 횟수 기반 반복문이고, while문은 조건 기반 반복문이다.
// 범위 기반 for문은 c++에 새로 추가된 기능으로 횟수도 조건도 생각할 필요 없이 배열의 요소를 처음부터 끝까지
// 반복해야될 경우에 아주 간단하게 짤 수 있고 배열이 변하더라도 수정할 필요 없이 동적으로 반복횟수를 다시 세팅해주는
// 범위 기반 for문으로 충분할 경우에는 활용하면 수정할때 안건들고 시간을 아낄 수 있는 프로그램이 된다.
// 
// for(auto 요소변수 : 배열이름){ 반복구문; }
// for(auto &요소변수 : 배열이름){ 반복구문; }
// 첫번째는 요소변수를 사용할때 실제 배열에 있는 요소와는 별개로 다른 변수인셈이다. 따라서 단순히 값을 사용할때 유용.
// 두번째는 요소변수를 사용할때 실제 배열에 있는 요소를 참조하는 형태의 변수이다. 수정할 시에 실제 배열에 영향을 준다.
//
#if 0
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int aList[5] = { 20,40,10,30,50 };

	sort(aList, aList + 5);

	for (auto n : aList) {
		cout << n << endl;
	}
}
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
