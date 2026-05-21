class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> present;
        for(auto num: nums){
            if(present.find(num) != present.end()){
                return true;
            }
            present[num]= 1;
        }
        return false;
    }
};