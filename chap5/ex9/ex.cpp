#include <iostream>
#include <string>
int main()
{
    using namespace std;
    int rows;
    cout <<"Enter number of rows:";
    cin >> rows;
    string dot =".";
    string star = "*";
    for(int i=0; i<rows; i++)
    {
        int j;
        for(j= 0; j<(rows-1-i); j++)
            cout << dot;
        for(int k= 0;k< rows-j;k++)
            cout << star;
        cout << endl;
    }
    
    return 0;
}
