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

void print(int a[], int n, int i) {
    printf("%d:", i);
    for (int j = 0; j < 8; j++) {
        printf("%d", a[j]);
    }
    printf("\n");
}

void InsertSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        // 若i个元素大于i-1则直接插入，否则找到合适的位置插入
        if (a[i] < a[i - 1]) {
            // 前一个元素的位置
            int j = i - 1;
            // 第i位置的值
            int x = a[i];
            // 当前一个元素的位置存在，并且，第i个位置的数值小于i-1的数值，
            while (j > -1 && x < a[j]) {
                // 元素后移获取位置
                a[j + 1] = a[j];
                j--;
            }
            // 插入到正确位置
            a[j + 1] = x;
        }
        print(a, n, i);
    }
}


int main() {
    int a[8] = {3, 1, 7, 5, 2, 4, 9, 6};
    InsertSort(a, 8);
    return 0;
}

