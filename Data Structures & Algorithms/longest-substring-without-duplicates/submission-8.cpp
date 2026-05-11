class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int last = 0;
        int len = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) == mp.end() || mp[s[i]] < last){
                mp[s[i]] = i;
            }else {
                len = max(len, i-last);
                last = mp[s[i]]+1;
                mp[s[i]] = i;
            }
        }
        len = max(len, (int)s.size()-last);
        return len;
    }
};
