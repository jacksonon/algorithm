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

using namespace std;

// 删除最外层的括号
class Solution {
public:
    string removeOuterParentheses(string S) {
        int L = 1, R = 0;
        string ans;
        for (int i = 1; i < S.length(); i++) {
            if (S[i] == '(') {
                L++;
            } else {
                R++;
            }
            if (R != L) {
                ans.push_back(S[i]);
            } else {
                i++;
                L = 1;
                R = 0;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}

