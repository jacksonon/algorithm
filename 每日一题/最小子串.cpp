#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>

using namespace std;

/*
给你一个字符串 S、一个字符串 T，
请在字符串 S 里面找出：包含 T 所有字符的最小子串。
示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
 */

// 滑动窗口算法。解决字符串匹配问题

/*
 * 一套框架不翻车诗歌
 *
 * 链表子串数组提，用双指针别犹豫
 * 双指针家三兄弟，各个都是万人迷
 *
 * 快慢指针最神奇，链表操作无压力
 * 归并排序找中点，链表成环搞判断
 *
 * 左右指针最常见，左右两端相向行
 * 反转数组要靠它，二分搜索是弟弟
 *
 * 滑动窗口老猛男，子串问题全靠它
 * 左右指针滑窗口，一前一后齐头进
 *
 */

class Solution {
public:

    unordered_map<char, int> ori, cnt;

    bool check() {
        for (const auto &p : ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c : t) {
            ++ori[c];
        }
        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1 , ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end() ) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};

int main() {
    return 0;
}
