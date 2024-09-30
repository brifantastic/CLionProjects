#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book_struct {
    char title[50];
    float price;
} Book;

Book InitBook() {
    Book newbook;
    strcpy(newbook.title, "blah");
    newbook.price=9.99;
    return newbook;
}

int main() {

    Book a = InitBook();
    printf("%s\n", a.title);
    printf("%f\n", a.price);

    return 0;
}

