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

// II.从上到下打印二叉树II
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> queue;
        vector<vector<int>> res;
        if (root != nullptr) queue.push(root);
        while (!queue.empty()) {
            vector<int> tmp;
            for (int i = queue.size(); i > 0; i--) {
                TreeNode *node = queue.front();
                queue.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }


};

int main() {
    return 0;
}

