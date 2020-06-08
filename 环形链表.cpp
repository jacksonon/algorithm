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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 环形链表
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // 哈希表
        unordered_map<ListNode*, int> m;
        while (head) {
            // 存储，当前节点，并指向下一个，如果当前节点的数量大1，则表示循环
            m[head]++;
            if (m[head] > 1) {
                return true;
            }
            head = head->next;
        }
        return false;

        // 我对环形的链表，首先第一想法就是双指针，最简单最好理解。快慢指针思想
//        if (head == NULL || head->next == NULL) {
//            return false;
//        }
//        ListNode *slow = head;
//        ListNode *fast = head->next;
//        while (slow != fast) {
//            if (fast == NULL || fast->next == NULL) {
//                return false;
//            }
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return true;
    }
};

int main() {
    return 0;
}

