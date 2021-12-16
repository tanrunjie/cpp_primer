#include <iostream>
#include <string>
using namespace std;
int main()
{
    struct pizza{
        string comp;
        float diameter;
        float weight;
    };
    cout <<"plz input the pizza info: comp, diameter, weight" <<endl;
    pizza piz;
    getline(cin,piz.comp);
    cin>>piz.diameter;
    cin>>piz.weight;
    cout <<piz.comp <<" " << piz.diameter<<" " <<piz.weight<<endl;
    return 0;
}