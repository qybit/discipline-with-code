#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        unordered_set<int> s(suits.begin(), suits.end());
        if (s.size() == 1)
            return "Flush";
        unordered_map<int, int> m;
        for (int r : ranks)
            m[r]++;
        if (m.size() == 5)
            return "High Card";
        for (auto [_, v] : m)
        {
            if (v >= 3)
                return "Three of a Kind";
        }
        return "Pair";
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