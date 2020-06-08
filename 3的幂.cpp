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

// 3的幂 给定一个整数，写一个函数来判断它是否是 3 的幂次方。
class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1. 只要不停的除3，最后结果等于1，就是3的幂 对3取余，
        // 2. 基准转换
        // 3. 数学计算法
        // 整数限制：用到了Int的最大值
        return n > 0 && 1162261467 % n == 0;
    }
};

int main() {
    return 0;
}

