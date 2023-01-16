#include <bits/stdc++.h>

using namespace std;

/**
 * 同Java String.split 方法
 *
 * @param src // 要分割的字符串
 * @param target // 按照 target 进行分割
 * @return ret{vector<string_view>} 按照 target 分割后返回的字符串数组
 */
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

void solve()
{
}
int main()
{
    solve();
    return 0;
}