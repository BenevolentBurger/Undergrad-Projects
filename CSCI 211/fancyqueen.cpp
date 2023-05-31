#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int i, j, k, l;

typedef vector<vector<string> > box;

// i turned the boxes into strings to make them look more solid in the terminal
box wb(5, vector<string>(7, " ")), bb(5, vector<string>(7, "\u2588")), wq, bq, *board[8][8];

bool ok(int q[], int c) {
    for (i = 0; i < c; i++)
        if (q[c] == q[i] || abs(q[c] - q[i]) == abs(c - i))
            return false;
    return true;
}

void backtrack(int &c) {
    c--;
    if (c == -1) exit(1);
}


/* "\u2588" = solid black box
   "\u2502" = vertical border
   "\u2500" = bottom border
*/

void print(int q[]) {
    static int count = 0;
    count++;
    cout << "Solution # " << count << ":" << endl;

    for (i = 0; i < 8; i++) cout << q[i] << "";
    cout << endl << endl;

    wq = wb;
    bq = bb;
    // For the white queen graphic (wq)
    wq[0][3] = wq[1][3] = wq[2][3] = wq[3][3] = wq[4][3] = "\u2588"; 
    wq[1][1] = wq[1][5] = wq[2][2] = wq[2][4] = wq[3][1] = wq[3][5] = "\u2588";
    wq[4][1] = wq[4][2] = wq[4][4] = wq[4][5] = "\u2588";

    // For the black queen graphic (bq)
    bq[0][3] = bq[1][3] = bq[2][3] = bq[3][3] = bq[4][3] = " ";
    bq[1][1] = bq[1][5] = bq[2][2] = bq[2][4] = bq[3][1] = bq[3][5] = " ";
    bq[4][1] = bq[4][2] = bq[4][4] = bq[4][5] = " ";

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            if ((i + j) % 2 == 0) {
                if (q[j] == i) board[i][j] = &wq;
                else board[i][j] = &wb;
            } else {
                if (q[j] == i) board[i][j] = &bq;
                else board[i][j] = &bb;
            }

    cout << " ";
    for (i = 0; i < 7 * 8; i++) cout << "\u2500";
    cout << endl;

    for (i = 0; i < 8; i++)
        for (k = 0; k < 5; k++) {
            cout << " " << "\u2502";
            for (j = 0; j < 8; j++)
                for (l = 0; l < 7; l++) cout << (*board[i][j])[k][l];
            cout << "\u2502" << endl;
        }

    cout << " ";
    for (i = 0; i < 7 * 8; i++) cout << "\u2500";
    cout << endl << endl;
}

int main() {
    int q[8];
    q[0] = 0;
    int c = 1;
    bool from_backtrack = false;

    while (1) {
        while (c < 8) {
            if (!from_backtrack) q[c] = -1;
            from_backtrack = false;
            while (q[c] < 8) {
                q[c]++;
                while (q[c] == 8) {					
                    backtrack(c);
                    q[c]++;
                }
                if (ok(q, c)) break;
            }	
            c++;
        }		
        print(q);
        backtrack(c);
        from_backtrack = true;
    }
}
