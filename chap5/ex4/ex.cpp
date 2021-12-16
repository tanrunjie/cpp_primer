#include <iostream>
int main()
{
    using namespace std;
    const int months = 12;
    int sells[months] = {0};
    string name[months] = {"Jan","Feb","March",
    "April", "May","June","July","Aug" ,"Sept","Oct","Nov","Dec"};
    int total = 0;
    for(int i=0; i<months; i++)
    {
        cout <<"Input " << name[i] <<" sells nums:";
        cin>>sells[i];
        total += sells[i];
    }
    cout <<"Total sells in this year: " << total << endl;

    return 0;

}