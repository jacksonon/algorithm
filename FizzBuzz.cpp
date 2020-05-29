#include <iostream>
#include <stack> // 栈使用
#include <unordered_map>
#include <vector> // 向量容器
#include <array>
#include <cctype>
#include <string>
#include<algorithm>
#include<sstream>

using namespace std;

/*
写一个程序，输出从 1 到 n 数字的字符串表示。
1. 如果 n 是3的倍数，输出“Fizz”；
2. 如果 n 是5的倍数，输出“Buzz”；
3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for (int num = 1; num <= n ; ++num) {
            bool divisibleBy3 = (num % 3 == 0);
            bool divisibleBy5 = (num % 5 == 0);

            if (divisibleBy3 && divisibleBy5) {
                ans.push_back("FizzBuzz");
            } else if (divisibleBy3) {
                ans.push_back("Fizz");
            } else if (divisibleBy5) {
                ans.push_back("Buzz");
            } else {
                ans.push_back(to_string(num));
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}

