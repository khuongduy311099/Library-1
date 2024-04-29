#include "defaultMenu.h"
#include "readerManagement.h"
#include "bookManagement.h"
#include "statistics.h"
void displayMenu()
{
    printf("\n===== Library Management System Menu =====\n");
    printf("1. Reader Management\n");
    printf("2. Book Management\n");
    printf("3. Make Borrow Form\n");
    printf("4. Make Return Form\n");
    printf("5. Basic Statistics\n");
    printf("0. Exit\n");
}
void readerManagement(char readerCodes[MAX_READERS][10],
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
    char choice;
    do
    {
        printf("\n===== Reader Management Menu =====\n");
        printf("a. See the list of readers in the library\n");
        printf("b. Add a reader\n");
        printf("c. Edit a reader's information\n");
        printf("d. Delete a reader's information\n");
        printf("e. Search readers by ID card\n");
        // printf("f. Search books by name\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            // See the list of readers in the library
            printf("\n===== List of Readers =====\n");
            for (int i = 0; i < readerCount; i++)
            {
                printf("Reader Code: %s\n", readerCodes[i]);
                printf("Name: %s\n", readerNames[i]);
                printf("ID Card: %s\n", readerIDs[i]);
                printf("Year of Birth: %d\n", readerYearsOfBirth[i]);
                printf("Gender: %s\n", readerGenders[i]);
                printf("Email: %s\n", readerEmails[i]);
                printf("Address: %s\n", readerAddresses[i]);
                printf("Creation Date: %s\n", readerCreationDates[i]);
                printf("Expiration Date: %s\n", readerExpirationDates[i]);
                printf("------------------------------------\n");
            }
            break;
        case 'b':
            addReader(readerCodes,
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
        case 'c':
            editReader(readerCodes,
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
        case 'd':
            deleteReader(readerCodes,
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
        case 'e':
            searchReaderByID(readerCodes,
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
        case '0':
            printf("Returning to Main Menu...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '0');
}

void bookManagement(
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
    char choice;
    do
    {
        printf("\n===== Book Management Menu =====\n");
        printf("a. See a list of books in the library\n");
        printf("b. Add a book\n");
        printf("c. Edit information of a book\n");
        printf("d. Delete book information\n");
        printf("e. Search books by ISBN\n");
        printf("f. Search for books by title\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            // See a list of books in the library
            printf("\n===== List of Books =====\n");
            for (int i = 0; i < bookCount; i++)
            {
                printf("ISBN: %s\n", bookISBNs[i]);
                printf("Title: %s\n", bookTitles[i]);
                printf("Author: %s\n", bookAuthors[i]);
                printf("Publisher: %s\n", bookPublishers[i]);
                printf("Year of Publication: %d\n", bookYearsOfPublication[i]);
                printf("Genre: %s\n", bookGenres[i]);
                printf("Price: %.2f\n", bookPrices[i]);
                printf("Quantity: %d\n", bookQuantities[i]);
                printf("------------------------------------\n");
            }
            break;
        case 'b':
            addBook(
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
        case 'c':
            editBook(bookISBNs,
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
        case 'd':
            deleteBook(bookISBNs,
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
        case 'e':
            searchBookByISBN(bookISBNs,
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
        case 'f':
            searchBookByTitle(bookISBNs,
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
        case '0':
            printf("Returning to Main Menu...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '0');
}
void basicStatistics(
    int bookCount,
    int readerCount,
    int borrowCount,
    char readerGenders[MAX_READERS][10],
    char bookGenres[MAX_BOOKS][50])
{
    char choice;
    do
    {
        printf("\n===== Basic Statistics Menu =====\n");
        printf("a. Statistics on the number of books in the library\n");
        printf("b. Statistics on the number of books by genre\n");
        printf("c. Statistics on the number of readers\n");
        printf("d. Statistics on the number of readers by gender\n");
        printf("e. Statistics on the number of books being borrowed\n");
        printf("f. Statistics on the list of readers who are late\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            // Statistics on the number of books in the library
            printf("Number of books in the library: %d\n", bookCount);
            break;
        case 'b':
            // Statistics on the number of books by genre
            bookBorrowStatistics(bookCount, bookGenres);
            break;
        case 'c':
            // Statistics on the number of readers
            printf("Number of readers in the library: %d\n", readerCount);
            break;
        case 'd':
            readerGenderStatistics(readerCount, readerGenders);
            break;
        case 'e':
            // Statistics on the number of books being borrowed
            printf("Number of books being borrowed: %d\n", borrowCount);
            break;
        case 'f':
            // Statistics on the list of readers who are late
            // Implement this functionality
            break;
        case '0':
            printf("Returning to Main Menu...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '0');
}