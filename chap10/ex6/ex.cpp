#include <iostream>
using namespace std;
class Move
{
private:
    double x;
    double y;

public:
    Move(double a = 0, double b = 0) : x(a), y(b)
    {
    }
    void showmove() const
    {
        cout << "x: " << x << "\ty:" << y << endl;
    }
    Move add (const Move & m)
    {
        x += m.x;
        y += m.y;
        return *this;
    }
    void reset(double a=0, double b=0)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Move m;
    m.showmove();

    Move m1(10,20);
    m.add(m1);
    m.showmove();

    m.reset();
    m.showmove();
    return 0;
}