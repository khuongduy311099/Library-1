#include <stdio.h>
#include <ctype.h>
#include <ctype.h>
#include <string.h>
#include "bookManagement.h"

void addBook(char bookISBNs[MAX_BOOKS][20],
             char bookTitles[MAX_BOOKS][100],
             char bookAuthors[MAX_BOOKS][50],
             char bookEditions[MAX_BOOKS][50],
             char bookPublishers[MAX_BOOKS][50],
             int bookYearsOfPublication[MAX_BOOKS],
             char bookGenres[MAX_BOOKS][50],
             float bookPrices[MAX_BOOKS],
             int bookQuantities[MAX_BOOKS],
             int &bookCount)
{
    if (bookCount < MAX_BOOKS)
    {
        printf("Adding a new book\n");

        // Read input for book details
        printf("Enter ISBN (book code): ");
        scanf("%s", bookISBNs[bookCount]);
        printf("Enter book title: ");
        scanf(" %[^\n]", bookTitles[bookCount]);
        printf("Enter author: ");
        scanf(" %[^\n]", bookAuthors[bookCount]);
        printf("Enter publisher: ");
        scanf(" %[^\n]", bookPublishers[bookCount]);
        printf("Enter edition: ");
        scanf(" %[^\n]", bookEditions[bookCount]);
        printf("Enter year of publication: ");
        scanf("%d", &bookYearsOfPublication[bookCount]);
        printf("Enter genre: ");
        scanf(" %[^\n]", bookGenres[bookCount]);
        printf("Enter price: ");
        scanf("%f", &bookPrices[bookCount]);
        printf("Enter number of books: ");
        scanf("%d", &bookQuantities[bookCount]);

        // Increment book count
        bookCount++;

        printf("Book added successfully!\n");
    }
    else
    {
        printf("Maximum book capacity reached. Cannot add more books.\n");
    }
}

