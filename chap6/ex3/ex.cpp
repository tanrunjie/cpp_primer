#include <iostream>

using namespace std;
void show_menu()
{
    cout << "Please enter one of the following choices:\n";
    cout << "c)carnivore\t"
         << "p)pianist\n";
    cout << "t)tree\t"
         << "g)game\n";
}
int main()
{
    char ch;
    show_menu();
    while (cin >> ch)
    {
        switch (ch)
        {
        case 'c':
            cout << "c" << endl;
            break;
        case 'p':
            cout << "p" << endl;
            break;
        case 't':
            cout << "A maple is a tree." << endl;
            break;
        case 'g':
            cout << "game" << endl;
            break;
        default:
            cout << "Please enter a c. p. t. or g:";
        }
    }
    return 0;
}