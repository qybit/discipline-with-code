#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool strongPasswordCheckerII(string password)
    {
        int n = password.size();
        if (n < 8)
            return false;
        bool hasDigit = false, hasUpper = false, hasLower = false, hasSpecial = false;
        string speical = "!@#$%^&*()-+";
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && password[i] == password[i - 1])
            {
                return false;
            }
            char c = password[i];
            if (isdigit(c))
            {
                hasDigit = true;
            }
            else if (isupper(c))
            {
                hasUpper = true;
            }
            else if (islower(c))
            {
                hasLower = true;
            }
            else if (speical.find(c) != string::npos)
            {
                hasSpecial = true;
            }
        }
        return hasDigit && hasUpper && hasLower && hasSpecial;
    }
};

void solve()
{
    Solution *s = new Solution();
}
int main()
{
    solve();
    return 0;
}