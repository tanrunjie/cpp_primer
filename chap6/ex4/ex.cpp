#include <iostream>

using namespace std;

void show_menu()
{
    cout << "Benevolent Order of Programmers Report\n";
    cout << "a. display by name \t"
         << "b. display by title\n";
    cout << "c. display by bopname \t"
         << "d. display by preference\n";
    cout << "q. quit\n";
}
int main()
{
    const int strsize = 256;
    struct bop
    {
        char fullname[strsize];
        char title[strsize];
        char bopname[strsize];
        int preference; // 0,1,2
    };

    const int num = 5;
    bop b[num] = {
        {"Wimp Macho", "Senior Programmer", "NICK1", 0},
        {"Raki Rhodes", "Junior Programmer", "NICK2", 1},
        {"Celia Laiter", "Teacher", "MIPS", 2},
        {"Hoppy Hipman", "Analyst Trainee", "AT", 1},
        {"Pat Hand", "Student", "LOOPY", 2}};

    char ch;
    show_menu();
    cout << "Enter your choice:";
    while (cin >> ch)
    {
        switch (ch)
        {
        case 'a':
            for (int i = 0; i < num; i++)
                cout << b[i].fullname << endl;
            break;
        case 'b':
            for (int i = 0; i < num; i++)
                cout << b[i].title << endl;
            break;
        case 'c':
            for (int i = 0; i < num; i++)
                cout << b[i].bopname << endl;
            break;
        case 'd':
            for (int i = 0; i < num; i++)
            {
                switch (b[i].preference)
                {
                case 0:
                    cout <<b[i].fullname<<endl;
                    break;
                case 1:
                    cout <<b[i].title<<endl;
                    break;
                case 2:
                    cout <<b[i].bopname<<endl;
                    break;
                default:
                    ;
                }  
            }
            break;
        case 'q':
            cout << "Bye!\n";
            exit(0);
            break;
        default:
            ;
        }
        cout << "Next choice:";
    }
    return 0;
}