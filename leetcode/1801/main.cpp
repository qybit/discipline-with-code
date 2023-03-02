#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

class Solution
{
public:
    int getNumberOfBacklogOrders(vector<vector<int>> &orders)
    {
        const int MOD = 1e9 + 7;
        priority_queue<PII, vector<PII>, less<PII>> buyOrders;
        priority_queue<PII, vector<PII>, greater<PII>> sellOrders;
        for (vector<int> &order : orders)
        {
            int price = order[0], amount = order[1], orderType = order[2];
            if (orderType == 0)
            {
                // 买入，看sell订单里的最小值
                while (amount > 0 && !sellOrders.empty() && sellOrders.top().first <= price)
                {
                    PII sellOrder = sellOrders.top();
                    sellOrders.pop();
                    int sellAmount = min(amount, sellOrder.second);
                    amount -= sellAmount;
                    sellOrder.second -= sellAmount;

                    if (sellOrder.second > 0)
                    {
                        sellOrders.push(sellOrder);
                    }
                }
                if (amount > 0)
                {
                    buyOrders.emplace(price, amount);
                }
            }
            else
            {
                // 卖出，看buy订单里最大值
                while (amount > 0 && !buyOrders.empty() && buyOrders.top().first >= price)
                {
                    PII buyOrder = buyOrders.top();
                    buyOrders.pop();
                    int buyAmount = min(amount, buyOrder.second);
                    amount -= buyAmount;
                    buyOrder.second -= buyAmount;

                    if (buyOrder.second > 0)
                    {
                        buyOrders.push(buyOrder);
                    }
                }
                if (amount > 0)
                {
                    sellOrders.emplace(price, amount);
                }
            }
        }
        int total = 0;
        while (!buyOrders.empty())
        {
            total = (buyOrders.top().second + total) % MOD;
            buyOrders.pop();
        }
        while (!sellOrders.empty())
        {
            total = (sellOrders.top().second + total) % MOD;
            sellOrders.pop();
        }
        return total;
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