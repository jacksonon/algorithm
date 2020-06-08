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

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 合并后排序

        // 从后往前，可以避免移动数组
        int last = m + n - 1;
        // 当 n 大于 0的时候
        while (n) {
            // 当 m 为0，则，将n赋值给m
            if (m == 0) {
                nums1[last --] = nums2[--n];
            } else if (nums2[n - 1] > nums1[m - 1]) {
                nums1[last--] = nums2[--n];
            } else {
                nums1[last--] = nums1[--m];
            }
        }
    }
};

int main() {
    return 0;
}

