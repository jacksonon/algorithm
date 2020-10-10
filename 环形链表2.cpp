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
#include <stdio.h>

using namespace std;




// 制作一个单链表结构体
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} // 快速构造
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // 快慢指针
        
        // 快慢指针均指向头部
        ListNode *slow = head, *fast = head;
        // 当快指针不为nullptr则存在循环
        while (fast != nullptr) {
            // 慢指针指向下一节点
            slow = slow->next;
            // 如果快指针的下一节点为空，则返回空节点
            if (fast->next == nullptr) {
                return nullptr;
            }
            // 快指针指向下一个节点的下一个
            fast = fast->next->next;
            // 如果快慢指针相遇
            if (fast == slow) {
                // 创建一个查询节点ptr
                ListNode *ptr = head;
                // 当查询节点和慢节点不一致时，就循环对比下一个节点，知道找到相交节点
                while (ptr != slow) {
                    // 查询节点指向下一个节点
                    ptr = ptr->next;
                    // 慢节点指向下一个节点
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;

        /*
        // 哈希表：使用了额外的空间
        unordered_set<ListNode *> visited;
        // 遍历链表的每一个节点
        while (head != nullptr) {
            // 如果Set包含这个节点，则证明存在环
            if (visited.count(head)) {
                return head;
            }
            // 将节点记录到set中
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
         */
    }
};


int main() {
    return 0;
}
