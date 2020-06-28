#include <bits/stdc++.h>

using namespace std;

int main () {
    while(1) {
        char num1[255], num2[255];
        char result[255][510] = {0};
        if(scanf("%s %s", num1, num2) == EOF) break;

        if(!strcmp(num1, "0") || !strcmp(num2, "0")) {
            printf("0\n");
            continue;
        }

        int i = strlen(num2)-1;
        int resultcounter = 0;
        int length = 0;
        while(i >= 0) {
            int extra = 0;
            int resultdigit = strlen(num2) - 1 - i;

            for(int j = strlen(num1)-1; j >= 0; j--) {
                result[resultcounter][resultdigit] = ((num2[i] -'0') * (num1[j] -'0') + extra) % 10;
                extra = ((num2[i] -'0') * (num1[j] - '0') + extra)/10;

                //printf("Res: %d Extra: %d index: %d\n", result[resultcounter][resultdigit], extra, resultdigit);
            
                resultdigit++;
            }

            if(extra > 0) {
                result[resultcounter][resultdigit] = extra;
                resultdigit++;
            }

            length = max(length, resultdigit);
            resultcounter++;
            i--;
        }

        char finalres[510];
        int extra = 0;
        //printf("%d\n", length);
        for(int j = 0; j < length; j++) {
            int sum = 0;

            for(int k = 0; k < 255; k++) {
                sum += result[k][j];
            }

            sum = sum + extra;
            finalres[j] = sum % 10;
            extra = sum/10;
            //printf("INdex: %d, value: %d\n", j, finalres[j]);
        }
        
        if(extra > 0) {
            finalres[length] = extra;
            finalres[length+1] = '\0';
            length++;
        } else {
            finalres[length] = '\0';
        } 

        for(int j = length-1; j >= 0; j--) {
            printf("%d", finalres[j]);
        }
        printf("\n");

    }

    return 0;
}