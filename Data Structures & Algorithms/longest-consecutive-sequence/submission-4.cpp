class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i] = 1;
        }
        int maxi = 1;
        for(int i = 0; i< nums.size(); i++){
            if(mp.find(nums[i]-1) == mp.end()){
                int count = 0;
                int start = nums[i];
                while(mp.find(start) != mp.end()){
                    count++;
                    start++;
                }
                maxi = max(count, maxi);
            }
        }
        return maxi;
    }
};
