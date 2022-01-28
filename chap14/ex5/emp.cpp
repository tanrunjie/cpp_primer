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
   Get();
}