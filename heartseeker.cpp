
// HeartSeeker
// ===========
// heartseeker.cpp -- by David Deng


// Libraries
// =========
#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
using namespace std;


// Function declarations
// =====================
void cls();
void enter_to_continue();
void attack();
void charge_up_attack();
int rand_between(int min, int max);


// Constants
// =========
const int player_min_damage = 50;      // Smallest possible damage a player's attack can deal.
const int player_max_damage = 100;     // Largest possible damage a player's attack can deal.
//const int charge_min_multi = 1		  // Small possible damage multiplier when using charge up.
//const int charge_max_multi = 3		  // Large possible damage multiplier when using charge up.

// Global Variables
// ================
string input;               // User input, from the command line.
int turn = 1;               // Which turn is it?
int player_hp = 100;        // Player's Health
int boss_hp = 850;         // Computer's Health


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

		cout << "  MENU" << endl;
		cout << "  ----" << endl;
		cout << "    1 - Attack" << endl;
		cout << "    2 - Charge Up (logic not yet implemented)" << endl;
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
			cout << "Sorry, this feature is not yet implemented :(" << endl;
			turn++;
			enter_to_continue();
			continue;
		}
		else {
			cout << "Invalid choice; try again..." << endl;
			enter_to_continue();
			continue;
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
			cout << "My son...I've failed you...I have nothing else to live for T_T" << endl;
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

void attack() {
	// Calculate damage dealt by this attack
	int damage = rand_between(player_min_damage, player_max_damage);

	// Remove the damage-dealt from the boss' health
	boss_hp -= damage;

	cout << "You deal " << damage << " to Azmodan." << endl;
}

//void charge_up() { 
	int charge_up = rand_between(charge_min_multi, charge_max_multi);

	attack()
}

// Generates a random integer between min and max
int rand_between(int min, int max) {
	int result = (rand() % (max - min + 1)) + min;
	return result;
}


