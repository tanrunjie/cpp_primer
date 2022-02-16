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

class Store
{
public:
    ostream &os;
    Store(ostream & o): os(o){}
    void operator()( const string & str)
    {
        size_t len = str.size();
        os.write((char*)&len, sizeof(size_t));
        os.write(str.data(), len);
    }
};

int GetStrs(ifstream & is, vector<string> & vs)
{
    size_t len;
    int j=0;
    while(is.read((char*)&len, sizeof(size_t)))
    {
        char temp[len+1];
        for(int i=0; i<len; i++)
            is.read(&temp[i],1);
        temp[len] = '\0';
        vs.push_back(string(temp));
        j++;
    }
    return j;
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
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover
    vector<string> vistr;
    ifstream fin("strings", ios_base::in | ios_base::binary);
    if(!fin.is_open())
    {
        cerr << "Cloud not open file for input." << endl;
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << endl << "Here are the strings read from the file:" << endl;
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}