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

using namespace std;

/*
 * 动态规划
 *
 */

// 最大子序和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto x : nums) {
            // 前一个和当前中返回一个最大的
            pre = max(pre + x, x);
            // 总和和当前返回一个最大的
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

int main() {

    return 0;
}

