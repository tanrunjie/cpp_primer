#include <iostream>

using namespace std;

int main()
{

    char first[80];
    cout<<"What is your first name?";
    cin.getline(first,80);
    
    char last[40];
    cout<<"What is your last name?";
    cin>>last;
    
    char grade;
    cout<<"What letter grade do you deserve?";
    cin >> grade;

    int age;
    cout<<"what is your age?";
    cin >> age;
    
    
    
    cout<<"Nmae: "<<last<<", " <<first<<endl;
    cout <<"Grade: " <<grade<<endl;


    cout <<"Age: "<< age<<endl;
    return 0;
}