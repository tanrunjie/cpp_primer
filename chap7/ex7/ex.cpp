#include <iostream>
using namespace std;

const int Max = 5;

double* fill_array(double ar[], double* begin, double*end)
{
    double temp;
    double* i;
    for(i=begin; i!=end; i++)
    {
        cout <<"Enter value #" << (i-begin+1) <<": ";
        cin>>temp;
        if(!cin)
        {
            cin.clear();
            while(cin.get()!='\n')
                continue;
            cout <<"Bad input: input process terminated.\n";
            break;
        }
        else if(temp < 0)
            break;
        *i = temp;
    }
    return i;
}

void show_array(const double ar[], double* p)
{
    for(const double *i=ar; i!=p;i++)
    {
        cout <<"Property #" <<(i-ar+1) <<": $";
        cout <<*i <<endl;
    }
}
void revalue(double r, double ar[], double* p)
{
    for(double *i=ar; i!=p; i++)
         (*i)*=r;
}

int main()
{
    double properties[Max];
    double *begin = properties;
    double *end = properties+Max;
    double *size = fill_array(properties, begin, end);
    show_array(properties, size);
    cout <<"Enter revaluation factor:";
    double factor;
    cin >> factor;
    revalue(factor,properties,size);
    show_array(properties,size);
    cout <<"Done.\n";
    
    return 0;
}