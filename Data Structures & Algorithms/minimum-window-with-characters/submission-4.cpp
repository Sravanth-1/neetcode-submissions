class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(256, 0);
        int startindex = -1;
        int minlen = INT_MAX;
        int tot = t.size();
        int left = 0;
        for(auto ch: t){
            count[ch]++;
        }
        for(int right = 0; right < s.size(); right++){
            if(count[s[right]] > 0){
                tot--;
            }
            count[s[right]]--;

            while(tot == 0){
                if(right-left+1 < minlen){
                    minlen = right - left +1;
                    startindex = left;
                }

                count[s[left]]++;
                if(count[s[left]] > 0){
                    tot++;
                }
                left++;
            }
        }

        if(minlen == INT_MAX){
            return "";
        }
        return s.substr(startindex, minlen);
    }
};
