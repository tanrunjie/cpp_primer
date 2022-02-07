#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

struct Big
{
    double stuff[20000];
};

int main()
{
    Big * pb;
    try{
        cout <<"Trying to get a big block of memory:"<<endl;
        pb = new Big[1000000];
        cout <<"Got past the new request;" << endl;
    }
    catch (bad_alloc & ba)
    {
        cout <<"Caught the exception!" << endl;
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
    if(pb!=0)
    {
        pb[0].stuff[0]=4;
        cout <<pb[0].stuff[0] << endl;
    }
    else
        cout <<"pb is null pointer" << endl;
    
    delete [] pb;
    return 0;
}