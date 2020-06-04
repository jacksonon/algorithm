#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
#include<sstream>
#include <set>

using namespace std;

/*
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，
其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
示例: 输入: [1,2,3,4] 输出: [24,12,8,6]
提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
进阶：你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int length = nums.size();
        vector<int> ans(length); // 创建对应大小的vector

        ans[0] = 1; // 左侧无元素。
        for (int i = 1; i < length; i++) {
            // 计算左侧乘积
            ans[i] = nums[i - 1] * ans[i - 1];
        }
        int R = 1;
        for (int j = length -1; j >= 0 ; j--) {
            // 从右到左进行遍历
            // 使用该位置的左侧乘积
            ans[j] = ans[j] * R;
            R *= nums[j];
        }
        return ans;

//        int length = nums.size();
//        // 辅助
//        vector<int> L(length, 0), R(length, 0);
//
//        // 输出
//        vector<int> ans(length);
//
//        L[0] = 1;
//        for (int i = 1; i < length; i++) {
//            L[i] = nums[i - 1] * L[i - 1];
//        }
//
//        R[length - 1] = 1;
//        for (int i = length - 2; i >= 0; i--) {
//            R[i] = nums[i + 1] * R[i + 1];
//        }
//
//        // 每一个位置的前缀*后缀
//        for (int j = 0; j < length; j++) {
//            ans[j] = L[j] * R[j];
//        }
//        return ans;
    }
};

int main() {

    return 0;
}