void editBook(char bookISBNs[MAX_BOOKS][20],
              char bookTitles[MAX_BOOKS][100],
              char bookAuthors[MAX_BOOKS][50],
              char bookEditions[MAX_BOOKS][50],
              char bookPublishers[MAX_BOOKS][50],
              int bookYearsOfPublication[MAX_BOOKS],
              char bookGenres[MAX_BOOKS][50],
              float bookPrices[MAX_BOOKS],
              int bookQuantities[MAX_BOOKS],
              int &bookCount)
{
    char editChoice;
    char searchISBN[20];
    int foundIndex = -1;

    printf("Enter the ISBN of the book to edit: ");
    scanf("%s", searchISBN);

    // Search for the book by ISBN
    for (int i = 0; i < bookCount; i++)
    {
        if (strcmp(bookISBNs[i], searchISBN) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        printf("\nBook Found!\n");
        printf("Current Details:\n");
        printf("ISBN (Book Code): %s\n", bookISBNs[foundIndex]);
        printf("Book Title: %s\n", bookTitles[foundIndex]);
        printf("Author: %s\n", bookAuthors[foundIndex]);
        printf("Publisher: %s\n", bookPublishers[foundIndex]);
        printf("Edition: %s\n", bookEditions[foundIndex]);
        printf("Year of Publication: %d\n",
               bookYearsOfPublication[foundIndex]);
        printf("Genre: %s\n", bookGenres[foundIndex]);
        printf("Price: %.2f\n", bookPrices[foundIndex]);
        printf("Number of Books: %d\n", bookQuantities[foundIndex]);

        printf("\nSelect field to edit:\n");
        printf("a. Book Title\n");
        printf("b. Author\n");
        printf("c. Publisher\n");
        printf("d. Edition\n");
        printf("e. Year of Publication\n");
        printf("f. Genre\n");
        printf("g. Price\n");
        printf("h. Number of Books\n");
        printf("0. Cancel\n");
        printf("Enter your choice: ");
        scanf(" %c", &editChoice);

        switch (editChoice)
        {
        case 'a':
            printf("Enter new book title: ");
            scanf(" %[^\n]", bookTitles[foundIndex]);
            printf("Book title updated successfully!\n");
            break;
        case 'b':
            printf("Enter new author: ");
            scanf(" %[^\n]", bookAuthors[foundIndex]);
            printf("Author updated successfully!\n");
            break;
        case 'c':
            printf("Enter new publisher: ");
            scanf(" %[^\n]", bookPublishers[foundIndex]);
            printf("Publisher updated successfully!\n");
            break;
        case 'd':
            printf("Enter new edition: ");
            scanf(" %[^\n]", bookEditions[foundIndex]);
            printf("Edition updated successfully!\n");
            break;
        case 'e':
            printf("Enter new year of publication: ");
            scanf("%d", &bookYearsOfPublication[foundIndex]);
            printf("Year of publication updated successfully!\n");
            break;
        case 'f':
            printf("Enter new genre: ");
            scanf(" %[^\n]", bookGenres[foundIndex]);
            printf("Genre updated successfully!\n");
            break;
        case 'g':
            printf("Enter new price: ");
            scanf("%f", &bookPrices[foundIndex]);
            printf("Price updated successfully!\n");
            break;
        case 'h':
            printf("Enter new number of books: ");
            scanf("%d", &bookQuantities[foundIndex]);
            printf("Number of books updated successfully!\n");
            break;
        case '0':
            printf("Edit canceled.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    else
    {
        printf("Book not found with ISBN %s\n", searchISBN);
    }
}

void deleteBook(char bookISBNs[MAX_BOOKS][20],
                char bookTitles[MAX_BOOKS][100],
                char bookAuthors[MAX_BOOKS][50],
                char bookEditions[MAX_BOOKS][50],
                char bookPublishers[MAX_BOOKS][50],
                int bookYearsOfPublication[MAX_BOOKS],
                char bookGenres[MAX_BOOKS][50],
                float bookPrices[MAX_BOOKS],
                int bookQuantities[MAX_BOOKS],
                int &bookCount)
{
    char searchISBN[20];
    int foundIndex = -1;

    printf("Enter the ISBN of the book to delete: ");
    scanf("%s", searchISBN);

    // Search for the book by ISBN
    for (int i = 0; i < bookCount; i++)
    {
        if (strcmp(bookISBNs[i], searchISBN) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        // Shift all elements after foundIndex to the left
        for (int i = foundIndex; i < bookCount - 1; i++)
        {
            strcpy(bookISBNs[i], bookISBNs[i + 1]);
            strcpy(bookTitles[i], bookTitles[i + 1]);
            strcpy(bookAuthors[i], bookAuthors[i + 1]);
            strcpy(bookPublishers[i], bookPublishers[i + 1]);
            strcpy(bookEditions[i], bookEditions[i + 1]);
            bookYearsOfPublication[i] = bookYearsOfPublication[i + 1];
            strcpy(bookGenres[i], bookGenres[i + 1]);
            bookPrices[i] = bookPrices[i + 1];
            bookQuantities[i] = bookQuantities[i + 1];
        }
        // Decrement book count
        bookCount--;
        printf("Book with ISBN %s deleted successfully!\n", searchISBN);
    }
    else
    {
        printf("Book not found with ISBN %s\n", searchISBN);
    }
}

void searchBookByISBN(char bookISBNs[MAX_BOOKS][20],
                      char bookTitles[MAX_BOOKS][100],
                      char bookAuthors[MAX_BOOKS][50],
                      char bookEditions[MAX_BOOKS][50],
                      char bookPublishers[MAX_BOOKS][50],
                      int bookYearsOfPublication[MAX_BOOKS],
                      char bookGenres[MAX_BOOKS][50],
                      float bookPrices[MAX_BOOKS],
                      int bookQuantities[MAX_BOOKS],
                      int bookCount)
{
    char searchISBN[20];
    int foundIndex = -1;

    printf("Enter the ISBN of the book to search: ");
    scanf("%s", searchISBN);

    // Search for the book by ISBN
    for (int i = 0; i < bookCount; i++)
    {
        if (strcmp(bookISBNs[i], searchISBN) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        printf("\nBook Found!\n");
        printf("ISBN (Book Code): %s\n", bookISBNs[foundIndex]);
        printf("Book Title: %s\n", bookTitles[foundIndex]);
        printf("Author: %s\n", bookAuthors[foundIndex]);
        printf("Publisher: %s\n", bookPublishers[foundIndex]);
        printf("Edition: %s\n", bookEditions[foundIndex]);
        printf("Year of Publication: %d\n",
               bookYearsOfPublication[foundIndex]);
        printf("Genre: %s\n", bookGenres[foundIndex]);
        printf("Price: %.2f\n", bookPrices[foundIndex]);
        printf("Number of Books: %d\n", bookQuantities[foundIndex]);
    }
    else
    {
        printf("Book not found with ISBN %s\n", searchISBN);
    }
}

void searchBookByTitle(char bookISBNs[MAX_BOOKS][20],
                       char bookTitles[MAX_BOOKS][100],
                       char bookAuthors[MAX_BOOKS][50],
                       char bookEditions[MAX_BOOKS][50],
                       char bookPublishers[MAX_BOOKS][50],
                       int bookYearsOfPublication[MAX_BOOKS],
                       char bookGenres[MAX_BOOKS][50],
                       float bookPrices[MAX_BOOKS],
                       int bookQuantities[MAX_BOOKS],
                       int bookCount)
{
    char searchTitle[MAX_TITLE_LENGTH];
    int foundIndexes[MAX_BOOKS]; // To store indexes of found books
    int foundCount = 0;

    printf("Enter the title of the book to search: ");
    scanf(" %[^\n]", searchTitle);

    // Convert search title to lowercase for case-insensitive comparison
    char searchTitleLower[MAX_TITLE_LENGTH];
    strcpy(searchTitleLower, searchTitle);
    for (int i = 0; searchTitleLower[i]; i++)
    {
        searchTitleLower[i] = tolower(searchTitleLower[i]);
    }

    // Search for the book by title
    for (int i = 0; i < bookCount; i++)
    {
        char bookTitleLower[MAX_TITLE_LENGTH];
        strcpy(bookTitleLower, bookTitles[i]);
        for (int j = 0; bookTitleLower[j]; j++)
        {
            bookTitleLower[j] = tolower(bookTitleLower[j]);
        }
        if (strstr(bookTitleLower, searchTitleLower) != NULL)
        {
            foundIndexes[foundCount++] = i; // Store index of found book
        }
    }

    if (foundCount > 0)
    {
        printf("\n%d Books Found!\n", foundCount);
        for (int i = 0; i < foundCount; i++)
        {
            int index = foundIndexes[i];
            printf("\nBook %d:\n", i + 1);
            printf("ISBN (Book Code): %s\n", bookISBNs[index]);
            printf("Book Title: %s\n", bookTitles[index]);
            printf("Author: %s\n", bookAuthors[index]);
            printf("Publisher: %s\n", bookPublishers[index]);
            printf("Edition: %s\n", bookEditions[index]);
            printf("Year of Publication: %d\n", bookYearsOfPublication[index]);
            printf("Genre: %s\n", bookGenres[index]);
            printf("Price: %.2f\n", bookPrices[index]);
            printf("Number of Books: %d\n", bookQuantities[index]);
        }
    }
    else
    {
        printf("No books found with title %s\n", searchTitle);
    }
}