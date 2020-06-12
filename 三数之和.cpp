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
 * 暴力思想是直接穷举三层：然后计算比较
 * 元素百分百
 * 第二重循环的元素，不小于第一层的元素，
 * 第三层不小于第二层
 * 先排序再按照特定顺序枚举，可以避免出现abc cba cab等等的形式
 */

// 三数之和：简化三重数组为两重数组
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举A
        for (int first = 0; first < n; ++first) {
            // 需要和上次不同，相同则跳过
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c指向最右端
            int third = n - 1;
            int target = - nums[first];
            // 枚举b，
            for (int second = first + 1; second < n; ++second) {
                // b 值也不可以重复
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 保证b在c的左侧，因为是已经拍过序的数组
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着b后续的增加，不会有和为0，且b<c的位置存在，可以break
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}

