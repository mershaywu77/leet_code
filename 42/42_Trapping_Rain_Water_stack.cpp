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
        int n = height.size();
        int sum = 0;
        if (n == 1) return 0;
        stack<int> stk;
        for (int i=0; i<n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int trap = height[stk.top()];
                stk.pop();
                if (!stk.empty()) {
                    sum += (min(height[stk.top()], height[i]) - trap) * (i - stk.top() - 1);
                }
            }
            if (!stk.empty() && height[i] == height[stk.top()]) {
                stk.pop();
            }
            stk.push(i);
        }
        return sum;
    }
};