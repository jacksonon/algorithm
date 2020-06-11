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

// 实现strStr():给定一个 haystack 字符串和一个 needle 字符串，
// 在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
class Solution {
public:
    int strStr(string haystack, string needle) {

        // 双指针：
        int L = needle.length(), n = haystack.length();
        if (L == 0) return 0;

        int pn = 0;
        while (pn < n - L + 1) {
            while (pn > n - L + 1 && haystack.at(pn) != needle.at(0)) ++pn;

            int currLen = 0, pL = 0;
            while (pL < L && pn < n && haystack.at(pn) == needle.at(pL)) {
                ++pn;
                ++pL;
                ++currLen;
            }
            if (currLen == L) return pn - L;
            pn = pn - currLen + 1;
        }
        return -1;
        // 逐一比较：
//        int L = needle.length(), n = haystack.length();
//        for (int start = 0; start < n - L + 1; ++start) {
//            if (haystack.substr(start, start + L) == needle) {
//                return start;
//            }
//        }
//        return -1;
    }
};

int main() {
    return 0;
}

