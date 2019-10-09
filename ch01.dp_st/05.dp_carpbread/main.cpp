#if 1
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    FILE *fp;
    char fname[50];
    printf("input_data file name? ");
    fgets(fname, 50, stdin);
    fname[strlen(fname)-1] = '\0';
	fp = freopen(fname, "r", stdin);
	if (fp == NULL) {
		fprintf(stderr, "input data file open error!!\n");
		return -1;
	}

    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> d(n+1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {

            .........

        }
    }
    cout << d[n] << '\n';
    return 0;
}

#else
//#include <stdio.h>
#include <cstdio>
#include <cstring>
int a[1001];
int d[1001];
int main() {
    FILE *fp;
    char fname[50];
    printf("input_data file name? ");
    fgets(fname, 50, stdin);
    fname[strlen(fname)-1] = '\0';
	fp = freopen(fname, "r", stdin);
	if (fp == NULL) {
		fprintf(stderr, "input data file open error!!\n");
		return -1;
	}

    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {

            ..........

        }
    }
    printf("%d\n",d[n]);
    return 0;
}

#endif
