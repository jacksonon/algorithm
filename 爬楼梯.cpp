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

// 爬楼梯
class Solution {
public:
    int climbStairs(int n) {
        // 动态规划
        if (n == 1) {
            return 1;
        }
        vector<int>dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution so = Solution();
    cout << so.climbStairs(3) << endl;
    return 0;
}

