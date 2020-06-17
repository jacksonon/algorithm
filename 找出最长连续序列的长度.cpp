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
#include <queue>
#include <fstream>
#include <cstring>
#include <zconf.h>

using namespace std;

// 给定一个未排序的整数数组，找出最长连续序列的长度。要求算法的时间复杂度为 O(n)。
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num: nums) {
            num_set.insert(num);
        }
        int longestStreak = 0;
        for (const int &num : num_set) {
            // 看看是不是最小值
            if (!num_set.count(num - 1)) {
                // 网上查最大值
                int curNum = num;
                int curStreak = 1;
                while (num_set.count(curNum + 1)) {
                    curNum += 1;
                    curStreak += 1;
                }
                longestStreak = max(longestStreak, curStreak);
            }
        }
        return longestStreak;
    }
};

int main() {
    return 0;
}

