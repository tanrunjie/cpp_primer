#include <iostream>
#include "tablenn0.h"

using namespace std;
int main()
{
    TableTennisPlayer player1("Chck","Blizzard",true);
    TableTennisPlayer player2("Tara","Boomdea",false);
    player1.Name();
    if(player1.HasTable())
        cout <<": has a table.\n";
    else
        cout <<": has not a table\n";


    player2.Name();
    if(player2.HasTable())
        cout <<": has a table.\n";
    else
        cout <<": has not a table\n";


    return 0;
}