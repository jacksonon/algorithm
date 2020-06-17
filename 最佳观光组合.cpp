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
#include <zconf.h>

using namespace std;

/*
给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。
一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。
返回一对观光景点能取得的最高分。
 */

// 最佳观光组合

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        // 枚举所有的值：景点组合与顺序无关，所以正序遍历一次即可
        int ans = 0, mx = A[0] + 0;
        for (int j = 1; j < A.size(); ++j) {
            // （A[i] + A[j] + i - j）
            // 枚举景点J的最大值，其实A[j] - j是固定的，因为枚举的事j的最大值，
            // 所以只需要枚举j景点时，A[i] + i的最大值即可
            // 计算最终得分： = A[j] + j 最大值 + A[j] - j最大值
            ans = max(ans, mx + A[j] - j);
            // A[i] + i的最大值
            mx = max(mx, A[j] + j);
        }
        return ans;
    }
};


int main() {
    return 0;
}

