#include <bits/stdc++.h>

using namespace std;

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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *pre1 = list1;
        for (int i = 0; i < a - 1; i++)
        {
            pre1 = pre1->next;
        }
        ListNode *pre2 = pre1->next;
        pre1->next = list2;
        for (int i = 0; i < b - a + 1; i++)
        {
            pre2 = pre2->next;
        }
        ListNode *pre3 = list2;
        while (pre3->next)
        {
            pre3 = pre3->next;
        }
        pre3->next = pre2;
        return list1;
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