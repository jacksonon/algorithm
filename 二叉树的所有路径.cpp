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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
};

// 二叉树的所有路径：给定一个二叉树，返回所有从根节点到叶子节点的路径。
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // 迭代：
        vector<string> paths;
        if (root == nullptr) return paths;
        vector<TreeNode *> node_stack;
        vector<string> path_stack;
        node_stack.push_back(root);
        path_stack.push_back(to_string(root->val));
        TreeNode *node;
        string path;
        while (!node_stack.empty()) {
            node = node_stack.back();
            node_stack.pop_back();
            path = path_stack.back();
            path_stack.pop_back();
            if ((node->left == nullptr) && (node->right == nullptr)) {
                paths.push_back(path);
            }
            if (node->left != nullptr) {
                node_stack.push_back(node->left);
                path_stack.push_back(path + "->" + to_string(node->left->val));
            }
            if (node->right != nullptr) {
                node_stack.push_back(node->right);
                path_stack.push_back(path + "->" + to_string(node->right->val));
            }
        }
        return paths;

        // 递归
//        vector<string> paths;
//        construct_paths(root, "", paths);
//        return paths;
    }

    void construct_paths(TreeNode *root, string path, vector<string> &paths) {
        if (root != nullptr) {
            // 不为空的时候计算路径
            path += to_string(root->val);
            if ((root->left == nullptr) && (root->right == nullptr)) {
                // 当前节点是叶子节点
                paths.push_back(path);
            } else {
                path += "->";
                construct_paths(root->left, path, paths);
                construct_paths(root->right, path, paths);
            }
        }
    }
};
int main() {
    return 0;
}

