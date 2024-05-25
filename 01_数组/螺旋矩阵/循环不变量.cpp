// 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
// 示例:
// 输入: 3 输出: [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0,
            starty = 0;
        int mid = n / 2;
        int loop = n / 2;
        int count = 1;
        int offset = 1;
        int i, j;
        while (loop--)
        {
            i = startx;
            j = starty;

            for (j = starty; j < n - offset; j++)
                res[startx][j] = count++;
            for (i = startx; i < n - offset; i++)
                res[i][j] = count++;
            for (; j > starty; j--)
                res[i][j] = count++;
            for (; i > starty; i--)
                res[i][j] = count++;
            startx++;
            starty++;
            offset += 1;
        }
        if (n % 2)
            res[mid][mid] = count;
        return res;
    }
};

int main()
{
    Solution solution;
    solution.generateMatrix(3);
}