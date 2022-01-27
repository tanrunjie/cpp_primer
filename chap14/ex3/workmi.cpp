#include <iostream>
#include <cstring>
#include "workermi.h"

const int SIZE = 5;
using namespace std;
int main()
{
    Worker *lolas[SIZE];
    int ct;
    Queue<Worker*> q;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
             << "w:waiter s:singer t:singing waiter q:quit" << endl;
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w,s,t or q:";
            cin >> choice;
        }
        if (choice == 'q')
            break;

        switch (choice)
        {
        case 'w':
            lolas[ct] = new Waiter;
            break;
        case 's':
            lolas[ct] = new Singer;
            break;
        case 't':
            lolas[ct] = new SingingWaiter;
            break;
        default:
            break;
        }
        cin.get();
        lolas[ct]->Set();
        q.enqueue(lolas[ct]);

    }

    cout <<"\nHere is your staff:\n";
    int i;
    for(i=0;i<ct;i++)
    {
        cout << endl;
        Worker * w = new SingingWaiter;
        q.dequeue(w);
        w->Show();
    }

    for(i=0;i<ct; i++)
        delete lolas[i];
    cout << "Bye." << endl;

    return 0;
}