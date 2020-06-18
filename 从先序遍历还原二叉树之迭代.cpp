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
我们从二叉树的根节点 root 开始进行深度优先搜索。

在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出 S，还原树并返回其根节点 root。

 

示例 1：
输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从先序遍历中还原二叉树
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {

        stack<TreeNode *> path;// 用来记录节点
        int pos = 0;// 记录位置
        // 当遍历的位置小于字符串的长度
        while (pos < S.size()) {
            int level = 0; // 看当前的层次
            // 当这个位置是-的时候，level +1 。pos + 1，位置和深度都加1
            while (S[pos] == '-') {
                ++level;
                ++pos;
            }
            int value = 0; // 计算当前节点的值
            // 当当前位置小于字符串长度且是一个数组的时候
            while (pos < S.size() && isdigit(S[pos])) {
                value = value * 10 + (S[pos] - '0'); //
                ++pos;
            }
            // 使用vaLuede的值创建节点
            TreeNode *node = new TreeNode(value);
            // 判断深度是否和栈的大小相等
            if (level == path.size()) {
                // 深度和栈大小相等，且栈不为空
                if (!path.empty()) {
                    // 顶部的左子节点为node
                    path.top()->left = node;
                }
            } else {
                // 深度和栈大小不等，说明左侧已经遍历完，
                while (level != path.size()) {
                    // 当深度和栈长度不等的时候，移除path顶部数据
                    path.pop();
                }
                // 移除完毕后，将path的顶部的右节点设置为node
                path.top()->right = node;
            }
            // node 节点入栈
            path.push(node);
        }
        while (path.size() > 1) {
            path.pop();
        }
        return path.top(); // 返回root节点
    }
};
int main() {
    return 0;
}

