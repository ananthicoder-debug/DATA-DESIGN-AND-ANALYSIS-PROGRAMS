#include <stdio.h>
#include <stdlib.h> // Required for abs()

int x[20]; // Global array to store queen positions (x[row] = column)

// Logic to check if placing a queen at (k, i) is safe
int Place(int k, int i) {
    int j; // LOCAL variable for the loop
    for (j = 1; j < k; j++) {
        // x[j] == i: same column
        // abs(x[j] - i) == abs(j - k): same diagonal
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) {
            return 0; // False
        }
    }
    return 1; // True
}

// Recursive backtracking algorithm
void NQueens(int k, int n) {
    int i, j; // LOCAL variables for the loops
    for (i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i; // Place queen k in column i

            if (k == n) { // All queens placed
                printf("Solution: ");
                for (j = 1; j <= n; j++) {
                    printf("%d ", x[j]);
                }
                printf("\n");
            } else {
                NQueens(k + 1, n); // Move to next queen
            }
        }
    }
}

int main() {
    int n;

    printf("--- N-Queens Solver ---\n");
    printf("Enter number of queens: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 20) {
        printf("Please enter a valid number between 1 and 20.\n");
        return 1;
    }

    printf("\nSolutions for %d Queens:\n", n);
    printf("--------------------------\n");
    NQueens(1, n);
    printf("--------------------------\n");

    return 0;
}
