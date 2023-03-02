#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string ans;
    int maxNodes;
    int n, k;
    unordered_set<string> visited;

    bool dfs(string s)
    {
        if (visited.size() == maxNodes)
        {
            ans = s;
            return true;
        }

        string prefix = s.substr(s.size() - n + 1);
        for (int i = 0; i < k; i++)
        {
            string node = prefix + to_string(i);
            if (visited.count(node) == 0)
            {
                s = s + to_string(i);
                visited.insert(node);
                if (dfs(s))
                {
                    return true;
                }
                visited.erase(node);
                s.pop_back();
            }
        }
        return false;
    }

    string crackSafe(int _n, int _k)
    {
        n = _n, k = _k;
        maxNodes = pow(k, n);
        ans.resize(n, '0');
        visited.insert(ans);
        dfs(ans);
        return ans;
    }
};

void solve()
{
    Solution *s = new Solution();
    cout << 1 << endl;
}
int main()
{
    solve();
    return 0;
}