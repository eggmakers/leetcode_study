// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(vector<int> &nums, int s)
    {
        int result = INT32_MAX;
        int sum = 0;
        int subLength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum >= s)
                {
                    subLength = j - i + 1;
                    result = result < subLength ? result : subLength;
                    break;
                }
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main()
{
    Solution solution;
    int s = 12;
    vector<int> nums = {4, 6, 2, 4, 9, 8, 7};
    cout << solution.minSubArrayLen(nums, s) << endl;
}