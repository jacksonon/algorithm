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
你现在是棒球比赛记录员。
给定一个字符串列表，每个字符串可以是以下四种类型之一：
1.整数（一轮的得分）：直接表示您在本轮中获得的积分数。
2. "+"（一轮的得分）：表示本轮获得的得分是前两轮有效 回合得分的总和。
3. "D"（一轮的得分）：表示本轮获得的得分是前一轮有效 回合得分的两倍。
4. "C"（一个操作，这不是一个回合的分数）：表示您获得的最后一个有效 回合的分数是无效的，应该被移除。
每一轮的操作都是永久性的，可能会对前一轮和后一轮产生影响。
你需要返回你在所有回合中得分的总和。
 */

// 棒球比赛
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> r_stack;
        for (auto op : ops) {
            if (op == "+") {
                int top = r_stack.top();
                r_stack.pop();
                int newtop = top + r_stack.top();
                r_stack.push(top);
                r_stack.push(newtop);
            } else if (op == "C") {
                r_stack.pop();
            } else if (op == "D") {
                r_stack.push(2 * r_stack.top());
            } else {
                r_stack.push(stoi(op));
            }
        }
        int ans = 0;
        while (!r_stack.empty()) {
            ans += r_stack.top();
            r_stack.pop();
        }
        return ans;
    }
};

int main() {
    return 0;
}

