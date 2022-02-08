#include <iostream>
#include <stdexcept>
using namespace std;

class bad_hmean : public logic_error
{
private:
    double v1;
    double v2;
public:
    explicit bad_hmean(double a=0, double b=0)
    :v1(a),v2(b),logic_error("bad_hmean\n")
    {}
    void mesg();
};

inline void bad_hmean::mesg()
{
    cout <<"hmean(" << v1 << "," << v2 << "):" 
        << "invalid arguments: a = -b \n";
}

class bad_gmean : public logic_error
{
public:
    double v1;
    double v2;
    bad_gmean(double a=0, double b=0)
    :v1(a),v2(b),logic_error("bad_gmean\n")
    {}
    const char * mesg();
};

inline const char * bad_gmean::mesg()
{
    return "gmean() arguments should be >=0\n";
}


