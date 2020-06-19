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
#include <fstream>
#include <cstring>
#include <zconf.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) , left(nullptr), right(nullptr){}
};

// 路径综合
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // 迭代
        if (root == nullptr) return false;

        vector<TreeNode *> node_stack;
        vector<int> sum_stack;
        node_stack.push_back(root);
        sum_stack.push_back(sum - root->val);

        TreeNode *node;
        int curr_sum;
        while (!node_stack.empty()) {
            node = node_stack.back();
            node_stack.pop_back();
            curr_sum = sum_stack.back();
            sum_stack.pop_back();
            if (node->right == nullptr && node->left == nullptr && curr_sum == 0) {
                return true;
            }

            if (node->right != nullptr) {
                node_stack.push_back(node->right);
                sum_stack.push_back(curr_sum - node->right->val);
            }

            if (node->left != nullptr) {
                node_stack.push_back(node->left);
                sum_stack.push_back(curr_sum - node->left->val);
            }
        }
        return false;

        // 递归
        /*
        if (root == nullptr) return false;
        sum -= root->val;
        if ((root->left == nullptr) && (root->right == nullptr)) {
            return sum == 0;
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
         */
    }
};

int main() {
    return 0;
}

