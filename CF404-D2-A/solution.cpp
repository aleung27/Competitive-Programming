#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    int n;
    scanf("%d", &n);

    char next;
    char diag, other;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %c", &next);
            
            if(i == j || i+j == n-1) {
                if(i == 0 && j == 0) diag = next;
                else if(next != diag) {
                    printf("NO\n");
                    return 0;
                }
            }

            else {
                if(i == 0 && j == 1) other = next;
                else if (next != other) {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }

    other == diag ? printf("NO\n") : printf("YES\n");


    return 0;
}
