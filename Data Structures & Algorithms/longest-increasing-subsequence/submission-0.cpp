class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;

        for(auto num : nums){
            int index = lower_bound(temp.begin(),temp.end(), num) - temp.begin();
            if(index < temp.size()){
                temp[index] = num;
            }else{
                temp.push_back(num);
            }
        }

        return temp.size();
    }
};