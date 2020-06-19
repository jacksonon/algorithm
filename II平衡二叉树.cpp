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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) , left(nullptr), right(nullptr){}
};

// II平衡二叉树,左右子树深度差不超过1
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }

    // 最优解：后续遍历 + 剪枝
    int recur(TreeNode *root) {
        // 通过一些判断避免一些不必要的遍历过程，即为剪枝
        if (root == nullptr) return 0;
        int left = recur(root->left);
        if (left == -1) return -1;
        int right = recur(root->right);
        if (right == -1) return -1;
        return abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
};

int main() {
    return 0;
}

