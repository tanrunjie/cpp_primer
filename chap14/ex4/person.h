#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


class Person
{
private:
    string first_name;
    string last_name;

public:
    Person() {}
    Person(string f, string l)
        : first_name(f), last_name(l) {}
    void Show() const
    {
        cout << "first_name: " << first_name << endl;
        cout << "last_name: " << last_name << endl;
    }
};
class Gunslinger :virtual public Person
{
private:
    double draw;
    int num;

public:
    Gunslinger() {}
    Gunslinger(Person &p, double d, int n)
        : Person(p), draw(d), num(n) {}
    double Draw() const { return draw; }
    void Show() const
    {
        Person::Show();
        cout << "draw: " << draw << endl;
        cout << "num: " << num << endl;
    }
};

class PokerPlayer : virtual public Person
{
private:
    
public:
    PokerPlayer(Person & p):Person(p){}
    int Draw()
    {
        srand(time(NULL));
        return rand()%52+1;
    }
    void Show() const
    {
        Person::Show();
    }
};

class BadDude: virtual public Gunslinger, virtual public PokerPlayer
{
private:

public:
    BadDude(Gunslinger & g, PokerPlayer & p)
    :Gunslinger(g),PokerPlayer(p){}
    double Gdraw() const
    {
        return Gunslinger::Draw();
    }
    int CDraw() 
    {
        return PokerPlayer::Draw();
    }
    void Show() 
    {
        Gunslinger::Show();
        cout <<"Next Card:" << CDraw() << endl;
    }

};
#endif