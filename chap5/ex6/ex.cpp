#include <iostream>

int main()
{
    using namespace std;

    struct Car
    {
        string make;
        int year;
    };

    int car_num;
    cout << "How many cars do you wish to catalog? ";
    cin >> car_num;

    Car *car = new Car[car_num];
    for(int i=0; i<car_num; i++)
    {
        cout <<"Car #" << i+1 <<":" << endl;
        cout <<"Please enter the make:";
        string str = "\n";
        getline(cin, str);
        getline(cin,car[i].make);
        cout <<"Please enter the year make:";
        cin >> car[i].year;
    }
    cout <<"Here is your collection:" << endl;
    for(int i=0; i<car_num; i++)
    {
        cout <<car[i].year <<" " << car[i].make << endl;
    }
    return 0;
}