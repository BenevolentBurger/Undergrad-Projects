#include <iostream>
using namespace std;

bool ok(int table[], int c) {
   static int mp[3][3] = { {0,2,1},  // 0  Men's preferences
                           {0,2,1},  // 1
                           {1,2,0}}; // 2
   static int wp[3][3] = { {2,1,0},  // 0  Women's preferences
                           {0,1,2},  // 1
                           {2,0,1}}; // 2
                     
   // Check for conflicts between man# c's marriage and previous marriages.
   for (int i = 0; i < c; ++i) {                                    // For each previous man#i, if
        if (table[i] == table[c]) return false;                     // man#i and man#c are married to the same woman OR
        if (mp[i][table[c]] < mp[i][table[i]] && wp[table[c]][i] < wp[table[c]][c]) return false;  // man#i and man#c's wife like each more than their own spouse OR
        if (mp[c][table[i]] < mp[c][table[c]] && wp[table[i]][c] < wp[table[i]][i]) return false;  // man#c and man#i's wife like each more than their own spouse,
   }
   return true;
}
void print(int table[]) {
    static int solution = 1;
    cout <<endl;
    cout << "Solution #" << solution++ << ":\nMan    Woman\n";
    for (int i = 0; i < 3; ++i)
        cout << i << "      " << table[i] << endl;
}

int main() {
    int table[3] = {};// Initialize the array to 0.
    int c = 0;       // Start on the first column
    while (c >= 0) { // End the loop if you backtrack from the first column
        if (c == 2) { // If you are in the last column, print and backtrack
            print(table);
            c--;
      }
        else                  // Otherwise, move to one before the first row of the next column
            table[++c] = -1;
      while (c >= 0) {
            table[c]++;           // Move to the next row
            if (table[c] == 3)     // If you have passed the end of the column, backtrack
            c--;
            else if (ok(table, c)) // Otherwise, if the tablke is ok, break (go back to the beginning of the outer loop)
            break;
      }
   }
   return 0;
}
