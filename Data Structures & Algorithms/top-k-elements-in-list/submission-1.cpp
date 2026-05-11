class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(auto i : nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>> q;
        for(auto i: mp){
            q.push({i.second , i.first});
        }

        while(k--){
            res.push_back(q.top().second);
            q.pop();
        }

        return res;
    }
};
