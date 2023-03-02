题目链接：[1669. 合并两个链表](https://leetcode.cn/problems/merge-in-between-linked-lists/)

## 模拟

题目要求删除链表 $list1$ 中  `a` 到 `b` 的全部节点，并将链表 $list2$ 接在被删除节点的位置。我们可以先找到 $list1$ 中的第 `a-1` 个节点设为 $pre1$，然后直接接到 $list2$ 的头节点上。继续遍历 $list1$ 的第 `b-a+1` 个节点的位置，设为 $pre2$。遍历 $list2$ 到最后一个节点，设为 $pre3$。将 $pre3$ 直接接到 $pre2$ 即可。

Code

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pre1 = list1;
        for (int i = 0; i < a - 1; i ++) {
            pre1 = pre1->next;
        }
        ListNode* pre2 = pre1->next;
        pre1->next = list2;
        for (int i = 0; i < b - a + 1; i ++) {
            pre2 = pre2->next;
        }
        ListNode* pre3 = list2;
        while (pre3->next) {
            pre3 = pre3->next;
        }
        pre3->next = pre2;
        return list1;
    }
};
```

### 复杂度分析

时间复杂度：$O(n + m)$，其中 $n$ 是链表 $list1$ 的长度，$m$ 是链表 $list2$ 的长度，我们至多只会在链表 $list1$ 上遍历 $b$ 次，本题 $b = n (最坏的情况下)$，需要遍历链表 $list2$ 找到最后一个节点。因此时间复杂度为 $O(n + m)$。

空间复杂度：$O(1)$。

