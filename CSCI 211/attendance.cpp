#include <iostream>
using std::cout;
using std::endl;

int main(){
    char firstName[] = {'E','r','i','c'};
    cout << "I am a CSCI 211 student. My first name is ";
    int numLetters = 5;
    for(int i = 0; i < numLetters; i++){
        cout << firstName[i];
    }
    cout << "." << endl;
    return 0;
}