#include <iostream>

using namespace std;

const int MAX_NUM = 10;
int arr_input(float golfs[MAX_NUM])
{
    cout << "At most input 10 nums, input -1 as end of input" << endl;
    float num;
    int cnt;
    for (cnt = 0; cnt < MAX_NUM;)
    {
        cin >> num;
        if (num == -1)
            break;
        golfs[cnt] = num;
        cnt++;
    }
    return cnt;
}

void arr_show(float golfs[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << golfs[i] << " ";
    }
    cout << endl;
}

float arr_avg(float golfs[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += golfs[i];
    }
    return sum / size;
}
int main()
{
    float golfs[MAX_NUM];
    int size = arr_input(golfs);
    arr_show(golfs, size);
    cout << "Avg: " << arr_avg(golfs, size) << endl;
    return 0;
}