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
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

关键是我们需要考虑到紧跟谷的每一个峰值以最大化利润。
如果我们试图跳过其中一个峰值来获取更多利润，那么我们最终将失去其中一笔交易中获得的利润，从而导致总利润的降低。
试图通过考虑差异较大的点以获取更多的利润，获得的净利润总是会小与包含它们而获得的静利润，因为 C 总是小于 A+B。
 */

class Solution {
public:
    // 谷峰法
    int maxProfit(vector<int> prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        // 从第一次一直寻找每一次峰谷
        while (i < prices.size() - 1) {
            // 循环 p.size - 1 次 寻找，下一个最近的谷，即当前值大于下一天的值
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            // 记录谷的值：
            valley = prices[i];
            // 循环谷值之后下一个最近的峰值
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            // 记录峰值
            peak = prices[i];
            // 计算每一次峰和谷的差值
            maxprofit += peak - valley;
        }
        return maxprofit;
    }

//    int maxProfit(vector<int>& prices) {
//        return calculate(prices, 0);
//    }
//
//    // 1. 暴力法：穷举所有可能
//    int calculate(vector<int> prices, int s) {
//        if ( s >= prices.size()) {
//            return  0;
//        }
//        int max = 0;
//        // 进行两次遍历：O（n^2)
//        for (int start = s; start < prices.size(); ++start) {
//            int maxprofit = 0;
//            for (int i = start + 1; i < prices.size(); ++i) {
//                // 起始与当前比较：，如果当前金额比较大，则卖出
//                if (prices[start] < prices[i]) {
//                    // 计算下一天的最大值 + 当然的差
//                    // 递归
//                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
//                    if (profit > maxprofit) {
//                        // 如果计算出下一天的收入比今天高，那么下一天的收入设置为最大
//                        maxprofit = profit;
//                    }
//                }
//                if (maxprofit > max) {
//                    max = maxprofit;
//                }
//            }
//        }
//        return max;
//    }
};

int main() {
    vector<int > test {7,1,5,3,6,4};
    Solution so = Solution();
    cout << so.maxProfit(test) << endl;
    return 0;
}

