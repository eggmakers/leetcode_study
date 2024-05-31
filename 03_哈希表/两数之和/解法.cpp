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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end())
            {
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

int main()
{
    vector<int> i = {2, 7, 11, 15};
    int target = 9;
    Solution so;
    for (vector<int>::iterator it = so.twoSum(i, target).begin(); it != so.twoSum(i, target).end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}