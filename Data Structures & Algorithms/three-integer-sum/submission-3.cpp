class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int start = i+1;
            int end = nums.size()-1;

            while(start < end){
                if(nums[start] + nums[end] == target){
                    res.push_back({nums[i], nums[start], nums[end] });
                    while(nums[start] == nums[start+1]){
                        start++;
                    }
                    start++;
                    end--;
                }else if(nums[start] + nums[end] < target){
                    start++;
                }else{
                    end--;
                }
            }
        }

        return res;
    }
};
