#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book_struct {
    char title[50];
    double price;
} Book;

Book InitBook(char title[], double price) {
    Book b;
    strcpy(b.title, title);
    b.price = price;
    return b;
}   

void PrintBook(Book b) {
    printf("Title: %s\n", b.title);
    printf("Price: %.2f\n", b.price);
}

int main() {
    Book b1 = InitBook("C Programming", 9.99);
    PrintBook(b1);
    return 0;
}

