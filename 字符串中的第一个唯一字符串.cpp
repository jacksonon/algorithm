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

// 字符串中的第一个唯一字符
class Solution {
public:
    int firstUniqChar(string s) {
        // 最优解就是线性复杂度，需要map辅助
        unordered_map<char, int> count;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s.at(i);
            pair<char, int> ipair(c, count[c]++);
            count.insert(ipair);
        }
        for (int j = 0; j < n; j++) {
            if (count[s.at(j)] == 1) {
                return j;
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}

