
// C++-style I/O
#include <iostream>

// for time()
#include <ctime>

// for strlen()
#include <string.h>

// for Sleep()
#include <windows.h>

using namespace std;



void typewriter(char msg[], int delay) {
    for (int i = 0; i < strlen(msg); i++) {
        cout << msg[i]; // print one character.
        cout << flush;  // force display of characters one-at-a-time.
        Sleep( delay ); // pause for <delay> milliseconds.
    }

    cout << endl;
}


void typewriter_slow(char msg[]) {
    typewriter(msg, 250);
}


void typewriter_fast(char msg[]) {
    typewriter(msg, 50);
}


// START OF EXECUTION
// ==================

int main(void) {
    // Seed the pseudo-random number generator.
    srand(time(NULL));

    // THE DEMO:
    // ---------
    cout << endl;
    typewriter_fast("This line prints quickly,");
    typewriter_slow("but this line takes muuuch longer!");
    typewriter_fast("Fast...");
    typewriter_slow("Slow...");
    typewriter_fast("Fast...");
    typewriter_slow("Slow...");

    cout << endl;

    typewriter("And this line prints at a custom speed, in-between!", 125);


    // Prevent cmd.exe from auto-closing on program exit.
    cout << endl << endl;
    cout << "  --> Press [ENTER] to exit. <--" << endl;
    string ignored;
    getline(std::cin, ignored);

    exit(0);
}

