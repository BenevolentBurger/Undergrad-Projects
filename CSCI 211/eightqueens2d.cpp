#include <iostream>
using namespace std;

int main(){
  // create a 2d array of an 8x8 board
  // initialize the array to 0  
  int q[8][8] = {0};
  int r = 0, c = 0;
  // place a queen in the first row and column
  q[r][c] = 1; 

  // next column backtracking point
  nextCol:
    c++;
    if (c == 8) goto print;
    r = -1; 

  // next row backtracking point
  nextRow:
    r++;
    if (r == 8) goto backtrack; // this is to check if the queen is in a safe position on the board

    // row test
    for (int i = 0; i < c; i++){
      if (q[r][i] == 1) goto nextRow; 
    }

    // up diagonal test 
    for (int i = 1; ((r-i)>=0 && (c-i)>=0); i++){ 
      if (q[r-i][c-i] == 1) goto nextRow;
    }

    // down diagonal test
    for (int i = 1; ((r+i)<8 && (c-i)>=0); i++){
      if (q[r+i][c-i] == 1) goto nextRow;
    }

    // TESTS END

    // If it's safe, place a queen in the current position
    q[r][c] = 1;
    // move to the next column
    goto nextCol;

  // backtrack to the previous column
  backtrack:
    c--;
    if (c == -1){
      return 0;
      // find the row with a queen in it
    }
    r = 0;
    while (q[r][c] != 1){
      r++;
    }

    q[r][c] = 0;
    goto nextRow;

  print:
    static int solutionNum = 0;
    cout << "Solution #" << ++solutionNum << ": " << endl;
    /* Fill in code to print 2d board */
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << q[i][j] << "";
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;

    return 0;
}