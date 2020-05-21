#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>

/* 每日温度

根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。
如果之后都不会升高，请在该位置用 0 来代替。
例如，
给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，
你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
*/

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> h_stack; // 统计天数使用
        int len = T.size();
        vector<int> res(len);
        for (int i = 0; i < len; i++) {
            // 当统计不为空 且 这天的温度T[i]比上次入栈的要高
            while (!h_stack.empty() && T[i] > T[h_stack.top()]) {
                // 记录日期差 温度日期差 = 当前天 - 栈顶温度最高的哪天
                res[h_stack.top()] = i - h_stack.top();
                // 使用完栈顶哪天就移除哪天
                h_stack.pop();
            }
            // 将当前天进入栈顶
            h_stack.push(i);
        }
        return res;
    }
};

int main() {
    return 0;
}
