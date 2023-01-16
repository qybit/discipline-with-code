#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string_view> split(const string &src, char target)
    {
        vector<string_view> ret;
        string_view s(src);
        int pos = 0;
        int n = s.size();
        while (pos < n)
        {
            while (pos < n && s[pos] == target)
            {
                pos++;
            }
            int start = pos;
            while (pos < n && s[pos] != target)
            {
                pos++;
            }
            if (pos > start)
            {
                ret.emplace_back(s.substr(start, pos - start));
            }
        }
        return ret;
    }

    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string_view> s1 = split(sentence1, ' ');
        vector<string_view> s2 = split(sentence2, ' ');
        int m = s1.size(), n = s2.size();
        int i = 0, j = 0;
        while (i < m && i < n && s1[i] == s2[i])
        {
            i++;
        }
        while (j < m - i && j < n - i && s1[m - j - 1] == s2[n - j - 1])
        {
            j++;
        }
        return i + j == min(m, n);
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