#include <cstring>
#include "stringbad.h"

using namespace std;

int StringBad::num_strings = 0;

int StringBad::HowMany()
{
    return num_strings;
}

StringBad::StringBad(const char * s)
{
    len = strlen(s);
    str = new char[len+1];
    strcpy(str, s);
    num_strings++;
    // cout <<num_strings<<": \"" << str <<"\" object created\n";
}


StringBad::StringBad()
{
    str = new char[1];  //兼容 delete [] str
    str[0] = '\0';
    num_strings++;
    // cout <<num_strings<<": \"" << str <<"\" object created\n";
}

StringBad::~StringBad()
{
    // cout << "\""<< str <<"\" object deleted, ";
    --num_strings;
    // cout <<num_strings << " left\n";
    delete [] str;
}

ostream & operator<<(ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, StringBad & st)
{
    char temp[StringBad::CINLIM];
    is.get(temp, StringBad::CINLIM);
    if(is)
        st = temp;
    while(is && is.get()!='\n')
        continue;
    return is;
}


// 拷贝函数深复制
StringBad::StringBad(const StringBad & st)
{
  num_strings++;
  len = st.len;
  str = new char[len+1];
  std::strcpy(str, st.str);  // 复制构造，深复制而非隐式浅复制
}


StringBad & StringBad::operator=(const char * s)
{
    delete []str;
    len = strlen(s);
    str = new char[len+1];
    strcpy(str,s);
    return *this;
}

// 赋值深复制:并非创建对象，而是对已有对象操作
StringBad & StringBad::operator=(const StringBad & st)
{
  if(this == &st)  // assigned to itself
    return *this;
  delete [] str; // free old
  len = st.len;
  str = new char [len+1];
  strcpy(str, st.str);
  return *this;
}


bool operator<(const StringBad & st1, const StringBad & st2)
{
    return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const StringBad & st1, const StringBad & st2)
{
    return (strcmp(st1.str, st2.str) > 0);
}
bool operator==(const StringBad & st1, const StringBad & st2)
{
    return (strcmp(st1.str, st2.str) == 0);
}

char & StringBad::operator[](int i)
{
    return str[i];
}