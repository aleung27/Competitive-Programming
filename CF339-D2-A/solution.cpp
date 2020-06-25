#include <bits/stdc++.h>

using namespace std;

int main() {
    char str[105];
    scanf("%s", str);

    int i = 0;
    int numbers[105];
    for(const auto& c: str) {
        if(c == '\0') break;
        if(c == '+') continue; 
        numbers[i] = c - '0';
        i++;
    }

    sort(numbers, numbers + i);

    for(int j = 0; j < i; j++) {
        j == i-1 ? printf("%d\n", numbers[j]) : printf("%d+", numbers[j]);
    }

    return 0;
}