#include <cmath>          
#include <iostream>       
using namespace std;      

void print(int q[], int sol) {     
  cout << "Solution #" << sol << ":\n";   // outputs the solution number to the console
  cout << "  " << q[1]+1 << " " << q[4]+1 << endl;   // outputs the board layout to the console
  cout << q[0]+1 << " " << q[2]+1 << " " << q[5]+1 << " " << q[7]+1 << endl;
  cout << "  " << q[3]+1 << " " << q[6]+1 << endl;
}

bool ok(int q[], int c) {     
  // initializes a two-dimensional array of integers that defines the board layout 
  // -1 is used as a value to indicate the end of the list of neighbors for a given square
  static int neighbor[8][5] = {{-1}, //row 1            
                               {0, -1},           
                               {0, 1, -1},        
                               {0, 2, -1},        
                               {1, 2, -1},        
                               {1, 2, 3, 4, -1},  
                               {2, 3, 5, -1},     
                               {4, 5, 6, -1}}; //row 8   
  for (int i = 0; i < c; i++)     // iterates through each row on the board
    if (q[c] == q[i]) return false;   // returns false if there is a conflict in the same row
  for (int i = 0; neighbor[c][i] != -1; i++) {     // iterates through each neighboring square on the board
    if (abs(q[c] - q[neighbor[c][i]]) == 1)     // returns false if there is a conflict diagonally
      return false;
  }
  return true;    // returns true if there are no conflicts
}

int main() {    // defines the main function
  int q[8] = {0}, c = 0, solutions = 0;   // initializes an integer array, a col, and a solutions counter
  q[0] = 0;   // sets the first queen at row 0, column 0
  
  while (true) {     // loops indefinitely
    c++;     // increments the col
    if (c == 8) {    // if all queens have been placed, print the solution
      print(q, ++solutions);
      c--;    // backtrack to find more solutions
    } else {
      q[c] = -1;    // initialize the next queen to row 1 as -1
    }

    while (true) {    // loops indefinitely
      q[c]++;    // move the queen to the next row
      if (q[c] == 8) {    // if there are no more rows to try, backtrack to find more solutions
        c--;
        if (c == -1) {    // if there are no more solutions, exit the program
          return 0;
        }
      } else if (ok(q, c)) {    // if the queen is in a valid position, move on to the next queen
        break;
      }
    }
  }
  return 0;   // exit
}