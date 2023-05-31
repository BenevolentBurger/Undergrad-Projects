#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> t[3];
  int n, from = 0, move = 1, to = 1, candidate = 1;

  cout << "Please enter how many rings you'd like to move: ";
  cin >> n;
  cout << endl;
  // initialize the three towers, adding the rings to tower 0 (using a stack with a vector)
  for (int i = n + 1; i >= 1; i--) {
    t[0].push_back(i);
  }
  t[1].push_back(n + 1);
  t[2].push_back(n + 1);

  // Determines odd vs even
  if (n % 2 == 0) {
    to = 2;
  } else {
    to = 1;
  }
  // while tower 1 does not contain all of the rings
  while (t[1].size() < n + 1) {
    cout << "Move # " << move << ": Moving ring " << candidate << " from tower "
         << char(from + 65) << " to tower " << char(to + 65) << endl;
    move++;
    // add the ring to the "to" tower from the top of the "from" tower
    t[to].push_back(t[from].back());
    t[from].pop_back();
    // determine the "from" tower, which is the smallest ring that hasnt been moved
    if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) {
      from = (to + 1) % 3;
    } else {
      from = (to + 2) % 3;
    }
    // candidate is the top of the stack of the from tower
    candidate = t[from].back();
    // determine the "to" stack, closest stack the popped int can be placed
    if (n % 2 == 0) {
      if (t[(from + 2) % 3].back() > candidate) {
        to = (from + 2) % 3;
      } else {
        to = (from + 1) % 3;
      }
    } else {
      if (t[(from + 1) % 3].back() > candidate) {
        to = (from + 1) % 3;
      } else {
        to = (from + 2) % 3;
      }
    }
  }
}