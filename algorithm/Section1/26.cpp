#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

int main(void)
{
    int n, rank;

    scanf("%d", &n);
    std::vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; `i++) {
        scanf("%d", &a[i]);
        b[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                b[i]--;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }   
    return 0;
} 

// 실력이 정수값으로 주어지고 나보다 앞의 숫자 중에서 나보다 작은 것들은 내 뒤로 밀고
// 나보다 높은 것들은 내 앞에 둔다. 그래서 내 순서가 내 최선 등수가 된다.

// 이를 좀더 간단하게 수식으로 바꿔보자.
// 1인덱스부터 지금인덱스까지 탐색 -> 
// 1번 주자의 최선의 등수를 구하고 그 배열을 그대로 사용하는 것이 아니다. 다시 이전 배열로
// 돌아가야 한다
// 모두 자기 인덱스 값을 등수로 갖고 있음. 여기서 내가 앞의 선수보다 실력이 좋으면 
// 인덱스 = `등수를 하나씩 뺴주면 되지 않나. 인덱스를 빼면 배열 순서도 바뀌니까 안 되겠고, 등수
// 변수를 하나 만들어서 이를 빼주면 되지 않나. 
// 예를 들어 2 8 10 7 1 9 4 15 가 들어오면
// 2 는 1인덱스니까 1등수이고, 8은 2 인덱스니까 2인데, 앞의 숫자보다 크니까 등수 변수를 --해줘서
// 1이 되는 것이지. 10의 경우엔 3인 덱스니까 등수변수는 3이고, 앞의 두 숫자보다 크니까 --를
// 두번해서 1이 되는 것이지. 
// 인덱스가 곧 현 등수인 것을 활용하면 되겠다.
