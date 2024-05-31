// 给定四个包含整数的数组列表A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
// 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        unordered_map<int, int> umap;
        for (int a : A)
        {
            for (int b : B)
            {
                umap[a + b]++;
            }
        }
        int count = 0;
        for (int c : C)
        {
            for (int d : D)
            {
                if (umap.find(0 - (c + d)) != umap.end())
                {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    Solution so;

    cout << so.fourSumCount(A, B, C, D) << endl;
}