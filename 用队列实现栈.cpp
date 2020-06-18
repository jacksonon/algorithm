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

// 用队列实现栈
class MyStack {
private:
    queue<int> pushQueue;
    queue<int> popQueue;
    int topValue;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        pushQueue.push(x);
        topValue = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (pushQueue.size() > 1) {
            topValue = pushQueue.front();
            popQueue.push(topValue);
            pushQueue.pop();
        }
        int result = pushQueue.front();
        pushQueue.pop();
        queue<int> tmp = pushQueue;
        pushQueue = popQueue;
        popQueue = tmp;
        return result;
    }

    /** Get the top element. */
    int top() {
        return topValue;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return pushQueue.empty();
    }
};

int main() {
    return 0;
}

