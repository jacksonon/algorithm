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

// 回文数
class Solution {
public:
    bool isPalindrome(int x) {
        // 边界条件
        if (x < 0 || (x % 10) == 0 && x != 0) {
            return false;
        }
        // 反转一半数字
        int revertNum = 0;
        while (x > revertNum) {
            revertNum = revertNum * 10 + x % 10;
            x /= 10;
        }
        return x == revertNum || x == revertNum / 10;
    }
};
int main() {
    return 0;
}

