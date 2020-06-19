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

class Solution {
public:
    int minDepth(TreeNode* root) {

        // 广度优先搜索迭代
        vector<pair<TreeNode*, int>> stack;
        if (root == nullptr) {
            return 0;
        } else {
            stack.push_back(pair<TreeNode*, int>(root, 1));
        }

        int cur_depth = 0;
        while (!stack.empty()) {
            pair<TreeNode*, int> cur = stack.front();
            stack.erase(stack.begin());
            root = cur.first;
            cur_depth = cur.second;
            if (root->left == nullptr && root->right == nullptr) {
                break;
            }
            if (root->left != nullptr) {
                stack.push_back(pair<TreeNode*, int>(root->left, cur_depth + 1));
            }
            if (root->right != nullptr) {
                stack.push_back(pair<TreeNode*, int>(root->right, cur_depth + 1));
            }
        }
        return cur_depth;

        /*
        // 深度优先搜索迭代
        vector<pair<TreeNode*, int>> stack;
        if (root == nullptr) {
            return 0;
        } else {
            stack.push_back(pair<TreeNode*, int>(root, 1));
        }

        int min_depth = INT_MAX;
        while (!stack.empty()) {
            pair<TreeNode*, int> current = stack.back();
            stack.pop_back();
            root = current.first;
            int current_depth = current.second;
            if (root->left == nullptr && root->right == nullptr) {
                min_depth = min(min_depth, current_depth);
            }
            if (root->left != nullptr) {
                stack.push_back(pair<TreeNode *, int>(root->left, current_depth + 1));
            }
            if (root->right != nullptr) {
                stack.push_back(pair<TreeNode*, int>(root->right, current_depth + 1));
            }
        }
        return min_depth;
        */

        /* // 边界条件
        if (root == nullptr) return 0;

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }
        return min_depth + 1;
         */
    }
};

int main() {
    return 0;
}

