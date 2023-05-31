#include <iostream>
using namespace std;

int main() {
  string letter[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I",
                       "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                       "S", "T", "U", "V", "W", "X", "Y", "Z"};
  int score[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int runners[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  string user;
  cout << "Enter string of letters: ";
  cin >> user;

  //to do until user enters done
  while (user != "done") {

    int total = int(user.length());

    //to find the scores
    for (int t = 0; t <= total; t++) {
      for (int z = 0; z <= 25; z++) {
        int l = 0;
        l = user.find(letter[z], t);

        //computer logic test code
        //cout<<endl<<t<<" "<<l<<endl;

        if (l == t) {
          score[z] += (l + 1);

          //how many runners there are per team
          runners[z]++;
        }
      }
    }

    int r = 0;

    // to see if one team has more runners
    for (int x = 0; x <= 25; x++) {
      if (runners[x] > 0) {
        r = runners[x];
        break;
      }
    }


    //to see if there are the same number of runners
    for (int x = 0; x <= 25; x++) {
      if (runners[x] > 0 && r > 0 && runners[x] != r) {
        cout << endl << "error please renter the string" << endl;
        cout << "Enter the string of letters: ";
        cin >> user;
      }
    }

    int teams = 0;

    cout << endl;
    // tp see how many teams there are 
    for (int x = 0; x <= 25; x++) {
      if (score[x] > 0) {
        teams++;
        cout << letter[x] << " has " << runners[x] << " team-members" << endl;
      }
    }

    cout << endl;
    cout << "There are " << teams << " teams";
    cout << endl;
    cout << endl;

    //average of each team
    for (int x = 0; x <= 25; x++) {
      float s = 0;
      if (score[x] > 0) {
        s = float(score[x]);
        s = s / runners[x];
        cout << letter[x] << " average score is " << s;
        cout << endl;
      }
    }

    int s2 = 0;

    //who won the race based on points
    for (int x = 0; x <= 25; x++) {
      if (score[x] < score[s2] && score[x]!=0 ) {
        s2 = x;
      }
    }

    float win = float(score[s2]) / float(runners[s2]);

    cout << endl
         << "The winning team is " << letter[s2] << " with a score of " << win
         << endl;

    cout << endl;
    cout << "Enter the string of letters: ";
    cin >> user;
  }

  return 0;
}