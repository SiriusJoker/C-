// learning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector <string>& strs) {
        string com_prefix = "";
        int size = strs[0].size();
        int n = strs.size();
        bool continue_ = true;
        string temp;
        string first = strs[0];
        for (string str : strs)
        {
            if (str.size() < size)
                size = str.size();
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 1;  j < n; j++)
            {
                temp = strs[j];
                if (first[i] != temp[i])
                    continue_ = false;
            }
            if (!continue_)
                break;
            else
                com_prefix += first[i];
        }
        return com_prefix;

    }
    bool isValid(string s) {
        string ob;
        bool res = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' or s[i] == '[' or s[i] == '{')
                ob += s[i];
            else
            {
                if (ob.size() < 1 ||
                    (s[i] == ')' and ob[ob.size() - 1] != ('(')) ||
                    (s[i] == '}' and ob[ob.size() - 1] != ('{')) ||
                    (s[i] == ']' and ob[ob.size() - 1] != ('[')))
                {
                    res = false;
                    break;
                }
                
                ob.pop_back();
            }
            res = ob.empty();
        }

        return res;
    }
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[k] != nums[i])
            {
                nums[++k] = nums[i];
            }
        }

        return k + 1;
    }
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val && i < nums.size() - 1)
            {
                nums[i] = nums[i + 1];
                nums[nums.size() - 1 - i];
            }
            else {
                k++;
            }
        }
        return k;

    }

    int strStr(string haystack, string needle) {
        int k = -1;
        if (haystack.length() >= needle.length()) {
            for (int i = 0; i < haystack.length(); i++) {
                if (haystack[i] == needle[0])
                {
                    k = 1;
                    if (i + needle.length() - 1 < haystack.length()) {
                        for (int j = 1; j < needle.length(); j++)
                        {
                            if (needle[j] == haystack[i + j])
                            {
                                k++;
                            }
                        }
                        if (k == needle.length())
                            return i;
                    }
                }
            }
        }
        return -1;
    }
// 2460
        vector<int> applyOperations(vector<int>& nums) {
            if (nums.size() > 1)
            {
                int k = 0;
                int j = 1;
                for (int i = 0; i < nums.size() - 1; i++)
                {
                    if (j >= nums.size())
                    {
                        nums[k] = nums[nums.size() - 1];
                        if(i== nums.size() - 2)
                            nums[nums.size() - 1] = 0;
                        nums[i] = 0;
                    }
                    else
                    { 
                    if (nums[i] == 0)
                    {
                        nums[i] = nums[i + 1];
                        nums[i + 1] = 0;
                        if (i + 2 < nums.size())
                        {
                            j = i + 2;
                        }
                    }
                    if (nums[i] == nums[j] && nums[i] != 0)
                    {
                        nums[k] = 2 * nums[i];
                        nums[j] = 0;
                        k++;
                        j++;
                        if (i > k)
                        {
                            nums[i] = 0;
                        }
                    }
                    else
                    {
                        if (nums[i] != 0) {
                            nums[k] = nums[i];
                            k++;
                            if (i > k)
                            {
                                nums[i] = 0;
                            }
                        }
                        j++;

                    }
                    }
                }
            }
            return nums;
        }
        void printVecInt(vector<int>& nums)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << "\n";
            }
        }
    
};

int main()
{
    Solution s;
    vector<int> nums;
    nums = { 847,847,0,0,0,399,416,416,879,879,206,206,206,272 };

    s.applyOperations(nums);
    s.printVecInt(nums);

}
