#include <stdio.h>
#include <stdlib.h>
#include "Coin.h"

char* FlipMe(Coin coin, int numFlips) {

    char* flipList = malloc(20);  // flipList is a list of flips

    for (int i =0; i<numFlips; i++) {
        coin = Flip(coin);
        if (IsHeads(coin))   // Either increment streak or set streak to zero
            flipList[i] = 'H';
        else
            flipList[i] = 'T';
    }

    return flipList;  // Return total flips required to match goal
}

int main() {
    Coin coin = InitCoin(14);
    int numFlips = 15;
    char* flips = FlipMe(coin, numFlips);
    printf("Flips: %p\n", flips);
    for (int i = 0; i < numFlips; i++) {
        printf("%c", flips[i]);
    }
    free(flips);

    return 0;
}