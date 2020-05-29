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
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
示例 1:输入: [1,2,3,1]输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
 */

/*
 *  二维规划只要用到本层的上一层即可使用滚动数组
 *  递归是自顶向下，迭代是自底向上
 *
 *  只有2种：打劫最后一家  和 不打劫最后一家 => 问题转换为最优子问题，
 *  将最优解使用递归方式
 *  将解答转化为跌打
 */

// 打家劫舍：动态规划 + 滚动数组（滚动数组意味着使用2个数，表式数组的值1 和 值2 ）
class Solution {
public:
    int rob(vector<int>& nums) {
        // 考虑两种边界情况
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        // 使用辅助数组做迭代：常见的递归转迭代的方式
//        vector<int> dp = vector<int>(size, 0);
//        dp[0] = nums[0];
//        dp[1] = max(nums[0], nums[1]);
//        for (int i = 2; i < size; ++i) {
//            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
//        }
//        return dp[size - 1];
        // 使用滚动数组做迭代：迭代都是从低到高
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            int temp = second;
            second = max(first + nums[i], second);
            // 保留下一次的前缀值：
            first = temp;
        }
        return second;
    }
};

int main() {
    vector<int> obj;
    obj.push_back(9);
    obj.push_back(0);
    obj.push_back(1);
    obj.push_back(9);
    Solution so = Solution();
    cout << so.rob(obj) << endl;
    return 0;
}

/*
 * 9 0 1 9
 * 9
 * 9 0
 *
 * max(0 + 2 , 1)
 * max(1 + 3, 2)
 * max(2 + 4, 3)
 */
