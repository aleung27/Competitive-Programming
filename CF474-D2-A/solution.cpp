#include <bits/stdc++.h>

using namespace std;

char keys[30] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};

int find(char ch) {
    int i = 0;
    while(keys[i] != ch) i++;

    return i;
}

int main () {

    char c;
    scanf("%c", &c);
    int shift;
    c == 'R' ? shift = -1 : shift = 1;

    char s[105];
    scanf("%s", s);
    for(const auto& ch: s) {
        if (ch == '\0') {
            printf("\n");
            break;
        } else {
            printf("%c", keys[find(ch)+shift]);
        }
    }

    return 0;
}