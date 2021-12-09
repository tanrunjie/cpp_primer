#include <iostream>
using namespace std;

double dist_trans(double ly)
{
    return ly*63240.0;
}

int main()
{
    cout <<"Enter the number of light years:";
    double ly;
    cin>>ly;
    cout <<ly <<" light years = " << dist_trans(ly) <<" astronomical units.\n";
    return 0;
}