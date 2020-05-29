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

 */


// 杨辉三角给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle = vector<vector<int>>();

        // 边界条件
        if (numRows == 0) {
            return triangle;
        }

        // 第一行
        triangle.push_back(vector<int>());
        triangle[0].push_back(1);

        // 遍历生成
        for (int rowNum = 1; rowNum < numRows; ++rowNum) {
            vector<int> row = vector<int>();
            vector<int> prevRow = triangle[rowNum - 1];
            // 头 + 1
            row.push_back(1);

            for (int j = 1; j < rowNum; ++j) {
                // 当小于行数的时候分次计算当前行的每一组数
                row.push_back(prevRow[j - 1] + prevRow[j]);
            }

            // 尾 + 1
            row.push_back(1);

            triangle.push_back(row);
        }

        return triangle;
    }
};

string IntToString(int & i) {
    string s;
    stringstream ss(s);
    ss << i;
    return ss.str();
}

int main() {
    Solution so = Solution();
    vector<vector<int>> yhsj = so.generate(10);
    for (auto i : yhsj) {
        string  a;
        for (auto p : i) {
            a += IntToString(p);
        }
        cout << a << endl;
    }
    return 0;
}

