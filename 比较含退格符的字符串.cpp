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

// 比较含退格的字符串
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string stack1 = "", stack2 = "";
        for (auto s : S)
            if (s == '#' && stack1 != "")
                stack1.pop_back();
            else if (s != '#') stack1.push_back(s);
        for (auto t : T)
            if (t == '#' && stack2 != "")
                stack2.pop_back();
            else if (t != '#') stack2.push_back(t);
        return stack1 == stack2;
        // 重排字符串
        // 双指针超时：
        /*
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S.at(i) == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (T.at(j) == '#') {
                    skipT++;
                    i--;
                } else if (skipT > 0) {
                    skipT--;
                    i--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0 && S.at(i) != T.at(j)) {
                return false;
            }
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            i--;
            j--;
        }
        return true;
         */
    }
};

int main() {
    return 0;
}

