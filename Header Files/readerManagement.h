#pragma once

#include "constants.h"

void addReader(char readerCodes[MAX_READERS][10],
               char readerNames[MAX_READERS][50],
               char readerIDs[MAX_READERS][20],
               int readerYearsOfBirth[MAX_READERS],
               char readerGenders[MAX_READERS][10],
               char readerEmails[MAX_READERS][50],
               char readerAddresses[MAX_READERS][100],
               char readerCreationDates[MAX_READERS][20],
               char readerExpirationDates[MAX_READERS][20],
               int &readerCount);
void editReader(char readerCodes[MAX_READERS][10],
                char readerNames[MAX_READERS][50],
                char readerIDs[MAX_READERS][20],
                int readerYearsOfBirth[MAX_READERS],
                char readerGenders[MAX_READERS][10],
                char readerEmails[MAX_READERS][50],
                char readerAddresses[MAX_READERS][100],
                char readerCreationDates[MAX_READERS][20],
                char readerExpirationDates[MAX_READERS][20],
                int &readerCount);
void deleteReader(char readerCodes[MAX_READERS][10],
                  char readerNames[MAX_READERS][50],
                  char readerIDs[MAX_READERS][20],
                  int readerYearsOfBirth[MAX_READERS],
                  char readerGenders[MAX_READERS][10],
                  char readerEmails[MAX_READERS][50],
                  char readerAddresses[MAX_READERS][100],
                  char readerCreationDates[MAX_READERS][20],
                  char readerExpirationDates[MAX_READERS][20],
                  int &readerCount);
void searchReaderByID(char readerCodes[MAX_READERS][10],
                      char readerNames[MAX_READERS][50],
                      char readerIDs[MAX_READERS][20],
                      int readerYearsOfBirth[MAX_READERS],
                      char readerGenders[MAX_READERS][10],
                      char readerEmails[MAX_READERS][50],
                      char readerAddresses[MAX_READERS][100],
                      char readerCreationDates[MAX_READERS][20],
                      char readerExpirationDates[MAX_READERS][20],
                      int readerCount);