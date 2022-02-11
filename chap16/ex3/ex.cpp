#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

void ShowString(string & s)
{
    cout << s << endl;
}

int main()
{

    vector<string> vs;
    string temp;
    ifstream ifs;
    ifs.open("in",ifstream::in);

    char delim = ' ';
    while(getline(ifs,temp, delim))
    {
        vs.push_back(temp);
    }
    for_each(vs.begin(),vs.end(), ShowString);
    cout << vs.size() << endl;
    return 0;
}