#include <string.h>
#include <stdio.h>
#include "initializeData.h"
void initializeDefaultUsers(
    char readerCodes[MAX_READERS][10],
    char readerNames[MAX_READERS][50],
    char readerIDs[MAX_READERS][20],
    int readerYearsOfBirth[MAX_READERS],
    char readerGenders[MAX_READERS][10],
    char readerEmails[MAX_READERS][50],
    char readerAddresses[MAX_READERS][100],
    char readerCreationDates[MAX_READERS][20],
    char readerExpirationDates[MAX_READERS][20],
    int &readerCount)
{

    for (int i = 0; i < 10; i++)
    {
        char code[10];
        sprintf(code, "RC00%d", i + 1);
        strcpy(readerCodes[i], code);
        sprintf(readerNames[i], "User%d", i + 1);
        sprintf(readerIDs[i], "ID00%d", i + 1);
        readerYearsOfBirth[i] = 1990 + i;
        strcpy(readerGenders[i], (i % 2 == 0) ? "Male" : "Female");
        sprintf(readerEmails[i], "user%d@example.com", i + 1);
        sprintf(readerAddresses[i], "%d Street, City, Country", i + 1);
        strcpy(readerCreationDates[i], "2022-01-01 10:00:00");
        strcpy(readerExpirationDates[i], "2026-01-01 10:00:00");
        readerCount++;
    }
}

void initializeDefaultBooks(
    char bookISBNs[MAX_BOOKS][20],
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
    // Default books
    for (int i = 0; i < 10; i++)
    {
        char isbn[20];
        sprintf(isbn, "ISBN00%d", i + 1);
        strcpy(bookISBNs[i], isbn);
        sprintf(bookTitles[i], "Book%d", i + 1);
        sprintf(bookAuthors[i], "Author%d", i + 1);
        sprintf(bookPublishers[i], "Publisher%d", i + 1);
        sprintf(bookEditions[i], "%dth Edition", i + 1);
        bookYearsOfPublication[i] = 2020 - i;
        sprintf(bookGenres[i], "Genre%d", i + 1);
        bookPrices[i] = 20.0 + i;
        bookQuantities[i] = 5 + i;
        bookCount++;
    }
}