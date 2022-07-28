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
	int *e = new int;
	*e = c[0]; //깊은 복사 e의 주소로 가서 c[0] 상수값을 저장한다.
	c[0] = 1;
	cout << c[0] << endl;
	cout << e[0] << endl;
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
#if 0
#endif
#if 0
#endif
#if 0
#endif
