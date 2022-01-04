#include <iostream>
#include <cstring>
using namespace std;

class plorg
{
    private:
        char name[20];
        int CI;
    public:
        plorg(){char n[20]="Plorga";  strcpy(name,n); CI=50;}
        void show() const
        {
            cout <<"name: " << name << endl;
            cout <<"CI: " << CI << endl;
        }
        void setCI(int ci)
        {
            CI = ci;
        }

};

int main()
{
    plorg p;
    p.show();

    p.setCI(20);
    p.show();

    return 0;
}