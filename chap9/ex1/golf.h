#ifndef _GOLF_H
#define _GOLF_H
#include <cstring>
#include <iostream>
using namespace std;
const int Len = 40;
struct golf
{
    char fullname[Len];
    int handicap;
};

void setgolf(golf & g, const char * name, int hc);

int setgolf(golf & g);

void sethandicap(golf & g, int hc);

void showgolf(const golf & g);

#endif