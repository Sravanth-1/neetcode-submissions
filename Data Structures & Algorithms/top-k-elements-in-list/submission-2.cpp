class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(auto num : nums){
            counts[num]++;
        }
        vector<vector<int>> freq(nums.size()+1);

        for(auto tup : counts){
            freq[tup.second].push_back(tup.first);
        }

        vector<int> res;
        for(int i = nums.size(); i> 0; i--){
            for(int j =0; j< freq[i].size(); j++){
                res.push_back(freq[i][j]);
                if(res.size() == k){
                    return res;
                }
            }
        }
    }
};
