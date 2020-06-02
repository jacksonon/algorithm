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


// 有效的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        // 哈希表计数器
        unordered_map<char, int> counter;
        for (int i = 0; i < s.length(); ++i) {
            counter[s.at(i) - 'a']++;
            counter[t.at(i) - 'a']--;
        }
        

        // 普通排序比较
//        sort(s.begin(), s.end());
//        sort(t.begin(), t.end());
//        cout << s << endl;
//        cout << t << endl;
//        return !s.compare(t);
    }
};

int main() {
    Solution so = Solution();
    cout << so.isAnagram("anagram", "nagaram") << endl;
    return 0;
}

