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
00000011 => 3
00000010 => 2
00000000 => 0 与运算

 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）
 输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
 */

// 位1的个数
class Solution {
public:
    int hammingWeightLoop(int n) {
        int bits = 0;
        int mask = 1;
        for (int i = 0; i < 2; ++i) {
            if ( (n & mask) != 0) {
                bits++;
            }
            // 掩码左移一位
            mask <<= 1;
        }
        return bits;
    }

    int hammingWeight(int n) {
        int sum = 0;
        // 当 n != 0时候，使用使用n 和 n -1 做与运算。 n 会一点一点变小，直到变为0
        while (n != 0) {
            sum++;
            // n和n - 1始终差1，1就是起始位，与运算0 与 任何都为1
            // 在二进制表示中，数字 n 中最低位的 1 总是对应 n - 1中的 0 。
            // 因此，将 n 和 n - 1 与运算总是能把 n 中最低位的 1 变成 0 ，并保持其他位不变。
            n &= (n - 1);
        }
        return sum;
    }
};

int main() {
    int t = 1;
    t <<= 1;
    t <<= 1;
    cout << t << endl;
    return 0;
}

