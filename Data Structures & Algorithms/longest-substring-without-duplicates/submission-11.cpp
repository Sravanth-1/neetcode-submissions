class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> present(256, -1);
        int last = 0;
        int maxlen = 0;
        for(int i = 0; i< s.size(); i++){
            if(present[s[i]] >= last){
                last = present[s[i]]+1;
            }
            maxlen = max(maxlen, i-last+1);
            present[s[i]] = i;
        }
        return maxlen;
    }
};
