#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <cstring>
#include "print_start_menu.h" // function to print out start menu.
#include "print_menu.h" // function to print out menu.
#include "game_initialise.h" // function to print out the status of player.
#include "player.h" // build a struct to store data.
#include "save.h" // function to save current game.
//#include "new_game.h" // function to create a new game.

//#include "story.h" // function to print out story of the game.

using namespace std;

// declaration of functions
void choose_option();
int game_start(player p);

// function to create a new game.
void new_game() {
    player p;
    srand(time(0));
    p.ID = rand() % 4 + 6;
    p.M_sanity = ( rand() % 2 + 16 ) * p.ID;
    p.M_intelligence = ( rand() % 2 + 12 ) * p.ID;
    p.M_favourability = ( rand() % 2 + 8 ) * p.ID;
    p.C_sanity = 2*p.M_sanity/3;
    p.C_intelligence = 2*p.M_intelligence/3;
    p.C_favourability = 2*p.M_favourability/3;
    p.day = 0;
    p.result = 0;
    cout << "====================================" << endl;
    cout << "YOUR CHARACTOR'S NAME? " << endl;
    cout << "====================================" << endl;
    cin >> p.name;
    save(p);
    cout << "====================================" << endl;
    cout << "WELCOME " << p.name << " AND HAVE FUN!"<< endl;
    cout << "====================================" << endl;
    cout << "generating game basic...\n" << endl;
    game_start(p);
}

// function to load existing game stored in saving.
void load_game() {
    player p;
    string line;
    ifstream fin("save.txt");
    if ( fin.fail() ) {
        cout << "error in file opening!" << endl;
        exit(1);
    }
    if ( fin >> line ) {
        strcpy(p.name, line.c_str());
        fin >> p.ID >> p.M_sanity >> p.M_intelligence >> p.M_favourability >>
        p.C_sanity >> p.C_intelligence >> p.C_favourability >> p.day >> p.result;
        fin.close();
        game_start(p);
    } else {
        cout << "====================================" << endl;
        cout << "\nYou have NO unfinished game. Please create a new game.\n" << endl;
        new_game();
    }
}

// function to print out story of the game.
void story() {
    string line;
    ifstream fin("story.txt");
    if ( fin.fail() ) {
        cout << "error in file opening!" << endl;
        exit(1);
    }
    while ( getline(fin, line) ) {
        cout << line << endl;
    }
    fin.close();
    print_menu();
    choose_option();
}

// function to close the game.
void quit() {
    cout << "\nGood Bye! HKU will miss you!\n" << endl;
}

//function to let player choose options from start menu.
void choose_option() {
    int Option;
    cin >> Option;
    switch (Option) {
        case 1:
            new_game();
            break;
        case 2:
            load_game();
            break;
        case 3:
            story();
            break;
        case 4:
            quit();
            break;
        default:
            quit();
    }
}

// function to calculate to total grade.
char grade(double result) {
    if (result >= 90) {
        return 'A';
    } else if (result >= 85) {
        return 'B';
    } else if (result >= 80) {
        return 'C';
    } else if (result >= 75) {
        return 'D';
    } else return 'F';
}

// function to achieve data addition.
void add_value(int max, int &value, int n) {
    if (value+n <= max) {
        value += n;
    } else value = max;
}

// function to achieve data subtraction.
void subtract_value(int min, int &value, int n) {
    if (value-n >= min) {
        value -= n;
    } else value = min;
}

// function to detect special day.
void special_day(player &p) {
    double n = 0;
    if (p.day == 15) {
        cout << "\nDeadline of Assignment 1\n" << endl;
        n = 5 * (p.C_intelligence/((double)p.M_intelligence));
        p.result += n;
        cout << "\nBased on your performance, you get: 5/" << n << endl;
    } else if (p.day == 20) {
        cout << "\nToday is the midterm test!\n" << endl;
        n = 15 * (p.C_intelligence/((double)p.M_intelligence)) + 10 * (p.C_sanity/((double)p.M_sanity));
        p.result += n;
        cout << "\nBased on your performance, you get: 25/" << n << endl;
    } else if (p.day == 25) {
        cout << "\nDeadline of Assignment 2\n" << endl;
        n = 5 * (p.C_intelligence/((double)p.M_intelligence));
        p.result += n;
        cout << "\nBased on your performance, you get: 5/" << n << endl;
    } else if (p.day == 30) {
        cout << "\nDeadline of Group project\n" << endl;
        n = 15 * (p.C_favourability/((double)p.M_favourability)) + 5 * (p.C_intelligence/((double)p.M_intelligence));
        p.result += n;
        cout << "\nBased on your performance, you get: 20/" << n << endl;
    } else if (p.day == 35) {
        cout << "\nDeadline of Assignment 3\n" << endl;
        n = 5 * (p.C_intelligence/((double)p.M_intelligence));
        p.result += n;
        cout << "\nBased on your performance, you get: 5/" << n << endl;
    } else if (p.day == 40) {
        cout << "\nToday is the final exam!\n" << endl;
        n = 25 * (p.C_intelligence/((double)p.M_intelligence)) + 15 * (p.C_sanity/((double)p.M_sanity));
        p.result += n;
        cout << "\nBased on your performance, you get: 40/" << n << endl;
        cout << "\nThis is the end of this semester!\n" << endl;
        cout << "\nGame Over! Your result is: " << grade(p.result) << endl;
    }
}

