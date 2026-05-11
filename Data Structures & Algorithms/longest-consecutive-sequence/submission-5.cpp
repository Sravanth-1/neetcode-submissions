class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(mp[nums[i]]) {
                continue;
            }
            mp[nums[i]] = 1;
            int left = mp[nums[i] - 1];
            int right = mp[nums[i] + 1];
            
            mp[nums[i] - left] = left + right + 1;
            mp[nums[i] + right] = left + right + 1;
            

            maxi = max(left + right + 1, maxi);
        }

        return maxi;
    }
};