
// HeartSeeker
// ===========
// heartseeker.cpp -- by David Deng


// Libraries
// =========
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;


// Function declarations
// =====================
void cls();
void enter_to_continue();
void attack();
//void do_or_die();
int rand_between(int min, int max);


// Constants
// =========
const int player_min_damage = 50;      // Smallest possible damage a player's attack can deal.
const int player_max_damage = 100;     // Largest possible damage a player's attack can deal.
const int do_or_die = 500;

// Global Variables
// ================
string input;               // User input, from the command line.
int turn = 1;               // Which turn is it?
int player_hp = 100;        // Player's Health
int boss_hp = 1180;         // Computer's Health


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

	cls();
	cout << " [you stare at the face of your resting son] " << endl;
	cout << "=============================================" << endl;
	cout << " \"My boy...I swear to you...I will not rest until I get your heart back\" " << endl;
	enter_to_continue();

	cls();
	cout << "________________________" << endl;
	cout << "| Twenty years later...|" << endl;
	cout << "|______________________|" << endl;
	enter_to_continue();

	cls();
	cout << " \"You: Two decades of searching through these blasted lands..."
		"I now face Azmodan... This is the final battle... My son...I will save you\" " << endl;
	enter_to_continue();

	cls();
	cout << "Azmodan:\"Your efforts have been for nought!"
		"...with your son's pure heart I shall envelop the world with darkness\"" << endl;
	enter_to_continue();


	// Loop forever
	while (1) {
		cls();

		// STATUS BAR
		// ==========

		cout << "Turn #" << turn << endl;
		//cout << "Boss HP: " << boss_hp << endl;
		cout << "Player HP: " << player_hp << endl;
		cout << "==============================================" << endl;
		cout << endl;

		// PLAYER'S TURN
		// =============

		cout << "  MENU" << endl;
		cout << "  ----" << endl;
		cout << "    1 - Attack" << endl;
		cout << "    2 - Do-Or-Die (kill or be killed)" << endl;
		cout << endl;
		cout << " Your choice? ";

		// Get user's choice from the command line.
		getline(cin, input);

		cout << endl;

		if (input == "1") {
			attack();
		}
		else if (input == "2") {
			cout << "This is it... I shall pure the last of my energy into this attack!" << endl;
			boss_hp -= do_or_die;
			player_hp -= 100;
			enter_to_continue();
			
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
			cls();
			cout << endl;
			cout << "__________________________________________________________________________" << endl;
			cout << "|Your journey was long and hard faught, but you managed to save the world|" << endl;
			cout << "|...but more importantly your son.                                       |" << endl;
			cout << "|________________________________________________________________________|" << endl;
			cout << endl;
			cout << "__________________________________________________________________________" << endl;
			cout << "|A year as past and your son has aged since your journey. He has made a  |" << endl;
			cout << "|full recovery...soon your kingdom will belong to your dear son.         | " << endl;
			cout << "|________________________________________________________________________|" << endl;
			cout << "CONGRATULATIONS, you have vanquished Azmodan." << endl;
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

//void do_or_die() {
//damage for the final attack
//boss_hp -= const int do_or_die
//player
//}

// Generates a random integer between min and max
int rand_between(int min, int max) {
	srand(time(NULL)); 
	int result = (rand() % (max - min + 1)) + min;
	return result;
}


