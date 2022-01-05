#include <iostream>
#include <algorithm>
#include "stonewt.h"
#include <vector>
using namespace std;

int main()
{
    vector<Stonewt> vec={Stonewt(200),Stonewt(100),Stonewt(0)};
   
    for(int i=3;i<6;i++)
    {
        vec.push_back(i*100);
    }

    for(int i=0 ;i<vec.size();i++)
    {
        cout << vec[i];
    }
    sort(vec.begin(),vec.end());

    cout <<"bigger than 11 stone:\n";
    for(int i=0 ;i<vec.size();i++)
    {
        if(vec[i]>=Stonewt(11,0))
            cout << vec[i];
    }
    cout <<"min:" << vec[0];
    cout <<"max:" << vec[vec.size()-1];
    return 0;
}