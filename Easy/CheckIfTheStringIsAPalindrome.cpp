#include <bits/stdc++.h>
bool checkPalindrome(string s)
{

    int c = 0, e = s.size() - 1;

    while (c < e)
    {
        if (!isalnum(s[c]))
        {
            c++;
        }
        else if (!isalnum(s[e]))
        {
            e--;
        }
        else if (tolower(s[c]) != tolower(s[e]))
        {
            return false;
        }
        else
        {
            c++;
            e--;
        }
    }
    return true;
}
