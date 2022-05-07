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
#include "random_task.h" // function for random special events.
//#include "new_game.h" // function to create a new game.

//#include "story.h" // function to print out story of the game.

using namespace std;

// declaration of functions
void choose_option();
void game_start(player p);

// function to create a new game.
void new_game() {
    player p;
    srand(time(0));
    p.ID = rand() % 4 + 6;
    p.M_sanity = ( rand() % 2 + 16 ) * p.ID;
    p.M_intelligence = ( rand() % 2 + 12 ) * p.ID;
    p.M_favourability = ( rand() % 2 + 8 ) * p.ID;
    p.C_sanity = p.M_sanity;
    p.C_intelligence = 2*p.M_intelligence/3;
    p.C_favourability = 2*p.M_favourability/3;
    p.day = 1;
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
            cout << "Your command is not found! System closed..." << endl;
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

// function to detect special day.(assignments, exams, group project)
void special_day(player &p) {
    double n = 0;
    if (p.day <= 15) {
        cout << "\nDeadline of Assignment 1: " << 15-p.day << " day(s) left...\n" << endl;
        if (p.day == 15) {
            n = 5 * (p.C_intelligence/((double)p.M_intelligence));
            p.result += n;
            cout << "\nBased on your performance, you get: 5/" << n << endl;
        }
    } else if (p.day <= 20) {
        cout << "\nMidterm test: " << 20-p.day << " day(s) left...\n" << endl;
        if (p.day == 20) {
            n = 15 * (p.C_intelligence/((double)p.M_intelligence)) + 10 * (p.C_sanity/((double)p.M_sanity));
            p.result += n;
            cout << "\nBased on your performance, you get: 25/" << n << endl;
        }
    } else if (p.day <= 25) {
        cout << "\nDeadline of Assignment 2: " << 25-p.day << " day(s) left...\n" << endl;
        if (p.day == 25) {
            n = 5 * (p.C_intelligence/((double)p.M_intelligence));
            p.result += n;
            cout << "\nBased on your performance, you get: 5/" << n << endl;
        }
    } else if (p.day <= 30) {
        cout << "\nDeadline of Group project: " << 30-p.day << " day(s) left...\n" << endl;
        if (p.day == 30) {
            n = 15 * (p.C_favourability/((double)p.M_favourability)) + 5 * (p.C_intelligence/((double)p.M_intelligence));
            p.result += n;
            cout << "\nBased on your performance, you get: 20/" << n << endl;
        }
    } else if (p.day <= 35) {
        cout << "\nDeadline of Assignment 3: " << 35-p.day << " day(s) left...\n" << endl;
        if (p.day == 35) {
            n = 5 * (p.C_intelligence/((double)p.M_intelligence));
            p.result += n;
            cout << "\nBased on your performance, you get: 5/" << n << endl;
        }
    } else if (p.day <= 40) {
        cout << "\nFinal exams: " << 40-p.day << " day(s) left...\n" << endl;
        if (p.day == 40) {
            n = 25 * (p.C_intelligence/((double)p.M_intelligence)) + 15 * (p.C_sanity/((double)p.M_sanity));
            p.result += n;
            cout << "\nBased on your performance, you get: 40/" << n << endl;
            cout << "\nThis is the end of this semester!\n" << endl;
            cout << "\nGame Over! Your result is: " << grade(p.result) << endl;
        }
    }
}

// function for start the game.
void game_start(player p) {
    int i = p.day;
    string anykey;
    double result, difficulty;
    string plan;
    while (i <= 40) {
        cout << "\nType in 'c' to continue\n" << endl;
        cin >> anykey;
        game_initialise(p);
        // user input to choose today's action and system response.
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
            } else if (p.C_intelligence <= p.M_intelligence/4) {
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
            } else if (p.C_favourability <= p.M_favourability/4) {
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
            } else if (p.C_sanity <= p.M_sanity/4) {
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
            cout << "\nAll contents are NOT saved...\nType in 'c' to continue\n" << endl;
            print_menu();
            choose_option();
            break;
        }
        // when san/int/fav is too low or too high, random speical events may occur (20%).
        if (p.C_sanity <= 30 || p.C_intelligence <= 20 || p.C_favourability <= 10 || p.C_sanity >= 100 || p.C_intelligence >= 80 || p.C_favourability >= 60) {
            if (rand()%5+0 == 3) {
                random_task(p);
            }
        }
        special_day(p);
        p.day++;
        i = p.day;
    }
}

// This is the main function.
int main() {
    print_start_menu();
    print_menu();
    choose_option();
    return 0;
}
