#include<iostream>
using namespace std;

int Fill_array(double arr[], int size)
{
    cout <<"Plz input double num:" << endl;
    double num;
    int i;
    for(i=0; i<size; i++)
    {
        if(cin>>num)
        {
            arr[i] = num;
        }
        else
            break;
    }
    return i;
}

void Show_array(double arr[], int size)
{
    for(int i=0; i<size; i++)
        cout <<arr[i] <<" ";
    cout <<endl;
}

void Reverse_array(double arr[], int size)
{
    for(int i=0; i< size/2; i++)
    {
        double tmp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = tmp;
    }
}
int main()
{
    int size = 10;
    double arr[size];
    size = Fill_array(arr,size);
    Show_array(arr,size);
    Reverse_array(arr, size);
    Show_array(arr,size);

    return 0;
}