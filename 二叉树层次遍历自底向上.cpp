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


// 自底向上的层次遍历
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root, 0, res);
        return vector<vector<int>>(res.rbegin(), res.rend());
    }

    void levelorder(TreeNode *node, int level, vector<vector<int>> &res) {
        if (!node) return;
        if (res.size() == level) res.push_back({}); // 每层使用心得空
        res[level].push_back(node->val);
        if (node->left) levelorder(node->left, level + 1, res);
        if (node->right) levelorder(node->right, level + 1, res);
    }
};

int main() {
    return 0;
}

