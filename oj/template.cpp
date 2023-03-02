#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void solve()
{
    cin >> n;
    vector<int> speeds(n);
    for (auto &it : speeds) cin >> it;
    vector<int> f(n + 1);
    int len = 1;
    f[len] = speeds[0];
    for (int i = 1; i < n; i ++) {
        if (speeds[i] <= f[len]) {
            f[++len] = speeds[i];
        } else {
            int l = 1, r = len, pos = 0;
            while (l <= r) {
                int m = (l + r) >> 1;
                if (f[m] > speeds[i]) {
                    pos = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            f[pos + 1] = speeds[i];
        }
    }

    cout << len << endl;
}
int main()
{
    solve();
    return 0;
}