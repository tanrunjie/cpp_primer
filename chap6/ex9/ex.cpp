#include <iostream>
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

    int cnt;
    string str;
    getline(inFile,str);
    cnt = stoi(str);
    struct donator{
        string name;
        double money;
    };
    donator *pd = new donator[cnt];
    for(int i=0; i<cnt; i++)
    {
        getline(inFile, pd[i].name);        
        getline(inFile, str);
        pd[i].money = stod(str);
        cout << pd[i].name << endl;
        cout << pd[i].money << endl;
    }
    for(int i=0; i<cnt; i++)
    {
        if(pd[i].money > 10000)
        {
            cout <<"Grand Patrons:" << pd[i].name \
            <<" with money:" <<pd[i].money << endl;
        }
        else
        {
            cout <<"Patrons:" <<pd[i].name \
            <<" with money:" << pd[i].money << endl;
        }
    }
    return 0;
}




   
  