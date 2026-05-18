class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0;
        int last = nums.size()-1;
        while(start < last){
            int mid = (start+last)/2;
            if(nums[last] > nums[mid]){
                last = mid;
            }else{
                start = mid+1;
            }
        }
        return nums[last];
    }
};
