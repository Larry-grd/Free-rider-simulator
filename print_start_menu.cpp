#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "print_start_menu.h"

using namespace std;

// function to print out start menu.
void print_start_menu() {
    string line;
    ifstream fin("start_menu.txt");
    if ( fin.fail() ) {
        cout << "error in file opening!" << endl;
        exit(1);
    }
    while ( getline(fin, line) ) {
        cout << line << endl;
    }
    fin.close();
}
