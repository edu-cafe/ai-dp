#if 1
#include <iostream>
using namespace std;
int d[1000001];
int go(int n) {

    .......

    return d[n];
}
int main() {
    int n;
    while(true) {
        cout << "Input n(n<=0 to quit) => ";
        cin >> n;
        if(n <= 0) break;
        cout << go(n) << "\n\n";
    }
    return 0;
}

#else
#include <stdio.h>
int d[1000001];
int go(int n) {

    ........

    return d[n];
}
int main() {
    int n;
    while(1) {
        printf("Input n(n<=0 to quit) => ");
        scanf("%d",&n);
        if(n<=0) break;
        printf("Operation Count to One : %d\n\n",go(n));
    }
    return 0;
}
#endif


