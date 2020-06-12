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

/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
 */

// 子集
class Solution {
private:
    // 递归、层序遍历
    vector<vector<int>> output;
public:

    void backtrack(int first, vector<int> curr, vector<int> nums) {
        output.push_back(curr);
        for (int i = first; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, curr, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // 回溯
        // 字典排序、二进制排序
        vector<int >track;
        backtrack(0, track, nums);
        return output;
    }
};

int main() {
    return 0;
}

