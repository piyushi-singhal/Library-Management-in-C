#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_STRING_LENGTH 30

struct Library
{
    char bookName[MAX_STRING_LENGTH];
    char author[MAX_STRING_LENGTH];
    int pages;
    float price;
};

// Function to display book information
void displayBook(struct Library book)
{
    printf("Book Name: %s\n", book.bookName);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
    printf("Price: %.2f\n", book.price);
    printf("\n");
}

int main()
{
    struct Library books[MAX_BOOKS];
    char authorName[MAX_STRING_LENGTH], bookTitle[MAX_STRING_LENGTH];
    int option, bookCount;
    bookCount = 0;

    do
    {
        // Menu
        printf("\n\n1. Add book information\n2. Display all book information\n");
        printf("3. List all books of a given author\n");
        printf("4. List the details of a specified book\n");
        printf("5. List the count of books in the library\n");
        printf("6. Exit\n\n");

        printf("\n\nEnter one of the above options: ");
        scanf("%d", &option);

        switch (option)
        {
        // Add book
        case 1:
            printf("Enter book name: ");
            scanf("%s", books[bookCount].bookName);

            printf("Enter author name: ");
            scanf("%s", books[bookCount].author);

            printf("Enter pages: ");
            scanf("%d", &books[bookCount].pages);

            printf("Enter price: ");
            scanf("%f", &books[bookCount].price);
            bookCount++;
            break;

        // Display all books
        case 2:
            if (bookCount == 0)
            {
                printf("No books entered yet.\n");
            }
            else
            {
                printf("All entered books:\n");
                for (int i = 0; i < bookCount; i++)
                {
                    displayBook(books[i]);
                }
            }
            break;

        // List books by author
        case 3:
            printf("Enter author name: ");
            scanf("%s", authorName);
            for (int i = 0; i < bookCount; i++)
            {
                if (strcmp(authorName, books[i].author) == 0)
                {
                    displayBook(books[i]);
                }
            }
            break;

        // List details of a specified book
        case 4:
            printf("Enter book name: ");
            scanf("%s", bookTitle);
            for (int i = 0; i < bookCount; i++)
            {
                if (strcmp(bookTitle, books[i].bookName) == 0)
                {
                    displayBook(books[i]);
                }
            }
            break;

        // List the count of books
        case 5:
            printf("\nNumber of books in the library: %d\n", bookCount);
            break;

        // Exit
        case 6:
            exit(0);
        }

    } while (option != 6);

    return 0;
}