#include "initializeData.h"
#include "defaultMenu.h"
#include "bookManagement.h"
#include "formManagement.h"
#include "constants.h"
int main()
{

    char choice;
    // Reader information
    char readerCodes[MAX_READERS][10];
    char readerNames[MAX_READERS][50];
    char readerIDs[MAX_READERS][20];
    int readerYearsOfBirth[MAX_READERS];
    char readerGenders[MAX_READERS][10];
    char readerEmails[MAX_READERS][50];
    char readerAddresses[MAX_READERS][100];
    char readerCreationDates[MAX_READERS][20];
    char readerExpirationDates[MAX_READERS][20];
    int readerCount = 0;

    // Book information
    char bookISBNs[MAX_BOOKS][20];
    char bookTitles[MAX_BOOKS][100];
    char bookAuthors[MAX_BOOKS][50];
    char bookEditions[MAX_BOOKS][50];
    char bookPublishers[MAX_BOOKS][50];
    int bookYearsOfPublication[MAX_BOOKS];
    char bookGenres[MAX_BOOKS][50];
    float bookPrices[MAX_BOOKS];
    int bookQuantities[MAX_BOOKS];
    int bookCount = 0;

    // Borrow ticket information
    char borrowReaderCodes[MAX_BORROW_TICKETS][10];
    char borrowDates[MAX_BORROW_TICKETS][20];
    char expectedReturnDates[MAX_BORROW_TICKETS][20];
    char actualReturnDates[MAX_BORROW_TICKETS][20];
    char borrowedISBNs[MAX_BORROW_TICKETS][20];
    int borrowCount = 0;

    initializeDefaultUsers(readerCodes,
                           readerNames,
                           readerIDs,
                           readerYearsOfBirth,
                           readerGenders,
                           readerEmails,
                           readerAddresses,
                           readerCreationDates,
                           readerExpirationDates,
                           readerCount);

    initializeDefaultBooks(bookISBNs,
                           bookTitles,
                           bookAuthors,
                           bookEditions,
                           bookPublishers,
                           bookYearsOfPublication,
                           bookGenres,
                           bookPrices,
                           bookQuantities,
                           bookCount);
    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case '1':
            readerManagement(
                readerCodes,
                readerNames,
                readerIDs,
                readerYearsOfBirth,
                readerGenders,
                readerEmails,
                readerAddresses,
                readerCreationDates,
                readerExpirationDates,
                readerCount);
            break;
        case '2':
            bookManagement(
                bookISBNs,
                bookTitles,
                bookAuthors,
                bookEditions,
                bookPublishers,
                bookYearsOfPublication,
                bookGenres,
                bookPrices,
                bookQuantities,
                bookCount);
            break;
        case '3':
            makeBorrowForm(borrowReaderCodes,
                           borrowDates,
                           expectedReturnDates,
                           actualReturnDates,
                           borrowedISBNs,
                           borrowCount);
            break;
        case '4':
            makeReturnForm(borrowReaderCodes,
                           borrowDates,
                           expectedReturnDates,
                           actualReturnDates,
                           borrowedISBNs,
                           borrowCount);
            break;
        case '5':
            basicStatistics(bookCount, readerCount, borrowCount, readerGenders, bookGenres);
            break;
        case '0':
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '0');

    return 0;
}
