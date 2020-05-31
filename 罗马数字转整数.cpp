#include <iostream>
#include <vector>
#include <cstdlib> // 随机数
#include <ctime>  // 时间
#include <random>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<char, int> lm_map = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
        }; // 初始化哈希表
        for (int i = 0; i < s.length(); ++i) {
            if (lm_map[s[i]] < lm_map[s[i + 1]]) {
                // 值小于下一位，则是减当前述
                result -= lm_map[s[i]];
            } else {
                result += lm_map[s[i]];
            }
        }
        return result;
    }
};

int main() {
    cout << "wang jia wei";
    return 0;
}

