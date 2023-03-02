#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        unordered_map<int, unordered_set<int>> m;
        for (auto &&log : logs)
        {
            int id = log[0], time = log[1];
            m[id].emplace(time);
        }
        vector<int> ans(k);
        for (auto &[_, minutes] : m)
        {
            int ops = minutes.size();
            ans[ops - 1]++;
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