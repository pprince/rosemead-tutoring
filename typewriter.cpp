
// C++-style I/O
#include <iostream>

// for time()
#include <ctime>

// for strlen()
#include <string.h>

// for Sleep()
#include <windows.h>

using namespace std;


// Generates a random integer between min and max
int rand_between(int min, int max) {
    int result = (rand() % (max - min + 1)) + min;
    return result;
}


void typewriter(char msg[], int min_delay, int max_delay) {
    for (int i = 0; i < strlen(msg); i++) {
        cout << msg[i];                     // print one character.
        cout << flush;                      // force display of characters one-at-a-time.
        Sleep( rand_between(min_delay, max_delay) );    // pause for 100-800 milliseconds.
    }

    cout << endl;
}


void typewriter_slow(char msg[]) {
    typewriter(msg, 200, 800);
}


void typewriter_fast(char msg[]) {
    typewriter(msg, 50, 200);
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

    typewriter("And this line prints at a custom speed, in-between!", 100, 400);


    // Prevent cmd.exe from auto-closing on program exit.
    cout << endl << endl;
    cout << "  --> Press [ENTER] to exit. <--" << endl;
    string ignored;
    getline(std::cin, ignored);

    exit(0);
}

