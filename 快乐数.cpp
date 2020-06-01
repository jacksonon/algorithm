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

// 快乐数
class Solution {
public:

    // 快慢指针：节省一个set的存储释放消耗
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            // 对10取余。是末位
            int d = n % 10;
            // 除10抛弃末位
            n = n / 10;
            // 计算+=平方和
            totalSum += d * d;
        }
        return totalSum;
    }

    bool isHappy(int n) {
        int slowRunner = n; // 看当前的数
        int fastRunner = getNext(n); // 指向下一个
        // 当快指针不为1时 且 快慢指针不相等（相等的话有问题了，就表明有循环了）
        // 使用while循环，进行计算
        while (fastRunner != 1 && slowRunner != fastRunner) {
            // 慢指针继续计算下一个数
            slowRunner = getNext(slowRunner);
            // 快指针跳跃式计算下下个数
            fastRunner = getNext(getNext(fastRunner));
        }
        // 使用快指针进行比较：可能为1，也可能快慢指针的数一致
        return fastRunner == 1;
    }

    /*
    int get_next(int n) {
        int totalSum = 0;
        // 进行位数遍历运算
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d; // += d的平方
        }
        return totalSum;
    }

    // 使用set检测循环
    bool isHappy(int n) {
        set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = get_next(n);
        }
        return n == 1;
    }
     */
};


int main() {
    return 0;
}

