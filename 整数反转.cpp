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

// 整数反转：范围是-2的31次方（尾数是-8）到2的31次方-1（尾数是7）
class Solution {
public:
    // 不使用辅助堆栈、数组的时候，我们使用数学方法进行判断
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            // 简单的数学计算
            int pop = x % 10;
            x /= 10;
            // 溢出判断
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main() {
    return 0;
}

