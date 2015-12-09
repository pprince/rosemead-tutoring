#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;
struct player {
        int hp;
        int hpmax;
        int agi;
        int str;
        string name;
        string abilities[2];
        bool dead;
        int ct;
        bool ally;
};
int ac = 0;
int ec = 0;
int etarget = rand() % 4;
int eability = rand() % 1;
int main() {
        int input;
        int target;
        player players[5];
        players[0].hp = 1500;
        cout << "Enter Ally 1 agility: ";
        cin >> players[0].agi;
        cout << "Enter Ally 1 strenght: ";
        cin >> players[0].str;
        players[0].abilities[0] = "Attack";
        players[0].abilities[1] = "Heal";
        players[0].name = "Edge";
        players[1].hp = 4000;
        cout << "Enter Ally 2 agility: ";
        cin >> players[1].agi;
        cout << "Enter Ally 2 strenght: ";
        cin >> players[1].str;
        players[1].abilities[0] = "Attack";
        players[1].abilities[1] = "Cross Slash";
        players[1].name = "Cloud";
        players[2].hp = 4000;
        cout << "Enter Ally 3 agility: ";
        cin >> players[2].agi;
        cout << "Enter Ally 3 strenght: ";
        cin >> players[2].str;
        players[2].abilities[0] = "Attack";
        players[2].abilities[1] = "Punch Art";
        players[2].name = "Tifa";
        players[3].hp = 8000;
        cout << "Enter Enemy 1 agility: ";
        cin >> players[3].agi;
        players[3].name = "Goblin";
        cout << "Enter Enemy 1 Strenght: ";
        cin >> players[3].str;
        players[3].abilities[0] = "Attack";
        players[3].abilities[1] = "Goblin Punch";
        players[4].hp = 13000;
        players[4].abilities[0] = "Attack";
        players[4].abilities[1] = "HellFire";
        cout << "Enter Enemy 2 agility: ";
        cin >> players[4].agi;
        players[4].name = "Ifrit";
        cout << "Enter Enemy 2 Strenght: ";
        cin >> players[4].str;
        for (int i = 0; i <= 4; i++) {
                players[i].dead = false;
                players[i].hpmax = players[i].hp;
                players[i].ct = 0;
                players[i].ally = true;
        }
        players[3].ally = false;
        players[4].ally = false;
        for (int i = 0; i <= 4; i++) {
                if (players[i].ally) {
                        ac += 1;
                }
                if (!players[i].ally) {
                        ec += 1;
                }
        }
        while (true) {
                for (int i = 0; i <= 4; i++) {
                        if (players[i].hp <= 0 && players[i].ally && !players[i].dead) {
                                players[i].dead = true;
                                ac -= 1;
                                break;
                        }
                        if (players[i].hp <= 0 && !players[i].ally && !players[i].dead) {
                                ec -= 1;
                                players[i].dead = true;
                                break;

                        }
                        if (ac <= 0) {
                                cout << "\nLost\n";
                                cin.get();
                                cin.get();
                                exit(0);
                        }
                        if (ec <= 0) {
                                cout << "\nwon\n";
                                cin.get();
                                cin.get();
                                exit(0);
                        }
                }
                for (int i = 0; i <= 4; i++) {
                        if (players[i].ct >= 100) {
                                if (players[i].ally) {
                                        cout << players[i].name << endl;
                                        for (int c = 0; c <= 1; c++) {
                                                cout << c << " - " << players[i].abilities[c] << endl;
                                        }
                                        cin >> input;
                                        cout << "Who do you want to target?\n";
                                        for (int j = 0; j <= 4; j++) {
                                                cout << j << " - " << players[j].name << " Hp: " << players[j].hp << endl;
                                        }
                                        cin >> target;
                                        if (players[target].dead) {
                                                cout << "\nAlready dead\n";
                                                players[i].ct = 0;
                                                break;
                                        }
                                        if (players[target].hp + players[i].str <= players[target].hpmax) {
                                                if (players[i].abilities[input] == "Attack") {
                                                        cout << players[i].name << " attacks " << players[target].name << " with " << players[i].str << " dmg" << endl;
                                                        players[target].hp += players[i].str;
                                                }
                                                if (players[i].abilities[input] == "HellFire") {
                                                        cout << players[i].name << " Casts HellFire " << players[target].name << " with " << players[i].str * 2 << " dmg" << endl;
                                                        players[target].hp += players[i].str * 2;
                                                }
                                                if (players[i].abilities[input] == "Heal") {
                                                        cout << players[i].name << " Heals " << players[target].name << " with " << players[i].str << " restored hp" << endl;
                                                        players[target].hp += 100;
                                                }
                                                if (players[i].abilities[input] == "Cross Slash") {
                                                        cout << players[i].name << " Cross slashes " << players[target].name << " with " << players[i].str * 4 << " dmg" << endl;
                                                        players[target].hp += players[i].str * 4;
                                                }
                                                if (players[i].abilities[input] == "Punch Art") {
                                                        cout << players[i].name << " uses Punch Art on " << players[target].name << " with " << players[i].str * 3 << " dmg" << endl;
                                                        players[target].hp += players[i].str * 3;
                                                }
                                                if (players[i].abilities[input] == "Goblin Punch") {
                                                        cout << players[i].name << " uses Goblin Punch on " << players[target].name << " with " << players[i].str * 3 << " dmg" << endl;
                                                        players[target].hp += players[i].str * 3;
                                                }
                                                players[i].ct = 0;
                                        }
                                        else {
                                                players[i].ct = 0;
                                                players[target].hp = players[target].hpmax;
                                                break;
                                        }
                                }
                                if (!players[i].ally) {
                                        while (true) {
                                                if (players[etarget].dead || !players[etarget].ally) {
                                                        if (ac <= 0) break;
                                                        time_t t;
                                                        time(&t);
                                                        srand(t);
                                                        etarget = rand() % 4;
                                                }
                                                if (!players[etarget].dead || players[etarget].ally) break;
                                        }
                                        if (players[i].abilities[eability] == "Attack") {
                                                cout << players[i].name << " attacks " << players[etarget].name << " with " << players[i].str << " dmg" << endl;
                                                players[etarget].hp += players[i].str;
                                        }
                                        if (players[i].abilities[eability] == "HellFire") {
                                                cout << players[i].name << " casts HellFire " << players[etarget].name << " with " << players[i].str * 2 << " dmg" << endl;
                                                players[etarget].hp += players[i].str * 2;
                                        }
                                        if (players[i].abilities[eability] == "Heal") {
                                                cout << players[i].name << " Heals " << players[etarget].name << " with " << players[i].str << " restored hp" << endl;
                                                players[etarget].hp += players[i].str;
                                        }
                                        if (players[i].abilities[eability] == "Cross Slash") {
                                                cout << players[i].name << " Cross slashes " << players[etarget].name << " with " << players[i].str * 4 << " dmg" << endl;
                                                players[etarget].hp += players[i].str * 4;
                                        }
                                        if (players[i].abilities[eability] == "Punch Art") {
                                                cout << players[i].name << " uses Punch Art on " << players[etarget].name << " with " << players[i].str * 3 << " dmg" << endl;
                                                players[etarget].hp += players[i].str * 3;
                                        }
                                        if (players[i].abilities[eability] == "Goblin Punch") {
                                                cout << players[i].name << " uses Goblin Punch on " << players[etarget].name << " with " << players[i].str * 3 << " dmg" << endl;
                                                players[target].hp += players[i].str * 3;
                                        }
                                        players[i].ct = 0;
                                        time_t t;
                                        time(&t);
                                        srand(t);
                                        etarget = rand() % 2;
                                        time(&t);
                                        srand(t);
                                        eability = rand() % 1;
                                }
                        }
                        players[i].ct += players[i].agi;
                        if (players[i].dead) players[i].ct = 0;
                }
        }
}
