class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;
        for(auto str: strs){
            vector<int> counts(26, 0);
            for(auto c : str){
                counts[c-'a']++;
            }
            string key = "";
            for(int i = 0; i< 26; i++){
                key += counts[i] + '#';
            }
            mp[key].push_back(str);
        }

        for(auto tup : mp){
            result.push_back(tup.second);
        }
        return result;
    }
};
