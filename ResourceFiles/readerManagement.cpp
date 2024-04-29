#include <stdio.h>
#include <time.h>
#include <string.h>
#include "readerManagement.h"

void addReader(char readerCodes[MAX_READERS][10],
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
    if (readerCount < MAX_READERS)
    {
        printf("Adding a new reader\n");

        // Read input for reader details
        printf("Enter reader code: ");
        scanf("%s", readerCodes[readerCount]);
        printf("Enter full name: ");
        scanf(" %[^\n]", readerNames[readerCount]);
        printf("Enter ID card: ");
        scanf("%s", readerIDs[readerCount]);
        printf("Enter year of birth: ");
        scanf("%d", &readerYearsOfBirth[readerCount]);
        printf("Enter gender: ");
        scanf("%s", readerGenders[readerCount]);
        printf("Enter email: ");
        scanf("%s", readerEmails[readerCount]);
        printf("Enter address: ");
        scanf(" %[^\n]", readerAddresses[readerCount]);

        // Get current time
        time_t currentTime;
        time(&currentTime);

        // Format current time as string
        strftime(readerCreationDates[readerCount], 20, "%Y-%m-%d %H:%M:%S",
                 localtime(&currentTime));

        // Set expiration date
        // Add 48 months to the current time
        struct tm *expirationDate = localtime(&currentTime);
        expirationDate->tm_mon += 48;
        mktime(expirationDate);
        strftime(readerExpirationDates[readerCount], 20, "%Y-%m-%d %H:%M:%S",
                 expirationDate);

        // Increment reader count
        (readerCount)++;

        printf("Reader added successfully!\n");
    }
    else
    {
        printf("Maximum reader capacity reached. Cannot add more readers.\n");
    }
}

void editReader(
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
    char editChoice;
    char searchID[20];
    int foundIndex = -1;

    printf("Enter the ID card to edit: ");
    scanf("%s", searchID);

    // Search for the reader by ID card
    for (int i = 0; i < readerCount; i++)
    {
        if (strcmp(readerIDs[i], searchID) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        printf("\nReader Found!\n");
        printf("Current Details:\n");
        printf("Reader Code: %s\n", readerCodes[foundIndex]);
        printf("Full Name: %s\n", readerNames[foundIndex]);
        printf("ID Card: %s\n", readerIDs[foundIndex]);
        printf("Year of Birth: %d\n", readerYearsOfBirth[foundIndex]);
        printf("Gender: %s\n", readerGenders[foundIndex]);
        printf("Email: %s\n", readerEmails[foundIndex]);
        printf("Address: %s\n", readerAddresses[foundIndex]);
        printf("Creation Date: %s\n", readerCreationDates[foundIndex]);
        printf("Expiration Date: %s\n", readerExpirationDates[foundIndex]);

        printf("\nSelect field to edit:\n");
        printf("a. Full Name\n");
        printf("b. Year of Birth\n");
        printf("c. Gender\n");
        printf("d. Email\n");
        printf("e. Address\n");
        printf("0. Cancel\n");
        printf("Enter your choice: ");
        scanf(" %c", &editChoice);

        switch (editChoice)
        {
        case 'a':
            printf("Enter new full name: ");
            scanf(" %[^\n]", readerNames[foundIndex]);
            printf("Full name updated successfully!\n");
            break;
        case 'b':
            printf("Enter new year of birth: ");
            scanf("%d", &readerYearsOfBirth[foundIndex]);
            printf("Year of birth updated successfully!\n");
            break;
        case 'c':
            printf("Enter new gender: ");
            scanf("%s", readerGenders[foundIndex]);
            printf("Gender updated successfully!\n");
            break;
        case 'd':
            printf("Enter new email: ");
            scanf("%s", readerEmails[foundIndex]);
            printf("Email updated successfully!\n");
            break;
        case 'e':
            printf("Enter new address: ");
            scanf(" %[^\n]", readerAddresses[foundIndex]);
            printf("Address updated successfully!\n");
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
        printf("Reader not found with ID card %s\n", searchID);
    }
}

void deleteReader(
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
    char searchID[20];
    int foundIndex = -1;

    printf("Enter the ID card of the reader to delete: ");
    scanf("%s", searchID);

    // Search for the reader by ID card
    for (int i = 0; i < readerCount; i++)
    {
        if (strcmp(readerIDs[i], searchID) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        // Shift all elements after foundIndex to the left
        for (int i = foundIndex; i < readerCount - 1; i++)
        {
            strcpy(readerCodes[i], readerCodes[i + 1]);
            strcpy(readerNames[i], readerNames[i + 1]);
            strcpy(readerIDs[i], readerIDs[i + 1]);
            readerYearsOfBirth[i] = readerYearsOfBirth[i + 1];
            strcpy(readerGenders[i], readerGenders[i + 1]);
            strcpy(readerEmails[i], readerEmails[i + 1]);
            strcpy(readerAddresses[i], readerAddresses[i + 1]);
            strcpy(readerCreationDates[i], readerCreationDates[i + 1]);
            strcpy(readerExpirationDates[i], readerExpirationDates[i + 1]);
        }
        // Decrement reader count
        (readerCount)--;
        printf("Reader with ID card %s deleted successfully!\n", searchID);
    }
    else
    {
        printf("Reader not found with ID card %s\n", searchID);
    }
}

void searchReaderByID(
    char readerCodes[MAX_READERS][10],
    char readerNames[MAX_READERS][50],
    char readerIDs[MAX_READERS][20],
    int readerYearsOfBirth[MAX_READERS],
    char readerGenders[MAX_READERS][10],
    char readerEmails[MAX_READERS][50],
    char readerAddresses[MAX_READERS][100],
    char readerCreationDates[MAX_READERS][20],
    char readerExpirationDates[MAX_READERS][20],
    int readerCount)
{
    char searchID[20];
    int foundIndex = -1;

    printf("Enter the ID card to search: ");
    scanf("%s", searchID);

    // Search for the reader by ID card
    for (int i = 0; i < readerCount; i++)
    {
        if (strcmp(readerIDs[i], searchID) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        printf("\nReader Found!\n");
        printf("Reader Code: %s\n", readerCodes[foundIndex]);
        printf("Full Name: %s\n", readerNames[foundIndex]);
        printf("ID Card: %s\n", readerIDs[foundIndex]);
        printf("Year of Birth: %d\n", readerYearsOfBirth[foundIndex]);
        printf("Gender: %s\n", readerGenders[foundIndex]);
        printf("Email: %s\n", readerEmails[foundIndex]);
        printf("Address: %s\n", readerAddresses[foundIndex]);
        printf("Creation Date: %s\n", readerCreationDates[foundIndex]);
        printf("Expiration Date: %s\n", readerExpirationDates[foundIndex]);
    }
    else
    {
        printf("Reader not found with ID card %s\n", searchID);
    }
}