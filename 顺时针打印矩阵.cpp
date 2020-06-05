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

using namespace std;

// 顺时针打印矩阵
class Solution {
private:
    // constexpr是C++11中新增的关键字，其语义是“常量表达式”，也就是在编译期可求值的表达式。
    // 最基础的常量表达式就是字面值或全局变量/函数的地址或sizeof等关键字返回的结果，
    // 而其它常量表达式都是由基础表达式通过各种确定的运算得到的。
    // constexpr值可用于enum、switch、数组长度等场合。
    // constexpr所修饰的变量一定是编译期可求值的，
    // 所修饰的函数在其所有参数都是constexpr时，一定会返回constexpr
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 模拟的方式：
        // 如果是空的，则直接返回空
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        // 计算有多少个宽高
        int rows = matrix.size(), columns = matrix[0].size();
        // 创建一个遍历数组保存是否遍历到结果的值
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        // 计算总数
        int total = rows * columns;
        // 开辟一个总数大小的用来保存返回值的向量
        vector<int> order(total);

        // 从0行0列开始遍历
        int row = 0, column = 0;
        int directionIndex = 0;
        // 当i小于的视乎开始
        for (int i = 0; i < total; i++) {
            // 保存当前的值从0开始：二维数组
            order[i] = matrix[row][column];
            // 记录该位置已被访问过
            visited[row][column] = true;
            // 计算下一行和下一列
            int nextRow = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            // 如果下一行小于0或者大于总行数，则反转
            // 如果下一列小于0，或者大于总列数，则反转
            // 如果已经访问过下一行下一列，反转
            if (nextRow < 0 ||nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                // 当前方向存储 + 1，且对 % 4 取余，判断当前的位置
                directionIndex = ( directionIndex + 1) % 4;
            }
            // 重新计算下一个row ,是原值，或是下一个起点
            row += directions[directionIndex][0];
            // 重新计算下一个column
            column += directions[directionIndex][1];
        }
        return order;
    }
};


int main() {
    return 0;
}

