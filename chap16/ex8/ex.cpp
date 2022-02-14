#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    string mat[5] = {"Ryan", "Sally", "Tan", "Ho", "Ho"};
    string pat[3] = {"Tan", "run", "jie"};
    vector<string> m(mat, mat + 5);
    vector<string> p(pat, pat + 3);
    sort(m.begin(), m.end());
    sort(p.begin(), p.end());

    for (int i = 0; i < 5; i++)
        cout << m[i] << " ";
    cout << endl;

    for (int i = 0; i < 3; i++)
        cout << p[i] << " ";
    cout << endl;

    cout <<"*******************" << endl;;
    vector<string> v(10);
    vector<string>::iterator it;
    it = set_union(m.begin(),m.end(),p.begin(),p.end(), v.begin());
    for(string str: v)
        cout << str <<" ";
    return 0;
}