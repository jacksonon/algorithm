#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
using namespace std;

// 字符串解码
class Solution {
public:

    // 获取数字
    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    // 重新品恒字符串
    string getString(vector<string> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector<string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取第一个数字并进栈
                string diagits = getDigits(s, ptr);
                stk.push_back(diagits);
            } else if (isalpha(cur) || cur == '[') {
                // 获取第一个字母并且进栈
                stk.push_back(string(1, s[ptr++]));
            } else {
                ++ptr;
                vector<string>sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                // 反转字符换
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前sub对应的字符串应该出现的次数
                int repTime = stoi(stk.back());
                stk.pop_back();
                string  t, o = getString(sub);
                // 构造字符换
                while (repTime--) t += o;
                // 将构造好的字符串进栈
                stk.push_back(t);
            }
        }
        return getString(stk);
    }
};

int main() {
    return 0;
}
