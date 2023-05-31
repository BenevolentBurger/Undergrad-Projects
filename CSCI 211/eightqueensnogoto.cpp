#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

// function to print board with queen or not
void print(int q[], int sol) {
  cout << "Solution #" << sol << ":\n";
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (q[i] == j)
        cout << "1 ";
      else
        cout << "0 ";
    }
    cout << endl;
  }
}

int main() {
   int q[8] = {};   // Initialize the array to 0.
   int c = 0;       // Start on the first column
   int solutions = 0;
   while (c >= 0) { // End the loop if you backtrack from the first column
      if (c == 7) { // If you are in the last column, print and backtrack
         print(q, ++solutions);
         --c;
      }
      else                  // Otherwise, move to one before the first row of the next column
         q[++c] = -1;
      while (c >= 0) {
         ++q[c];            // Move to the next row
         if (q[c] == 8)     // If you have passed the end of the column, backtrack
            --c;
         else if (ok(q, c)) // Otherwise, if the queen is ok, break (go back to the beginning of the outer loop)
            break;
      }
   }
   return 0;
}