#include <iostream>
#include <string>
#include "queuetp.h"

using namespace std;
int main()
{
    QueueTP<string> cs(5);
    string temp;

    while(!cs.isfull())
    {
        cout <<"Please enter your name. you will be served in the order of arrival." << endl;
        cout <<"name:";
        getline(cin, temp);
        cs.enqueue(temp);
    }
    cout <<"The queue is full. Processing begins!" << endl;

    while(!cs.isempty())
    {
        cs.dequeue(temp);
        cout <<"Now processing " << temp << "..." << endl;
        
    }

    return 0;
}