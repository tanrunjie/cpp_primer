#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class bad_hmean : public logic_error
{
private:
    double v1;
    double v2;
public:
    explicit bad_hmean(double a=0, double b=0)
    :v1(a),v2(b),logic_error("wow")
    {}
    const char* what()
    {
        return "hmean() invalid arguments: a = -b \n";
    }
};

class bad_gmean : public bad_hmean
{
public:
    bad_gmean(double a=0, double b=0)
    :bad_hmean(a,b)
    {}
    const char* what()
    {
        return "gmean() arguments should be >=0\n";
    }
    
};


