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
};

int main()
{
    Solution s;
    

    cout << s.strStr(needle, needle);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
