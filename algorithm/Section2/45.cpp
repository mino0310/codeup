#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>


int remain_cnt(std::vector<int> prince, int n);

int main(void)
{
    int n, k, i, l = 1, cnt = 0, cut = 0;

    scanf("%d %d", &n, &k);
    std::vector<int> prince(n + 1);

    for (i = 1; i <= n; i++) {
        prince[i] = i;
    }
    while ((cnt = remain_cnt(prince, n)) != 1) {
        int tmp_cnt = 0, tmp = k;
        i = l;
        while (1) {
            if (prince[i % n] != 0) {
                tmp_cnt++;
            }
            i++;
            if(tmp_cnt == k) {
                prince[(i - 1) % n] = 0;
                printf("this index number %d is zero!\n", (i - 1) % n);
                break ;
            }
        }
        l = i % n;
        printf("now index = %d\n", l);
    }
    for (i = 1; i <= n; i++) {
        printf("%d ", prince[i]);
    }

    return 0;
}

int remain_cnt(std::vector<int> prince, int n) {
    int i, cnt = 0;

    for (i = 1; i <= n; i++) {
        if (prince[i]) {
            cnt++;
        }
    }
    // printf("cnt = %d\n", cnt);
    return cnt;
}

/*
입력 8 3 
출력 7

이 문제의 핵심은 뭔가
문제에서 말하는 것을 쪼개보자.
둥글게 앉아 있고 (둥글게 자료를 저장해야 함.)
특정 숫자가 되어버리면 해당 공간에서 삭제가 된다. 
그 다음부터 다시 반복 (언제까지? 남은 숫자가 하나일 때까지)



*/