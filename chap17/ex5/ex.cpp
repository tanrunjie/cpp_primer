#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
using namespace std;

int main()
{
    ifstream fmat;
    ifstream fpat;
    fmat.open("mat", ios::in);
    fpat.open("pat", ios::in);
    if (!fmat.is_open() || !fpat.is_open())
    {
        cerr << "Cloud not open mat pat" << endl;
        exit(1);
    }
    vector<string> m;
    vector<string> p;

    string s;
    while (fmat >> s)
        m.push_back(s);
    while (fpat >> s)
        p.push_back(s);
    fmat.close();
    fpat.close();

    sort(m.begin(), m.end());
    sort(p.begin(), p.end());

    for (int i = 0; i < m.size(); i++)
        cout << m[i] << " ";
    cout << endl;

    for (int i = 0; i < p.size(); i++)
        cout << p[i] << " ";
    cout << endl;

    cout << "*******************" << endl;
    
    ofstream fout;
    fout.open("matnpat", ios_base::out);
    if(!fout.is_open())
    {
        cerr <<"fout failed" << endl;
        exit(1);
    }
    vector<string> v;
    set_union(m.begin(),m.end(),p.begin(),p.end(), back_inserter(v));

    vector<string>::iterator vit;
    vit = unique(v.begin(),v.end());
    v.resize(distance(v.begin(), vit));
    for(string str: v)
        fout << str << endl;
 
    fout.close();

    return 0;
}