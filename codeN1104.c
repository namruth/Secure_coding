#include <stdio.h>
#include <string.h>

struct Books {
    char title[50];
    char author[50];
    int book_id;
};

struct Books book1 = {.title = "God of small things", .author = "Arundathi Roy", .book_id = 111};
struct Books book2 = {.title = "Piranesi", .author = "Susanna Clarke", .book_id = 112};
struct Books book3 = {.title = "Count of Monte Cristo", .author = "Alexander Dumas", .book_id = 113};
struct Books book4 = {.title = "Dune", .author = "Frank Herbert", .book_id = 114};


void printBookDetails(struct Books *bookToPrint) {
    printf("Book Id: %d\n", bookToPrint->book_id);
    printf("Book Author: %s\n", bookToPrint -> author);
    printf("Book Name: %s\n", bookToPrint -> title);
}

struct Books* checkLibrary(int book_id) {
    if (book_id == book1.book_id) {
        return &book1;
    } else if (book_id == book2.book_id) {
        return &book2;
    }
    return NULL;
}

int main() {
    int bookId;
    printf("Enter book id for details:");
    scanf("%d", &bookId);
    struct Books* bookDetails = checkLibrary(bookId);
    printBookDetails(bookDetails);
    return (0);
}

