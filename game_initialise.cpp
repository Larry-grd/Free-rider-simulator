#include <iostream>
#include "game_initialise.h" // function to print out the status of player.
#include "player.h" // user-defined data type struct.

using namespace std;

// function to print out the status of player.
void game_initialise(player p) {
    cout << "====================================" << endl;
    cout << "NAME: " << p.name << endl;
    cout << "Your current status" << endl;
    cout << "SAN: " << p.M_sanity << "/" << p.C_sanity << endl;
    cout << "INT: " << p.M_intelligence << "/" << p.C_intelligence << endl;
    cout << "FAV: " << p.M_favourability << "/" << p.C_favourability << endl;
    cout << "DAY: " << p.day << endl;
    cout << "====================================" << endl;
}
