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

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

// 员工的重要性：简单的深度优先搜索问题
class Solution {
public:
    unordered_map<int, Employee*> emap;
    int getImportance(vector<Employee*> employees, int id) {
        // 根据id保存每一个职员对应的开发者
        for (Employee *e: employees) {
            emap.emplace(e->id, e);
        }
        // 根据id递归求该职员的权重
        return dfs(id);
    }

    // 递归从根节点取出每一个id和其对应的值
    int dfs(int eid) {
        Employee *employee = emap.at(eid);
        int ans = employee->importance;
        for (int subid: employee->subordinates) {
            ans += dfs(subid);
        }
        return ans;
    }
};

// 自底向上的层次遍历
//class Solution {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//
//    }
//};

int main() {
    return 0;
}

