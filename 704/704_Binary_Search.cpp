// @algorithm @lc id=792 lang=cpp 
// @title binary-search


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([-1,0,3,5,9,12],9)=4
// @test([-1,0,3,5,9,12],2)=-1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==0) {
            return -1;
        } else {
            int end = nums.size() - 1;
            return search_helper(nums, 0, end, target);
        }
    }
    int search_helper(const vector<int>& nums, 
                      const int& begin,
                      const int& end,
                      const int target) {
        if (begin == end) {
            if (target == nums.at(end)) {
                return end;
            } else {
                return -1;
            }
        } else {
            int mid = begin + (end - begin) / 2;
            if (target == nums.at(mid)) {
                return mid;
            } else if (target > nums.at(mid)) {
                return search_helper(nums, mid, end, target);
            } else {
                return search_helper(nums, begin, mid, target);
            }
        } 

        }
};