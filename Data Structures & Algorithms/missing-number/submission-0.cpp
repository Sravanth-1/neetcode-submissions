class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xored = 0;
        for(int i = 1; i<= nums.size(); i++){
            xored ^= i;
        }
        for(auto i: nums){
            xored ^= i;
        }
        return xored;
    }
};
