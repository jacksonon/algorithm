#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
#include<sstream>
#include <unordered_set> // 数组去重
#include <numeric>
using namespace std;

// 最长公共前缀：编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 既然是公共前缀，只要一次遍历就够了啊 水平扫描法
        // 通常在前第一个字符串长度允许的情况下就能找出最优解
        // 极端情况
        if (strs.size() == 0) return "";
        // 取第0个：使用第0个作为标杆
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            // 从第一个开始比较。判断是否有公公交集：从字符串1找字符串0，如果有交集
            while (strs[i].find((prefix)) != 0) {
                // 第0个字符串截取：每次都比前一次<1
                prefix = prefix.substr(0, prefix.size() - 1);
                // 如果符合判断条件，且第0个都空了，还是没找到，那么没有交集
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

int main() {
    return 0;
}

