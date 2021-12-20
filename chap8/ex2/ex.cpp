#include <iostream>
#include <string>
using namespace std;

struct CandyBar
{
    char *brand;
    double weight;
    int calorie;
};

void setBar(CandyBar &cb, char *b = (char*)"Millennium Munch", double w = 2.85, int c = 350)
{
    cb.brand = b;
    cb.weight = w;
    cb.calorie = c;
}
const void showBar(const CandyBar &cb)
{
    cout << "cb.brand:" << cb.brand << endl;
    cout << "cb.weight:" << cb.weight << endl;
    cout << "cb.calorie" << cb.calorie << endl;
}

int main()
{
    CandyBar cb;
    setBar(cb);
    showBar(cb);
    return 0;
}