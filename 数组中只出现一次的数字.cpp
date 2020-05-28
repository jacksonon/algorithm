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
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:输入: [2,2,1]输出: 1

**你还记得大明湖畔的交换律和结合律吗？**

使用位运算。对于这道题，可使用异或运算。异或运算有以下三个性质。
任何数和 00 做异或运算，结果仍然是原来的数，即 a^0=a。
任何数和其自身做异或运算，结果是 00，即 a^a=0。
异或运算满足交换律和结合律，即 a^b^a = b^a^a = b^(a^a) = b^0 = b;
p	q	    p & q	p | q	p ^ q
0	0	    0	    0	    0
0	1	    0	    1	    1
1	1	    1	    1	    0
1	0	    0	    1	    1

^ => 同位为0，不同位为1
    00101010
 ^  00101010
 =  00000000
 */

// 数组中只出现一次的数字
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 知道上面的规律就很简单了
        int ret = 0;
        // 普及一下auto的关键字使用，自 C++ 11 以来，auto 关键字用于两种情况：
        // 声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符。
        for (auto e: nums) {
            ret ^= e;
        }
        return ret;
    }
};

int main() {
    return 0;
}
