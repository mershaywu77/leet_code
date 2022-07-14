// @algorithm @lc id=42 lang=cpp 
// @title trapping-rain-water


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([0,1,0,2,1,0,1,3,2,1,2,1])=6
// @test([4,2,0,3,2,5])=9
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> leftMax(height.begin(), height.end());
        vector<int> rightMax(height.begin(), height.end());
        int actualSum = height[0];
        int expectSum = 0;
        for (int i=1; i<len; ++i) {
            if (leftMax[i] < leftMax[i-1]) {
                leftMax[i] = leftMax[i-1];
            }
            actualSum += height[i];
        }
        for (int i=len-2; i>=0; --i) {
            if (rightMax[i] < rightMax[i+1]) {
                rightMax[i] = rightMax[i+1];
            }
        }
        for (int i=0; i<len; ++i) {
            if (rightMax[i] != leftMax[i]) {
                rightMax[i] = min(rightMax[i], leftMax[i]);
            }
            expectSum += rightMax[i];
        }
        return expectSum - actualSum;
    }
};