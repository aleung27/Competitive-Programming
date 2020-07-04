#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    int n;
    scanf("%d", &n);

    if(n==0) {
        printf("1\n");
    } else {
        int mod = n % 4;
        if(mod == 0) printf("6\n");
        else if (mod == 1) printf("8\n");
        else if (mod == 2) printf("4\n");
        else printf("2\n");
    }


    return 0;
}
