#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    cout <<"Enter words (to stop, type the word done):\n" ;

    char words[256];
    char done[5] = "done";
    int cnt = 0;

    while(cin>>words)
    {
        if(strcmp(words, done) ==0)
        {
            break;
        }
        cnt++;
    }
    cout <<"You entered a total of " <<cnt <<" words.\n";
    return 0;
}