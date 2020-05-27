#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
using namespace std;


// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 对称二叉树
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return true;
        }

        if (t1 == NULL || t2 == NULL) {
            return false;
        }

        return (t1->val == t2->val) && (isMirror(t1->right, t2->left)) && (isMirror(t1->left, t2->right));
    }
};

int main() {
    return 0;
}