// function for start the game.
int game_start(player p) {
    string anykey;
    double result, difficulty;
    string plan;
    for (int i = p.day; i < 41; i++) {
        cout << "\nType in 'C' to continue\n" << endl;
        cin >> anykey;
        p.day = i;
        game_initialise(p);
        cout << "\nwhat are you going to do today? (study, play, rest, /quit, /save_quit)\n" << endl;
        cin >> plan;
        if (plan == "/save_quit") {
            save(p);
            cout << "\nAll contents are saved...\nType in 'C' to continue\n" << endl;
            print_menu();
            choose_option();
            break;
        } else if (plan == "/quit") {
            cout << "\nAll contents are NOT saved...\nType in 'C' to continue\n" << endl;
            print_menu();
            choose_option();
            break;
        } else if (plan == "study") {
            if (p.C_intelligence >= 3*p.M_intelligence/4) {
                cout << "\nI love study!\n" << endl;
                subtract_value(0, p.C_sanity, rand() % 4 + 1);
                subtract_value(0, p.C_favourability, rand() % 2 + 1);
                add_value(p.M_intelligence, p.C_intelligence, rand() % 4 + 6);
            } else if (p.C_intelligence <= 1*p.M_intelligence/4) {
                cout << "\nI hate study!\n" << endl;
                subtract_value(0, p.C_sanity, rand() % 4 + 11);
                subtract_value(0, p.C_favourability, rand() % 4 + 6);
                add_value(p.M_intelligence, p.C_intelligence, rand() % 4 + 6);
            } else {
                cout << "\nJust a boring study day...\n" << endl;
                subtract_value(0, p.C_sanity, rand() % 4 + 6);
                subtract_value(0, p.C_favourability, rand() % 4 + 1);
                add_value(p.M_intelligence, p.C_intelligence, rand() % 4 + 6);
            }
        } else if (plan == "play") {
            if (p.C_favourability >= 3*p.M_favourability/4) {
                cout << "\nHanging out with my friends makes me feel good!\n" << endl;
                subtract_value(0, p.C_intelligence, rand() % 4 + 1);
                add_value(p.M_sanity, p.C_sanity, rand() % 4 + 1);
                add_value(p.M_favourability, p.C_favourability, rand() % 4 + 1);
            } else if (p.C_favourability <= 1*p.M_favourability/4) {
                cout << "\nI haven't played with my friends for so long.\n" << endl;
                subtract_value(0, p.C_intelligence, rand() % 4 + 11);
                add_value(p.M_sanity, p.C_sanity, rand() % 4 + 1);
                add_value(p.M_favourability, p.C_favourability, rand() % 4 + 1);
            } else {
                cout << "\nLet have some fun!\n" << endl;
                subtract_value(0, p.C_intelligence, rand() % 4 + 6);
                add_value(p.M_sanity, p.C_sanity, rand() % 4 + 1);
                add_value(p.M_favourability, p.C_favourability, rand() % 4 + 1);
            }
        } else if (plan == "rest") {
            if (p.C_sanity >= 3*p.M_sanity/4) {
                cout << "\nIt is good to lie on the bed and do nothing...\n" << endl;
                subtract_value(0, p.C_favourability, rand() % 2 + 1);
                subtract_value(0, p.C_intelligence, rand() % 2 + 1);
                add_value(p.M_sanity, p.C_sanity, rand() % 4 + 6);
            } else if (p.C_sanity <= 1*p.M_sanity/4) {
                cout << "\nThank god that I can have a rest\n" << endl;
                subtract_value(0, p.C_favourability, rand() % 4 + 6);
                subtract_value(0, p.C_intelligence, rand() % 4 + 6);
                add_value(p.M_sanity, p.C_sanity, rand() % 4 + 6);
            } else {
                cout << "\nI feel more relief\n" << endl;
                subtract_value(0, p.C_favourability, rand() % 4 + 1);
                subtract_value(0, p.C_intelligence, rand() % 4 + 1);
                add_value(p.M_sanity, p.C_sanity, rand() % 4 + 6);
            }
        } else {
            cout << "\nWRONG COMMAND!\n" << endl;
            cout << "\nAll contents are NOT saved...\nType in 'C' to continue\n" << endl;
            print_menu();
            choose_option();
            break;
        }
        special_day(p);
    }
    return 0;
}

// This is the main function.
int main() {
    print_start_menu();
    print_menu();
    choose_option();
    return 0;
}
