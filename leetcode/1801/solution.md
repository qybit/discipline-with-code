题目链接：[1801. 积压订单中的订单总数](https://leetcode.cn/problems/number-of-orders-in-the-backlog/)

## 优先队列模拟

订单数组 $orders$ 被定义为由 $order[i] = [price, amount, orderType]$ ,表示有 $amount$ 笔类型为 $orderType$ 、价格为 $price$ 的订单，订单类型有 $buy$ 和 $sell$ 两种，订单按照从左到右的顺序提交。每次采购订单时，需要在已经提交的售卖订单中查找最便宜的售卖订单。相反的，每次销售订单时，需要在已经提交的购买订单中查找最贵的采购订单。这一查找过程，可以使用优先队列来优化。

由于订单是按顺序提交，设 $order = [price, amount, orderType]$ 为当前提交的某个订单时：

- $orderType=0$ 时，表示这是一笔采购订单，如果当前 $sellOrders$ 中销售最便宜的订单价格 **低于或等于** 当前采购的价格时，我们将该笔订单从优先队列 $sellOrders$ 中弹出并设为 $sellOrder$ ，结合 $amount$ 和 $sellOrder$ 存在订单数量进行采购操作。如果采购完成，$sellOrder$ 仍有销售需求就把它放回队列中。假如 $amount > 0$ 我们继续采购订单的操作，直到没有可供采购的订单为止。
- $orderType=1$ 时，表示这是一笔销售订单，如果当前 $buyOrders$ 中采购最贵的订单价格 **高于或等于** 当前销售的价格时，我们将该笔订单从优先队列 $buyOrders$ 中弹出并设为 $buyOrder$ ，结合 $amount$ 和 $buyOrder$ 存在订单数量进行销售操作。如果销售完成，$buyOrder$ 仍有采购需求就把它放回队列中。假如 $amount > 0$ 我们继续销售订单的操作，直到没有可供销售的订单为止。

Code

```c++
typedef pair<int, int> PII;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int MOD = 1e9 + 7;
        priority_queue<PII, vector<PII>, less<PII>> buyOrders;
        priority_queue<PII, vector<PII>, greater<PII>> sellOrders;
        for (vector<int> &order : orders) {
            int price = order[0], amount = order[1], orderType = order[2];
            if (orderType == 0) {
                // 买入，看sell订单里的最小值
                while (amount > 0 && !sellOrders.empty() && sellOrders.top().first <= price) {
                    PII sellOrder = sellOrders.top();
                    sellOrders.pop();
                    int sellAmount = min(amount, sellOrder.second);
                    amount -= sellAmount;
                    sellOrder.second -= sellAmount;

                    if (sellOrder.second > 0) {
                        sellOrders.push(sellOrder);
                    }
                }
                if (amount > 0) {
                    buyOrders.emplace(price, amount);
                }
            } else {
                // 卖出，看buy订单里最大值
                while (amount > 0 && !buyOrders.empty() && buyOrders.top().first >= price) {
                    PII buyOrder = buyOrders.top();
                    buyOrders.pop();
                    int buyAmount = min(amount, buyOrder.second);
                    amount -= buyAmount;
                    buyOrder.second -= buyAmount;

                    if (buyOrder.second > 0) {
                        buyOrders.push(buyOrder);
                    }
                }
                if (amount > 0) {
                    sellOrders.emplace(price, amount);
                }
            }
        }
        int total = 0;
        while (!buyOrders.empty()) {
            total = (buyOrders.top().second + total) % MOD;
            buyOrders.pop();
        }
        while (!sellOrders.empty()) {
            total = (sellOrders.top().second + total) % MOD;
            sellOrders.pop();
        }
        return total;
    }
};
```

### 复杂度分析

时间复杂度：$O(nlogn)$，其中 $n$ 表示为订单数组的长度，我们需要将每笔订单放入优先队列 $O(n)$，每次放入后都要进行调整 $O(logn)$，最后还需要将其弹出队列对积压订单求和，时间复杂度与入队相同。因此最终的时间复杂度为 $O(nlogn)$。

空间复杂度：$O(n)$，需要存储优先队列中的数据。