#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
using namespace std;

/*
给定一个Excel表格中的列名称，返回其相应的列序号。
例如，
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28

本质上是一个26进制转10进制的算法
 */

// Excel表列序号
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            // 从低位到高位，但是都是个位
            int num = s[i] - 'A' + 1;
            // 像十进制*10 ascii*26，所以类似于26进制的方法 + 个位 => 依次类推
            ans = ans * 26 + num;
        }
        return ans;
    }
};

int main() {

    return 0;
}

