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

// 删除字符串中的所有相邻重复项
class Solution {
public:
    string removeDuplicates(string S) {
        // 栈模拟
        string res = "";
        for (auto ch : S) {
            if (res.empty() || ch != res.back()) {
                res.push_back(ch);
            } else {
                res.pop_back();
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

