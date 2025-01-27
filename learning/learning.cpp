// learning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
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
                //nums[nums.size() - 1 - i];
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
    // test nums = { 847,847,0,0,0,399,416,416,879,879,206,206,206,272 };
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

        //1480
        vector<int> runningSum(vector<int>& nums) {
            vector<int> running_Sum(nums.size());
            for (int i = 0; i < nums.size(); i++)
            {
                running_Sum[i] += nums[i];
                for (int j = i + 1; j < nums.size(); j++)
                {
                    running_Sum[j] += nums[i];
                }
            }
            return running_Sum;
        }
        //1672
        //vector<vector<int>> nums;
        //nums = { {1,2,3 }, { 3,2,1 } };
        int maximumWealth(vector<vector<int>>& accounts) {
            if (accounts.size() < 1)
                return 0;
            int n = accounts.size();
            int m = accounts[0].size();
            int max = 0;
            int temp = 0;
            for (int i = 0; i < n; i++)
            {
                for (auto each : accounts[i])
                {
                    temp += each;
                }
                if (temp > max)
                    max = temp;
                temp = 0;
            }
            return max;
        }
        void printVecInt(vector<int>& nums)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << "\n";
            }
        }
        //412
        vector<string> fizzBuzz(int n) {
            vector<string> str(n);
            for (int i = 1; i <= n; i++) {
                if (i % 3 == 0) {
                    if (i % 5 == 0)
                        str[i - 1] = "FizzBuzz";
                    else
                        str[i - 1] = "Fizz";
                }
                else if (i % 5 == 0)
                    str[i - 1] = "Buzz";
                else
                    str[i - 1] = to_string(i);
            }

            return str;
        }

        //1342. Number of Steps to Reduce a Number to Zero
        //Given an integer num, return the number of steps to reduce it to zero.

        //    In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
        //    https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/

        int numberOfSteps(int num) {
            if (num == 0)
                return 0;
            int steps = 0;
            while (num != 0) {
                steps++;
                if (num % 2 == 0)
                    num /= 2;
                else
                    num -= 1;
            }
            return steps;
        }
};

int main()
{
    Solution s;

    s.fizzBuzz(15);
    //s.printVecInt(nums1);

}
