#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
using namespace std;

// 一般解决树问题多数采用递归或者迭代

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode *right;
    // 使用参数列表初始化
    TreeNode() : val(0), left(NULL), right(NULL){}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

// 二叉搜索树种第k小的元素
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 迭代
        stack<TreeNode *> stack;
        while (true) {
            while (root != NULL) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (--k == 0) {
                return root->val;
            }
            root = root->right;
        }
    }
};

int main() {
    return 0;
}
