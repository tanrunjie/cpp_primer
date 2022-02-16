#include <iostream>
#include <string>
#include <cstdlib>
#include "emp.h"

using namespace std;
const char *file = "staff.txt";
const int MAX = 10;

int main()
{
    abstr_emp *pc[MAX];

    ifstream fin;
    int classtype;
    int i = 0;
    char ch;
    fin.open(file);
    // open and read
    if (fin.is_open())
    {
        cout << "Here are the current contents of the "
             << file << " file:" << endl;
        while ((fin >> classtype).get(ch))
        {
            switch (classtype)
            {
            case Employee:
                pc[i] = new employee;
                break;
            case Manager:
                pc[i] = new manager;
                break;
            case Fink:
                pc[i] = new fink;
                break;
            case HighFink:
                pc[i] = new highfink;
                break;
            default:
                cerr << "Warning: Type error!" << endl;
                break;
            }
            pc[i]->setall(fin);
            pc[i]->ShowAll();
            i++;
        }
        fin.close();
    }

    // input new content
    ofstream fout(file, ios::out | ios::app);
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output." << endl;
        exit(EXIT_FAILURE);
    }
    int index = 0;
    cout << "\nPlease enter the class type of your input:\n";
    cout << "1)Employee\t2)Manager\t3)Fink\t4)Highfink\tq)Quit\n";
    while (cin >> classtype && index < MAX)
    {
        cin.ignore();
        switch (classtype)
        {
        case 1:
            pc[index] = new employee;
            pc[index]->SetAll();
            break;
        case 2:
            pc[index] = new manager;
            pc[index]->SetAll();
            break;
        case 3:
            pc[index] = new fink;
            pc[index]->SetAll();
            break;
        case 4:
            pc[index] = new highfink;
            pc[index]->SetAll();
            break;
        default:
            break;
        }
        index++;
        cout << "\nPlease enter the class type of your input:\n";
        cout << "1)Employee\t2)Manager\t3)Fink\t4)Highfink\tq)Quit\n";
    }
    cout <<"Input over." << endl <<"Thank you!" << endl;
    cout <<"Begin to write into the file ..."<<endl;
    cout <<"Writing ..."<<endl;
    for(i=0;i<index;i++)
        pc[i]->writeall(fout);
    fout.close();
    cout << "write over. \n";


    fin.clear();
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the current contents of the "
             << file << " file:" << endl;
        while ((fin >> classtype).get(ch))
        {
            switch (classtype)
            {
            case Employee:
                pc[i] = new employee;
                break;
            case Manager:
                pc[i] = new manager;
                break;
            case Fink:
                pc[i] = new fink;
                break;
            case HighFink:
                pc[i] = new highfink;
                break;
            default:
                cerr << "Warning: Type error!" << endl;
                break;
            }
            pc[i]->setall(fin);
            pc[i]->ShowAll();
            i++;
        }
        fin.close();
    }

    return 0;
}