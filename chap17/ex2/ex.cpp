#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[])
{
    if(argc==1)
    {
        cerr <<"Usage: " << argv[0] <<" filename[s]" << endl;
        exit(EXIT_FAILURE);
    }

    ofstream fout;
    fout.open(argv[1], ios_base::out);
    if(!fout.is_open())
    {
        cerr << "Cloud not open" << argv[1] << endl;
        fout.clear();
        exit(EXIT_FAILURE);
    }

    char ch;
    while(cin.get(ch) && ch!='#')
    {
        fout << ch;
    }
    fout.close();

    return 0;
}