#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>

using namespace std;

/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
*/

class MinStack {
    stack<int> u_stack;
    stack<int> m_stack;
public:
    MinStack() {
        // 栈顶推一个最大值占位,初始化
        m_stack.push(INT_MAX);
    }

    void push(int x) {
        // 用户栈直接入栈，最小值栈入栈比较过的值
        u_stack.push(x);
        m_stack.push(min(m_stack.top(), x));
    }

    void pop() {
        // 同时pop取值
        u_stack.pop();
        m_stack.pop();
    }

    int top() {
        return u_stack.top();
    }

    int getMin() {
        return m_stack.top();
    }
};


int main() {
    MinStack ms = MinStack();
    return 0;
}

