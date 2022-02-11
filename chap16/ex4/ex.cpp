#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int reduce(long ar[], int n)
{
    vector<long> vl;
    for(int i=0 ;i<n;i++)
        vl.push_back(ar[i]);
    sort(vl.begin(),vl.end());

    vector<long>::iterator it;
    it = unique(vl.begin(),vl.end()); //unique 搭配resize使用
    vl.resize(distance(vl.begin(),it));

    for(int i=0; i<vl.size();i++)
        cout << vl[i] <<" ";

    cout << endl;
    return vl.size();
}

int main()
{
    long ar[10] = {1,3,5,7,9,2,3,5,10,3};

    cout << reduce(ar,10) << endl;

    return 0;
}