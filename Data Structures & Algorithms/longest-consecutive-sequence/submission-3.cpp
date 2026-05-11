class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        int maxi = 1;
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                dp[i] = dp[i-1]+1;
                maxi = max(dp[i], maxi);
            }else if(nums[i] == nums[i-1]){
                dp[i] = dp[i-1];
            }
        }
        return maxi;
    }
};
