#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
using namespace std;

// 补充知识：迭代需要队列或者栈的辅助

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
    // 迭代的方式稍微耗费一点空间可以提升一倍效率：8ms -> 4ms
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode *> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode* t1 = q.top();
            q.pop();
            TreeNode* t2 = q.top();
            q.pop();

            if (t1 == NULL && t2 == NULL) {
                continue;
            }

            if (t1 == NULL || t2 == NULL) {
                return false;
            }

            if (t1->val != t2->val) {
                return false;
            }

            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
//        isMirror(root, root);
    }

//    bool isMirror(TreeNode* t1, TreeNode* t2) {
//        if (t1 == NULL && t2 == NULL) {
//            return true;
//        }
//
//        if (t1 == NULL || t2 == NULL) {
//            return false;
//        }
//
//        return (t1->val == t2->val) && (isMirror(t1->right, t2->left)) && (isMirror(t1->left, t2->right));
//    }
};

int main() {
    return 0;
}
