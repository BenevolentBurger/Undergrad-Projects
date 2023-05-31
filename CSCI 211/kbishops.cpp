#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a bishop placement is valid
bool ok(int q[], int c, int n) {
   for (int i = 0; i < c; ++i)                       
      if ((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n)) // Check if any other bishop is in the same diagonal
         return false; // If yes, then the placement is not valid
   return true; // If no, then valid
}

// Function to calculate the number of solutions for k bishops on an n*n chessboard
int calcKBishops(int bs, int k) {
   int* bPos = new int[k];        
   bPos[0] = 0;
   int cB = 0, nSol = 0;
   while (cB >= 0) {
      ++cB;
      if (cB == k) {            
         ++nSol; // A solution is found
         --cB;
      }
      else
         bPos[cB] = bPos[cB-1];        
      while (cB >= 0) {
         ++bPos[cB];
         if (bPos[cB] == bs*bs)
            --cB;
         else if (ok(bPos, cB, bs))
            break;
      }
   }
   delete [] bPos;
   return nSol;
}

// Main function
int main() {
   int bs, k;
   while (true) {
      cout << "Enter value of board size: ";
      cin >> bs;
      if (bs == -1)
         break;
      cout << "Enter number of bishops (k): ";
      cin >> k;
      cout << "Number of solutions: " << calcKBishops(bs, k) << "\n";
   }
   return 0;
}