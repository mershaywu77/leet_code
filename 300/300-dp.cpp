class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp
        //f(0) = {nums[0]} = 1
        //f(1) = f(0)+1 // nums[1] > nums[0] {nums[0, nums[1]}
        //f(1) = 1 // {nums[1]}
        //f(n) // max size if sub str end with nums[n]
        //f(n) = f(n-1) + 1 // nums[n] > nums[n-1]
        //f(n) = max(f(i)+1) //nums[n] >nums[i]
        int n = nums.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i < n ; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                int temp = 1;
                if (nums[i] > nums[j])
                    temp = dp[j] + 1;
                dp[i] = max(dp[i], temp);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};