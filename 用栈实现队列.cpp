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

// 用栈实现队列
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int front;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if (s1.empty()) {
            front = x;
        }
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int some = s1.top();
                s2.push(some);
                s1.pop();
            }
        }
        int rval = s2.top();
        s2.pop();
        return rval;
    }

    /** Get the front element. */
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    return 0;
}

