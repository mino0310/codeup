#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

int is_prime(int n);

int main(void) {
    int i, cnt, n;

    scanf("%d", &n);
    std::vector<int> output(n + 1);
    int start = n;
    while (n){
        i = 2;
        int tmp = n;
        while (i <= tmp) {
            while (is_prime(i) && tmp % i == 0) {
                output[i]++;
                tmp /= i;
            }
            i++;
        }
        n--;
    }
    printf("%d! = ", start);
    for (int i = 1; i <= start; i++) {
        if (output[i]) {
            printf("%d ", output[i]);
        }
    }
}

int is_prime(int n) {
    
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 1;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}


// 상상 이상으로 큰 숫자가 들어온다
// 그러니까 팩토리얼을 계산을 해버리면은 안 된다.
// 쪼개서 계산 해야 한다.
// 계산은 어떻게하냐? 
// 53! 이라고 하면은
// 53이란 숫자가 입력되면 이를 가지고 있다가 1부터 53까지 하나씩 증가시켜가며
// 그 숫자들을 소인수분해해서 소인수들이 나올 때마다 
// 소인수 갯수배열의 해당 숫자를++ 해주면 되지 않나
// 그런데 소인수 갯수배열은 어떤 방식으로 나열하지

// 찬찬히 해보자
// 우선 예시를 풀어보자
// 5!은 1 2 3 4 5 가 곱해져있는 형태
// 1 은 소수가 아니니까 패스
// 2 는 소수이니까 2의 개수 ++
// 3 은 소수니까 3의 개수 ++
// 4 는 소수의 곱으로 표현 가능 (2 * 2)하니까 2의 개수 +2 
// 5 는 소수니까 5의 개수 ++ 
// 그래서 2개수 3 / 3개수 1 / 5개수 1 
// 그래서 3 1 1 

// 안이 어떻게 돌아가는지 생각해보자
// 일단 5가 들어오면 5부터 -- 해가면서 2까지는 계산을 해야 한다
// 우선 5부터 ... 소수를 무한정 대입하면서 나눠질 때까지 하는 것은
// 엄청 비효율적이고 답도 안나올 듯.. 나눠질 때까지 숫자를 증가시킬 테니까
// 아닌가 해당 수를 소인수 분해하고 배열의 카운트를 추가하는 것이 핵심
// 소인수분해를 할 때 소인수는 그 수보다 커질 수는 없기 때문에 맥시멈이 
// 있구나
// 그러면 괜찮을 듯 ... 

// 5라고 하면  i = 2 부터 시작해서 5를 나눠본다
// 안 나눠지면 i++ 5까지 하지
// 3도 나머지가 0이 아니니 다시 ++
// 4는 소수가 아니니까
// 5는 소수니 나눠보자. 나머지가 0이 되었네. 그러니 5의 배열의 카운트++
// 그리고 몫도 0이 되었으므로 이제 5반복을 끝내고 -- 연산

// 4가 되면 다시 i = 2 부터 시작해서 4로 나눠본다
// 이제 반복
// 소인수 배열도 처음 입력받은 n + 1 개를 맥시멈으로 하면 될 듯
// 이를 넘어갈 수 없으니
