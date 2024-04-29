#pragma once

#include "constants.h"

void makeBorrowForm(char borrowReaderCodes[MAX_BORROW_TICKETS][10],
                    char borrowDates[MAX_BORROW_TICKETS][20],
                    char expectedReturnDates[MAX_BORROW_TICKETS][20],
                    char actualReturnDates[MAX_BORROW_TICKETS][20],
                    char borrowedISBNs[MAX_BORROW_TICKETS][20],
                    int &borrowCount);
void makeReturnForm(char borrowReaderCodes[MAX_BORROW_TICKETS][10],
                    char borrowDates[MAX_BORROW_TICKETS][20],
                    char expectedReturnDates[MAX_BORROW_TICKETS][20],
                    char actualReturnDates[MAX_BORROW_TICKETS][20],
                    char borrowedISBNs[MAX_BORROW_TICKETS][20],
                    int &borrowCount);