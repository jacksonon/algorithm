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

// 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和
class Solution {
public:
    int getSum(int a, int b) {
        if (!(a & b)) return a ^ b; // a&b计算进位，无进位直接返回不进位结果
        // 防止符号溢出
        return getSum(a ^ b, ((unsigned int)(a & b)) << 1);// 递归计算进位与不进位的和
    }
    
    /*
     * 迭代方式：当b不为0的时候一直计算
     while (b) {
		auto carry = ((unsigned int)(a & b)) << 1;
		a ^= b;
        b = carry;
    }
    return a;
     */
};
int main() {

    return 0;
}

