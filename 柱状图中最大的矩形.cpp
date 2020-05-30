#include <iostream>
#include <vector>
#include <cstdlib> // 随机数
#include <ctime>  // 时间
#include <random>
#include <stack>

using namespace std;

// 柱状图中最大的矩形：枚举高，一次遍历
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 单调栈 + 常数优化
        int n = heights.size();
        vector<int> left(n), right(n, n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = max(ans, (right[j] - left[j] - 1) * heights[j]);
        }
        return ans;

        /*
        int n = heights.size();
        int ans = 0;
        for (int mid = 0; mid < n; ++mid) {
            // 枚举高
            int height = heights[mid];
            int left = mid, right = mid;
            // 确定左右边界
            while (left - 1 >= 0 && (heights[left - 1]) >= height) {
                --left;
            }
            while (right + 1 < n && (heights[right + 1] >= height)) {
                ++right;
            }
            // 计算面积
            ans = max(ans, (right - left + 1) * height);
        }
        return ans;
         */
    }
};

int main() {
    cout << "wang jia wei";
    return 0;
}

