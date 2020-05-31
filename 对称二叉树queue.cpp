#include <iostream>
#include <vector>
#include <cstdlib> // 随机数
#include <ctime>  // 时间
#include <random>
#include <stack>
#include <queue>

using namespace std;

// 对称二叉树

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solutio {
public:

    bool check(TreeNode* u, TreeNode* v) {
        queue<TreeNode *> q;
        q.push(u);
        q.push(v);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) {
                return false;
            }
            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

int main() {
    cout << "wang jia wei";
    return 0;
}

