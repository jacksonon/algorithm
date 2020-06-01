#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
#include<sstream>

using namespace std;

/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

这里参考了快速排序的思想，快速排序首先要确定一个待分割的元素做中间点x，
然后把所有小于等于x的元素放到x的左边，大于x的元素放到其右边。
这里我们可以用0当做这个中间点，把不等于0(注意题目没说不能有负数)的放到中间点的左边，等于0的放到其右边。
这的中间点就是0本身，所以实现起来比快速排序简单很多
我们使用两个指针las和cur，只要nums[cur]!=0，我们就交换nums[last++]和nums[cur]
 */

// 快慢指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 是0元素，只前进cur指针
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                // 非0元素，交换当前指针和慢速指针指向的元素，
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
//        int lastNonZeroFoundAt = 0;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (nums[i] != 0) {
//                nums[lastNonZeroFoundAt++] = nums[i];
//            }
//        }
//        for (int i = lastNonZeroFoundAt; i < nums.size(); ++i) {
//            nums[i] = 0;
//        }
    }
};


int main() {
    return 0;
}

