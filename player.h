#ifndef PLAYER_H
#define PLAYER_H

struct player {
    char name[20];
    int ID;
    int M_sanity;
    int M_intelligence;
    int M_favourability;
    int C_sanity;
    int C_intelligence;
    int C_favourability;
    int day;
    double result;
};

#endif
