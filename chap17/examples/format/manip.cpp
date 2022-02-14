#include <iostream>
using namespace std;

int main()
{
    cout <<"Enter an integer:" << endl;
    int n;
    cin >> n;
    // decimal 10
    cout <<"n\tn*n" << endl;
    cout <<n<<"\t"<<n*n <<"(decimal)" << endl;

    // heximal 16
    cout << hex;
    cout <<n<<"\t"<<n*n <<"(hexadecimal)" << endl;

    // octal 8
    cout << oct;
    cout <<n<<"\t"<<n*n <<"(octal)" << endl;

    dec(cout);
    cout <<n<<"\t"<<n*n <<"(decimal)" << endl;

    return 0;

}