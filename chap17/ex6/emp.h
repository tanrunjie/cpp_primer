#ifndef EMP_H
#define EMP_H

#include <iostream>
#include <fstream>

#include <string>
using namespace std;

enum classkind
{
    Zero,
    Employee,
    Manager,
    Fink,
    HighFink
};
class abstr_emp
{
private:
    string fname;
    string lname;
    string job;

protected:
    virtual void Data() const
    {
        cout << "fname: " << fname << endl;
        cout << "lname: " << lname << endl;
        cout << "job: " << job << endl;
    }
    virtual void Get()
    {
        cout << "Please input fname,lname,job: ";
        cin >> fname >> lname >> job;
    }

public:
    abstr_emp() : fname(""), lname(""), job("") {}
    abstr_emp(const string &fn, const string &ln, const string &j)
        : fname(fn), lname(ln), job(j) {}
    abstr_emp(const abstr_emp &a)
        : fname(a.fname), lname(a.lname), job(a.job) {}

    virtual ~abstr_emp() = 0;
    virtual void SetAll() = 0;
    virtual void ShowAll() const = 0;
    virtual void setall(ifstream &fin)
    {
        getline(fin, fname);
        getline(fin, lname);
        getline(fin, job);
    }
    virtual void writeall(ofstream &fout)
    {
        fout << fname << endl
             << lname << endl
             << job << endl;
    }

    friend ostream &operator<<(ostream &os, const abstr_emp &e)
    {
        os << "fname: " << e.fname << endl;
        os << "lname: " << e.lname << endl;
    }
};

class employee : virtual public abstr_emp
{
public:
    employee() : abstr_emp() {}
    employee(const string &fn, const string &ln,
             const string &j) : abstr_emp(fn, ln, j) {}
    void ShowAll() const
    {
        cout << "Category: employee: " << endl;
        abstr_emp::ShowAll();
    }
    void SetAll()
    {
        abstr_emp::SetAll();
    }
    virtual void setall(ifstream &fin) { abstr_emp::setall(fin); }

    virtual void writeall(ofstream &fout)
    {
        fout << Employee << endl;
        abstr_emp::writeall(fout);
    }
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof;

protected:
    int InChargeOf() const { return inchargeof; }
    int &InChargeOf() { return inchargeof; }
    void Data() const
    {
        cout << "inchargeof: " << inchargeof << endl;
    }
    void Get()
    {
        cout << "Please input inchargeof: ";
        cin >> inchargeof;
    }

public:
    manager() : abstr_emp(), inchargeof(0) {}
    manager(const string &fn, const string &ln,
            const string &j, int ico = 0)
        : abstr_emp(fn, ln, j), inchargeof(ico) {}
    manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico) {}
    manager(const manager &m)
        : abstr_emp(m), inchargeof(m.InChargeOf()) {}
    void ShowAll() const
    {
        cout << "Category: manager" << endl;
        abstr_emp::ShowAll();
        Data();
    }
    void SetAll()
    {
        abstr_emp::SetAll();
        Get();
    }
    virtual void setall(ifstream &fin)
    {
        abstr_emp::setall(fin);
        fin >> inchargeof;
        fin.ignore();
    }
    virtual void writeall(ofstream &fout)
    {
        fout << Manager << endl;
        abstr_emp::writeall(fout);
        fout << inchargeof << endl;
    }
};

class fink : virtual public abstr_emp
{
private:
    string reportsto;

protected:
    const string ReportsTo() const { return reportsto; }
    string &ReportsTo() { return reportsto; }
    void Data() const
    {
        cout << "reportsto: " << reportsto << endl;
    }
    void Get()
    {
        cout << "Please input reportsto: ";
        cin >> reportsto;
    }

public:
    fink() : abstr_emp(), reportsto("") {}
    fink(const string &fn, const string &ln,
         const string &j, const string &rpo)
        : abstr_emp(fn, ln, j), reportsto(rpo) {}
    fink(const abstr_emp &e, const string &rpo)
        : abstr_emp(e), reportsto(rpo) {}
    fink(const fink &e)
        : abstr_emp(e), reportsto(e.ReportsTo()) {}
    void ShowAll() const
    {
        cout << "Category: fink" << endl;
        abstr_emp::ShowAll();
        Data();
    }
    void SetAll()
    {
        cout <<"Fink setall"<< endl;
        abstr_emp::SetAll();
        Get();
    }
    virtual void setall(ifstream &fin)
    {
        abstr_emp::setall(fin);
        fin >> reportsto;
        fin.ignore();
    }
    virtual void writeall(ofstream &fout)
    {
        fout << Fink << endl;
        abstr_emp::writeall(fout);
        fout << reportsto << endl;
    }
};

class highfink : public manager, public fink
{

protected:
    void Data() const
    {
        manager::Data();
        fink::Data();
    }
    void Get()
    {
        manager::Get();
        fink::Get();
    }

public:
    highfink() : abstr_emp(), manager(), fink() {}
    highfink(const string &fn, const string &ln, const string &j, const string &rpo, int ico)
        : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
    highfink(const abstr_emp &e, const string &rpo, int ico)
        : abstr_emp(e), manager(e, ico), fink(e, rpo) {}
    highfink(const fink &f, int ico)
        : abstr_emp(f), manager(f, ico), fink(f) {}
    highfink(const manager &m, const string &rpo)
        : abstr_emp(m), manager(m), fink(m, rpo) {}
    highfink(const highfink &h)
        : abstr_emp(h), manager(h), fink(h) {}
    void ShowAll() const
    {
        cout << "Category: highfink" << endl;
        abstr_emp::Data();
        Data();
    }
    void SetAll()
    {
        abstr_emp::Get();
        Get();
    }
    virtual void setall(ifstream &fin)
    {
        abstr_emp::setall(fin);
        fin >> manager::InChargeOf();
        fin.ignore();
        fin >> fink::ReportsTo();
        fin.ignore();
    }
    virtual void writeall(ofstream &fout)
    {
        fout << HighFink << endl;
        abstr_emp::writeall(fout);
        fout << manager::InChargeOf() << endl;
        fout << fink::ReportsTo() << endl;
    }
};

#endif