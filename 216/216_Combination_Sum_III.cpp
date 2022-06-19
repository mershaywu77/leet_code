// @algorithm @lc id=216 lang=cpp 
// @title combination-sum-iii


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(3,7)=[[1,2,4]]
// @test(3,9)=[[1,2,6],[1,3,5],[2,3,4]]
// @test(4,1)=[]
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> track;

    vector<vector<int>> combinationSum3(int k, int n) {  
        backtrack(1, k, n);
        return ans;
    }

    void backtrack(int val, int k, int n) {
        int la = ans.size();
        int lt = track.size();
        if (lt == k && n == 0) {
            ans.push_back(track);
        } else if (lt == k && n != 0) {
            return;
        }
        while (val <= n && val <= 9) {
            track.push_back(val);
            backtrack(val+1, k, n-val);
            track.pop_back();
            ++val;
        }
        return;
    }
};