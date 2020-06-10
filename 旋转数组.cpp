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



// 旋转数组：给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 暴力：旋转k次，
        // 使用额外的数组 on on  a[(i + k) % nums.length] = nums[i]; 拷贝数组
        // 环状
        k = k % nums.size();
        int count = 0;
        // 当数量小于总数
        for (int start = 0; count < nums.size() ; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};

int main() {
    return 0;
}

