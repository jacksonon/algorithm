#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>

using namespace std;

/* LRU淘汰算法：在JAVA PYTHON中都有对应的数据结构，如OrderedDict(py)、LinkedHashMap(Java)
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。
它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；
如果密钥不存在，则插入该组「密钥/数据值」。
当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 */

/* 解题思路 ： 双向链表 + 哈希表
LRU 缓存机制可以通过哈希表辅以双向链表实现，我们用一个哈希表和一个双向链表维护所有在缓存中的键值对。
双向链表按照被使用的顺序存储了这些键值对，靠近头部的键值对是最近使用的，而靠近尾部的键值对是最久未使用的。
哈希表即为普通的哈希映射（HashMap），通过缓存数据的键映射到其在双向链表中的位置。
 */

// 双向链表
struct DLinkedNode {
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    // 使用初始化列表来初始化字段
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache; // hash表存储
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail; // 双向链表头尾连接
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkedNode* node = cache[key]; // 拿出节点地址
        moveToHead(node);
        return node->value; // 移动到头部后返回该节点的值
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            // 不存在。添加一个新节点
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                // size过大移除尾部
                DLinkedNode* remove = removeTail();
                cache.erase(remove->key);
                --size;
            }
        } else {
            // 存在移动到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    // 定义链表的一些操作：主要是这个链表的操作，添加头部和移除节点

    // 将node节点替换head节点
    void addToHead(DLinkedNode* node) {
        node->prev = head; // 当前节点的前一个设置为head
        node->next = head->next; // 将head的下一个节点交给node
        head->next->prev = node; // head的下一个节点的前一个节节点变为node
        head->next = node; // 头结点的下一个为node
    }

    // 移除节点：通过修改前后节点的指向移除该节点
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next; // node前一个节点的next节点 设置为node的next
        node->next->prev = node->prev; // node后一个节点的前节点，设置为node的prev
    }

    // 移动到头部
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    // 移除尾部节点
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev; // 获取虚尾部的前一个节点
        removeNode(node);
        return node;
    }
};

int main() {
    return 0;
}
