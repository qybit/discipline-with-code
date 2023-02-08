题目链接：[1233. 删除子文件夹](https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/)

## 排序

删除列表 $folder$ 中全部子文件夹，可以对列表进行排序处理，假设 $folder[i] (i>0)$ 为一个子文件夹，那么它与 $folder[i-1]$ 的关系一定满足 $folder[i-1] + \$foo = folder[i](\$foo表示为任意路径)$，也就是说 $folder[i-1]$ 是 $folder[i]$ 的一个前缀，只要满足这一关系就可以删除。而不属于前缀时，则使用 $folder[i]$ 重新作为前缀进行下一次匹配。

Code

```c++
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        string pre = "";
        for (auto p : folder) {
            if (pre != "" && p.find(pre) == 0) {
                continue;
            }
            pre = p + "/";
            ans.emplace_back(p);
        }
        return ans;
    }
};
```

### 复杂度分析

时间复杂度：$O(nl \times logn)$，其中 $n$ 表示为文件夹列表 $folder$ 的长度，$l$ 表示为某个 $folder[i]$ 作为前缀进行匹配时的长度。

空间复杂度：$O(l)$。