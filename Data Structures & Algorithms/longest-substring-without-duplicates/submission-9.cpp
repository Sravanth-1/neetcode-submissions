class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(256, -1);
        int start = 0;
        int maxlen = 0;
        for(int i = 0; i< s.size(); i++){
           if(vis[s[i]] >= start){
              start = vis[s[i]]+1;
           }
           maxlen = max(maxlen, i-start+1);
           vis[s[i]] = i;
        }
        return maxlen;
        
    }
};
