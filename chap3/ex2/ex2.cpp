#include <iostream>
using namespace std;


int main()
{
    float ft, inch, pds;
    cout <<"plz input height and weight: e.g ft,inch,pds" << endl;
    cin >> ft >> inch >> pds;
    float height = float(ft*12+inch)*0.0254;
    float weight = pds/2.2;
    cout <<"your height is " << height <<" m" << endl;
    cout <<"your weight is " << pds/2.2 <<" kg" <<endl;
    cout <<"your bmi is " << weight/(height*height) <<endl;
    return 0;
}