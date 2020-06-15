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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

// I.二叉树的深度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // DFS
//        if (root == nullptr) return 0;
//        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        // BFS:广度优先搜索
        queue<TreeNode *> q;
        if (root) q.push(root);
        int ans = 0;
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ++ans;
        }
        return ans;
    }
};

int main() {
    return 0;
}

