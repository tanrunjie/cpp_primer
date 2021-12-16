#include <iostream>
#include <string>
using namespace std;
int main()
{
    cout <<"Enter words (to stop, type the word done):\n" ;

    string words;
    string done = "done";
    int cnt = 0;

    while(cin>>words)
    {
        if(words == done)
        {
            break;
        }
        cnt++;
    }
    cout <<"You entered a total of " <<cnt <<" words.\n";
    return 0;
}