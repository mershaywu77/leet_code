// @algorithm @lc id=78 lang=cpp 
// @title subsets


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3])=[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// @test([0])=[[],[0]]
class Solution {
public:
    vector<vector<int>> ans = {};
    vector<int> track = {};
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {return ans;}
        backtrack(0, nums);
        return ans;
    }

    void backtrack(int start, const vector<int>& nums) {
        int len_n = nums.size();
        if (start >= len_n) {
            ans.push_back(track);
            return; 
        }
        track.push_back(nums[start]);
        backtrack(start+1, nums);
        track.pop_back();
        backtrack(start+1, nums);
    }
};