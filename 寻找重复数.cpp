#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
using namespace std;

/*
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），
 可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

输入: [1,3,4,2,2]
输出: 2
示例 2:

不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。
 */

/*
 * cnt[i]标识nums[]数组中小于等于i的数有多少个
 * [1, target -1 ]
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 二分查找
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r) {
            // 二进制右移相当于/2,取中间数位置
            int mid = (l + r) >> 1;
            int cnt = 0; // 和
            for (int i = 0; i < n; ++i) {
                // 等效于：当num[i] <= mid 的时候进行添加
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid){
                // 当Cnt小于中间数的时候，左l = mid + 1;重新进行计算
                l = mid + 1;
            } else {
                // 当中间数大于mid的视乎，那么右r = mid - 1；重新计算
                r = mid - 1;
                // 位置设置为当前mid
                ans = mid;
            }
        }
        return ans;
    }
};

// 寻找重复数
int main() {
    return 0;
}
