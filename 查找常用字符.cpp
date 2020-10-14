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
#include <stdio.h>

using namespace std;



/*
 * 给定仅有小写字母组成的字符串数组 A，
 * 返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
 * 例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
 * 你可以按任意顺序返回答案。
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        /*
         * 计数
         */
        vector<int> minfreq(26, INT_MAX); // 最小频率统计
        vector<int> freq(26); // 频率
        // 遍历整个字符串A
        for (const string &word: A) {
            // 填充频率统计为26个0
            fill(freq.begin(), freq.end(), 0);
            // 判断单词每个字符出现的次数
            for (char ch: word) {
                ++freq[ch - 'a'];
            }
            // 比较火的最小出现频率
            for (int i = 0; i < 26; ++i) {
                minfreq[i] = min(minfreq[i], freq[i]);
            }
        }

        // 还原存储结果到字符
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minfreq[i]; ++j) {
                ans.emplace_back(1, i + 'a');
            }
        }
        return ans;
    }

};

int main() {
    return 0;
}
