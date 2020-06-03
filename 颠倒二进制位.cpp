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

// 颠倒二进制位
class Solution {
public:
//    uint32_t reverseBits(uint32_t n) {
//        // 1.逐位颠倒
//        uint32_t ret = 0, power = 31; // 0-31共32位，表示32位整数
//        while (n != 0) {
//            // 当n不为0，值为每一次颠倒的位置的和
//            // 二进制使用 << power换到对应位置，
//            // &1可以取出二进制的最后一位，理解为&00000001，即可，其它位&0均为0，只有最后一位为1时候，才是1
//            ret += (n & 1) << power; // 乘power
//            // 实现从右到左遍历，计算完最后一位，将最后一位移除，继续计算 power - 1位
//            n = n >> 1; // 右移1位。安全部右移后是000000，此时结果为0
//            power -= 1; // power变成下一位
//            cout << ret << endl;
//        }
//        return ret;
//    }

    // 优化：缓存该值，且每8位一计算
    uint32_t reverseByte(uint32_t byte, unordered_map<uint32_t, uint32_t> cache) {
        if (cache.find(byte) != cache.end()) {
            return cache[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.emplace(byte, value);
        return value;
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 24;
        unordered_map<uint32_t, uint32_t> cache;
        while (n != 0) {
            ret += reverseByte(n & 0xff, cache) << power;
            n = n >> 8;
            power -= 8;
        }
        return ret;
    }

    /*
     * 神仙解法
     class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
     */
};

/*
 * 1 & 1 =1 其它都是0
 */

int main() {
    Solution s = Solution();
    s.reverseBits(8);
    return 0;
}

