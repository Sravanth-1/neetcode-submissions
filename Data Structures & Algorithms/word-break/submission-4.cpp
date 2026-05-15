class Solution {
public:
    bool find(string s, int index, vector<string>& wordDict, unordered_map<int, bool> &mp){
        if(index == s.size()){
            return true;
        }
        if(mp.find(index) != mp.end()){
            return mp[index];
        }
        for(auto w: wordDict){
            if(index + w.size() <= s.size() && s.compare(index, w.size(), w) == 0){
                if(find(s, index + w.size(), wordDict, mp)){
                    return mp[index] = true;
                }
            }
        }

        return mp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> mp;
        return find(s, 0, wordDict, mp);
    }
};
