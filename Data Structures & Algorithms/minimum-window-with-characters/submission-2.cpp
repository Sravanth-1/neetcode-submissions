class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        vector<int> vis(256, 0);
        for(auto i: t){
            vis[i]++;
        }
        int count = t.size();
        int start = 0;
        int beststart = -1;
        int minlen = INT_MAX;
        for(int i = 0; i< s.size(); i++){
            if(vis[s[i]] > 0){
                count--;
            }
            vis[s[i]]--;
            while(count == 0){
                if(i-start+1 < minlen){
                    minlen = i-start+1;
                    beststart = start;
                }
                vis[s[start]]++;
                if(vis[s[start]] > 0){
                    count++;
                }
                start++;
            }
        }
        if(beststart == -1){
            return "";
        }
        return s.substr(beststart, minlen);
    }
};
