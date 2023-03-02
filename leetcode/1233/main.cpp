#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        string pre = "";
        for (auto p : folder)
        {
            if (pre != "" && p.find(pre) == 0)
            {
                continue;
            }
            pre = p + "/";
            ans.emplace_back(p);
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