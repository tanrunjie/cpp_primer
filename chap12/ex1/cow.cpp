#include "cow.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int Cow::cow_num = 0;

Cow::Cow()
{
    name[0]='\0';
    hobby = NULL;
    weight = 0.0;
    cow_num++;
    cout <<"cow_num: " << cow_num << endl;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    strcpy(name, nm);
    hobby = new char[strlen(ho)+1];
    strcpy(hobby, ho);
    weight = wt;
    cow_num++;
    cout <<"cow_num: " << cow_num << endl;

}

Cow::Cow(const Cow & c)
{
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    cow_num++;
    cout <<"cow_num: " << cow_num << endl;

}

Cow::~Cow()
{
    delete hobby;
    cow_num--;
    cout <<"cow_num: " << cow_num << endl;

}

Cow & Cow::operator=(const Cow & c)
{   
    // important! 判断自身，删除旧有数据空间
    if(this == &c)
        return *this;
    delete hobby;

    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const
{

    cout << "name: " << name << endl;
    cout << "hobby: " << hobby << endl;
    cout << "weight: " << weight << endl;
    cout <<"cow_num: " << cow_num << endl;

}