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
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

数组完成排序后，我们可以放置两个指针 i 和 j，
其中 i 是慢指针，而 j 是快指针。
只要 nums[i] = nums[j]，我们就增加 j 以跳过重复项。
当我们遇到 nums[j] != nums[i] 时，跳过重复项的运行已经结束，
因此我们必须把它（nums[j]）的值复制到 nums[i + 1]。
然后递增 i，接着我们将再次重复相同的过程，直到 j 到达数组的末尾为止。

 【 0 1 1 3 3 4 5】
 0 1 -> 0 1 -> i + 1, [1 1 3 3 4 5]
 

 */

// 双指针、快慢指针
// 删除数组中重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        // j是快指针，始终比i快1
        for (int j = 1; j < nums.size(); j++) {
            // 如果下一个不等于上一个
            if (nums[j] != nums[i]) {
                i++;// 那么计数+1，再下一次为++i起始
                // 将num[i]的值设置为num[j]
                // 因为下一个不等于上一个，所以num[0] = nums[1] ？后移？ + 1 = j
                nums[i] = nums[j];
            }
        }
        // 数组从 0 开始
        return i + 1;
    }
};

int main() {

    return 0;
}

