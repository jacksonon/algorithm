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

// 多数元素：找出数组中出现次数大于n / 2的数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 哈希表：理解最简单 O(N)
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (auto num : nums) {
            ++counts[num]; // 哈希表对应位置 +1；
            if (counts[num] > cnt) { // 当前位置数比基数大
                majority = num; // 将最大值设置为遍历到的数
                cnt = counts[num]; // 更改基数
            }
        }
        return majority;
    }
};

int main() {
    return 0;
}

