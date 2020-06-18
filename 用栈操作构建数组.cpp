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

// 用栈操作构建数组
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int curr = 1;
        for (auto t : target) {
            if (t != curr) {
                for (int i = 0; i < t - curr; ++i) {
                    res.push_back("Push");
                    res.push_back("Pop");
                }
            }
            res.push_back("Push");
            curr = t + 1;
        }
        return res;
    }
};

int main() {
    return 0;
}

