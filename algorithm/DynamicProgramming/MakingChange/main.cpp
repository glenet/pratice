#include <iostream>
#include <string.h>
using namespace std;

int makingChange(int *coin, int n, int S)
{
    if (n < 0)
        return -1;
    if (n == 0 && S > 0 )
        return -1;

    int count[S + 1];
    for (int i = 0; i < S + 1; i++)
        count[i] = 0xFFFF;
    //S = 0, no need coins
    count[0] = 0;

    for (int i = 1; i < S + 1; i++) {
        for (int j = 0; j < n; j++) {
            if (coin[j] <= i && count[i - coin[j]] + 1 < count[i])
                count[i] = count[i - coin[j]] + 1;
        }
    }

    if (count[S] == 0xffff)
        return -1;
    else
        return count[S];
}

int makingChange_2Dim(int *coin, int n, int S)
{
    //Base case
    if (n < 0)
        return -1;
    if (n == 0 && S > 0)
        return -1;

    int count[n + 1][S + 1];

    //no coin, impossible
    for (int i = 0; i < S + 1; i++)
        count[0][i] = 0xffff;

    //S = 0, no need coin
    for (int i = 0; i < n + 1; i++)
        count[i][0] = 0;

    count[0][0] = 0;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < S + 1; j++) {
            int cur_value = j;
            int cur_coin = coin[i - 1];
            if (cur_coin <= cur_value) {
                count[i][j] = min(count[i - 1][j], count[i][cur_value - cur_coin] + 1);
            }
            else
                count[i][j] = count[i - 1][j];
        }
    }

    if (count[n][S] == 0xffff)
        return -1;
    else
        return count[n][S];
}

int main(int argc, char **argv)
{
    int size, sum;
    cout << "input 'size' and 'sum'" << endl;
    cout << "ex: 4 63" << endl;
    cin >> size >> sum;

    cout << "input coins" << endl;
    cout << "ex: 1 10 30 40" << endl;

    int* arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        int c;
        cin >> c;
        arr[i] = c;
    }

    int out = makingChange(arr, size, sum);

    cout << endl;
    if (out > 0)
        cout << "1 Dim: Minimum " << out << " coins needed" << endl;
    else
        cout << "1 Dim: Impossible" << endl;

    out = makingChange_2Dim(arr, size, sum);

    if (out > 0)
        cout << "2 Dim: Minimum " << out << " coins needed" << endl;
    else
        cout << "2 Dim: Impossible" << endl;
    delete [] arr;
}
