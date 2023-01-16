#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        unordered_map<string, int> m;
        int n = messages.size();
        for (int i = 0; i < n; i++)
        {
            m[senders[i]] += count(messages[i].begin(), messages[i].end(), ' ') + 1;
        }
        int maxWord = 0;
        string ans;
        for (auto &[k, v] : m)
        {
            if (v > maxWord)
            {
                ans = k;
                maxWord = v;
            }
            else if (v == maxWord)
            {
                if (k > ans)
                {
                    ans = k;
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