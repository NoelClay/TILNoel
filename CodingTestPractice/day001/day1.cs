//3진법과 4진법 그 중간의 이상한 진법변환이 이루어져야 할 것 같다.
//자리 올림이 일어날때 3의 n승으로 자리올림이 일어나되 4는 3의 의미를 가지고 있고 3진법과 달리 3의 

//10진법을 3진법으로 바꾸되 그 바꾼 녀석을 
//수를 3으로 나눈 몫으로 초기화하고 3으로 나눈 나머지는 그자리에 추가한다. 
//그런데 3으로 나누어 떨어질 경우엔 4를 추가하고 몫-1 한다.
// 9/3 은 몫은 3 나머지는 0 따라서 4를 추가하고 몫-2
// 10/3은 몫은 3 나머지는 1 따라서 1을 추가하고 몫은 3 다시 3으로 나누면 나누어 떨어지므로 4추가 하고 몫-1

using System;

namespace Nara124
{  
    class Nara124
    {
        int Solution(int n)
        {
            string result = "";
            while(n>0)
            {
                if(n%3==0){
                    result+=4;
                    n/=3;
                    n--;
                }
                else{
                    result+=(n%3);
                    n/=3;
                }
            }
        }

        static void Main()
        {
            int n;
            scanf("%d", n);
            console.WriteLine(Solution(n));
        }
    }
}