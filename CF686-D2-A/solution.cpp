#include <bits/stdc++.h>

using namespace std;

int main () {
    int requests;
    long long creams;
    scanf("%d %lld", &requests, &creams);
    char symbol;
    long long packs;
    int sad = 0;

    for(int i = 0; i < requests; i++) {
        scanf(" %c %lld", &symbol, &packs);
        symbol == '+' ? creams += packs : (creams >= packs ? creams -= packs : sad++);
    }

    printf("%lld %d\n", creams, sad);

    return 0;
}