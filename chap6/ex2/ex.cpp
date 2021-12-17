#include <iostream>

int main()
{
    using namespace std;
    const int MAX_NUM = 10;
    double donations[MAX_NUM];
    
    int cnt =0;
    double donation;
    for(int i=0; i<MAX_NUM; i++)
    {
        if(cin>>donation)
        {
            donations[i] = donation;
        }
        else
        {
            
            double sum;
            for(int j=0; j<i; j++)
            {
                sum += donations[j];
            }
            double avg = sum/i;
            cout <<"avg:" << avg << endl;
            int big_num = 0;
            for(int j=0; j<i; j++)
            {
                if(donations[j]> avg)
                    big_num++;
            }
            cout <<"There are " <<big_num <<" bigger than avg"<<endl;
            break;
        }
    }
    return 0;
}
