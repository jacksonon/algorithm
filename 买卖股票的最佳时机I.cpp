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

/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
注意：你不能在买入股票前卖出股票。

 考量一次遍历解法！！！
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 一次遍历：
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            // vector 可以枚举
            maxprofit = max(maxprofit, price - minprice); // 获取最大，保证下次最大微针
            minprice = min(price, minprice); // 获取最小。保证下次最小为真
        }
        return maxprofit;

        // 1.暴力法 O(n^2)
//        int n = (int)prices.size(), ans = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = i + 1; j < n; ++j) {
//                // 循环遍历所有结果，保留最大值
//                ans = max(ans, prices[j] - prices[i]);
//            }
//        }
//        return ans;
    }
};

int main() {
    return 0;
}

