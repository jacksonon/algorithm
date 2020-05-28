#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
using namespace std;

/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
 */

// 反转字符串，没有空间限制使用递归，有限制使用双指针，
// o(n)执行了 n/2次交换
// o(1) 常数级空间
class Solution {
public:
    // 递归解法 O(N)空间，使用到了堆栈空间
    void helper(vector<char>& s, int left, int right) {
        if (left >= right) {
            return;
        }
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
        helper(s, left, right);
    }
    
    void reverseString(vector<char>& s) {
        // left首元素,right尾元素
        int left = 0, right = s.size() -1;
        // 当左index 小于 右index
        while (left < right) {
            // 保存最左侧值
            char tmp = s[left];
            // 左侧设置为右侧，之后left += 1
            s[left++] = s[right];
            // 右侧设置为左侧，之后right -=1
            s[right--] = tmp;
        }
    }
};

int main() {
    return 0;
}
