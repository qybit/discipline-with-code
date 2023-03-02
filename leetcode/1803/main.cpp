/*
 * @Author: qybit 2601970213@qq.com
 * @Date: 2023-01-05 22:57:33
 * @LastEditors: qybit 2601970213@qq.com
 * @LastEditTime: 2023-01-06 00:23:18
 * @FilePath: \discipline-with-code\1803\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>

using namespace std;

struct Tire
{
    Tire *root = nullptr;
    array<Tire *, 2> son{nullptr, nullptr};
    int sum;

    Tire() : sum(0) {}
};

class Solution
{
private:
    Tire *root = nullptr;

public:
    void insert(int x)
    {
        Tire *cur = root;
        for (int k = 14; k >= 0; k--)
        {
            int b = (x >> k) & 1;
            if (cur->son[b] == nullptr)
            {
                cur->son[b] = new Tire();
            }
            cur = cur->son[b];
            cur->sum++;
        }
    }

    int get(int num, int x)
    {
        Tire *cur = root;
        int sum = 0;
        for (int k = 14; k >= 0; k--)
        {
            int r = (num >> k) & 1;
            if ((x >> k) & 1)
            {
                if (cur->son[r] != nullptr)
                {
                    sum += cur->son[r]->sum;
                }

                if (cur->son[r ^ 1] == nullptr)
                {
                    return sum;
                }

                cur = cur->son[r ^ 1];
            }
            else
            {
                if (cur->son[r] == nullptr)
                {
                    return sum;
                }
                cur = cur->son[r];
            }
        }
        sum += cur->sum;
        return sum;
    }

    int f(vector<int> &nums, int x)
    {
        root = new Tire();
        int res = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            insert(nums[i - 1]);
            res += get(nums[i], x);
        }
        return res;
    }

    int countPairs(vector<int> &nums, int low, int high)
    {
        return f(nums, high) - f(nums, low - 1);
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