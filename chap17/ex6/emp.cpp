#include "emp.h"

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const
{
    cout << "fname: " << fname << endl;
    cout << "lname: " << lname << endl;
    cout << "job: " << job << endl;
}

void abstr_emp::SetAll()
{
    abstr_emp::Get();
}

// void abstr_emp::setall(ifstream &fin)
// {
//     getline(fin, fname);
//     getline(fin, lname);
//     getline(fin, job);
// }
// void abstr_emp::writeall(ofstream &fout)
// {
//     fout << fname << endl
//          << lname << endl
//          << job << endl;
// }

// void employee::setall(ifstream &fin) { abstr_emp::setall(fin); }

// void employee::writeall(ofstream &fout)
// {
//     fout << Employee << endl;
//     abstr_emp::writeall(fout);
// }
