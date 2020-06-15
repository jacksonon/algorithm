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

// 递增顺序查找树
class Solution {
public:
    // ，我们在树上进行中序遍历，但会将树中的节点之间重新连接而不使用额外的空间。
    // 具体地，当我们遍历到一个节点时，把它的左孩子设为空，并将其本身作为上一个遍历到的节点的右孩子。
    TreeNode *cur;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *ans = new TreeNode(0);
        cur = ans;
        inorder(root);
        return ans->right; // 只有右侧节点有值
    }

    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left); // 左子树排序
        node->left = nullptr; // 重置左侧为空
        cur->right = node; // 将cur右侧保存为node
        cur = node; // cur当前为node
        inorder(cur->right); // 排序右侧
    }

//    TreeNode* increasingBST(TreeNode* root) {
//        vector<int> vals;
//        inorder(root, vals);
//        TreeNode *ans = new TreeNode(0), *cur = ans;
//        for (int v : vals) {
//            cur->right = new TreeNode(v);
//            cur = cur->right;
//        }
//        return ans->right;
//    }
//
//    void inorder(TreeNode *node, vector<int> &vals) {
//        if (node == nullptr) return;
//        inorder(node->left, vals);
//        vals.push_back(node->val);
//        inorder(node->right, vals);
//    }
};

int main() {
    return 0;
}

