#include<stdio.h>
struct Book {
    char title[50];
    char author[50];
    int year;
};
 int main() {
     struct Book b1;
     printf("enter title:\n");
     scanf("%s", b1.title);
     printf("enter author name: \n");
     scanf("%s", b1.author);
     printf("enter year: ");
     scanf("%d", &b1.year);
     printf("Title: %s\nAuthor: %s\nYear: %d\n", b1.title, b1.author, b1.year);
     return 0;
 }