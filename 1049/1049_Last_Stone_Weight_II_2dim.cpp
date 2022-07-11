// @algorithm @lc id=1130 lang=cpp 
// @title last-stone-weight-ii


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([2,7,4,1,8,1])=1
// @test([31,26,33,21,40])=5
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int len = stones.size();
        int sum = 0;
        int lastStone = 101;
        if (len == 1) {
            return stones[0];
        }
        for (int i=0; i<len; ++i) {
            sum += stones[i];
        }
        vector<vector<int>> dp(len, vector<int>(sum+1, 0));
        for (int j=0; j<sum+1; ++j) {
            if (stones[0] <= j) {
                dp[0][j] == stones[0];
            }
        }
        for (int i = 1; i < len; ++i) {
            for (int j = 1; j < sum+1; ++j) {
                if (stones[i] > j) { 
                    dp[i][j] = dp[i-1][j]; 
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]]+stones[i]);
                } 
                int tmp = abs(sum - 2 * dp[i][j]);
                if (tmp < lastStone) {
                    lastStone = tmp;
                }
            }
        }
        return lastStone;
    }
};