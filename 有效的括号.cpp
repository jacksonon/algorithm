#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>

using namespace std;

/*
小型编译器感觉；
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
 */

/*
 * map(dic) 用来存储对应关系
 * stack(数组) 用来代替栈结构
 */

class Solution {
public:

    // 构建括号map
    unordered_map<char, char> mapK = {
            {'{', '}'},
            {'[', ']'},
            {'(', ')'}
    };

    bool isValid(std::string s) {
        if (s.empty()) {
            // 空串
            return true;
        } else if (s.size() % 2) {
            // 不是2的整数倍
            return false;
        } else {
            // 只有此时才需要此时构建stack
            stack<char> myStack;
            for (int i = 0; i < s.length(); i++) {
                // 栈是空的先入栈
                if (myStack.empty()) {
                    myStack.push(s[i]);
                } else {
                    // 将即将入栈的和栈顶比较
                    if (s[i] == mapK[myStack.top()]) {
                        myStack.pop();
                    } else {
                        myStack.push(s[i]);
                    }
                }
            }
            // 如果执行完毕栈空了
            return myStack.empty();
        }
    }
};

int main() {

    Solution a = Solution();
    bool isFull = a.isValid("({)");

    cout << "别扭的C++" << endl;
    cout << "结果：" << isFull << endl;
    return 0;
}

