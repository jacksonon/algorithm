#include <iostream>
#include <vector>
#include <cstdlib> // 随机数
#include <ctime>  // 时间
#include <random>

using namespace std;

/*
一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 */


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // 使用参数列表初始化
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序 + 随机（前序、后序）=> 中序+前or后 = 唯一二叉树（核心）
class Solution {

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 递归：
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int l, int r) {
        // 如果左侧比右侧大，则返回NULL
        if (l > r) return NULL;
        int p = (l + r) >> 1;
        if ((l + r) % 2 == 1) {
            unsigned seed;
            seed = time(0);
            srand(seed);
            p += rand() % 2;
        }

        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(nums, l, p - 1);
        root->right = helper(nums, p + 1, r);
        return root;
    }
};

int main() {
    cout << "wang jia wei";
    return 0;
}
