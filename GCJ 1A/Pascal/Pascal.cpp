#include <cstdio>

int main() {
    int cases;
    int total;

    scanf("%d", &cases);

    for (int a = 0; a < cases; a++) {
        scanf("%d", &total);

        printf("Case #%d:\n", a+1);

        if(total == 1) {
            printf("1 1\n");
            continue;
        }

        for (int j = 1; j <= total/2;j++){
            printf("%d %d\n", j, j);
        }

        if(total % 2 == 1) {
            printf("%d %d\n", total/2 + 1, total/2 + 1);
        }

        printf("%d %d\n", total/2 + 1, total/2);
    }

    return 0;
}