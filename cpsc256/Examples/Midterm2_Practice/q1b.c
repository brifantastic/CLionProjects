#include <stdio.h>
#include <stdlib.h>

int main() {
    int sum = 0;
    int i = 0;

    while (i < 50) {
        sum = sum + i;
        i = i + 1;
    }

    printf("Sum of first 50 numbers is %d\n", sum);
}

