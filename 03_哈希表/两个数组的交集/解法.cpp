// 题意：给定两个数组，编写一个函数来计算它们的交集。
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &num1, vector<int> &num2)
    {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(num1.begin(), num1.end());
        for (int num : num2)
        {
            if (nums_set.find(num) != nums_set.end())
            {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main()
{
    vector<int> num1 = {0, 2, 3, 1, 2, 1};
    vector<int> num2 = {0, 2, 3, 4};
    Solution so;
    for (vector<int>::iterator it = so.intersection(num1, num2).begin(); it != so.intersection(num1, num2).end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}
