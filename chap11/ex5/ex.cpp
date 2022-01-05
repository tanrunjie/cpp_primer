#include <iostream>
#include "stonewt.h"

using namespace std;


void display(const Stonewt st, int n)
{
    for(int i=0; i<n; i++)
    {
        cout <<"Wow! ";
        st.show('m');
    }
}
int main()
{
    Stonewt pavarotti = 260; //implicit transform
    Stonewt wolfe(286.7);
    Stonewt taft(21, 8);

    cout <<"The tenor weighed "<< pavarotti ;

    cout <<"The detective weighed " << wolfe ;
    cout <<"The president weighed " << taft ;
    pavarotti = 265.8;
    taft = 325;
    cout <<"After dinner, the tenor weighted " << pavarotti ;
    cout <<"After dinner, the President weighted " << taft ;
    display(taft, 2);
    cout <<"The wrestler weighed even more.\n";
    display(422, 2);
    cout <<"No stone left uneared\n";
    
    cout << endl << endl << endl;

    Stonewt sum = pavarotti + wolfe;
    Stonewt diff = taft - pavarotti;
    Stonewt mul =  2.2* taft;
    cout << sum << diff << mul;
    return 0;
}