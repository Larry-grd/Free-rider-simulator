#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "print_menu.h"

using namespace std;

// function to print out menu.
void print_menu() {
    
    string anykey;
    cin >> anykey;
    string line;
    ifstream fin("menu.txt");
    if ( fin.fail() ) {
        cout << "error in file opening!" << endl;
        exit(1);
    }
    while ( getline(fin, line) ) {
        cout << line << endl;
    }
    fin.close();
}
