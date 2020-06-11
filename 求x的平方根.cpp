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

/*
由于计算机无法存储浮点数的精确值（浮点数的存储方法可以参考 IEEE 754，这里不再赘述），
 而指数函数和对数函数的参数和返回值均为浮点数，
 因此运算过程中会存在误差。例如当 x = 2147395600时，
exp(0.5 * log(x))的计算结果与正确值 46340 相差 10^-11
 ，这样在对结果取整数部分时，会得到 46339 这个错误的结果。
 因此在得到结果的整数部分ans 后，我们应当找出ans与ans+1 中哪一个是真正的答案。

 */

// x的平方根:计算并返回 x 的平方根，其中 x 是非负整数。
class Solution {
public:
    int mySqrt(int x) {

        // 牛顿迭代有 y = f(x) = x^2 - C
        if (x == 0) return 0;
        double C = x , x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);

        // 二分查找：一般都应该是考虑这个问题
        // 左侧、右侧、结果
//        int l = 0, r = x, ans = -1;
//        // 如果左侧小于右侧
//        while (l <= r) {
//            // 取中间数
//            int mid = l + (r - 1) / 2;
//            // 计算中间数的平方和是否小于这个数
//            // 平方数的和小于x,则ans = mid，大于x则左移
//            if ((long long )mid * mid <= x) {
//                // 左侧向右移动1，证明这个数在中间右侧
//                ans = mid;
//                l = mid + 1;
//            } else {
//                // 反推：
//                r = mid - 1;
//            }
//        }
//        return ans;

        // 袖珍计算器算法：指数函数exo和对数函数ln代替平方根函数
        // √x = x ^ 1 /2  = (e ^ ln x) ^ 1 / 2 = e ^ 1 /2 ln x
//        if (x == 0) return 0;
//        int ans = exp(0.5 * log (x));
//        return ((long long )(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};

int main() {
    return 0;
}

