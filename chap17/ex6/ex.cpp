#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "emp.h"

using namespace std;
const char * file = "text.txt";
const int MAX = 10;

int main()
{

    ifstream fin;
    fin.open(file);
    if(fin.is_open())
    {
        // show content
    }
    fin.close();

    

    employee * pc[MAX];
    
    int type;

    cout <<"select object type you make: " << endl
        << "0:employee\t1:manager\t2:fink\t3:highfink" << endl;
    cin >> type;

    switch (type)
    {
    case 0:
        /* code */
        break;
    
    default:
        break;
    }







    // employee em("Trip", "Harris", "Thumper");
    // // cout << em << endl;
    // em.ShowAll();
    // cout << endl;
    // manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    // // cout << ma << endl;
    // ma.ShowAll();
    // cout << endl;

    // fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    // // cout << fi << endl;
    // fi.ShowAll();
    // cout << endl;

    // highfink hf(ma, "Curly Kew");
    // hf.ShowAll();

    // cout <<"Press a Key for next phase:\n";
    // cin.get();

    // highfink hf2;
    // hf2.SetAll();

    // cout <<"Using an abstr_emp * pointer:\n";
    // abstr_emp * tri[4]={&em, &fi, &hf, &hf2};
    // for(int i=0; i<4; i++)
    //     tri[i]->ShowAll();

    return 0;
}