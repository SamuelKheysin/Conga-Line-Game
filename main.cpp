/*
Author: Samuel Kheysin
Date: 7/7/21
Description: Create a silly Zombie Conga Line using your Linked List
*/
#include <iostream>
#include <string>
#include "conga.h"

using namespace std;   

int main()
{
    bool exit = false;

    cout << "Welcome!" << endl << endl << endl;

    while (!exit) {
        // read rounds
        int rounds;
        while (true) {
            string response;
            // prompt for rounds
            cout << "How many rounds would you like to play? : ";
            cin >> response;
            rounds = atoi(response.c_str());
            if (rounds > 0)
                break;
            // repeat for invalid input
            cout << "Invalid input. Please try again." << endl << endl;
        }
        // initialize conga line
        Conga conga;
        conga.Play(rounds);
        // wait for user input
        bool ok = false;
        while (!ok) {
            // prompt for continue
            cout << endl << endl << "Would you like to continue? (Y/N): ";
            string response;
            cin >> response;
            if (response.compare("y") == 0 || response.compare("Y") == 0) {
                ok = true;
                break;
            } else if (response.compare("n") == 0 || response.compare("N") == 0) {
                ok = true;
                exit = true;
                break;
            }
            // repeat for invalid input
            cout << "Invalid input. Please try again." << endl << endl;
        }
        cout << endl << endl;
    }

    cout << endl << endl << "Good-Bye!" << endl << endl;

    return 0;
}
