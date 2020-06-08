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

// 两个数组的交集II
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 哈希映射
        // 较小数组放在前面
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> m;
        for (auto n : nums1) {
            ++m[n]; // 记录较短数组中的每个数出现的次数和位置
        }
        int k = 0;
        for (auto n : nums2) {
            auto it = m.find(n);
            if (it != end(m) && --it->second >= 0) {
                nums1[k++] = n;
            }
        }
        return vector<int>(begin(nums1), begin(nums1) + k);
    }
};

int main() {
    return 0;
}

