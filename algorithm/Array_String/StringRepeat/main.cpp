//請實作演算法，判斷某字串裡的所有字元市否皆不同

#include <iostream>
#include <string.h>
using namespace std;


bool isRepeat(const char *str, int len)
{
    char index[128];
    memset(index, 0, sizeof(index));
    for (int i = 0; i < len; i++) {
        char cur = str[i];
        if (index[cur] == 0)
            index[cur] = 1;
        else
            return true;
    }

    return false;
}

int main(int argc, char** argv)
{
    char str1[] = "abcdefg";
    cout << "str: \"" << str1 << "\" repeat: " << isRepeat(str1, strlen(str1)) << endl;
    char str2[] = "abcdefgaab";
    cout << "str2: \"" << str2 << "\" repeat: " << isRepeat(str2, strlen(str2)) << endl;
}
