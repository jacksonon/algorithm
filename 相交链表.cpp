#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
#include<sstream>
#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

// 相交链表：寻找第一个重合点，然后比较重合点之后的值是否一致
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 暴力法：双循环
        // 哈希法：使用哈希表先存A，再和B比较
        // 浪漫的双指针：
        auto a = headA, b = headB;
        while (a != b) {
            if (a) a = a->next;
            else a = headB;
            if (b) b = b->next;
            else b = headA;
        }
        // a + all + b = b + all + a; 只要有重合，早晚会相遇
        return a;
    }
};


int main() {

    return 0;
}

