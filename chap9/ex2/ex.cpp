#include <iostream>
#include <string>

void strcount(const std::string str)
{
    using namespace std;
    static int total = 0;
    int space_num = 0;
    for(int i=0; i<str.size(); i++)
        if(str[i]==' ')
            space_num++;

    total += (str.size()- space_num);
    cout << str.size()-space_num << " characters\n";
    cout << total << " characters total\n";
}

int main()
{
    using namespace std;
    string input;

    cout << "Enter a line: \n";
    getline(cin, input);
    while (input!="")
    {
        strcount(input);
        cout << "Enter next line(empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye\n";
    return 0;
}
