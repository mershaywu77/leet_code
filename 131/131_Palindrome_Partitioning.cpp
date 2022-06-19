// @algorithm @lc id=131 lang=cpp 
// @title palindrome-partitioning


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("aab")=[["a","a","b"],["aa","b"]]
// @test("a")=[["a"]]
// @test("aaa")=[["a","a","a"], ["a","aa"], ["aa", "a"], ["aaa"]]
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> track;
    vector<vector<string>> partition(string s) {
        backtrack(0, s);
        return ans;
    }

    void backtrack(int ind, const string& s) {
        int st = track.size();
        int ss = s.size();
        if (ind == ss) {
            ans.push_back(track);
            return;
        }
        for (int j=1; j<=(ss-ind); j++) {
            if (isPalindrome(s.substr(ind,j))) {
                track.push_back(s.substr(ind,j));
                backtrack(ind+j, s);
                track.pop_back();
            } 
        }
    }

    bool isPalindrome(string s) {
        int l = s.size();
        if (l == 0) {
            return true;
        }
        int first = 0;
        int last = l - 1;
        while (first < last) {
            if (s[first] != s[last]) {
                return false;
            }
            ++first;
            --last;
        }
        return true;
    }
};