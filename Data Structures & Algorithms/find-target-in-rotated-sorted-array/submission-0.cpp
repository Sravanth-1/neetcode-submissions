class Solution {
public:
    int find(int target, vector<int>& nums, int low, int high){

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low < high){
            int mid = (low+high)/2;
            if(nums[mid] <= nums[high]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        
        int a = find(target, nums, 0, low-1);
        int b = find(target, nums, low, nums.size()-1);
        return max(a, b);

    }
};
