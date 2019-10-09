#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

.........

int main()
{
    int n = 0;
    int i;

    while (1) {
        printf("\nInput n (quit:n<0) --> ");
        scanf("%d", &n);
        if (n < 0) break;
        for(i=0; i<=n; i++) printf("%d ", fibo(i));
        putchar('\n');
    }
    return 0;
}
