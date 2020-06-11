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

// 阶乘后的零：给定一个整数 n，返回 n! 结果尾数中零的数量
class Solution {
public:
    int trailingZeroes(int n) {
        // 计算阶乘太慢
        // 数学分析：
        int zeroCount = 0;
        while (n > 0) {
            n /= 5;
            zeroCount += n;
        }
        return zeroCount;
    }
};

int main() {
    return 0;
}

