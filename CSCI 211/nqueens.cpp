#include <iostream>
#include <cmath>
using namespace std;

// Function to check if the current position is valid
bool ok(int q[], int c) {
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c]) || (abs(q[c] - q[i]) == abs(c - i))) {
            return false;
        }
    }
    return true;
}

int main() {
    int num_queens;

    // Ask user for the number of queens
    cout << "Enter the number of queens: ";
    cin >> num_queens;

    // Iterate through each problem
    for (int i = 1; i <= num_queens; i++) {
        int* q = new int[i]; // Dynamically allocate memory for array q
        q[0] = 0;
        int solution_count = 0; // Initialize solution count to 0
        int col = 0; // Start at the first column
        bool backtrack = false; // Set backtrack flag to false

        // Start searching for solutions
        while (true) {
            while (col < i) {
                if (!backtrack) {
                    q[col] = -1; // Initialize the current column's row to -1
                }
                backtrack = true;

                // Iterate through rows of the current column
                while (q[col] < i) {
                    q[col]++;

                    // If we reached the end of the rows, backtrack to the previous column
                    if (q[col] == i) {
                        backtrack = true;
                        col--;
                        break;
                    }

                    // If the current position is valid, move on to the next column
                    if (ok(q, col)) {
                        backtrack = false;
                        col++;
                        break;
                    }
                }

                // If we've backtracked to before the first column, we've found all solutions
                if (col == -1) break;
            }

            // If we've backtracked to before the first column, we've found all solutions
            if (col == -1) break;

            solution_count++; // Increment the solution count
            col--; // Backtrack to the previous column
            backtrack = true;
        }

        delete[] q; // Delete the dynamically allocated memory for the array q

        // Print the number of solutions for the current problem
        cout << "There is/are " << solution_count << " solution(s) to the " << i << " Queen(s) problem." << endl;
    }

    return 0;
}
