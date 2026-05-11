class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto i: strs){
            string temp = "";
            vector<int> counts(26, 0);
            for(int j = 0; j< i.size(); j++){
                counts[i[j]-'a']++;
            }
            for(int j = 0; j< 26; j++){
                temp += to_string(counts[j]) + '#';
            }
            mp[temp].push_back(i);
        }

        vector<vector<string>> result;

        for(auto i: mp){
            result.push_back(i.second);
        }

        return result;
    }
};
