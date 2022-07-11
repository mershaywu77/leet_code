// @algorithm @lc id=70 lang=cpp 
// @title climbing-stairs


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(2)=2
// @test(3)=3
class Solution {
public:
    int climbStairs(int n) {
        vector<int> nums = {1, 2};
        int len = 2;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i=0; i<n+1; ++i) {
            for (int j=0; j<len; ++j) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[n];
    }
};