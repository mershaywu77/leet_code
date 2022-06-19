// @algorithm @lc id=93 lang=cpp 
// @title restore-ip-addresses


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("25525511135")=["255.255.11.135","255.255.111.35"]
// @test("0000")=["0.0.0.0"]
// @test("101023")=["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

class Solution {
public:
    vector<string> ans;
    vector<int> track; // e.g. [3,3,3,3] -> "255.255.255.255"
    vector<string> restoreIpAddresses(string s) {
        backtrack(0, s);
        return ans;
    }

    void backtrack(int start, const string& s) {
        int ts = track.size();
        int ss = s.size();
        if (ts == 4) {
            if (start >= ss) {
            string a = toAddressString(track, s);
            ans.push_back(a);
            }
            return;
        }
        for (int i=1; i<4; ++i) {
            string tmp = s.substr(start, i);
            if (start + i - 1 < ss && validNum(tmp) && stoi(tmp) < 256) {
                track.push_back(i);
                backtrack(start+i, s);
                track.pop_back();
            }
        }
    }

    bool validNum(string s) {
        if (s.front() == '0' && s.size() > 1) {
            return false;
        } else {
            return true;
        }
    }

    string toAddressString(vector<int> nums, const string& s) {
        if (nums.size() == 0) {
            return "";
        }
        string res = "";
        int start = 0;
        for (auto i: nums) {
            res += s.substr(start, i) + ".";
            start += i;
        }
        res.pop_back();
        return res;
    }
};