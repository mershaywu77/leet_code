// @algorithm @lc id=46 lang=cpp 
// @title permutations


#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3])=[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// @test([0,1])=[[0,1],[1,0]]
// @test([1])=[[1]]
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track = {};
        vector<vector<int>> result = {};
        backtrack(nums, track, result);
        return result;
    }

    void backtrack(const vector<int>& nums, vector<int>& track, vector<vector<int>>& result) {
        if (track.size() == nums.size()) {
            result.push_back(track);
            return;
        }
        for (auto it=nums.begin(), end=nums.end(); it != end; ++it) {
            if (track.empty() || (std::find(track.begin(), track.end(), (*it)) == track.end())) {
                track.push_back(*it);
                backtrack(nums, track, result);
                track.pop_back();
            }
        }

    }

};