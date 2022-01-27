#ifndef WINEC_H_
#define WINEC_H_
#include <string>
#include <valarray>
#include <iostream>

using namespace std;

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;

public:
    T1 &first();
    T2 &second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}
    Pair() {}
};

template <class T1, class T2>
T1 &Pair<T1, T2>::first()
{
    return a;
}

template <class T1, class T2>
T2 &Pair<T1, T2>::second()
{
    return b;
}

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine:private string, private PairArray
{
private:
    int yrs;
public:
    Wine(const char * l, int y, const int yr[], const int bot[])
    :string(l),yrs(y)
    {
        PairArray::first() = ArrayInt(yr, yrs);
        PairArray::second() = ArrayInt(bot, yrs);
    }
    Wine(const char * l, int y)
    :string(l), yrs(y) {GetBottls();}

    void GetBottls()
    {
        cout <<"Please input "<<yrs<<" times years and bottles:";
        int y[yrs];
        int b[yrs];
        for(int i=0;i<yrs;i++)
        {
            cin>>y[i] >>b[i];
        }
        PairArray::first() = ArrayInt(y, yrs);
        PairArray::second() = ArrayInt(b, yrs);
    }

    string & Label(){return (string &)*this;}

    int sum()
    {
        int s = 0;
        for(int i=0;i<yrs;i++)
        {
            s+= PairArray::second()[i];
        }
        return s;
    }
    void show() const
    {
        cout <<"Label: " << (string)*this << endl;
        cout <<"YRS: "<< yrs << endl;
        for(int i=0;i<yrs ;i++)
        {
            cout <<"year: " << PairArray::first()[i] << "\tbottles: "
            <<PairArray::second()[i] << endl;
        }
    }
};

#endif