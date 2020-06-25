#include <bits/stdc++.h>

using namespace std;

int main () {
    int nwires;
    scanf("%d", &nwires);

    int wires[nwires];

    for(int i = 0; i < nwires; i++) {
        scanf("%d", &wires[i]);
    }

    int shots;
    scanf("%d", &shots);

    int index, wireno;
    for(int i = 0; i < shots; i++) {
        scanf("%d %d", &wireno, &index);
        wireno--;
        index--;
        if(wireno == 0 && wireno == nwires-1) {
            //one wire
            wires[wireno] = 0;
        } else if(wireno == 0) {
            //Cant mvoe down one
            wires[wireno+1] += wires[wireno]-index-1;
            wires[wireno] = 0;
        } else if(wireno == nwires-1) {
            wires[wireno-1] += index;
            wires[wireno] = 0;
        } else {
            wires[wireno+1] += wires[wireno] - index -1;
            wires[wireno-1] += index;
            wires[wireno] = 0;
        }
    }

    for(int i = 0; i < nwires; i++) {
        printf("%d\n", wires[i]);
    }

    return 0;
}