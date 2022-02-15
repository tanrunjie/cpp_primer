#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void ShowStr(const string & temp)
{
    cout << temp << endl;
}

void Store(string temp, ofstream fout)
{

}

int main()
{
    vector<string> vostr;
    string temp;

    // acquire
    cout <<"Enter strings (empty line to quit):" << endl;
    while(getline(cin,temp) && temp[0] !='\0')
        vostr.push_back(temp);
    cout <<"Here is your input." << endl;
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // store
    ofstream fout("strings", ios_base::out | ios_base::binary);
    // for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover
    vector<string> vistr;
    ifstream fin("strings", ios_base::in | ios_base::binary);
    if(!fin.is_open())
    {
        cerr << "Cloud not open file for input." << endl;
        exit(EXIT_FAILURE);
    }
    // GetStrs(fin, vistr);
    cout << endl << "Here are the strings read from the file:" << endl;
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}