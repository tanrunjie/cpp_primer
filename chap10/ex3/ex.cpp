#include <cstring>
#include <iostream>
using namespace std;
const int Len = 40;

class golf
{
    private:
        char fullname[Len];
        int handicap;
    public:
        golf(const char * name, int hc)
        {
            strcpy(fullname, name);
            handicap = hc;
        }
        void setgolf(const char * name, int hc)
        {
            strcpy(fullname, name);
            handicap = hc;
        }
        void sethandicap(int hc)
        {
            handicap = hc;
        }
        void showgolf() const
        {
            cout << "fullname:" << fullname << endl;
            cout << "handicap:" << handicap << endl;
        }
};


int main()
{
    const char name[10] = "tanrunjie";
    golf g(name, 100);
    g.showgolf();
    g.sethandicap(200);
    g.showgolf();
    return 0;
}