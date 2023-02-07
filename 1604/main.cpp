#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int convert(string time)
    {
        int hours = (time[0] - '0') * 10 + (time[1] - '0');
        int mins = (time[3] - '0') * 10 + (time[4] - '0');
        return hours * 60 + mins;
    }

    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
    {
        unordered_map<string, vector<int>> m;
        int n = keyName.size();
        for (int i = 0; i < n; i++)
        {
            m[keyName[i]].emplace_back(convert(keyTime[i]));
        }
        vector<string> ans;
        for (auto &[k, v] : m)
        {
            sort(v.begin(), v.end());
            int sz = v.size();
            bool flag = false;
            if (sz > 2)
            {
                for (int i = 2; i < sz; i++)
                {
                    if (v[i] - v[i - 2] <= 60)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
            {
                ans.emplace_back(k);
            }
        }
        sort(ans.begin(), ans.end());
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