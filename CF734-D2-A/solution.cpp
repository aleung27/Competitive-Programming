#include <bits/stdc++.h>

using namespace std;

int main () {
    int games, a = 0, d = 0;
    char next;
    scanf("%d ", &games);

    for(int i = 0; i < games; i++) {
        scanf("%c", &next);
        next == 'A' ? a++ : d++;
    }

    if(a == d) {
        printf("Friendship\n");
        return 0;
    }

    a < d ? printf("Danik\n") : printf("Anton\n");

    return 0;
}