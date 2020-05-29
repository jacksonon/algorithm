#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>

/*
根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。

例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：
    3
   / \
  9  20
    /  \
   15   7
*/

// 普及一些概念：所有的遍历不考虑顺序的情况下都是先左后右，然后记忆根节点位置
// 前（记做：前根）：根左右  中（记做：中根）：左根右 后（记做：后根）：左右根
// 前序遍历：遍历根节点：递归遍历左子树；递归遍历右子树
// 中序遍历：递归遍历左子树，遍历根节点；递归遍历右子树
// 后序遍历：递归遍历左子树；递归遍历右子树；最后遍历根节点


// 本题解题思路：从前序遍历拿到根节点；然后从中序遍历的地方拿出左、右节点、即可

using namespace std;

// 通用TreeNode节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int, int> index;

public:
    // 构建
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(); // 获取所有节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i; // 将中序的所有节点全部存到map里面
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* myBuildTree(
            const vector<int>& preorder, // 前序遍历结果集
            const vector<int>& inorder, // 中序遍历结果集
            int preorder_left, // 前序遍历的左节点
            int preorder_right, // 前序遍历的右节点位置
            int inorder_left,  // 中序遍历的左节点位置
            int inorder_right) { // 中序遍历的右节点位置
        // 如果前序的左大于右，则不存在
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        int p_root = preorder_left;
        int i_root = index[preorder[p_root]]; // 取出中序遍历节点根节点位置

        // 建立根节点
        TreeNode* root = new TreeNode(preorder[p_root]);
        // 从中序遍历中取出左子树节点数目
        int size_left_subtree = i_root - inorder_left; // 根 - 左侧起始
        // 递归构造左右子树

        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, i_root - 1);
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, i_root + 1, inorder_right);
        return root;
    }
};

int main() {
    return 0;
}
