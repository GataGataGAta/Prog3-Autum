#include <stdio.h>

int main() {
    int k, n, m;
    printf("k : ");
    scanf("%d", &k);

    int a[10];
    printf("%d個の整数 : ", k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }

    printf("n : ");
    scanf("%d", &n);

    printf("m : ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int b[16];
        printf("%d個の整数: ", n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[j]);
        }

        int match = 1;
        for (int j = 0; j <= n - k; j++) {
            for (int l = 0; l < k; l++) {
                if (b[j + l] != a[l]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                break;
            }
        }

        printf("%d\n", match);
    }

    return 0;
}
