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
    // cpp中NULL标识0，czo中null标识(void*)，cpp不支持void*指针隐式转换
    ListNode(int x) : val(x), next(nullptr){}
};

// 回文链表：请判断一个链表是否为回文链表。
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 转换为数组。前后倒序比较
        // 递归：

        // 空一定是回文
        if (head == nullptr) {
            return true;
        }

        // 获取前半部分尾结点
        ListNode *firsHalftEnd = endOfFirstHalf(head);
        // 反转后面的链表
        ListNode *secondHalfStart = reverseList(firsHalftEnd->next);

        bool res = true;
        ListNode *p1 = head;
        ListNode *p2 = secondHalfStart; // 指向反转后的头
        while (res && p2 != nullptr) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        // 再次反转拼接，修复链表
        firsHalftEnd->next = reverseList(secondHalfStart);
        return res;
    }

private:
    // 反转链表
    ListNode* reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr) {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    // 找寻前半部分尾节点
    ListNode * endOfFirstHalf(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    return 0;
}

