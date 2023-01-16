题目链接：[2284. 最多单词数的发件人](https://leetcode.cn/problems/sender-with-largest-word-count/)

## 哈希表

数组 $messages$ 和 $senders$ 可以知道某个消息 $messages[i]$ 是由 $senders[i]$ 发出的，那么需要统计发出的消息中累计单词数量最大的发件人名字。我们不需要关注数组 $messages$ 中某个消息 $message$ 是在什么时候发出的，只需要知道 $message$ 是谁发出的，并且知道 $message$ 中有多少个单词。这一过程可以借助哈希表来存储发件人名字和发件人发出的消息中单词总数，具体实现如下。

实现上，直接遍历 $messages$ 即可，设 $i$ 为当前遍历过程中的某条消息，我们以 $senders[i]$ 作为哈希表的 $key$ 值，这样某个人发出的全部消息都可以关联到发件人。观察 $messages[i]$ 题目说明了信息是由若干个单词用空格，开头和结尾不会有多余的空格，因此直接统计消息中空格的数量 $count$，那么这条消息的单词数量就是 $count + 1$，我们把它累加到哈希表中。最后遍历整个哈希表，获取消息中单词数最多的发件人名字，如果单词数量一样，那么按照返回字典序最大的名字。

Code

```c++
class Solution 
{
public:

    string largestWordCount(vector<string>& messages, vector<string>& senders) 
    {
        unordered_map<string, int> m;
        int n = messages.size();
        for (int i = 0; i < n; i ++) {
            m[senders[i]] += count(messages[i].begin(), messages[i].end(), ' ') + 1;
        }
        int maxWord = 0;
        string ans;
        for (auto &[k, v] : m) {
            if (v > maxWord) {
                ans = k;
                maxWord = v;
            } else if (v == maxWord) {
                if (k > ans) {
                    ans = k;
                }
            }
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(n)$，其中 $n$ 为字符串数组 $messages$ 所有字符串长度之和，我们遍历每个字符串并统计空格数量。最后还遍历哈希表 $O(n)$，对比名字字典序 $O(C)$（$C \in [1,10]$ ）。

空间复杂度：$O(n)$，哈希表最大存储 $n$ 个发件人名字，每个发件人名字长度最大为 $C$（$C \in [1,10]$ ）。