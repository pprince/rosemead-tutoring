
// HeartSeeker
// ===========
// heartseeker.cpp -- by David Deng


// Libraries
// =========
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


// Function declarations
// =====================
void cls();
void enter_to_continue();
void attack(int damage_multiplier=1);
void charge_up_attack();
int rand_between(int min, int max);


// Constants
// =========
const int player_min_damage = 50;      // Smallest possible damage a player's attack can deal.
const int player_max_damage = 100;     // Largest possible damage a player's attack can deal.
const int charge_min_multi = 1;        // Small possible damage multiplier when using charge up.
const int charge_max_multi = 3;        // Large possible damage multiplier when using charge up.


// Global Variables
// ================
string input;                       // User input, from the command line.
int turn = 1;                       // Which turn is it?
int player_hp = 100;                // Player's Health
int boss_hp = 850;                  // Computer's Health
bool did_chargeup = false;          // Track whether the Charge-Up attack was used on previous turn.


// Execution starts here...
int main() {

        cls();
        cout << endl;
        cout << "Welcome to HeartSeeker!" << endl;
        enter_to_continue();
        cls();

        cout << " Grey: \"My lord...We have terrible news. The deamon lord Azmodan has stolen your son's heart..."
                        "now he won't wake up\"" << endl;
        enter_to_continue();

        cout << " [you stare at the face of your resting son] " << endl;
        cout << "=============================================" << endl;
        cout << " \"My boy...I swear to you...I will not rest until I get your heart back\" " << endl;
        enter_to_continue();

        cout << "________________________" << endl;
        cout << "| Twenty years later...|" << endl;
        cout << "|______________________|" << endl;
        enter_to_continue();

        cout << " \"You: Two decades of searching through these blasted lands..."
                        "I now face Azmodan... This is the final battle... My son...I will save you\" " << endl;
        enter_to_continue();

        cout << "Azmodan:\"Your efforts have been for nought!"
                "...with your son's pure heart I shall envelop the world with darkness\"" << endl;
        enter_to_continue();


        // Loop forever
        while (1) {
                cls();

                // STATUS BAR
                // ==========

                cout << "Turn #" << turn << endl;
                cout << "Boss HP: " << boss_hp << endl;
                cout << "Player HP: " << player_hp << endl;
                cout << "==============================================" << endl;
                cout << endl;

                // PLAYER'S TURN
                // =============

                if (did_chargeup == false) {
                        // TYPICAL CASE; previous attack was NOT skipped for charge-up ...
                        // ... We print the menu, get the player's selection, and do a normal attack.

                        cout << "  MENU" << endl;
                        cout << "  ----" << endl;
                        cout << "    1 - Attack" << endl;
                        cout << "    2 - Charge Up" << endl;
                        cout << "    3 - DO-OR-DIE (logic not yet implemented)" << endl;
                        cout << endl;
                        cout << " Your choice? ";

                        // Get user's choice from the command line.
                        getline(cin, input);
                        cout << endl;

                        if (input == "1") {
                                attack();
                        }
                        else if (input == "2") {
                                cout << "You forego your attack, and gather your strength..." << endl;
                                did_chargeup = true;
                        }
                        else {
                                cout << "Invalid choice; try again..." << endl;
                                enter_to_continue();
                                continue;
                        }
                }
                else {  // SPECIAL CASE; did_chargeup == true ...
                        // So, we skip the usual menu+prompt, and instead auto-attack w/ bonus charge-up damage.

                        int multiplier = rand_between(charge_min_multi, charge_max_multi);

                        cout << "Because you meditated and charged up your energies before attacking," << endl;
                        cout << "    you deal " << multiplier << " times as much damage as usual!" << endl;
                        cout << endl;

                        attack(multiplier);

                        did_chargeup = false;
                }

                // Check if boss died
                // ==================
                if (boss_hp <= 0) {
                        // Player wins!
                        cout << endl;
                        cout << "CONGRATULATIONS, you have vanquished Azmodan." << endl;
                        cout << "The villagers sing your praises." << endl;
                        break;
                }

                // BOSS'S TURN
                // ===========

                cout << endl;
                cout << "Azmodan slowly crushes your son's heart...for 10 damage" << endl;
                player_hp -= 10;

                // Check if player died
                // ====================
                if (player_hp <= 0) {
                        // Player loses!
                        cout << endl;
                        cout << "My son...I've failed you...I hav\e nothing else to live for T_T" << endl;
                        cout << endl;
                        cout << "  ... 64M3 0V3R, N00B." << endl;
                        break;
                }

                enter_to_continue();

                // Keep track of 1st turn, 2nd turn, etc.
                turn++;
        }

        // Prevent cmd.exe from exiting before the user can read the "Game Over" message
        getline(std::cin, input);

        return 0;
}


// Function definitions
// ====================

void cls() {
        system("cls");
}

void enter_to_continue() {
        string ignored_input;
        cout << endl << " ... press [Enter] to continue." << endl << endl;
        getline(std::cin, ignored_input);
}

void attack(int damage_multiplier) {
        // Calculate damage dealt by this attack
        int damage = rand_between(player_min_damage, player_max_damage) * damage_multiplier;

        // Remove the damage-dealt from the boss' health
        boss_hp -= damage;

        cout << "You deal " << damage << " to Azmodan." << endl;
}

// Generates a random integer between min and max
int rand_between(int min, int max) {
        int result = (rand() % (max - min + 1)) + min;
        return result;
}


