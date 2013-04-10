#include <iostream>
#include <algorithm>
#include <string.h>
#include <assert.h>
using namespace std;

bool isMatch(char str1[], int len1, char str2[], int len2)
{
    if (len1 != len2)
        return false;

    char c_str1[len1];
    char c_str2[len2];

    strcpy(c_str1, str1);
    strcpy(c_str2, str2);

    sort(c_str1, c_str1 + len1 - 1);
    sort(c_str2, c_str2 + len2 - 1);

    return strcmp(c_str1, c_str2) ? false : true;
}

int main(int argc, char **argv)
{
    char* str[4] = {"god", "dog", "ccc", "c"};
    assert(isMatch(str[0], strlen(str[0]) + 1, str[1], strlen(str[1]) + 1) == true);
    assert(isMatch(str[0], strlen(str[0]) + 1, str[2], strlen(str[2]) + 1) == false);
    assert(isMatch(str[0], strlen(str[0]) + 1, str[3], strlen(str[3]) + 1) == false);
    cout << "Done" << endl;
}
