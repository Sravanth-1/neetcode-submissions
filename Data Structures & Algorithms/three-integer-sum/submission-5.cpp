class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int start = i+1;
            int last = nums.size()-1;
            while(start < last){
                if(nums[start] + nums[last] < target){
                    start++;
                } else if(nums[start] + nums[last] > target){
                    last--;
                }else{
                    triplets.push_back({nums[i], nums[start], nums[last]});
                    start++;
                    last--;
                    while(start < last && nums[start] == nums[start-1]){
                        start++;
                    }
                }
            }
        }
        return triplets;
    }
};
