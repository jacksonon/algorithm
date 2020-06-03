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

/*
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
注意：整数序列中的每一项将表示为一个字符串。
 */

// 外观数列：后一个是用来描述前一个外观的，如11 -> 21 -> 1211 标识1个2和1个1
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string pre = countAndSay(n - 1), res = "";
        int count = 1;
        for (int i = 0; i < pre.length(); i++) {
            if (pre[i] == pre[i+1]) {
                count++; // 计算同样的数有几个
            } else {
                res += to_string(count) + pre[i];
                count = 1;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}

