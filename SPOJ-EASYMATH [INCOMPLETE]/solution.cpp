#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if(a == 0) return b;

    gcd(b % a, a);
}

long long lcm(long long a, long long b) {
    return (a*b)/gcd(a, b);
}

int main () {
    int t;
    scanf("%d", &t);

    for(;t > 0; t--) {
        long long lower, upper, a, d;
        long long total = 0;
        scanf("%lld %lld %lld %lld", &lower, &upper, &a, &d);

        long long occurences[5];
        for(int i = 0; i < 5; i++) {
            occurences[i] = (upper-lower+1)/(a +i*d);

            if((upper-lower+1) % (a + i*d) != 0) {
                long long counter = 1, start = lower;

                while(start % (a + i*d) != 0) {
                    counter++;
                    start++;
                }
                
                if((upper-lower+1) % (a + i*d) == counter) occurences[i]++;
            }

            total += occurences[i];
        }

        //printf("%lld %lld %lld %lld %lld\n", occurences[0], occurences[1], occurences[2], occurences[3], occurences[4]);

        for (int i = 0; i < 5; i++) {
            for(int j = i; j < 5; j++) {
                long long LCM = lcm(a + i*d, a + j*d);
                long long count = (upper-lower+1)/LCM;
                
                if((upper-lower+1) % LCM != 0) {

                }
            }
        }

    }    

    return 0;
}