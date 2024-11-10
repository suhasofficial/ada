#include <string.h>
#include <stdio.h>

void Shifttable(char P[], int t[]);
int horsepool(char T[], char P[], int t[]);

int main()
{
    char text[200], pattern[200];
    int s[256]; // You need a larger size, typically 256 for all ASCII characters

    printf("Enter the source string: ");
    fgets(text, sizeof(text), stdin);  // Corrected line
    printf("Enter the Pattern string: ");
    fgets(pattern, sizeof(pattern), stdin);  // Corrected line

    // Remove newline characters if present
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    Shifttable(pattern, s);
    int found = horsepool(text, pattern, s);

    if (found == -1)
    {
        printf("Pattern not found in string\n");
    }
    else
    {
        printf("Pattern found at position %d\n", found);
    }

    return 0;
}

void Shifttable(char P[], int t[])
{
    int m, i, j;

    m = strlen(P);
    // Initialize shift table
    for (i = 0; i < 256; i++)  // Adjusted to cover all ASCII characters
    {
        t[i] = m;  // If a character is not in the pattern, set shift to the length of the pattern
    }

    // Fill in the shift table for characters that appear in the pattern
    for (j = 0; j < m - 1; j++)
    {
        t[(unsigned char)P[j]] = m - j - 1;
    }
}

int horsepool(char T[], char P[], int t[])
{
    int n, m, i, j;

    n = strlen(T);
    m = strlen(P);
    i = m - 1;

    while (i < n)
    {
        j = m - 1;
        while (j >= 0 && T[i - m + j + 1] == P[j])
        {
            j--;
        }

        if (j < 0)
        {
            return i - m + 1;  // Pattern found at this position
        }
        else
        {
            i += t[(unsigned char)T[i + 1]];  // Use the shift value for the character at T[i+1]
        }
    }

    return -1;  // Pattern not found
}
