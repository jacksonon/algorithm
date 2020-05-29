#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>

using namespace std;

// 给定一个二叉树，返回它的中序 遍历。
// 前：根 左 右 
// 中：左 根 右 （其中每个node都是先左后右）
// 后：左 右 根

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

// 一劳永逸
class Solution {
public:
    // 递归：左 根 右 中序遍历
    // 基于栈的遍历
    // 新的数据结构，线索二叉树 莫里斯遍历
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res; // 保存结果
        stack<TreeNode *> call; // 调用栈
        TreeNode *curr = root;
        while (curr != nullptr || !call.empty()) {
            while (curr != nullptr) {
                call.push(curr); // roor不为空先入栈
                curr = curr->left;  // 将当前访问设为左侧
            }
            curr = call.top();// 拿出栈顶元素
            call.pop(); // 栈顶出战
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};

int main() {
    return 0;
}

