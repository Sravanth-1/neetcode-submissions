class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>> mp;
        for(int i = 0; i< s.size(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {i, i};
            }
            mp[s[i]].second = i;
        }
        int start = 0;
        int track = mp[s[0]].second;
        vector<int> res;
        for(int i = 1; i< s.size(); i++){
            if(i > track){
                res.push_back(i-start);
                start = i;
                track = mp[s[i]].second;
            }else{
                track = max(track, mp[s[i]].second);
            }
        }

        res.push_back(s.size()-start);
        return res;
    }
};
