#include <iostream>
#include <fstream>
#include <cstdlib>
#include "player.h"
#include "save.h"


using namespace std;

void save(player p) {
    ofstream fout("save.txt");
    if ( fout.fail() ) {
        cout << "error in file opening!" << endl;
        exit(1);
    }
    fout << p.name << " " << p.ID << " " << p.M_sanity << " "
    << p.M_intelligence << " " << p.M_favourability
    << " " << p.C_sanity << " "<< p.C_intelligence
    << " " << p.C_favourability << " "
    << p.day << " " << p.result << endl;
    fout.close();
}
