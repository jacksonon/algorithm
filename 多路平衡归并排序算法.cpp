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

#define k 5 // 5路排序
#define MAXKEY 10000
#define MINKEY -1

typedef int LoserTree[k] ; // 非终端节点，完全二叉树，所以可以使用一维数组标识
typedef struct {
    int key;
} ExNode, External[k + 1]; // 标识败者树的叶子节点
External b;

int a0[] = {10, 15, 16};
int a1[] = {9, 18, 20};
int a2[] = {20, 22, 40};
int a3[] = {6, 15, 25};
int a4[] = {12, 37, 48};

int t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0; // 模拟初始归并记录使用

// 比较败者
void Adjust(LoserTree ls, int s) {
    int t = (s + k) / 2;
    while (t > 0) {
        if (b[s].key > b[ls[t]].key) {
            int swap = s;
            s = ls[t];
            ls[t] = swap;
        }
        t = t / 2;
    }
    ls[0] = s;
}

// 创建败者树
void CreateLoserTree(LoserTree ls) {
    b[k].key = MINKEY;
    for (int i = 0; i < k; i++) {
        ls[i] = k;
    }
    for (int i = k - 1; i >= 0; i--) {
        Adjust(ls, i);
    }
}

// 模拟从外箱内存读取归并的每一小部分
void input(int i) {
    switch (i) {
        case 0:
            if (t0 < 3) {
                b[i].key = a0[t0];
                t0++;
            } else {
                b[i].key = MAXKEY;
            }
            break;
        case 1:
            if (t1 < 3) {
                b[i].key = a1[t1];
                t1++;
            } else {
                b[i].key = MAXKEY;
            }
            break;
        case 2:
            if (t2 < 3) {
                b[i].key = a2[t2];
                t2++;
            } else {
                b[i].key = MAXKEY;
            }
            break;
        case 3:
            if (t3 < 3) {
                b[i].key = a3[t3];
                t3++;
            } else {
                b[i].key = MAXKEY;
            }
            break;
        case 4:
            if (t4 < 3) {
                b[i].key = a4[t4];
                t4++;
            } else {
                b[i].key = MAXKEY;
            }
            break;
        default:
            break;
    }
}

// 败者树的简历和内部归并
void K_Merge(LoserTree ls) {
    for (int i = 0; i <= k; i++) {
        input(i);
    }
    // 创建败者树
    CreateLoserTree(ls);
    // 最终的胜者存储在ls[0]中，当值为MAXKEY时，证明5个文件归并介绍
    while (b[ls[0]].key != MAXKEY) {
        printf("%d ", b[ls[0]].key);
        input(ls[0]);
        Adjust(ls, ls[0]);
    }
}

int main() {
    LoserTree ls;
    K_Merge(ls);
    return 0;
}

