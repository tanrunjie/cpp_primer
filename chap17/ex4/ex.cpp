#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{

    ifstream fin1;
    ifstream fin2;

    ofstream fout;
    fin1.open("in1", ios_base::in);
    fin2.open("in2", ios_base::in);
    fout.open("out", ios_base::out);

    if (!fout.is_open() || !fin1.is_open() || !fin1.is_open())
    {
        cerr << "Cloud not open file" << endl;
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        string s1, s2;

        getline(fin1, s1); // 返回值:一直为True，就算结尾；失败抛出异常
        getline(fin2, s2);

        if (s1.size() != 0 && s2.size() != 0)
            fout << s1 << " " << s2 << endl;
        else if (s1.size() != 0 && s2.size() == 0)
            fout << s1 << endl;
        else if (s1.size() == 0 && s2.size() != 0)
            fout << s2 << endl;
        else
            break;
    }

    fin1.close();
    fin2.close();

    fout.close();

    return 0;
}