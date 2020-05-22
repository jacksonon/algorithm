#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>

using namespace std;


/*
给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。

示例 1:
输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
 */


/*
c.begin() 返回一个迭代器，它指向容器c的第一个元素
c.end() 返回一个迭代器，它指向容器c的最后一个元素的下一个位置
c.rbegin() 返回一个逆序迭代器，它指向容器c的最后一个元素
c.rend() 返回一个逆序迭代器，它指向容器c的第一个元素前面的位置
 */

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// 扁平化嵌套列表迭代器
class NestedIterator {
private:
    stack<NestedInteger> h_stack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // 倒序遍历:因为栈后进先出
        for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter ++) {
            h_stack.push(*iter);
        }
    }

    int next() {
        auto t = h_stack.top(); //取出栈顶
        h_stack.pop(); // 取出后移除
        return t.getInteger();
    }

    bool hasNext() {
        // 非空时
        while (!h_stack.empty()) {
            auto cur = h_stack.top();
            if (cur.isInteger()) {
                return true;
            }
            h_stack.pop(); // 解析后删除
            auto curList = cur.getList();
            // 从当前List再进入栈内
            for (auto iter = curList.rbegin(); iter != curList.rend(); iter++) {
                h_stack.push(*iter);
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
