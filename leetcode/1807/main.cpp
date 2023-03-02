#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        unordered_map<string, string> m;
        for (vector<string> &kv : knowledge)
        {
            m[kv[0]] = kv[1];
        }
        bool addKey = false;
        string ans, key;
        for (char c : s)
        {
            if (c == '(')
            {
                addKey = true;
            }
            else if (c == ')')
            {
                if (m.count(key) != 0)
                {
                    ans += m[key];
                }
                else
                {
                    ans.push_back('?');
                }
                addKey = false;
                key.clear();
            }
            else
            {
                if (addKey)
                {
                    key.push_back(c);
                }
                else
                {
                    ans.push_back(c);
                }
            }
        }
        return ans;
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