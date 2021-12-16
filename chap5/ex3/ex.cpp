#include <iostream>
int main()
{
    using namespace std;

    float dap = 100, cle = 100;

    for (int i = 1;; i++)
    {
        dap += i*10;
        cle *= 1.05;
        if(cle > dap)
        {
            cout << i <<" years" << endl;
            break;
        }    
    }
    return 0;
}