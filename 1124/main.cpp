#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        int n = hours.size();
        vector<int> count(n + 1);
        stack<int> st;
        st.push(0);
        for (int i = 1; i <= n; i++)
        {
            count[i] = count[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if (count[st.top()] > count[i])
            {
                st.push(i);
            }
        }
        int ans = 0;
        for (int i = n; i >= 1; i--)
        {
            while (st.size() && count[st.top()] < count[i])
            {
                ans = max(ans, i - st.top());
                st.pop();
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