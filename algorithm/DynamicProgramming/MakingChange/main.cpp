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
        cout << "Minimum " << out << " coins needed" << endl;
    else
        cout << "Impossible" << endl;

    delete [] arr;
}
