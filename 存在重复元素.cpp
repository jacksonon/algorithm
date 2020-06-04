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
给定一个整数数组，判断是否存在重复元素。
如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
 [1 2 3 4 5 1] => true
 */

// 存在重复元素
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 这个我们通常在平时开发中会用到，尽量避免使用该算法
        // 朴素线性查找：超时。双循环：i < len && j < i O(n^2)
        // 先排序，然后比较相邻元素：最坏的onlogn，堆排序o1，扫描复杂度为On | ONlogN = Onlogn
        // 哈希表、set、vector
        unordered_map<int, int> u_map;
        for (auto use : nums) {
            u_map[use]++;
            if (u_map[use] > 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}

