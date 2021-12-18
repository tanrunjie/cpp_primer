#include <iostream>
using namespace std;

const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> pa[i].fullname;
        if (!cin)
            break;
        cin >> pa[i].hobby;
        if (!cin)
            break;
        cin >> pa[i].ooplevel;
        if (!cin)
            break;
    }
    return i;
}

void display1(student st)
{
    cout << "fullname:" << st.fullname << endl;
    cout << "hobby:" << st.hobby << endl;
    cout << "ooplevel:" << st.ooplevel << endl;
}

void display2(const student *st)
{
    cout << "fullname:" << st->fullname << endl;
    cout << "hobby:" << st->hobby << endl;
    cout << "ooplevel:" << st->ooplevel << endl;
}

void display3(const student st[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "fullname:" << st[i].fullname << endl;
        cout << "hobby:" << st[i].hobby << endl;
        cout << "ooplevel:" << st[i].ooplevel << endl;
    }
}
int main()
{
    cout << "enter class size:";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for(int i=0; i<entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete []ptr_stu;
    cout <<"Done\n";
    return 0;
}