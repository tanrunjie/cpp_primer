#ifndef PORT_H_
#define PORT_H_

#include <iostream>
#include <cstring>
using namespace std;
class Port
{
private:
    char style[20];
    int bottles;

public:
    char *brand;
    Port(const char *br = "none", const char *st = "none", int b = 0)
    {
        brand = new char[strlen(br) + 1];
        strcpy(brand, br);
        strcpy(style, st);
        bottles = b;
    }
    Port(const Port &p)
    {
        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
    }
    virtual ~Port() { delete[] brand; }

    Port &operator=(const Port &p)
    {
        if (this == &p)
            return *this;
        delete[] brand;
        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
        return *this;
    }
    Port &operator+=(int b)
    {
        bottles += b;
        return *this;
    }
    Port &operator-=(int b)
    {
        bottles -= b;
        return *this;
    }
    int BottleCount() const { return bottles; }
    virtual void Show() const
    {
        cout << "Brand: " << brand << endl;
        cout << "Kind: " << style << endl;
        cout << "Bottles: " << bottles << endl;
    }
    friend ostream &operator<<(ostream &os, const Port &p)
    {
        os << p.brand << ". " << p.style << ". " << p.bottles;
    }
};

class VintagePort : public Port
{
private:
    char *nickname;
    int year;
public:
    VintagePort()
    {
        year = 0;
        nickname = new char[1];
        nickname[0] = '\0';
    }
    VintagePort(const char * br, int b, const char * nn, int y)
    :Port(br,"none",b)
    {
        nickname = new char[strlen(nn)+1];
        strcpy(nickname, nn);
        year = y;
    }
    VintagePort(const VintagePort & vp)
    :Port(vp.brand,"none",vp.BottleCount())
    {
        nickname = new char[strlen(vp.nickname) +1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
    }
    ~VintagePort(){delete [] nickname;}
    VintagePort & operator=(const VintagePort & vp)
    {
        if(this==&vp)
            return *this;
        Port::operator=((const Port&) vp);
        delete [] nickname;
        nickname = new char[strlen(vp.nickname)+1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
        return *this;
    }
    void Show() const
    {
        Port::Show();
        cout <<"Nickname: " << nickname << endl;
        cout <<"Year: " << year << endl;
    }
    friend ostream & operator<<(ostream & os, const VintagePort & vp)
    {
        os << (const Port&)vp <<endl;
        os <<"Nickname: " << vp.nickname << endl;
        os <<"Year: " << vp.year << endl;
        return os;
    }
};

#endif