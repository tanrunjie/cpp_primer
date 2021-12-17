#include<iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("file.txt");
    if(!inFile.is_open())
    {
        cerr <<"Failed open file.txt\n";
        exit(0);
    }
    char ch;
    int cnt=0;
    while(inFile>>ch)
    {
        cnt++;
    }
    cout << cnt <<endl;
    inFile.close();
    return 0;
}