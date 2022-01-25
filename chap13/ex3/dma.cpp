#include "dma.h"
#include <cstring>
using namespace std;

ABC::ABC()
{
    label = new char[1];
    label[0] = '\0';
    rating = 0;
}

ABC::ABC(const char * l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}
ABC::ABC(const ABC& rs) // important!!
{
    label = new char[strlen(rs.label) + 1];
    strcpy(label,rs.label);
    rating = rs.rating;
}

ABC & ABC::operator=(const ABC & rs)
{
    if(this==&rs)
        return *this;
    delete []label;
    label = new char[strlen(rs.label)+1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

ABC::~ABC(){ delete [] label;}

baseDMA::baseDMA(const char * l, int r):ABC(l,r){}

baseDMA::baseDMA(const baseDMA & rs):ABC(rs.label,rs.rating){}


ostream & operator<<(ostream & os, const ABC & rs)
{
    os<<"Label:" << rs.label << endl;
    os<<"Rating:"<<rs.rating << endl;
    return os;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if(this==&rs)   
        return *this;
    ABC::operator=(rs);
    return *this;
}

ostream & operator<<(ostream & os, const baseDMA & rs)
{
    os<< (const ABC&) rs;
    return os;
}
lacksDMA::lacksDMA(const char * c, const char * l, int r):ABC(l,r)
{
    strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA( const ABC & rs, const char * c):ABC(rs)
{
    strncpy(color, c, COL_LEN-1);
    color[COL_LEN-1] = '\0';
}

ostream & operator<<(ostream & os, const lacksDMA & ls)
{
    os << (const ABC&) ls;
    os <<"Color: " << ls.color << endl;
    return os;
}

hasDMA::hasDMA(const char *s, const char * l, int r):ABC(l,r)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const ABC & rs):ABC(rs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs): ABC(hs)
{
    style = new char[strlen(hs.style)+1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    cout <<"in hasDMA" << endl;
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if(this==&hs)
        return *this;
    ABC::operator=(hs);
    delete []style;
    style = new char[strlen(hs.style)+1];
    strcpy(style, hs.style);
    return *this;
}

ostream & operator<<(ostream &os, const hasDMA & hs)
{
    os<< (const ABC &) hs;  // 强制类型转换
    os<<"Style: "<<hs.style << endl;
    return os;
}

