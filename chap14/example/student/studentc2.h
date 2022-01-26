#ifndef STUDENTC2_H_
#define STUDENTC2_H_

#include <iostream>
#include <string>
#include <valarray>

using namespace std;
// 多重私有继承 has-a
class Student: private string, private valarray<double>
{
private:
    typedef valarray<double> ArrayDb;
    ostream & arr_out(ostream & os) const;

public:
    Student():string("Null Student"),ArrayDb(){}
    Student(const string & s):string(s),ArrayDb(){}
    explicit Student(int n):string("Nully"), ArrayDb(n){} //不支持隐式转换
    Student(const string & s, int n):string(s),ArrayDb(n){}
    Student(const string & s, const ArrayDb & a):string(s),ArrayDb(a){}
    Student(const char * str, const double * pd, int n)
    :string(str),ArrayDb(pd,n){}
    ~Student(){}
    double Average() const;
    const string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;

    friend istream & operator>>(istream & is, Student & stu);
    friend istream & getline(istream & is, Student & stu);
    friend ostream & operator<<(ostream & os, const Student & stu);

};

#endif