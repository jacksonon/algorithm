#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
#include<sstream>
#include <set>

using namespace std;

// 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
class Solution {
public:
    int sumNums(int n) {
        // 逻辑与打断递归。当n = 0时递归被中断
        cout << n << endl;
        n && (n += sumNums(n - 1));
        cout << "结果值为" << n << endl;
        return n;
    }
};

/*
 * 5 4 3 2 1 0
 * 0 1 3 6 10 15
 * 先由上到下，再由下到上
 * 先压栈：即 s5 <- s4 <- s3 <- s2 <- s1
 * 再出栈：即 s1 = 1 -> s2 = 2 + s1 = 3 -> ....直到 s5 = 5 + s4 = 15;
 * sumNums(5) = 5 + sumNums(4) = 15
 * sumNums(4) = 4 + sumNums(3) = 10
 * sn(3) = 3 + sn(2) = 6
 * sn(2) = 2 + sn(1) = 3
 * sn(1) = 1 + sn(0) = 1
 * 底层其实是对线程栈的压栈和出栈操作
 */

int main() {
    Solution s = Solution();
    s.sumNums(5);
    return 0;
}

