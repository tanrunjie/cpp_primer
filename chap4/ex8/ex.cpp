#include <iostream>
#include <string>
using namespace std;
int main()
{
    struct Pizza{
        string comp;
        float diameter;
        float weight;
    };
    cout <<"plz input the pizza info: diameter, comp, weight" <<endl;
    Pizza *piz = new Pizza;
    cin>>piz->diameter;


    string mystr="/n";
    getline(cin,mystr); //!!important!, clean the buffer!

    getline(cin,piz->comp);
    cin>>piz->weight;

    cout <<"res:\n";
    cout <<(*piz).comp <<" " << (*piz).diameter<<" " <<(*piz).weight<<endl;
    delete piz;
    return 0;
}