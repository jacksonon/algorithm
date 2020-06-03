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
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
示例 1:
输入: [3,0,1]
输出: 2
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 高斯求和
        int ex = nums.size() * (nums.size() + 1) / 2;
        int fn = 0;
        for(int s : nums) fn += s;
        return ex - fn;
        // 位运算:由于异或运算（XOR）满足结合律
        // 哈希表先存后比较 双o(n)
        // 排序：sort 排序，比较首尾是否一致，首尾一致，遍历比较中间
    }
};

int main() {

    return 0;
}

