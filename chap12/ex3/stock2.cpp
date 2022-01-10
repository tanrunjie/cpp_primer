#include <cstring>
#include "stock2.h"

using namespace std;
Stock::Stock()
{
    company = new char[8];
    strcpy(company, "no name");

    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, int n, double pr)
{
    company = new char[strlen(co)+1];
    strcpy(company, co);

    if(n<0)
    {
        cerr<<"Number of shares can't be negative. "
        << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}
Stock & Stock::operator=(const Stock &s)
{
    company = new char[strlen(s.company)+1];
    strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    (*this).set_tot();
}


Stock::~Stock()
{
    delete [] company;
}

void Stock::buy(int num, double price)
{
    if(num<0)
    {
        cerr<<"Number of sahres purchased can't be negative. "
        << "Transaction is aborted.\n";
    }
    else
    {
        shares +=num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price)
{
    if(num<0)
    {
        cerr<<"Number of shares sold can't be negative."
        <<"Transaction is aborted.\n";

    }
    else if(num>shares)
    {
        cerr<<"You can't sell more than you have!"
        <<"Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
    os <<"Company:"<<s.company<<endl;
    os <<"Shares:"<<s.shares<<endl;
    os <<"Share Price: $" << s.share_val << endl;
    os <<"Total Worth: $" << s.total_val << endl;
    return os;

}


void Stock::show() const
{
    cout <<"Company:"<<company<<endl;
    cout <<"Shares:"<<shares<<endl;
    cout <<"Share Price: $" << share_val << endl;
    cout <<"Total Worth: $" << total_val << endl;
}

const Stock & Stock::topval(const Stock & s) const
{
    if(s.total_val > total_val)
        return s;
    else
        return *this;
}