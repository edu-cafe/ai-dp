#include <cstdio>
#include <cstring>
int d[11];
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

    ..........

    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",d[n]);
    }
}
