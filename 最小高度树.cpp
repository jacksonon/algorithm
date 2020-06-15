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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

// 最小高度树：有序数组
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode* dfs(vector<int>nums, int L, int R) {
        if (L > R) {
            return nullptr;
        }
        int mid = (L + R) >> 1; // 计算中间
        TreeNode *ptr = new TreeNode(nums[mid]);
        ptr->left = dfs(nums, L, mid - 1);
        ptr->right = dfs(nums, mid + 1, R);
        return ptr;
    }
};

int main() {
    return 0;
}

