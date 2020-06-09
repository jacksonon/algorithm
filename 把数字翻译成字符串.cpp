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

using namespace std;

/*
给定一个数字，我们按照如下规则把它翻译为字符串：
0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 单独翻译；
 组合翻译：最多两位组合因为z就是25，最多也就是25，大于25就无效，

 动态规划：
 1. 找出动态方程
 2. 实现动态方程
 3. 使用滚动数组优化动态方程

 1. 找出动态方程：
    - 可以单独作为1位来翻译
    - 如果i-1和i组成的数字在10-25之间，可以把这两位连起来翻译 => x
f(i) = f(i-1) + f(i-2)[i - 1 >= 0, 10 <= x <= 25]
此时时间复杂度为O(n)

 2. 滚动数组优化：
 为什么可以优化？
 因为fi 只和它的前两项有关量，可以用滚动数组的思想把f数组压缩成3个变量，
 这样空间复杂度就编程了O(1)
 array[滚] = [p, q, r];

双O（logn)
 
 p = 0
 q = 1
 r = 0
 r = r + q = 1
 
 
 */

 // 把数字翻译成字符串
class Solution {
public:
    int translateNum(int num) {
        string src = to_string(num);
        int p = 0, q = 0, r = 1;
        for (int i = 0; i < src.size(); ++i) {
            p = q;
            q = r;
            r = 0;
            r += q;
            if (i == 0) {
                continue;
            }
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10") {
                r += p;
            }
        }
        return r;
    }
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x) , left(nullptr), right(nullptr){}
};

class TreeInorder {
public:
    void inorder(TreeNode *root, cons)
};

int main() {
    return 0;
}

