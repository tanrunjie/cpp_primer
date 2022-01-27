#include <iostream>
#include <string>
#include <cctype>
#include "mystack.h"

using namespace std;

int main()
{
    Stack<string> st;
    char ch;
    string po;
    cout <<"Please enter A to add a purchase order."<<endl;
    cout <<"P to process a PO or Q to quit." << endl;

    while(cin>>ch && toupper(ch)!='Q')
    {
        while(cin.get()!='\n')
            continue;
        if(!isalpha(ch))
        {
            cout <<'\a';
            continue;
        }
        switch (ch)
        {
        case 'A':
        case 'a':
            cout <<"Enter a PO number to add:";
            cin>>po;
            if(st.isfull())
                cout <<"stack already full" << endl;
            else
                st.push(po);
            break;
        case 'P':
        case 'p':
            if(st.isempty())
                cout <<"stack already empty" << endl;
            else
            {
                st.pop(po);
                cout << "PO #" << po << " poped" << endl;
                break;
            }
        default:
            break;
        }
        cout <<"Please enter A to add a purchase order." << endl;
        cout <<"P to process a PO, or Q to quit." << endl;
    }
    cout <<"Bye" << endl;
    return 0;
}