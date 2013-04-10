#include <iostream>

using namespace std;

void reverse(char *str)
{
    char *tmp = str;

    while ((*tmp)) {
        tmp++;
    }

    //null for the end
    tmp--;

    while(tmp > str) {
        swap(*str, *tmp);
        str++;
        tmp--;
    }
}

int main(int argc, char **argv)
{
    char str[] = "qwert";
    reverse(str);
    cout << "reverse: " << str << endl;

    return 0;
}

