#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string str;
    cout <<"Enter words (q to quit):\n";
    int vowels=0, cons=0, others=0;
    while(cin>>str && str!="q")
    {
        if(isalpha(str[0]))
        {
            if(str[0]=='a'||str[0]=='A' || str[0]=='e' || str[0]=='E')
                vowels++;
            else if(str[0]=='i'||str[0]=='I' || str[0]=='o' || str[0]=='o')
                vowels++;
            else if (str[0]=='u'||str[0]=='U')
                vowels++;
            else
                cons++;
        }
        else
        {
            others++;
        }
    }
    cout <<vowels <<" words beginning with vowels\n";
    cout <<cons <<" words beginning with consonants\n";
    cout <<others <<" others\n";
    return 0;
}