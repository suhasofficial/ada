
#include <stdio.h>
#include <stdlib.h> // Include for abs()
#include <math.h>

// Function prototypes
void queen(int row, int n);
void print(int n);
int place(int row, int column);

int board[20]; // Array to store the column position of queens on the board
int count = 0; // Counter to keep track of the number of solutions

// Function to print the solution
void print(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);
    for (i = 0; i < n; i++) // Rows of the board
    {
        for (j = 0; j < n; j++) // Columns of the board
        {
            if (board[i] == j) // Queen at the (i,j) position
                printf("Q ");
            else
                printf("- "); // Empty slot
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed at board[row][column]
int place(int row, int column)
{
    int i;
    for (i = 0; i < row; i++)
    {
        // Check if the column is already occupied or if the diagonals are attacked
        if (board[i] == column || abs(board[i] - column) == abs(i - row))
            return 0; // Conflict
    }
    return 1; // No conflict
}

// Function to solve the N-Queens problem recursively
void queen(int row, int n)
{
    int column;
    for (column = 0; column < n; column++) // Try every column for the current row
    {
        if (place(row, column)) // Check if placing a queen at (row, column) is valid
        {
            board[row] = column; // Place the queen in the current column of the current row
            if (row == n - 1)    // If all queens are placed
                print(n);        // Print the solution
            else                 // Otherwise, go to the next row
                queen(row + 1, n);
        }
    }
}

int main()
{
    int n;
    printf("Enter number of Queens: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20) // Bound the board size for practical use
    {
        printf("Invalid input. Please enter a positive integer for n, and less than or equal to 20.\n");
        return 1;
    }

    // Call the queen function to solve the problem starting from row 0
    queen(0, n);
    return 0;
}
