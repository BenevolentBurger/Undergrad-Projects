#include <cmath>
#include <iostream>
using namespace std;

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

bool ok(int q[]) {
  // tests row, up diag, down diag
  for (int c = 0; c < 8; c++) {
    for (int i = 0; i < c; i++) {
      if (q[c] == q[i] or (c - i == abs(q[c] - q[i]))) return false; // Queen cannot be placed if this condition is met
    }
  }
  return true;
}

int main() {
  // sets up 1-dimensional array and solution count to 0s. 
  int q[8] = {0}, solutions = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        for (int l = 0; l < 8; l++) {
          for (int m = 0; m < 8; m++) {
            for (int n = 0; n < 8; n++) {
              for (int o = 0; o < 8; o++) {
                for (int p = 0; p < 8; p++) {
                  q[0] = i;
                  q[1] = j;
                  q[2] = k;
                  q[3] = l;
                  q[4] = m;
                  q[5] = n;
                  q[6] = o;
                  q[7] = p;
                  if (ok(q)){
                    print(q, ++solutions);
                  } 
                  /* Tries literally every single configuration of where a queen can
                  possibly be (n = 8^8) if it's valid, and print it. This is very inefficient */
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
