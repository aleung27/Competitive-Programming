#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    int n;
    scanf("%d", &n);

    int status = 0;

    int lastrb, lastra;
    scanf("%d %d", &lastra, &lastrb);
    if(lastra != lastrb) status = 1;

    int ra, rb;
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &ra, &rb);
        if(ra > lastra && status == 0) status = -1;
        if(ra != rb) status = 1;

        lastrb = rb;
        lastra = ra;
    }

    if(status == 0) printf("maybe\n");
    else if(status == 1) printf("rated\n");
    else printf("unrated\n");

    return 0;
}