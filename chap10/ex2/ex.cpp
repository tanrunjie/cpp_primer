#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person{
    private:
        static const int LIMII = 25;
        string lname;
        char fname[LIMII];
    public:
        Person() {lname =""; fname[0] = '\0';}
        Person(const string & ln, const char * fn="Heyyou")
        {
            lname = ln;
            if(strlen(fn)>LIMII)
                strncpy(fname, fn, LIMII);
            else
                strcpy(fname, fn);
        }
        void Show() const
        {
            cout <<fname <<" " << lname ;
        }
        void FormalShow() const        
        {
            cout << lname << ", " << fname ;
        }
};

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    cout << endl;
    one.FormalShow();
    cout << endl;

    two.Show();
    cout << endl;
    two.FormalShow();
    cout << endl;

    three.Show();
    cout << endl;
    three.FormalShow();
    cout << endl;

    return 0;
}