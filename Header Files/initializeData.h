#pragma once

#include "constants.h"
void initializeDefaultUsers(char readerCodes[MAX_READERS][10],
                            char readerNames[MAX_READERS][50],
                            char readerIDs[MAX_READERS][20],
                            int readerYearsOfBirth[MAX_READERS],
                            char readerGenders[MAX_READERS][10],
                            char readerEmails[MAX_READERS][50],
                            char readerAddresses[MAX_READERS][100],
                            char readerCreationDates[MAX_READERS][20],
                            char readerExpirationDates[MAX_READERS][20],
                            int &readerCount);
void initializeDefaultBooks(char bookISBNs[MAX_BOOKS][20],
                            char bookTitles[MAX_BOOKS][100],
                            char bookAuthors[MAX_BOOKS][50],
                            char bookEditions[MAX_BOOKS][50],
                            char bookPublishers[MAX_BOOKS][50],
                            int bookYearsOfPublication[MAX_BOOKS],
                            char bookGenres[MAX_BOOKS][50],
                            float bookPrices[MAX_BOOKS],
                            int bookQuantities[MAX_BOOKS],
                            int &bookCount);