#include <bits/stdc++.h>

using namespace std;

class Solution1
{
public:
    int s2i(const string_view &s)
    {
        int num = 0;
        for (char c : s)
        {
            num = num * 10 + (c - '0');
        }
        return num;
    }

    vector<int> split(const string &src, char target)
    {
        vector<int> ret;
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
                string_view t = s.substr(start, pos - start);
                if (isdigit(t[0]))
                {
                    ret.push_back(s2i(t));
                }
            }
        }
        return ret;
    }

    bool areNumbersAscending(string s)
    {
        vector<int> nums = split(s, ' ');
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int prev = 0;
        int pos = 0, n = s.size();
        while (pos < n)
        {
            if (isdigit(s[pos]))
            {
                int cur = 0;
                while (pos < n && isdigit(s[pos]))
                {
                    cur = cur * 10 + s[pos] - '0';
                    pos++;
                }
                if (cur <= prev)
                {
                    return false;
                }
                prev = cur;
            }
            else
            {
                pos++;
            }
        }
        return true;
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