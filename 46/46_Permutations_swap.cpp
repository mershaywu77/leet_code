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
    // backtrack based on swap()
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }

    void backtrack(int start, vector<int>& nums) {
        int end = nums.size();
        if (start == end) {
            ans.push_back(nums);
            return;
        }
        for (int i=start; i<end; ++i) {
            swap(nums[i], nums[start]);
            backtrack(start+1, nums);
            swap(nums[i], nums[start]);
        }
    }
};