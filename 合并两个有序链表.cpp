#include <iostream>
#include <vector>
#include <cstdlib> // 随机数
#include <ctime>  // 时间
#include <random>
#include <stack>
#include <queue>

using namespace std;

// 单链表结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 将两个有序链表合为一个升序链表并返回，新链表是通过拼接所有节点而组成
class Solutio {
public:
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {

        // 哨兵节点
        ListNode* preHead = new ListNode(-1);
        ListNode* prev = preHead;
        // 当均为非空的时候进行迭代
        while (l1 != nullptr && l2 != nullptr) {
            // 比较l1和l2的值
            if (l1->val < l2->val) {
                // 将节点指针指向l1
                prev->next = l1;
                // 将l1指向下一个
                l1 = l1->next;
            } else {
                // 将节点指针指向l2
                prev->next = l2;
                // 将l2指向下一个
                l2 = l2->next;
            }
            // 将orev指针指向l1 或者 l2的下一个节点，将节点同步
            prev = prev->next;
        }
        // 合并l1,l2最多只有一个还未被合并完，直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;
        return preHead->next;

        /*
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            // 比较根节点：如果l1 < l2 的值，则l1的根节点设为首节点，将l1->next继续与l2进行比较
            l1->next = mergeTwoList(l1->next, l2);
            return l1;
        } else {
            // 将l2作为根节点
            l2->next = mergeTwoList(l1, l2->next);
            return l2;
        }
         */
    }
};

int main() {
    cout << "wang jia wei";
    return 0;
}

