class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        if(nums.size() == 0){
            return 0;
        }
        int maxi = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i< nums.size(); i++){
            if(nums[i-1]+1 == nums[i] && dp[i-1]+1 > dp[i]){
                dp[i] = dp[i-1]+1;
                maxi = max(dp[i], maxi);
            }else if(nums[i-1] == nums[i]){
                dp[i] = dp[i-1];
            }
        }
        return maxi;
    }
};
