#include <stdio.h>
#include <stdlib.h>

int main() {

    int sum=0;
    int i=0;

    while (i<50) {
        sum = sum + (i+1);
        i++;
    }
    printf("%d",sum);

    return 0;
}

