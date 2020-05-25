#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

// 删除链表中的节点
class Solution {
public:
    void deleteNode(ListNode* node) {
        // 因为是单链表
        // 将像删除的节点设置为下一个节点：
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    return 0;
}
