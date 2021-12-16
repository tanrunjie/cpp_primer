#include <iostream>
using namespace std;

int main()
{
    struct CandyBar{
        string brand;
        float weight;
        int calorie;
    };
    CandyBar snacks[3]={
        {"tan", 1.1, 100},
        {"run", 2.2, 200},
        {"jie", 300.2, 2000}
    };
    for(int i=0; i<3;i++)
    {
        cout <<snacks[i].brand <<" " << snacks[i].weight<<" " <<snacks[i].calorie <<endl;
    }
    return 0;
}