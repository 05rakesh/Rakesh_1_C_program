#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book {
    int book_id;
    char title[100];
    char author[100];
    int year_published;
    int available; 
};
void addBook(struct Book *books, int *num_books) {
    struct Book new_book;

    printf("Enter book ID: ");
    scanf("%d", &new_book.book_id);

    printf("Enter book title: ");
    scanf(" %[^\n]", new_book.title);

    printf("Enter author name: ");
    scanf(" %[^\n]", new_book.author);

    printf("Enter year published: ");
    scanf("%d", &new_book.year_published);

    new_book.available = 1; 

    
    books[*num_books] = new_book;
    (*num_books)++;

    printf("Book added successfully!\n");
}


struct Book *searchBook(struct Book *books, int num_books, int book_id) {
    for (int i = 0; i < num_books; i++) {
        if (books[i].book_id == book_id) {
            return &books[i]; 
        }
    }
    return NULL; 
}


void deleteBook(struct Book *books, int *num_books, int book_id) {
    struct Book *book_to_delete = searchBook(books, *num_books, book_id);

    if (book_to_delete != NULL) {
       
        for (int i = book_to_delete - books; i < *num_books - 1; i++) {
            books[i] = books[i + 1];
        }
        (*num_books)--;
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found!\n");
    }
}


void displayBooks(struct Book *books, int num_books) {
    if (num_books == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("-----------------------------------------------------\n");
    printf("| Book ID | Title               | Author          | Year | Availability |\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("| %6d | %-18s | %-15s | %4d | %12s |\n",
               books[i].book_id, books[i].title, books[i].author,
               books[i].year_published, books[i].available ? "Available" : "Borrowed");
    }
    printf("-----------------------------------------------------\n");
}

int main() {
    struct Book books[100]; 
    int num_books = 0; 
    int choice;

    while (1) {
        printf("\nLibrary Book Management System\n");
        printf("1. Add a book\n");
        printf("2. Search for a book\n");
        printf("3. Delete a book\n");
        printf("4. Display all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &num_books);
                break;
            case 2: {
                int book_id;
                printf("Enter book ID to search: ");
                scanf("%d", &book_id);
                struct Book *found_book = searchBook(books, num_books, book_id);
                if (found_book != NULL) {
                    printf("Book found:\n");
                    printf("Book ID: %d\n", found_book->book_id);
                    printf("Title: %s\n", found_book->title);
                    printf("Author: %s\n", found_book->author);
                    printf("Year Published: %d\n", found_book->year_published);
                    printf("Availability: %s\n", found_book->available ? "Available" : "Borrowed");
                } else {
                    printf("Book not found!\n");
                }
                break;
            }
            case 3: {
                int book_id;
                printf("Enter book ID to delete: ");
                scanf("%d", &book_id);
                deleteBook(books, &num_books, book_id);
                break;
            }
            case 4:
                displayBooks(books, num_books);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}