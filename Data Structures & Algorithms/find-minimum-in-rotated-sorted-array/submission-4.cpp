class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0;
        int last = nums.size()-1;
        while(start <= last){
            int mid = (start+last)/2;
            if(nums[start] <= nums[mid] && nums[mid] <= nums[last]){
                return nums[start];
            }
            if(nums[start] <= nums[mid]){
                start = mid+1;
            }else{
                last = mid;
            }
        }
    }
};
