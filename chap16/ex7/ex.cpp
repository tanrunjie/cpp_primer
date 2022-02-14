#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

vector<int> Lotto(int cnt, int num)
{
    srand((unsigned)time(NULL));
    vector<int> lotto;
    for (int i = 1; i <= cnt; i++)
        lotto.push_back(i);
    // for (int i = 0; i < cnt; i++)
    //     cout << lotto[i] << " ";
    // cout << endl;
    random_shuffle(lotto.begin(), lotto.end());

    lotto.resize(num);
    for (int i = 0; i < num; i++)
        cout << lotto[i] << " ";
    cout << endl;
    return lotto;
}

int main()
{
    vector<int> winners;

    winners = Lotto(51, 6);

}