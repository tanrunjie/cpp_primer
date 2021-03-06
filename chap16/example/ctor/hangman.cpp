#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

const int NUM = 26;
const string wordlist[NUM] = {
    "apiary","beetle","cereal","danger","ensign","florid","garage",
    "health","insult","jackal","keeper","loaner","manage","nonce",
    "onset","plaid","quilt","remote","stolid","train","useful",
    "valid","whence","xenon","yearn","zippy"
};

int main()
{
    srand(time(0));
    char play;
    cout << "Will you play a word game?<y/n>";
    cin >> play;
    play = tolower(play);
    while(play=='y')
    {
        string target = wordlist[rand() %NUM];
        int length = target.length();
        string attemp(length,'-');
        string badchars;
        int guesses = 6;
        cout <<"Guess my secret word. It has " << length 
        << " letters, and you guess\n"
        << "one letter at a time. You get " << guesses
        << " wrong guesses.\n";

        cout <<"Your word: " << attemp << endl;
        
        while(guesses>0 && attemp!=target)
        {
            char letter;
            cout <<"Guess a letter: ";
            cin >> letter;
            if(badchars.find(letter)!=string::npos ||
            attemp.find(letter)!=string::npos)
            {
                cout <<"You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if(loc == string::npos)
            {
                cout <<"Oh, bad guess!" << endl;
                --guesses;
                badchars += letter;
            }
            else
            {
                cout <<"Good guess! "<<endl;
                attemp[loc] = letter;

                // 找到多个同字母
                loc = target.find(letter, loc+1);
                while (loc != string::npos)
                {
                    attemp[loc] = letter;
                    loc = target.find(letter, loc+1);
                }
                
            }
            cout << "Your word: " << attemp << endl;
            if(attemp != target)
            {
                if(badchars.length()>0)
                    cout <<"Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left" << endl;
            }
        }
        if(guesses>0)
            cout <<"That's right!" << endl;
        else 
            cout <<"Sorry, the word is " << target << ".\n";
        
        cout <<"Will you play another?<y/n>";
        cin >> play;
        play = tolower(play);
    }

    cout <<"Bye!" << endl;
    return 0;
}