#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>
#include <iostream>

using namespace std;

class Worker
{
private:
    string fullname;
    long id;

protected:
    virtual void Data() const;
    virtual void Get();

public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const string &s, long n) : fullname(s), id(n) {}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

template<class Type> 
class Queue
{
private:
    enum {SIZE =20};
    int queuesize;
    Type * items;
public:
    explicit Queue(int ss= SIZE);
    Queue(const Queue & qu);
    ~Queue(){delete [] items;}
    bool isfull() const
    {
        return queuesize == SIZE;
    }
    bool isempty() const
    {
        return queuesize == 0;
    }
    bool enqueue(const Type &it)
    {
        if(isfull())
            return false;
        else
        {
            items[queuesize] = it;
            queuesize++;
        }
    }
    bool dequeue(Type &it)
    {
        if(isempty())
            return false;
        else
        {
            it = items[queuesize];
            queuesize--;
        }
    }
    Queue & operator=(const Queue & qu);
};

template<class Type> 
Queue<Type>::Queue(int ss):queuesize(ss)
{
    items = new Type[queuesize];
}

template<class Type> 
Queue<Type>::Queue(const Queue & qu)
{
    queuesize = qu.queuesize;
    items = new Type[queuesize];
    for(int i=0; i<queuesize; i++)
        items[i] = qu.items[i];
}

template<class Type> 
Queue<Type> & Queue<Type>::operator=(const Queue<Type> & qu)
{
    if(this==&qu)
        return *this;
    delete [] items;
    queuesize = qu.queuesize;
    items = new Type[queuesize];
    for(int i=0; i< queuesize; i++)
        items[i] = qu.items[i];
    return *this;
}

class Waiter : virtual public Worker
{
private:
    int panache;

protected:
    void Data() const;
    void Get();

public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const string &s, long n, int p = 0)
        : Worker(s, n), panache(p) {}
    Waiter(const Worker &wk, int p = 0)
        : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker
{
protected:
    enum
    {
        other,
        alto,
        contralto,
        soprano,
        brass,
        baritone,
        tenor
    };
    enum
    {
        Vtypes = 7
    };
    void Data() const;
    void Get();

private:
    static char *pv[Vtypes];
    int voice;

public:
    Singer() : Worker(), voice(other) {}
    Singer(const string &s, long n, int v = other)
        : Worker(s, n), voice(v) {}
    Singer(const Worker &wk, int v = other)
        : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};

class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter(){}
    SingingWaiter(const string & s, long n, int p=0, int v=other)
    :Worker(s,n), Waiter(s,n,p), Singer(s,n,v){}
    SingingWaiter(const Worker & wk, int p=0, int v=other)
    :Worker(wk), Waiter(wk,p), Singer(wk,v){}
    SingingWaiter(const Waiter & wt, int v = other)
    :Worker(wt), Waiter(wt), Singer(wt,v){}
    SingingWaiter(const Singer & wt, int p = 0)
    :Worker(wt), Waiter(wt, p), Singer(wt){}
    void Set();
    void Show() const;
};
#endif