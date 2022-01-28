#include "person.h"

int main()
{
    string fname = "tan";
    string lname = "runjie";
    Person p(fname,lname);
    p.Show();

    Gunslinger g(p,10.5,3);
    g.Show();

    PokerPlayer pp(p);
    pp.Show();
    cout <<"******************" << endl;
    BadDude bd(g,pp);
    bd.Show();

    return 0;
}