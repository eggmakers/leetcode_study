// 给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int record[26] = {0};
        // add
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++)
        {
            // 通过record数据记录 magazine里各个字符出现次数
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.length(); j++)
        {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j] - 'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if (record[ransomNote[j] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string ransomNote = "iwantyoudie";
    string magazine = "igffdgfdsgdfffsdfsdafqfqfydfqwasdfdntdsdadwdaweweeiwadee";
    Solution so;
    cout << so.canConstruct(ransomNote, magazine) << endl;
}