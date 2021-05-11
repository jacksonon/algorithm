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
#include <stdio.h>
#include <math.h>

using namespace std;

/*
 * CLANG
 * LLVM
 * GCC
 *
 *
 * Darwin架构：现在
 * XNU
 * Mach BSD libKern I/OKit
 */


/*
 * 实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 */

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        // 进行牛顿迭代 y = f(x) = x^2 -C
        double  c = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + c / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};

/*
 * 二分查找 O（logx)，会超时
 * int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - 1) / 2;
            // 进行数学计算，计算乘积与目标大小比较
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
 */

/*
 * 数学计算法
 * // 边界条件
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        return (long long )(ans + 1) * (ans + 1) <= x ? ans + 1 : ans;
 */

int main() {

    int rs = Solution().mySqrt(19);

    return 0;
}
