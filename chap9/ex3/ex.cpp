#include <iostream>
#include <cstring>
using namespace std;

const int BUF = 1024;
char buffer[BUF]; // chunk of memory
struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    // method 1
    chaff *c = new (buffer)chaff[2];

    // method 2
    // chaff *c = new chaff[2];
    strcpy(c[0].dross, "dross");
    c[0].slag = 2;
    strcpy(c[1].dross, "dross1");
    c[1].slag = 4;
    for(int i=0; i<2;i++)
    {
        cout << c[i].dross<<endl;
        cout << c[i].slag << endl;
    }
    return 0;
}