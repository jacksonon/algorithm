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

// 下一个更大的元素I :单调栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        // 需要hashmap辅助
        stack<int> stack;
        unordered_map<int, int> rmap;
        // 先对Num2中的元素进行排序
        for (int i = 0; i < nums2.size(); i++) {
            while(!stack.empty() && nums2[i] > stack.top()) {
                rmap.emplace(stack.top(), nums2[i]);
                stack.pop();
            }
            stack.push(nums2[i]);
        }
        while (!stack.empty()) {
            rmap.emplace(stack.top(), -1);
            stack.pop();
        }
        // 然后从哈希表中寻找1对应的值加到vector
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = rmap[nums1[i]];
        }
        return res;
    }
};
int main() {
    return 0;
}

