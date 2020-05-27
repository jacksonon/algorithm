#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
using namespace std;

// 全是技巧和套路！！！
// 连续子数组使用前缀和来解决；
// 一旦涉及统计出现次数，就可以考虑散列表unordered_map

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        // 计算出现次数
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0, ans = 0;
        // 计算同余出现的次数
        for (int elem: A) {
            // 前缀和
            sum += elem;
            // 处理element为负数时候的情况
            int modules = (sum % K + K) % K;
            if (record.count(modules)) {
                ans += record[modules]; // 获取结果
            }
            // 哈希表中以该余数为键的值+1
            ++record[modules];
        }
        return ans;
    }
};

int main() {
    return 0;
}
