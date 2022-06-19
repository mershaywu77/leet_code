// @algorithm @lc id=90 lang=cpp 
// @title subsets-ii


#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "algm/algm.h"
using namespace std;
// @test([1,2,2])=[[],[1],[1,2],[1,2,2],[2],[2,2]]
// @test([0])=[[],[0]]
// @test([4,4,4,1,4]) = [[],[1],[1,4],[4],[4,1],[4,1,4],[4,4],[4,4,1],[4,4,1,4],[4,4,4],[4,4,4,1],[4,4,4,1,4],[4,4,4,4]]
// @test([4,1,0]) = [[],[0],[0,1],[0,1,4],[0,4],[1],[1,4],[4]]
class Solution {
public:
    set<vector<int>> setAns;
    vector<int> track;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        backtrack(0, nums);
        vector<vector<int>> ans(setAns.begin(), setAns.end());
        return ans;
    }

    void backtrack(int start, const vector<int>& nums) {
        int ns = nums.size();
        if (start >= ns) {
            setAns.insert(copy_n_sort(track));
            return;
        }
        track.push_back(nums[start]);
        backtrack(start+1, nums);
        track.pop_back();
        backtrack(start+1, nums);
    }

    vector<int> copy_n_sort(vector<int> vi) {
        sort(vi.begin(), vi.end());
        return vi;
    }
};