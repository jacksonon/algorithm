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

// 计算质数：统计所有小于非负整数 n 的质数的数量。
class Solution {
public:
    int countPrimes(int n) {
        // 比特表优化：使用bitmap优化vector，每一个vector的每一位都是一个
        int count = 0;
        const int size = sizeof(int) * 8;
        vector<int> signs(n / size + 1, 0);

        for (int i = 2; i < n; i++) {
            if (signs[i / size] & (1 << (i & (size - 1))) == 0) {
                count++;
                for (int j = i + 1; j < n; j += i) {
                    signs[j / size] |= 1 << (j & (size - 1));
                }
            }
        }

        // 暴力解法：
        // 优化暴力解法：折半，是规律的总结
        // 厄拉多塞筛法
//        vector<bool> num(n, true);
//        int res = 0;
//        // 外循环优化，因为计算一个数是否为质数，主需要整除到sqrt(n)
//        for (int i = 2; i <= sqrt(n); i++) {
//            if (num[i]) {
//                int k = 2;
//                while (k * i < n) {
//                    num[k * i] = false;
//                    k++;
//                }
//            }
//        }
//        for (int i = 2; i < n; i++) {
//            if (num[i]) {
//                res++;
//            }
//        }
//        return res;
    }
};

int main() {
    return 0;
}

