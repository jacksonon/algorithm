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

// 验证回文穿:给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
class Solution {
public:
    // c++内置函数
    bool isPalindrome(string s) {
        string tmp;
        for (auto c : s) {
            if (islower(c) || isdigit(c)) tmp += c;
            else if (isupper(c)) tmp += (c + 32); // 大写转小写
        }
        int i = 0, j = tmp.size() - 1;
        while (i < j) {
            if (tmp[i++] != tmp[j--]) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}

