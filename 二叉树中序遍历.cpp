#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>

using namespace std;

// 给定一个二叉树，返回它的中序 遍历。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

// 一劳永逸
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res; // 保存结果
        stack<TreeNode *> call; // 调用栈
        if (root != nullptr) {
            call.push(root); // 根节点入栈
        }
        // 非空
        while (!call.empty()) {
            TreeNode *t = call.top();
            call.pop(); // 访问节点弹出
            if (t != nullptr) {
                // 先序遍历：右 左 父
                // 后序遍历：父 右 左
                // 中续遍历：右 父 左

                // 右节点不为空，右节点先进栈，最后处理
                if (t->right) {
                    call.push(t->right);
                }
                // 当前节点压栈，留着以后处理
                call.push(t);
                // 当前节点之前添加一个空节点，标识已经访问过了
                call.push(nullptr);
                // 如果左子节点不为空
                if (t->left) {
                    // 将左子节点放在最上面，优先处理
                    call.push(t->left);
                }
            } else {
                // 空节点标识已经访问过了，现在需要处理除了地柜之外的内容
                // 处理最顶层节点，处理后从call栈移除
                res.push_back(call.top()->val);
                call.pop();
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

