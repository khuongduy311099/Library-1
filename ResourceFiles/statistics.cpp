#include <stdio.h>
#include <string.h>
#include "statistics.h"

void bookBorrowStatistics(int bookCount, char bookGenres[MAX_BOOKS][50])
{
    // Implement statistics on the number of books by genre
    int genreCount[MAX_BOOKS] = {0}; // Array to store count of books for each genre
    int totalBooks = 0;              // Total number of books

    // Count books by genre
    for (int i = 0; i < bookCount; i++)
    {
        // Increment count for the genre of the current book
        for (int j = 0; j < bookCount; j++)
        {
            if (strcmp(bookGenres[i], bookGenres[j]) == 0)
            {
                genreCount[i]++;
            }
        }
        totalBooks++;
    }

    // Display statistics
    printf("Book Borrow Statistics by Genre:\n");
    for (int i = 0; i < bookCount; i++)
    {
        printf("%s: %d books (%.2f%%)\n", bookGenres[i], genreCount[i],
               (float)genreCount[i] / totalBooks);
    }
}

// Other statistics functions

void readerGenderStatistics(
    int readerCount,
    char readerGenders[MAX_READERS][10])
{
    int maleCount = 0;
    int femaleCount = 0;

    // Count readers by gender
    for (int i = 0; i < readerCount; i++)
    {
        if (strcmp(readerGenders[i], "Male") == 0)
        {
            maleCount++;
        }
        else if (strcmp(readerGenders[i], "Female") == 0)
        {
            femaleCount++;
        }
    }

    // Display statistics
    printf("Reader Gender Statistics:\n");
    printf("Male: %d\n", maleCount);
    printf("Female: %d\n", femaleCount);
}