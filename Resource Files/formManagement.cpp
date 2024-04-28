#include <statistics.h>
#include <stdio.h>

void makeBorrowForm(
    char borrowReaderCodes[MAX_BORROW_TICKETS][10],
    char borrowDates[MAX_BORROW_TICKETS][20],
    char expectedReturnDates[MAX_BORROW_TICKETS][20],
    char actualReturnDates[MAX_BORROW_TICKETS][20],
    char borrowedISBNs[MAX_BORROW_TICKETS][20],
    int &borrowCount)
{
    // Implement function to make borrow form
    char readerCode[20];
    char borrowDate[20];
    char returnDate[20];
    char ISBNs[MAX_BOOKS][20];
    int numBooks;

    // Get input from user
    printf("Enter reader code: ");
    scanf("%s", readerCode);
    printf("Enter borrow date: ");
    scanf("%s", borrowDate);
    printf("Enter return date: ");
    scanf("%s", returnDate);
    printf("Enter number of books: ");
    scanf("%d", &numBooks);
    printf("Enter ISBNs of books: ");
    for (int i = 0; i < numBooks; i++)
    {
        scanf("%s", ISBNs[i]);
    }

    // Display borrow form
    printf("\nBorrow Form:\n");
    printf("Reader Code: %s\n", readerCode);
    printf("Borrow Date: %s\n", borrowDate);
    printf("Return Date: %s\n", returnDate);
    printf("Books Borrowed:\n");
    for (int i = 0; i < numBooks; i++)
    {
        printf("%d. ISBN: %s\n", i + 1, ISBNs[i]);
    }
}

void makeReturnForm(
    char borrowReaderCodes[MAX_BORROW_TICKETS][10],
    char borrowDates[MAX_BORROW_TICKETS][20],
    char expectedReturnDates[MAX_BORROW_TICKETS][20],
    char actualReturnDates[MAX_BORROW_TICKETS][20],
    char borrowedISBNs[MAX_BORROW_TICKETS][20],
    int &borrowCount)
{
    // Implement function to make return form
    char readerCode[20];
    char returnDate[20];
    char ISBNs[MAX_BOOKS][20];
    int numBooks;

    // Get input from user
    printf("Enter reader code: ");
    scanf("%s", readerCode);
    printf("Enter return date: ");
    scanf("%s", returnDate);
    printf("Enter number of books: ");
    scanf("%d", &numBooks);
    printf("Enter ISBNs of books: ");
    for (int i = 0; i < numBooks; i++)
    {
        scanf("%s", ISBNs[i]);
    }

    // Display return form
    printf("\nReturn Form:\n");
    printf("Reader Code: %s\n", readerCode);
    printf("Return Date: %s\n", returnDate);
    printf("Books Returned:\n");
    for (int i = 0; i < numBooks; i++)
    {
        printf("%d. ISBN: %s\n", i + 1, ISBNs[i]);
    }
}