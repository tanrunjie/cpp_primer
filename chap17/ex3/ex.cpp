#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[])
{
    if(argc<=2)
    {
        cerr <<"Usage: " << argv[0] <<" infile outfile" << endl;
        exit(EXIT_FAILURE);
    }
    ifstream fin;
    ofstream fout;
    fin.open(argv[1], ios_base::in);
    fout.open(argv[2], ios_base::out);

    if(!fout.is_open() || !fin.is_open())
    {
        cerr << "Cloud not open" << argv[1] <<"or" <<argv[2]<< endl;
        fout.clear(); 
        exit(EXIT_FAILURE);
    }

    char ch;
    while(fin.get(ch))
    {
        fout << ch;
    }
    fin.close();
    fout.close();

    return 0;
}