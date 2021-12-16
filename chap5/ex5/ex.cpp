#include <iostream>
int main()
{
    using namespace std;
    const int months = 12;
    const int years = 3;
    int sells[months][years] = {0};
    string name[months] = {"Jan","Feb","March",
    "April", "May","June","July","Aug" ,"Sept","Oct","Nov","Dec"};
    int total = 0;
    for(int j=0; j<years; j++)
        for(int i=0; i<months; i++)
        {
            cout <<"Input " << j <<"year, "<< name[i] <<" sells nums:";
            cin>>sells[i][j];
            total += sells[i][j];
        }
    cout <<"Total sells in "<<years <<" year: " << total << endl;

    return 0;

}