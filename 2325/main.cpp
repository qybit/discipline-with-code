#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        unordered_map<char, char> m;
        int ch = 0;
        for (char c : key)
        {
            if (c == ' ' || m.count(c))
                continue;
            m[c] = (char)(ch + 'a');
            ch++;
        }
        for (char &c : message)
        {
            if (c == ' ')
            {
                continue;
            }
            c = m[c];
        }
        return message;
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