#include <iostream>
#include "stonewt.h"

using std::cout;
using std::endl;

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs -int(lbs);
    pounds = lbs;
    m = 'p';
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn*Lbs_per_stn + lbs;
    m = 'p';

}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
    m = 'p';

}

Stonewt::~Stonewt(){}


void Stonewt::show(char m) const
{
    if(m=='s')
    {
        cout << "s mode: " << stone <<" stone.\n";
    }
    else if(m=='i')
    {
        cout <<"i mode: " << int(pounds) << " pounds.\n";
    }
    else if(m=='m')
    {
        cout <<"m mode: " << pounds << " pounds.\n";
    }
    else
    {
        cout <<"Invalid mode.\n";
    }
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
    os << s.stone <<" stone. " << s.pds_left <<" pounds\n";
    return os;
}

Stonewt Stonewt::operator+(const Stonewt& s) const
{
    Stonewt sum;
    sum.pounds = pounds + s.pounds;
    sum.stone = int(sum.pounds)/Lbs_per_stn;
    sum.pds_left = int(sum.pounds) % Lbs_per_stn + sum.pounds -int(sum.pounds);
    return sum;
}

Stonewt Stonewt::operator-(const Stonewt& s) const
{
    Stonewt sum;
    sum.pounds = pounds - s.pounds;
    if(sum.pounds>0)
    {
        sum.stone = int(sum.pounds)/Lbs_per_stn;
        sum.pds_left = int(sum.pounds) % Lbs_per_stn + sum.pounds -int(sum.pounds);
    }
    else
    {
        cout <<"pounds minue less than zero" << endl;
        sum.stone = 0;
        sum.pds_left = 0;
    }
    return sum;
}

Stonewt Stonewt::operator*(double n) const
{
    Stonewt res;
    res.pounds = pounds * n;
    res.stone = int(res.pounds)/Lbs_per_stn;
    res.pds_left = int(res.pounds) % Lbs_per_stn + res.pounds -int(res.pounds);
    return res;
}
