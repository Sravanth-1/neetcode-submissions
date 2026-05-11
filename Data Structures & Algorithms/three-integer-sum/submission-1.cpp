class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            int j = i+1;
            int k = nums.size()-1;

            while(j < k){
                int sum = nums[k]+nums[j];
                if(sum == -nums[i]){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(nums[j] == nums[j-1]){
                        j++;
                    }
                    k--;
                    while(nums[k] == nums[k+1]){
                        k--;
                    }
                }else if(sum < -nums[i]){
                    j++;
                }else{
                    k--;
                }
            }
        }

        return res;
    }
};